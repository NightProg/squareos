#include "mem.h"

#include <stdint.h>

void *memset(void *ptr, int value, size_t num) {
    uint8_t *p = (uint8_t *)ptr;
    while (num--) {
        *p++ = (uint8_t)value;
    }
    return ptr;
}

