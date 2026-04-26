# ME 507 – Lab 2: Motor Driver (STM32)

This project implements a motor control system using an STM32 microcontroller and a dual-channel motor driver. The goal of the lab is to interface hardware with embedded C code by generating PWM signals to control the speed and direction of DC motors.

The system uses a timer configured for high-frequency PWM (~20 kHz) to drive two motors independently. A custom motor driver module (`motor_driver.c/.h`) abstracts the low-level hardware interactions, allowing for simple control of each motor through function calls.

User commands are sent over UART in a predefined format (`Mnxy`), where each command sets the direction and duty cycle of a selected motor. The program parses incoming serial data, converts hexadecimal input into signed values, and updates motor behavior in real time.

This project demonstrates key embedded systems concepts including:

* PWM generation using hardware timers
* UART communication with interrupt handling
* Driver abstraction using C structs and modular design
* Real-time control of hardware peripherals

The final system allows a user to control two motors independently via a serial terminal interface.
