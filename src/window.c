/*
** VICTORTV57 PROJECT, 2025
** CONTROLLER_TEST
** File description:
** Where the window is manage
*/

#include "../include/struct.h"

void destroy_sf(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

int create_sf(sfRenderWindow *window)
{
    sfVideoMode mode = {1, 1, 1};
    sfIntRect rect = {1, 1, 1, 1};

    if (!window)
        return 84;
    return 0;
}

void my_draw(sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
}

int main_program(void)
{
    my_background_t *background = malloc(sizeof(my_background_t));
    sfVideoMode mode = {1, 1, 1};
    sfRenderWindow *window = sfRenderWindow_create(mode, "controller_test", sfResize | sfClose, NULL);
    sfEvent event;

    create_sf(window);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        my_draw(window);
        sfRenderWindow_pollEvent(window, &event);
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            destroy_sf;
            return 0;
        }
        show_controller_output(window);
    }
    destroy_sf(window);
    return 0;
}
