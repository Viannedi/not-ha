#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
#include <conio.h>
#include <stdio.h>

int main()
{

    int answer;
    char textAnswer[50];
    while (1) {
        system("cls");

        printf("1. Creates a file, each record of which contains data, the type of which is specified in a specific version\n");
        printf("2. Opens an existing file (or reports that the file specified by the name does not exist)\n");
        printf("3. Closes the file\n");
        printf("4. Allows you to view the contents of the file\n");
        printf("5. Allows you to add a record to the file\n");
        printf("6. Allows you to exit the program\n");
        printf("7. Most profitable");

        printf("\nEnter command:");
        scanf("%d", &answer);

        switch (answer) {
        case 1:
            printf("Enter name of file: ");
            scanf("%s", &textAnswer);
            createFile(textAnswer);
            break;

        case 2:
            printf("Enter name of file: ");
            scanf("%s", &textAnswer);
            openFile(textAnswer);
            break;

        case 3:
            closeFile();
            break;

        case 4:
            printf("Enter name of file: ");
            scanf("%s", &textAnswer);
            printStruct(textAnswer);
            _getch();
            break;

        case 5:
            printf("Enter name of file: ");
            scanf("%s", &textAnswer);
            addRecord(textAnswer);
            break;

        case 6:
            exit(0);
            break;
        case 7:
            printf("Enter name of file: ");
            scanf("%s", &textAnswer);
            mostProfitableSessions(textAnswer);
            _getch();
            break;
        default:
            printf("");
            break;
        }
    }
    return 0;
}