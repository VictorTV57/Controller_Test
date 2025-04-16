/*
** VICTORTV57 PROJECT, 2025
** CONTROLLER_TEST
** File description:
** main
*/

#include "../include/struct.h"

static int read_print(const char *str)
{
    const char *flag_main = "-h";

    if (strcmp(str, flag_main) == 0) {
        printf("\033[1;36m=== Controller Test Help ===\033[0m\n\n");
        printf("\033[1;36mCredits:\033[0m \033[1;34mVictorTV57\033[0m (\033[4;34mhttps://github.com/VictorTV57\033[0m)\n");
        printf("\033[37mThis program is made to test the output of your controller.\033[0m\n\n");
        printf("\033[1;36mUsage:\033[0m\n");
        printf("\033[37mYou can launch the program using the following command:\033[0m\n");
        printf("\033[33m\t./controller_test\033[0m\n");
        return 0;
    } else
        return main_program();
}

static int flag_gestion(int argc, char **argv)
{
    if (argc <= 1)
        return main_program();
    for (int i = 1; i < argc; i++)
        read_print(argv[i]);
    return 0;
}

int main(int argc, char **argv)
{
    return flag_gestion(argc, argv);
}
