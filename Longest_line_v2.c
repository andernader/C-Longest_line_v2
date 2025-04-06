#include <stdio.h>
#include <string.h>

int main(){
    char filename[100];
    char buffer[250];
    char longest_line[250];
    int length;
    int longest_length;
    FILE *fptr;

    start:
    memset(filename, 0, sizeof(filename));
    memset(buffer, 0, sizeof(buffer));
    memset(longest_line, 0, sizeof(longest_line));
    length = 0;
    longest_length = 0;

    printf("file name : ");
    scanf("%99s", filename);

    filename[strcspn(filename, "\n")] = '\0';

    if(strcmp(filename, "exit") == 0)
        return 0;

    fptr = fopen(filename, "r");

    if(fptr == NULL){
        fprintf(stderr, "Error! File not found!\n\n");
        goto start;
    }

    while(fgets(buffer, sizeof(buffer), fptr) != NULL){
        length = strlen(buffer);
        if(longest_length < length){
            strncpy(longest_line, buffer, sizeof(longest_line));
            longest_length = length;
        }
    }

    longest_length--;
    longest_line[longest_length] = '\0';

    printf("Longest_line   = %s\n", longest_line);
    printf("Longest_length = %d\n\n", longest_length);

    fclose(fptr);

    goto start;
    return 0;
}
