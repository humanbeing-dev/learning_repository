#include <iostream>
#include <string>

std::string reverse_string(const std::string &str);

int main (){
    
    std::cout << "Type in the text you want reversed and hit Enter: ";
    std::string input_string;
    std::getline(std::cin, input_string);
    std::cout << "\nYou've typed: " << input_string << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Reversing string via the use of pointers..." << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Reversed string is: " << reverse_string(input_string) << std::endl;
    
    return 0;
}

std::string reverse_string(const std::string &str){
    std::string reversed;
    const char *start = str.c_str();
    const char *end = str.c_str() + str.size() - 1;
    while (end >= start) {
        reversed.push_back(*end);
        end--;
    }
    return reversed;
}