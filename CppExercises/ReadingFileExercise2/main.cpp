// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

std::string enterWord() {
    std::string sub_str;
    std::cout << "Enter the substring to search for: "; 
    std::cin >> sub_str;
    std::cout << std::endl;
    return sub_str;
}

void displayWordFindQuantity(const std::string &sub_str, std::ifstream &in_file) {
    int word_count = 0;
    int find_count = 0;
    std::string str;
        while (in_file >> str){
            word_count++;
            if (str.find(sub_str) != std::string::npos) // or -1 as npos
                find_count++;
        }
    std::cout << word_count << " words were searched..." << std::endl;
    std::cout << "The substring " << sub_str << " was found " << find_count << " times." << std::endl;
}

int main() {
    
    std::ifstream in_file;
    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::string sub_str;
    sub_str = enterWord();
    
    displayWordFindQuantity(sub_str, in_file);
    
    std::cout << std::endl;
    return 0;
}

