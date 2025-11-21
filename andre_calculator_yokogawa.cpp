#include <iostream>     // for std::cin, std::cout
#include <limits>       // for std::numeric_limits
#include <stdexcept>    // for std::runtime_error
#include <string>       // if using std::string for prompts

/*
==================================================
Calculator class:
1. Handles all arithmetic operations.
2. Encapsulates behaviour and keeps the modularity
   of logic.
==================================================
*/

class Calculator
{
    public:
        double Addition(double num_one, double num_two)
        {
            return num_one + num_two;
        }

        double Subtraction(double num_one, double num_two)
        {
            return num_one - num_two;
        }

        double Multiplication(double num_one, double num_two)
        {
            return num_one * num_two;
        }

        double Division(double num_one, double num_two)
        {
            if(!num_two)
            {
                throw std::runtime_error("Error: Division by zero does not exist.\n");
            }
            
            return num_one / num_two;
        }        
};

/*
==================================================
Calculator_Application class:
1. Handles user interface and program flow.
2. Keeps user interface (UI) separate from logic.
==================================================
*/

class Calculator_Application
{
    public:
        void Run()
        {
            bool is_Running = true;

            while(is_Running)
            {
                Print_Menu();

                int user_option;
                double num_one, num_two;

                while(!(std::cin >> user_option))
                {
                    std::cout << "Invalid input. Please enter a valid option\n\n";
                    Print_Menu();
                }
                

                if(user_option == 5)
                {
                    is_Running = false;
                    std::cout << "Thank you for using Andre's calculator. Goodbye.\n";
                    std::cout << "© 2025 Andre's Technical Interview to Yokogawa Singapore.\n";
                    break;
                }
   
                std::cout << "Please enter the first number:\n";
                while(!(std::cin >> num_one))
                {
                    std::cout << "Invalid input. Please enter a valid first number.\n\nPlease enter the first number:\n";
                }
                std::cout << "Please enter the second number:\n";
                while(!(std::cin >> num_two))
                {
                    std::cout << "Invalid input. please enter a valid second number.\n\nPlease enter the second number:\n";
                }
                
                try
                {
                    double result = Perform_Number_Operation(user_option, num_one, num_two);
                    std::cout << "\nResult: " << result << std::endl << std::endl;
                }
                catch(const std::exception& e)
                {
                    std::cout << "\n" << e.what() << std::endl << std::endl;
                }
                
                Pause();
            }
        }

    private:
        Calculator calculator;

        void Print_Menu()
        {
            std::cout << "===== Welcome to Andre's Calculator =====\n";
            std::cout << "Choose an option from 1 to 5:\n";
            std::cout << "1. Addition\n";
            std::cout << "2. Subtraction\n";
            std::cout << "3. Multiplication\n";
            std::cout << "4. Division\n";
            std::cout << "5. Exit\n";
        }   

        double Perform_Number_Operation(int option, double num_one, double num_two)
        {
            switch (option)
            {
                case 1:
                    return calculator.Addition(num_one, num_two);
                    
                case 2:
                    return calculator.Subtraction(num_one, num_two);
                
                case 3:
                    return calculator.Multiplication(num_one, num_two);

                case 4:
                    return calculator.Division(num_one, num_two);

                default:
                    throw std::runtime_error("Invalid menu option.");
            }
        }

        void Pause()
        {
            std::cout << "Press the ENTER key to continue...";
            std::cin.ignore();
            std::cin.get();
            std::cout << std::endl;
        }
};

int main()
{
    Calculator_Application application;
    application.Run();
    return 0;
}
