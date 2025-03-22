# shellcheck disable=SC2034
source_file=$(find . -type f -name "*.c")

boot_file="boot/boot.asm"
cc=i686-elf-gcc
as=nasm
build_dir="build"
target=squareos.bin
iso=squareos.iso
objects=$(find $build_dir -type f -name "*.o")
$asm=$(find ./kernel/asm -type f -name "*.asm")



compile_c() {
  for element in $source_file; do
        mkdir -p "$(dirname "$build_dir/$element.o")" 
      $cc -c "$element" -o "$build_dir/$element.o" -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -g -I kernel

  done
}

compile_boot() {
  $as -f elf32 $boot_file -o "$build_dir/boot.o"
}

compile_asm() {
  for element in $(find ./kernel/asm -type f -name "*.asm"); do
          mkdir -p "$(dirname "$build_dir/$element.o")" 

      $as -f elf32 $element -o "$build_dir/$element.o"
  done
}

link() {
  $cc -T linker.ld -o "$target"  -ffreestanding -O2 -nostdlib $(find $build_dir -type f -name "*.o") -lgcc
}

iso() {
  cp $target isodir/boot
  grub-mkrescue -o $iso isodir
}

set -x
echo $asm
compile_c
compile_boot
compile_asm
link
iso