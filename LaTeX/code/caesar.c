// Written by Siddharth Mahendraker
// Copyright (c) 2011
// MIT Licence

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// a - z in ascii
#define CHAR_START 97
#define CHAR_STOP  122

/*
 * Usage: ./shiftcipher [shift] [-e|-d] file.txt
 *
 * Only lowercase ASCII will be parsed, everything else
 * will be skipped
 */


int main(int argc, char *argv[]){

    if(argv[1] == NULL){
        printf("An error occured, a shift value is required. \n");
        exit(EXIT_FAILURE);
    }

    int shift = atoi(argv[1]) % 26;
    int encrypt;

    if(argv[2] == NULL){
        printf("An error occured, please use -e or -d
                to set the encryption/decryption mode. \n");
        exit(EXIT_FAILURE);
    } else {
        if(strcmp((char *)argv[2], "-e") == 0){
            encrypt = 1;
        }
        if(strcmp((char *)argv[2], "-d") == 0){
            encrypt = 0;
        }
        if(encrypt != 1 && encrypt != 0){
            printf("An error occured, please use -e or -d
                    to set the encryption/decryption mode. \n");
            exit(EXIT_FAILURE);
        }
    }

    FILE *file = fopen(argv[3], "r");

    if(file == NULL){
        printf("An error occured opening the file %s. \n",argv[3]);
        exit(EXIT_FAILURE);
    }

    // Main body of the code begins here

    // Retreives the integer representation which correspond to
    // the first character and move the internal pointer forward

    int i = fgetc(file);

    // Loops through each of the characters in the file until the
    // end of the file is reached

    int ctxt;

    if(encrypt == 1){
        while(i != EOF){
            if(i >= CHAR_START && i <= CHAR_STOP){
                ctxt = i+shift;

                if(ctxt > CHAR_STOP){
                    ctxt = CHAR_START + (ctxt - (CHAR_STOP + 1));
                } else if(ctxt < CHAR_START){
                    ctxt = (CHAR_STOP + 1) - (CHAR_START - ctxt);
                }

                char c = (char) ctxt;
                printf("%c", c);
            }

            i = fgetc(file);
        }
    }else{
        while(i != EOF){
            if(i >= CHAR_START && i <= CHAR_STOP){
                ctxt = i-shift;

                if(ctxt > CHAR_STOP){
                    ctxt = CHAR_START + (ctxt - (CHAR_STOP + 1));
                } else if(ctxt < CHAR_START){
                    ctxt = (CHAR_STOP + 1) - (CHAR_START - ctxt);
                }

                char c = (char) ctxt;
                printf("%c", c);
            }

            i = fgetc(file);
        }
    }

    fclose(file);
    return 0;
}
