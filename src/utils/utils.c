#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void string_to_uppercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            str[i] = str[i] - 'a' + 'A'; // to_uppercase(str[i]); msm coisa
        }
    }
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear"); // Linux / macOS
#endif
}

void pause_view()
{
    printf("Pressione ENTER para continuar...");
    getchar();
}

int validate_numeric_string(char numbers[])
{
    for (int i = 0; numbers[i] != '\0'; i++)
    {
        if (numbers[i] < '0' || numbers[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}
