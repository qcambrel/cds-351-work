#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (true)
    {   
        // Prompt user for digit in numerical or word form
        std::string input;
        std::cout << "Enter a digit (0-9) or a spelled-out number (zero-nine): ";
        std::cin >> input;

        // Check if digit is a number
        if (isdigit(input.at(0))){
            int digit = std::stoi(input);
            std::cout << "Spelled-out value: " << digits.at(digit) << std::endl;
        } else {
            for (int i = 0; i < 10; i++){
                if (input == digits[i]){
                    std::cout << "Digit value: " << i << std::endl;
                }
            }
        }
    }

    return 0;
}