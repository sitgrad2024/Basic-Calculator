#include <iostream>     // for std::cin, std::cout
#include <iomanip>      // for std::setprecision
#include <limits>       // for std::numeric_limits
#include <stdexcept>    // for std::runtime_error
#include <string>       // if using std::string for prompts
#include <sstream>      // for stringstream

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
        long double Addition(long double num_one, long double num_two)
        {
            return num_one + num_two;
        }

        long double Subtraction(long double num_one, long double num_two)
        {
            return num_one - num_two;
        }

        long double Multiplication(long double num_one, long double num_two)
        {
            return num_one * num_two;
        }

        long double Division(long double num_one, long double num_two)
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
                long double num_one, num_two, result;

                user_option = GetValidatedMenuOption();
                
                if(user_option == 5)
                {
                    is_Running = false;
                    std::cout << "\nThank you for using Andre's calculator. Goodbye.\n";
                    std::cout << "\n© 2025 Andre's Technical Interview to Yokogawa Singapore.\n";
                    break;
                }
   
                num_one = GetValidatedNumber("\nPlease enter the first number:\n");
                num_two = GetValidatedNumber("\nPlease enter the second number:\n");
                
                try
                {
                    result = Perform_Number_Operation(user_option, num_one, num_two);
                    std::cout << std::fixed << std::setprecision(5) << "\nResult: " << result << std::endl << std::endl;
                }
                catch(const std::exception& e)
                {
                    std::cout << "\n" << e.what() << std::endl << std::endl;
                }
            }
        }

    private:
        Calculator calculator;

        void Print_Menu()
        {
            std::cout << "\n===== Welcome to Andre's Calculator =====\n";
            std::cout << "Choose an option from 1 to 5:\n";
            std::cout << "1. Addition\n";
            std::cout << "2. Subtraction\n";
            std::cout << "3. Multiplication\n";
            std::cout << "4. Division\n";
            std::cout << "5. Exit\n";
            std::cout << std::endl;
        }  
        
        int GetValidatedMenuOption()
        {
            int option;
            std::string line;
            while (true)
            {
                std::cout << "Enter your option (1-5): ";
                std::getline(std::cin, line);
                std::stringstream ss(line);

                if (ss >> option && ss.eof() && option >= 1 && option <= 5)
                    return option;
                else
                {
                    std::cout << "\nInvalid input. Please enter a valid option (1-5).\n\n";
                    Print_Menu();
                }
            }
        }

        long double GetValidatedNumber(const std::string &prompt)
        {
            long double num;
            std::string line;
            while(true)
            {
                std::cout << prompt;
                std::getline(std::cin, line);
                std::stringstream ss(line);

                if(ss >> num && ss.eof())
                {
                    return num;
                }
                else
                {
                    std::cout << "\nInvalid input. Please enter a valid number.\n\n";
                }
            }
        }       

        long double Perform_Number_Operation(int option, long double num_one, long double num_two)
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
};

int main()
{
    Calculator_Application application;
    application.Run();
    return 0;
}
