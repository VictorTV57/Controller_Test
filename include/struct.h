/*
** VICTORTV57 PROJECT, 2025
** CONTROLLER_TEST
** File description:
** struct
*/

#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Joystick.h>


#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

typedef struct background {
    sfSprite *background;
    sfTexture *image;
    sfVector2f position;
}my_background_t;

    #define FUNCTIONS_H

    int show_controller_output(sfRenderWindow *window);

    static int read_print(const char *str);
    static int flag_gestion(int argc, char **argv);

    void destroy_sf(sfRenderWindow *window);
    int create_sf(sfRenderWindow *window);
    void my_draw(sfRenderWindow *window);
    int main_program(void);

#endif
