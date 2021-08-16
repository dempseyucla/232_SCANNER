#include "scanner.h"

int main(int argc, char** argv)
{
    TOKEN *token = NULL;

    if (argc < 3)
    {
        printf("Paths to two files (the transition table and the input) should be provided as arguments.");
        fflush(stdout);
        exit(1);
    }

    if (!freopen(argv[1], "r", stdin))
    {
        printf("Could not open file at \"%s\". Exiting...", argv[1]);
    }

    TRANS_TABLE *table = readTable();


    if (!freopen(argv[2], "r", stdin))
    {
        printf("Could not open file at \"%s\". Exiting...", argv[2]);
    }

    while ((token = scanner(table)) != NULL)
    {
        printToken(token, table);
        freeToken(&token);
        fflush(stdout);
    }
    printf("\n");
    freeTable(&table);
}