# Andre's Basic Calculator in C++

A simple console-based andre_calculator_yokogawa application written in C++. This project demonstrates clean code structure by separating the computational logic (via the `Calculator` class) from the user interface and program flow (via the `Calculator_Application` class).

## Features
- Addition
- Subtraction
- Multiplication
- Division (with error handling for division by zero)
- Input validation for menu options and numbers
- Clean, modular class design

## How to Compile
To compile the program, use any C++ compiler that supports C++11 or later. Below are example commands using **g++**:

```bash
g++ -std=c++11 -o calculator andre_calculator_yokogawa.cpp
```
Replace `main.cpp` with the filename containing your code.

## How to Run
After compilation, run the program from your terminal:

```bash
./calculator
```

## Usage Instructions
1. When the program starts, you will see a menu with five options.
2. Enter a number from **1 to 5** to select the arithmetic operation or exit the program.
3. If you choose operations 1–4, you will be prompted to enter two numbers.
4. The program will calculate and display the result.
5. Press **ENTER** to return to the menu.
6. Choose option **5** to exit the program.

## Example Menu
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

## License
© 2025 Andre's Technical Interview to Yokogawa Singapore.

