/*
decrypte.c
----------------------------------------------------------------------------
Decryption or encryption of txt by key.
*/



#include <Windows.h>
#include <stdio.h>


char* decrypte_line(char* line, long key, char mode) {

    int i, mode_sign;
    char ch;
    size_t len = strlen(line);

    if (mode == 'd') mode_sign = 1;
    else { mode_sign = -1; }

    key *= mode_sign;

    for (i = 0; i < len - 1; i++) {
        ch = *(line + i);
        if (isdigit(ch)) {
            ch = '0' + (ch - '0' - key) % 10;
        }
        if (isalpha(ch)) {
            if (islower(ch)) {
                if ((ch - 'a' - key) < 0) ch += 26;
                ch = 'a' + (ch - 'a' - key) % 26;
            }
            else {
                if ((ch - 'A' - key) < 0) ch += 26;
                ch = 'A' + (ch - 'A' - key) % 26;
            }
        }
        *(line + i) = ch;
    }

    return line;
}

