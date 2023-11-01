#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void print_menu();
char read_input();
void print_vector(const vector<int> &list);
void add_number(vector<int> &list);
void print_mean(const vector<int> &list);
void print_smallest(const vector<int> &list);
void print_largest(const vector<int> &list);
void print_find(const vector<int> &list);

int main() {

    bool quit = false;
    char choice {};
    vector <int> numbers {};

    do {
        print_menu();
        choice = read_input();
        if (choice == 'P')
            print_vector(numbers);
        else if (choice == 'A')
            add_number(numbers);
        else if (choice == 'M')
            print_mean(numbers);
        else if (choice == 'S')
            print_smallest(numbers);
        else if (choice == 'L')
            print_largest(numbers);
        else if (choice == 'F')
            print_find(numbers);
        else {
            cout << "Quitting program." << endl;
            quit = true;
        }
    } while (!quit);                  
    return 0;   
}

void print_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find number" << endl;
    cout << "Q - Quit" << endl;
    
}

char read_input() {
    cout << "\nEnter your choice: ";
    char input {};
    cin >> input;
    input = toupper(input);
    if (input == 'P' || input == 'A' || input == 'M' || input == 'S' || input == 'L' || input == 'Q' || input == 'F')
        return input;
    else {
        cout << "Invalid argument, please try again: ";
        return read_input();
    }
}

void print_vector(const vector<int> &list) {
    if (list.size() == 0)
        cout << "No integers in the vector." << endl << endl;
    else {
        cout << "Integers in the vector: [ ";
        for (int number: list)
            cout << number << " ";
        cout << "]";
        cout << endl << endl;
    }
}

void add_number(vector<int> &list) {
    int a {};
    cout << "Enter integer to be added to the vector: ";
    cin >> a;
    list.push_back(a);
    cout << "Added integer: " << a << endl << endl;
}

void print_mean(const vector<int> &list) {
    if (list.size() == 0)
        cout << "No integers in the vector." << endl << endl;
    else {
        double result {};
        for (int number: list)
            result += number;
        result = result/list.size();
        cout << "Mean of the integers inside the vector is: " << result << endl << endl;
    }
}

void print_smallest(const vector<int> &list) {
    if (list.size() == 0)
        cout << "No integers in the vector." << endl << endl;
    else {
        int result {list.at(0)};
        for (size_t i{}; i+1 < list.size(); ++i){
            if (list.at(i) < result)
                result = list.at(i);
        }
        cout << "The smallest number in the vector is: " << result << endl << endl;
    }
}

void print_largest(const vector<int> &list) {
    if (list.size() == 0)
        cout << "No integers in the vector." << endl << endl;
    else {
        int result {list.at(0)};
        for (size_t i{}; i+1 < list.size(); ++i){
            if (list.at(i) > result)
                result = list.at(i);
        }
        cout << "The alrgest number in the vector is: " << result << endl << endl;
    }
}

void print_find(const vector<int> &list) {
    if (list.size() == 0)
        cout << "No integers in the vector." << endl << endl;
    else {
        int number {};
        bool found {false};
        cout << "Input integer to find: ";
        cin >> number;
        for (auto find: list) {
            if (find == number)
                found = true;
        }
        if (found == true)
            cout << number << " was found." << endl << endl;
        else
            cout << number << " was not found." << endl << endl;                
    }
}
