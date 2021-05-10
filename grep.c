#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

char *readLine(FILE *file);
int patternMatch(char *pattern, char *line);

int main(int argc, char *argv[]) {
    int ret = 0;
    char *pattern = NULL;
    char *filename = NULL;

    if (argc >= 2) {
        pattern = argv[1];
        filename = argv[2];
    }
    //Argument check
    if (pattern == NULL || filename == NULL) {
        fprintf(stderr, "Pattern or filename not given!\n");
        ret = 101;
    }
    //Opening file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        ret = 102;
    }

    //Main loop
    //Take one line from file and check for pattern
    bool match = false;
    char *line = readLine(file);
    while (line != NULL) {
        ret = patternMatch(pattern, line);
        if (ret == 0) {
            match = true;
        }
        free(line);
        line = readLine(file);
    }
    if (match) {
        ret = 0;
    }

    fclose(file);
    return ret;
}

//Reads one line from file and returns it
char *readLine(FILE *file) {
    int size = SIZE;
    char *ret = malloc(size + 1);
    int len = 0;
    int letter;

    if (ret == NULL) {
        fprintf(stderr, "Error: allocation failed!\n");
        exit(-1);
    }
    while ((letter = getc(file)) && letter != EOF && letter != '\n') {
        if (len == size) {
            char *tmp = realloc(ret, size + SIZE + 1);
            if (tmp == NULL) {
                free(ret);
                fprintf(stderr, "Error: realloc failed!\n");
                exit(-1);
            }
            ret = tmp;
            size += SIZE;
        }
        ret[len] = letter;
        ++len;
    }
    if (letter == EOF && len == 0) {
        free(ret);
        ret = NULL;
    } else {
        ret[len] = '\0';
    }
    return ret;
}
 //Looks for pattern in a given line of text
int patternMatch(char *pattern, char *line) {
    int ret = 1;
    int patternIndex = 0;
    int lineIndex = 0;
    while (pattern[patternIndex] != '\0' && line[lineIndex] != '\0') {
        if (pattern[patternIndex] == line[lineIndex]) {
            patternIndex += 1;
        } else {
            patternIndex = 0;
        }
        lineIndex += 1;
    }
    if (pattern[patternIndex] == '\0') {
        printf("%s\n", line);
        ret = 0;
    }
    return ret;
}
