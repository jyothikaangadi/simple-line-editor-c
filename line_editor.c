#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

void display(char lines[][MAX_LENGTH], int lineCount)
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- Document -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

void insertLine(char lines[][MAX_LENGTH], int *lineCount)
{
    int lineNumber;

    if (*lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > *lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = *lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    fgets(lines[lineNumber - 1], MAX_LENGTH, stdin);

    lines[lineNumber - 1][strcspn(lines[lineNumber - 1], "\n")] = '\0';

    (*lineCount)++;

    printf("Line inserted successfully.\n");
}

void deleteLine(char lines[][MAX_LENGTH], int *lineCount)
{
    int lineNumber;

    if (*lineCount == 0)
    {
        printf("Document is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > *lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = lineNumber - 1; i < *lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    (*lineCount)--;

    printf("Line deleted successfully.\n");
}

int main()
{
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
    char command;

    printf("===== SIMPLE LINE EDITOR =====\n");

    while (1)
    {
        printf("\nCommands:\n");
        printf("I = Insert line\n");
        printf("D = Delete line\n");
        printf("P = Display document\n");
        printf("Q = Quit\n");

        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'I' || command == 'i')
        {
            insertLine(lines, &lineCount);
        }
        else if (command == 'D' || command == 'd')
        {
            deleteLine(lines, &lineCount);
        }
        else if (command == 'P' || command == 'p')
        {
            display(lines, lineCount);
        }
        else if (command == 'Q' || command == 'q')
        {
            printf("Exiting editor...\n");
            break;
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}