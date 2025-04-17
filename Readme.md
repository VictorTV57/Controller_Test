# 🎮 Controller Test

A lightweight tool to visualize and debug game controller inputs in real-time using SFML and ncurses. Designed to assist developers in mapping and testing controller buttons, sticks, triggers, and D-Pads.

## 🧩 Features

- ✅ Real-time display of controller input states.
- 🎮 Supports PlayStation and Xbox controllers.
- 📋 Displays button IDs and axis positions.
- 🖥️ Terminal-based interface using ncurses.
- 🔄 Continuous input monitoring with graceful exit.

## 📸 Controller Mapping Reference

For detailed controller mappings, refer to the following visual guides:

- [PlayStation 5 Controller Mapping](https://controller.dl.playstation.net/controller/lang/en/2100002.html)
- [Xbox Series X|S Controller Mapping](https://news.xbox.com/en-us/2023/08/03/keyboard-button-mapping-for-xbox-controllers/)

These references provide comprehensive diagrams illustrating button and axis mappings for both controller types.

## 🛠️ Installation

```bash
# Clone the repository:
git clone https://github.com/VictorTV57/controller_test.git
cd controller_test

# Install dependencies (Debian/Ubuntu):
sudo apt-get install libsfml-dev libncurses5-dev

# Compile the project:
make
```

## 🚀 Usage

```bash
# Run the program:
./controller_test

# Display the help message:
./controller_test -h
```

> **Note:** Use the `-h` flag to display the help message.

## 🧪 Output Overview

Upon running the program, you'll see real-time updates of your controller's state, including:

- **Connection Status:** Indicates whether a controller is connected.
- **Button Presses:** Lists IDs of currently pressed buttons.
- **Axis Positions:** Displays positions of analog sticks and triggers.
- **D-Pad Directions:** Shows the current state of the D-Pad.

**Example output:**

```yaml
=== CONTROLLER DEBUG INTERFACE === 

Controller Status:
Connected - 13 buttons
ID of button(s) pressed : 
Arrows : PovX=0, PovY=0
Left joystick : X=0.0, Y=0.0, L3=0
Central Buttons : Share=0, PS=0, Pause=0
Right joystick : X=0.0, Y=0.0, R3=0
Buttons : A=0, B=0, Y=0, X=0
Triggers Up : L1=0, R1=0
Triggers Down : L2=0.0, R2=0.0

Press CTRL+C to quit (Quitforce handler engaged).  
```

## 🧠 Controller Button IDs

| Function             | PlayStation           | Xbox                  | Button ID |
|----------------------|-----------------------|-----------------------|-----------|
| Cross / A            | ❌ Cross              | 🇦 A                  | 0         |
| Circle / B           | ⭕ Circle             | 🇧 B                  | 1         |
| Triangle / Y         | 🔺 Triangle           | 🇾 Y                  | 2         |
| Square / X           | 🟥 Square             | 🇽 X                  | 3         |
| L1 / LB              | L1                    | LB                    | 4         |
| R1 / RB              | R1                    | RB                    | 5         |
| Share / View         | Share                 | View                  | 8         |
| Options / Menu       | Options               | Menu                  | 9         |
| PS / Xbox            | PlayStation logo      | Xbox logo             | 10        |
| Left Stick Press     | L3                    | LS                    | 11        |
| Right Stick Press    | R3                    | RS                    | 12        |

> *Note: Axis positions for triggers and sticks are accessed via `sfJoystick_getAxisPosition` with respective axes like `sfJoystickX`, `sfJoystickY`, `sfJoystickZ`, etc.*

## 🧑‍💻 Author

Developed by [VictorTV57](https://github.com/VictorTV57)

## ©️ License
[![License: CC BY-NC 4.0](https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc/4.0/)
