#ifndef KERNEL_KEYBOARD_KEY
#define KERNEL_KEYBOARD_KEY


static unsigned char keymap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',  /* Backspace */
    '\t',  /* Tab */
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',  /* Enter */
    0,    /* Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0,    /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,  /* Right shift */
    '*',
    0,    /* Alt */
    ' ',  /* Space bar */
    0,    /* Caps lock */
    /* Fonction keys */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  /* F1-F10 */
    0,    /* Num lock */
    0,    /* Scroll Lock */
    /* Keypad */
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
};


#endif