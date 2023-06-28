#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

/*
     * Assuming your member variable is a pointer.
     * 1. You need a No-args constructor
     * 2. You need an Overloaded constructor (initializer) which is a pointer to a constant member variable.
     * 3. You need a Copy constructor which is a constant reference to a class object.
     * 4. You need a Move Constructor which is a double reference of a class object.
     * 5. You need a Deconstructor
     * 6. You need a Copy assignment operator which is a reference to a class object operator equals which requires a constant reference of a right hand side class object.
     * 7. You need a Move assignment operator which is a reference to a class object operator equals which requires a double reference (reference to a r-value) to a Mystring right hand side object.
     * 8. You can add display method which doesn't return anything and doesn't change values of the member variables.
     * 9. You can add get_length method which doesn't require any input and returns and integer and doesn't change values of the member variables.
     * 10. You can add get_str method which doesn't require any input and returns a constant pointer to a member variable and doesn't change values of the member variables.
     * 
     * 11. Adding friend functions:
     * - Insertion operator function returns a reference to a std::ostream object, the function name is operator<< which requires a reference to a ostream object and a 
     * reference to a constant class object of the right hand side. 
     * - Extraction operator function returns a reference to a std::istream object, the function name is operator>> which requires a reference to a istream object and a
     * reference to a class object of the right hand side.clTabCtrl
     */

class Mystring
{
    // Overloaded insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    // Overloaded extraction operator
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);
private:
    char* str;
public:
    // No-args constructor
    Mystring();
    // Overloaded constructor
    Mystring(const char *source_string);
    // Copy constructor
    Mystring(const Mystring &source);
    // Move constructor
    Mystring(Mystring &&source);
    // Deconstructor
    ~Mystring();
    // Copy assignment operator
    Mystring &operator=(const Mystring &rhs);
    // Move assignment operator
    Mystring &operator=(Mystring &&rhs);
    // Display method
    void display() const;
    // Getters
    int get_length() const;
    const char *get_str() const;
    // Overloaded insertion operator
    std::ostream &operator<<(std::ostream &os) const;
    // Overloaded extraction operator
    std::istream &operator>>(std::istream &is);
    // Overloaded unary minus operator - make lower case BUT DONT CHANGE the object itself. RETURN LOWER CASE
    Mystring operator-();
    // Overloaded equality operator - checks if the strings are the same
    bool operator==(const Mystring &rhs); 
    // Overloaded not quality operator - checks if the strings are NOT the same
    bool operator!=(const Mystring &rhs);
    // Overloaded less then operator returns true if lhs is lexically less then rhs
    bool operator<(const Mystring &rhs);
    // Overloaded more then operator returns true if lhs is lexically more then rhs
    bool operator>(const Mystring &rhs);
    // Concatentation
    Mystring operator+(const Mystring &rhs) const;
    // Concatenate and store the result in the lhs object
    Mystring &operator+=(const Mystring &rhs);
    // Multiplying the string x times
    Mystring operator*(int number);
    // Multiplying the string x times and storing the result in the left hand side object.
    Mystring &operator*=(int number);
    // Pre-increment ++ overloaded operator - makes all letter uppercase
    Mystring &operator++();
    // Post-increment ++ overloaded operator - makes all letter uppercase
    Mystring operator++(int);
    // Pre-increment -- overloaded operator - rewrites the string backwars
    Mystring &operator--();
    // Post-increment -- overloaded operator - rewrites the string backwars
    Mystring operator--(int);
};

#endif // MYSTRING_H
