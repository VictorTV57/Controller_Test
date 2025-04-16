/*
** VICTORTV57 PROJECT, 2025
** CONTROLLER_TEST
** File description:
** Show controller output
*/

#include "../include/struct.h"

int show_controller_output(sfRenderWindow *window)
{
    initscr();
    clear();

    char button_info[1024] = "Controller Status:\n";

    if (!sfJoystick_isConnected(0)) {
        strcat(button_info, "No controller connected");
    } else {
        unsigned int button_count = sfJoystick_getButtonCount(0);

        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Connected - %u buttons\n", button_count);

        // List pressed buttons
        strcat(button_info, "ID of button(s) pressed : ");
        for (unsigned int i = 0; i < button_count; i++) {
            if (sfJoystick_isButtonPressed(0, i)) {
                snprintf(button_info + strlen(button_info),
                         sizeof(button_info) - strlen(button_info),
                         "%u ", i);
            }
        }
        strcat(button_info, "\n");        

        // D-Pad
        float PovX = sfJoystick_getAxisPosition(0, sfJoystickPovX);                            // Arrow (Left/Right)
        float PovY = sfJoystick_getAxisPosition(0, sfJoystickPovY);                            // Arrow (Up/Down)
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Arrows : PovX=%.0f, PovY=%.0f\n", PovX, PovY);

        // Left Joystick
        float LX = sfJoystick_getAxisPosition(0, sfJoystickX);                                 // Left joystick : Left/Right
        float LY = sfJoystick_getAxisPosition(0, sfJoystickY);                                 // Left joystick : Up/Down
        float L3 = sfJoystick_isButtonPressed(0, 11);                                          // L3 button (Left joystick button)
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Left joystick : X=%.1f, Y=%.1f, L3=%.0f\n", LX, LY, L3);

        // Others Buttons
        float btnShare = sfJoystick_isButtonPressed(0, 8);                                      // Share button ; Select on Xbox
        float btnPS = sfJoystick_isButtonPressed(0, 10);                                        // PlayStation logo button ; Xbox logo button on Xbox
        float btnPause = sfJoystick_isButtonPressed(0, 9);                                      // Options button ; Pause on Xbox
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Central Buttons : Share=%.0f, PS=%.0f, Pause=%.0f\n", btnShare, btnPS, btnPause);

        // Right Joystick
        float RX = sfJoystick_getAxisPosition(0, sfJoystickU);                                 // Right joystick : Left/Right
        float RY = sfJoystick_getAxisPosition(0, sfJoystickV);                                 // Right joystick : Up/Down
        float R3 = sfJoystick_isButtonPressed(0, 12);                                          // R3 button (Right joystick button)
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Right joystick : X=%.1f, Y=%.1f, R3=%.0f\n", RX, RY, R3);

        // ABXY Buttons
        float btn_A = sfJoystick_isButtonPressed(0, 0);                                         // Cross button ; A on Xbox
        float btn_B = sfJoystick_isButtonPressed(0, 1);                                         // Circle button ; B on Xbox
        float btn_Y = sfJoystick_isButtonPressed(0, 2);                                         // Triange button ; Y on Xbox
        float btn_X = sfJoystick_isButtonPressed(0, 3);                                         // Square button ; X on Xbox
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Buttons : A=%.0f, B=%.0f, Y=%.0f, X=%.0f\n", btn_A, btn_B, btn_Y, btn_X);

        // Top Triggers
        float L1 = sfJoystick_isButtonPressed(0, 4);                                            // L1 triggers ; LB on Xbox
        float R1 = sfJoystick_isButtonPressed(0, 5);                                            // R1 triggers ; RB on Xbox
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Triggers Up : L1=%.0f, R1=%.0f\n", L1, R1);

        // Bottom Triggers (Analog)
        float Z = sfJoystick_getAxisPosition(0, sfJoystickZ);                                   // L2 triggers ; LT on Xbox
        float R = sfJoystick_getAxisPosition(0, sfJoystickR);                                   // R2 triggers ; RT on Xbox
        snprintf(button_info + strlen(button_info), sizeof(button_info) - strlen(button_info),
                "Triggers Down : L2=%.1f, R2=%.1f\n", Z, R);
    }

    // Better format display
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    box(stdscr, 0, 0);
    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(1, 2, "=== CONTROLLER DEBUG INTERFACE ===");
    attroff(COLOR_PAIR(1) | A_BOLD);
    attron(COLOR_PAIR(2));
    mvprintw(3, 2, "%s", button_info);
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3) | A_BOLD);
    mvprintw(LINES-3, 2, "Press CTRL+C to quit (Quitforce handler engaged).");
    attroff(COLOR_PAIR(3) | A_BOLD);
    mvhline(LINES-4, 1, ACS_HLINE, COLS-2);

    refresh();

    return 0;
}
