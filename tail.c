// tail.c
// Řešení IJC-DU2, příklad 1), 19. 4. 2022
// Autor: Matyáš Strelec, FIT
// Přeloženo: clang 13.1.6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 4096 // Maximum length of one line -1 => printed lines are MAX_LENGTH-1 long

int main(int argc, char *argv[])
{
    int linesCount; // Number of lines to be printed
    char* fileName; // Name of the file to be printed
    bool parseError = false; // Error flag
    FILE *fp; // File to be opened

    // Parse command line arguments
    switch (argc)
    {
        case 1: // Expect reading from stdin and default number of lines
            linesCount = 10;
            fp = stdin;
            break;
        case 2: // Expect filename
            linesCount = 10;
            fileName = argv[1];
            break;
        case 3: // Expect reading from stdin and given number of lines
            if (strcmp(argv[1], "-n") == 0)
            {
                linesCount = atoi(argv[2]);
                fp = stdin;
            }
            else
            {
                parseError = true;
            }
            break;
        case 4: // Expect filename and given number of lines
            if (strcmp(argv[1], "-n") == 0)
            {
                linesCount = atoi(argv[2]);
                fileName = argv[3];
            }
            else if (strcmp(argv[2], "-n") == 0)
            {
                linesCount = atoi(argv[3]);
                fileName = argv[1];
            }
            else
            {
                parseError = true;
            }
            break;
        default: // Unexpected number of arguments given
            parseError = true;
            break;
    }

    if(parseError) // Print error and exit
    {
            fprintf(stderr, "Wrong arguments given.\n");
            return 1;
    }

    // If not reading from stdin, open file for reading and check if file exists, otherwise print error and exit
    if (fp != stdin)
    {
        fp = fopen(fileName, "r");
        if (fp == NULL)
        {
            fprintf(stderr, "Error opening file.\n");
            return 1;
        }
    }

    // Create array to store last n strings
    char lines[linesCount][MAX_LENGTH+2]; // MAX_LENGTH+2 is to account for '\n' and '\0'
    int rollingArrayIndex = 0;  // Index in the array of string to be printed, after crossing maxium number of lines, it goes back to 0
    int linesRead = 0;  // Number of lines read from file

    // Read the file and store last n strings
    char buffer[MAX_LENGTH+2]; // Buffer to read the line into
    bool errorPrinted = false;  // Flag to indicate if error has been printed (only needs to be printed once)

    while((fgets(buffer, MAX_LENGTH+1, fp)) != NULL)    // Read the file line by line
    {
        // If line is longer than the set limit (indicated by lack of newline), print error and continue
        if(!strchr(buffer, '\n') && errorPrinted == false)
        {
            fprintf(stderr, "Line too long. Continuing with lines limited to %d characters.\n", MAX_LENGTH-1);
            errorPrinted = true;
        }

        // Discard rest of the line if the buffer is full
        char c;
        if(!strchr(buffer, '\n'))
            while((c = fgetc(fp)) != '\n' && c != EOF);

        buffer[MAX_LENGTH-1] = '\0'; // Terminate the string
        for (int i = 0; i < strlen(buffer); i++) // Replace trailing newline with null to avoid problems with printing
        {
            if(buffer[i] == '\n')
                buffer[i] = '\0';
        }
        

        // Save lines to rolling buffer        
        linesRead++;
        strcpy(lines[rollingArrayIndex], buffer);
        rollingArrayIndex = (rollingArrayIndex + 1) % linesCount; // If index is bigger than number of lines to be read, it goes back to 0
    
    }

    // Print last n lines, if file was shorter than n lines, print all lines
    if (linesRead < linesCount)
        linesCount = linesRead;

    for(int i = 0; i < linesCount; i++)
    {
        printf("%s\n", lines[(rollingArrayIndex + i) % linesCount]); // Use remainder to print lines in the correct order
    }

    // Close the file
    fclose(fp);

    return 0;
}