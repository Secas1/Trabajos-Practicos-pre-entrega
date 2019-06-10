#include <stdio.h>
#include <stdlib.h>

int menu(char* OptMenu)
{
    int option=-1;

    printf("%s",OptMenu);
    fflush(stdin);
    scanf("%d",&option);

    return option;
}
