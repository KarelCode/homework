#include <stdio.h>
#include <stdlib.h>

#define MSG_LENGHT 10

//Function declarations
char *readInput(int *msgLen);
void shift(char *msg, int msgLen, int offset);
int compare(char *msg1, int msgLen1, char *msg2);
void printMsg(char *msg, int len);

enum {ERROR_INPUT = 100, ERROR_LENGHT = 101};

int main(int argc, char *argv[]) {
    int ret = 0;
    
    char *msgEnc, *msg;
    int msgEncLen, msgLen, msgTmpLen;

    msgEnc = msg = NULL;
    msgEncLen = msgLen = msgTmpLen = 0;
    //Reading input and handling if it fails to allocate memory
    msgEnc = readInput(&msgEncLen);
    if (msgEnc) {
        msg = readInput(&msgLen);
    }
    if (msgEnc == NULL || msg == NULL) {
        ret = ERROR_INPUT;
        fprintf(stderr, "Error: Chybny vstup!\n");
    } else if (msgEncLen != msgLen) {
        ret = ERROR_LENGHT;
        fprintf(stderr, "Error: Chybna delka vstupu!\n");
    }
    
    if (ret == 0) {
        int offset = 1;
        int sameLetters = 0;
        int correctOffset = 0;
        char *msgTmp = malloc(msgEncLen * 2);
        if (msgTmp == NULL) {
            fprintf(stderr, "Error: allocation failed!\n");
        } else {
            while (sizeof(msgTmp) < sizeof(msgEnc)) {
                char *tmp = realloc(msgTmp, sizeof(msgTmp) * 2);
                if (tmp == NULL) {
                    fprintf(stderr, "Error: allocation failed!\n");
                    free(msgTmp);
                    msgTmp = NULL;
                    break;
                }
            }
        }
        msgTmpLen = msgEncLen;

        //Comparing messages and shifting by an offset
        for (int i = 0; i < 52; ++i) {
            int tmp = compare(msgEnc, msgEncLen, msg);
            if (tmp > sameLetters) {
                int letter;
                sameLetters = tmp;
                for (int i = 0; i < msgEncLen; ++i) {
                    letter = msgEnc[i];
                    msgTmp[i] = letter;
                }
                correctOffset = i;
            }
            shift(msgEnc, msgEncLen, offset);
        }
        //Print to console
        printMsg(msgTmp, msgTmpLen);

        free(msgTmp);
    }


    free(msgEnc);
    free(msg);


    return ret;
}

//Reading a line from input and checking if it's valid
char *readInput(int *msgLen) {
    int size = MSG_LENGHT;
    char *msg = malloc(size);
    int len = 0;
    if (msg == NULL) {
        fprintf(stderr, "Error: allocation failed!\n");
    } else {
        int c;
        while ((c = getchar()) != EOF && c != '\n') {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                free(msg);
                msg = NULL;
                len = 0;
                break;
            }
            if (len == size) {
                char *tmp = realloc(msg, size * 2);
                if (tmp == NULL) {
                    fprintf(stderr, "Error: allocation failed!\n");
                    free(msg);
                    msg = NULL;
                    len = 0;
                    break;
                }
                size *= 2;
                msg = tmp;
            }
            msg[len++] = c;
        }
    }

    *msgLen = len;
    return msg;
}

//Print message to console
void printMsg(char *msg, int len) {
    if (msg) {
        for (int i = 0; i < len; ++i) {
            putchar(msg[i]);
        }
        putchar('\n');
    }
}

//Shift a message by an offset
void shift(char *msg, int msgLen, int offset) {
    for (int i = 0; i < msgLen; ++i) {
        if (msg[i] + offset > 122) {
            msg[i] = msg[i] + (offset - 58);
        } else if ((msg[i] + offset > 90) && (msg[i] + offset < 97)){
            msg[i] = msg[i] + (offset + 6);
        } else {
            msg[i] = msg[i] + offset;
        }
    }
}

//Compare messages and return number of same letters
int compare(char *msg1, int msgLen1, char *msg2) {
    int sameLetters = 0;
    for (int i = 0; i < msgLen1; ++i) {
        if (msg1[i] == msg2[i]) {
            ++sameLetters;
        }
    }
    return sameLetters;
}
