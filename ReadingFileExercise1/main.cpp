// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>

int count(const char score[6], const char key[6]) {
    int result {};
    for (size_t i = 0; i < 5; ++i) {
        if(score[i] == key[i])
            result++;
    }
    return result;
}

int main() {
    std::ifstream in_file;
    in_file.open("responses.txt");
    if (!in_file) {
        std::cout << "Error opening file!";
        return 1;
    }
    char key [6];
    key[5] = '\0';
    char score [6];
    score[5] = '\0';
    std::string name;
    int sum {};
    in_file >> key;
    int iterations {};
    
    std::cout << std::setw(10) << std::left << "Student"
              << std::setw(10) << std::right << "Score" 
              << std::endl;
    
    std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    
    while (in_file >> name >> score) {
        std::cout << std::setw(10) << std::left << name
                  << std::setw(10) << std::right << count(score, key)
                  << std::endl;
                  sum += count(score,key);
                  iterations++;
    }
    
    std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    
    double average {0};
    if (iterations != 0)
        average = static_cast<double>(sum) / iterations;
        
    std::cout << std::setw(10) << std::left << "Average"
              << std::setw(10) << std::right << std::setprecision(1) << std::fixed << average;
              
    std::cout << std::endl;
              
    in_file.close();
    return 0;
}

