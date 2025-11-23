# Andre's Basic Calculator in C++

A simple Basic Calculator application written in C++. This project demonstrates clean code structure by separating the computational logic (via the `Calculator` class) from the user interface and program flow (via the `Calculator_Application` class).

## 1. Features
- Addition
- Subtraction
- Multiplication
- Division (with error handling for division by zero)
- Input validation for menu options and numbers
- Clean, modular class design

## 2. How to Compile
To compile the program, go to the file directory where you store the following program:
```bash
andre_calculator_yokogawa.cpp
```
In the address bar of the file directory, type the following:
```bash
cmd
```
Once the command prompt has opened, type the following into the command prompt:
```bash
g++ andre_calculator_yokogawa.cpp -o andre_calculator_yokogawa.exe
```
Press the ENTER key on your device.

## 3. How to Run
After compilation, locate the following .exe file in the file directory where you store **andre_calculator_yokogawa.cpp**:
```bash
andre_calculator_yokogawa.exe
```
Double-click the .exe file, and allow the file to run.

## Instructions on how to use the program
1. When the program starts, you will see a menu with five options.
2. Enter a number from **1 to 5** to select the arithmetic operation or exit the program.
3. If you choose operations 1–4, you will be prompted to enter two numbers.
4. The program will calculate and display the result.
5. Press **ENTER** to return to the menu.
6. Choose option **5** to exit the program.

## Program Example (Menu)
```
===== Welcome to Andre's Calculator =====
Choose an option from 1 to 5:
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Exit
```

## Notes
- Division by zero results in a clear error message.
- Invalid inputs (like letters instead of numbers) will prompt the user to try again.

## Copyright
© 2025 Andre's Technical Interview to Yokogawa Singapore.

