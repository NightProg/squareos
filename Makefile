CC = i686-elf-gcc
AS = i686-elf-as
CFLAGS = -ffreestanding -O2 -Wall -Wextra -std=gnu99 -nostdlib -Ikernel
LDFLAGS = -T linker.ld -lgcc -nostdlib -ffreestanding

SRC_DIR = kernel
BUILD_DIR = build
BOOT_DIR = boot

# Trouver tous les fichiers .c et .asm
SOURCES = $(shell find $(SRC_DIR) -name "*.c")
ASM_SOURCES = $(BOOT_DIR)/boot.asm $(shell find $(SRC_DIR)/asm -name "*.asm")

# Générer les fichiers .o avec la même structure dans build/
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
ASM_OBJECTS = $(patsubst %.asm, $(BUILD_DIR)/%.o, $(ASM_SOURCES))

TARGET = squareos.bin

# Création des répertoires nécessaires dans build/
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(shell find $(SRC_DIR) -type d | sed "s|^$(SRC_DIR)|$(BUILD_DIR)|")

# Compilation complète
all: $(BUILD_DIR) $(TARGET)

# Debugging
debug:
	@echo "ASM_SOURCES = $(ASM_SOURCES)"
	@echo "ASM_OBJECTS = $(ASM_OBJECTS)"

# Linker
$(TARGET): $(OBJECTS) $(ASM_OBJECTS)
	$(CC) $(OBJECTS) $(ASM_OBJECTS) $(LDFLAGS) -o $(TARGET)

# Compilation des fichiers .c en .o dans $(BUILD_DIR)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers .asm en .o dans $(BUILD_DIR)
$(BUILD_DIR)/%.o: %.asm | $(BUILD_DIR)
	mkdir -p $(dir $@)
	nasm -f elf32 $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILD_DIR) $(TARGET) isodir squareos.iso

# Création de l'ISO
iso: $(TARGET)
	mkdir -p isodir/boot/grub
	cp $(TARGET) isodir/boot/
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o squareos.iso isodir


qemu: iso
	qemu-system-i386 -cdrom squareos.iso