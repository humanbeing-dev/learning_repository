#include "Mystring.h"
#include <iostream>
#include <cstring>

/* No-args constructor
 * 1. Null out a pointer.
 * 2. Allocate a space for a pointer on heap.
 * 3. Because there was no arguments, the pointer when dereferenced will lead to a null character (finishing the string)
 */
Mystring::Mystring()
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
}
    
/* Overloaded constructor
 * 1. Null out a pointer.
 * 2. Handle a scenario when somebody initiaties with an empty string, by doing the same code as a no args constructor.
 * 3. If the input is not a null pointer then allocate space for the length of the given string + 1 for the null character.
 * 4. then copy the string over from the input to the member variable.
 */
Mystring::Mystring(const char *source_string)
    : str{nullptr} {
        if (source_string==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(source_string) + 1];
            std::strcpy(str, source_string);
        }
}

/* Copy constructor
 * 1. Null out a pointer.
 * 2. Allocate space on heap for the length of the input member variable + 1 for the null character.
 * 3. Copy from the input member variable to 'this' member variable.
 */
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) +1];
        std::strcpy(str, source.str);
}

/* Move constructor
 * 1. Steal source pointer to this pointer.
 * 2. Null out the source pointer.
 */
Mystring::Mystring(Mystring &&source)
    : str{source.str} {
        source.str = nullptr;
    }
    
/* Destructor
 * 1. Delete the whole string of a class object member variable.
 */
Mystring::~Mystring() {
    delete [] str;
}

/* Copy assignment
 * 1. Handle if right hand side refrence is the same as 'this' by returning dereferenced this.
 * 2. Delete whole 'this'.
 * 3. Allocate space on heap for the whole length of the right hand side member variable + 1 for the null character.
 * 4. Copy right hand side member variable to the 'this' member variable.
 * 5. Return dereferenced 'this'.
 */
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this ==&rhs) 
        return *this;
    else {
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
    }
}

/* Move assignment
 * 1. Handle if right hand side refrence is the same as 'this' by returning dereferenced this.
 * 2. Delete whole 'this'.
 * 3. Steal the pointer of the right hand side member variable and assign it to current member variable.
 * 4. Null out the pointer of the right hand side member variable
 * 5. Return dereferenced 'this'.
 */
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    else {
        str = rhs.str;
        rhs.str = nullptr;
    return *this;
    }
}

/* Display method
 * 1. Display the pointer (if it's a pointer to the 'char' member variable it will display the whole string by default - its std::cout object function)
 * 2. Display length of the string.
 */
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

/* getters
 * 1. Return 'strlen' of the string.
 */
int Mystring::get_length() const {
    return std::strlen(str);
}

/* 1. Return the string.
 */
const char *Mystring::get_str() const {
    return str;
}
/* Overloaded insertion operator
 * 1. Take the output stream object and output the string of the right hand side object.
 * 2. Return output stream object so you can chain multiple output statements (the result of the output stream is output stream (becomes left hand side of another <<)).
 */
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

/* Overloaded extraction operator
 * 1. Create a character buffer for the input on _heap_.
 * 2. Insert the characters into the buffer.
 * 3. Assing object initiated with the buffer to the right hand side object.
 * 4. Delete the whole buffer.
 * 5. Return the insertion object so you can chain multiple insertions.
 */
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

/* Overloaded unary operator which creates a temporary object of lower case string.
 * 1. Crate a temporary buffer for the string length on the heap.
 * 2. Copy the right hand side string to the buffer.
 * 3. Loop through each of the characters of the buffer up to the length of the buffer and use std::tolower function to make all letter lowercase
 * 4. Initialize a new temporary object with the created string on the buffer (heap)
 * 5. Delete the buffer (no longer need. The object has 'taken' the string)
 * 6. Return the temporary object. 
 */
Mystring operator-(const Mystring &rhs){
    char *buff = new char [std::strlen(rhs.str)+1];
    std::strcpy(buff, rhs.str);
    for (size_t i=0; i <std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}
/* Overloaded equality operator which compares two strings.
 * 1. return the comparison to 0 of the comparison of left hand side reference to an object and right hand side reference to an object which are both constant (as we dont want to change either)
 * Compare the strings by using std::strcmp function.
 */
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

/* Overloaded NOT equality operator which compares two strings.
 * 1. return the comparison to 0 of the comparison of left hand side reference to an object and right hand side reference to an object which are both constant (as we dont want to change either)
 * Compare the strings by using std::strcmp function.
 */
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) != 0);
}
/* Overloaded less then operator returns true if lhs is lexically less then rhs
 * return the comparison of both strings when string1 is less then string2 and compared to truth (1);
 */
bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return ((lhs.str < rhs.str) == 1);
}

/* Overloaded more then operator returns true if lhs is lexically less then rhs
 * return the comparison of both strings when string1 is more then string 2 and compared to truth (1);
 */
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return ((lhs.str > rhs.str) == 1);
}

/* Concatentation
 * 1. Allocate a character buffer on heap for the length of the both strings.
 * 2. Copy left hand side string in to the character buffer by using std::strcpy.
 * 3. Concatentate right hand side string to the buffer by using std::strcat.
 * 4. Create a temporary object intialized with the buffer.
 * 5. Delete the whole buffer.
 * 6. Return the temporary object.
 */
Mystring operator+(const Mystring &rhs, const Mystring &lhs) {
    char *buff = new char[std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

/* Concatenate and store the result in the lhs object
 * 1. Allocate a character buffer on heap for the length of the both strings.
 * 2. Copy left hand side string in to the character buffer by using std::strcpy.
 * 3. Concatentate right hand side string to the buffer by using std::strcat.
 * 4. Create a temporary object intialized with the buffer.
 * 5. Assing this temporary object to the left hand side object.
 * 6. Delete the whole buffer.
 * 7. Return the left hand side object.
 */
Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = rhs + lhs;
    return lhs;
}

/* Multiplying the string x times.
 * 1. Create a buffer for x number of times of the strlen of the string + 1 for the null character.
 * 2. strcat left hand side string to the buffer exactly x time with a for loop.
 * 3. Initialize the temporary object with the buffer.
 * 4. Delete the whole buffer.
 * 5. Return the temporary object.
 */
Mystring operator*(Mystring &lhs, int number) {
    char *buff = new char[(std::strlen(lhs.str)*number) + 1];
    std::strcpy(buff, lhs.str);
    for (int i = 1; i < number; i++)
        std::strcat(buff, lhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

/* Multiplying the string x times and storing the result in the left hand side object.
 * 1. Create a buffer for x number of times of the strlen of the string + 1 for the null character.
 * 2. strcat left hand side string to the buffer exactly x time with a for loop.
 * 3. Initialize the temporary object with the buffer.
 * 5. Assign the temporary object to the left hand side object.
 * 4. Delete the whole buffer.
 * 5. Return the temporary object.
 */
Mystring &operator*=(Mystring &lhs, int number) {
    lhs = lhs * number;
    return lhs;
}

/* Pre-increment ++ overloaded operator - makes all letter uppercase
 * 1. Iterate through the length of the sources string and make each letter uppercase by using the std::toupper.
 * 2. Return the source.
 */
Mystring &operator++(Mystring &source) {
    for (size_t i=0; i < std::strlen(source.str); i++)
        source.str[i] = std::toupper(source.str[i]);
    return source;
}

/* Post-increment ++ overloaded operator - makes all letter uppercase
 * 1. Iterate through the length of the sources string and make each letter uppercase by using the std::toupper.
 * 2. Return the source.
 */
Mystring operator++(Mystring &source, int) {
    Mystring temp{source};
    operator++(source);
    return temp;
}

/* Pre-increment -- overloaded operator - rewrites the string backwars
 * 1. Cratea a buffer for a string of the source's string length on heap.
 * 2. iterate through the buffer coming from the beginning to the end of the string and iterate simultanously through the sources string from the end to beginning
 * and while doing so assign the values to the positions in the string.
 * 3. Add null terminated character at the end of the buffer's string
 * 4. Assign the buffer string to the source object.
 * 5. Delete the whole buffer.
 * 6. Return the source object.
 */
Mystring &operator--(Mystring &source) {
    char *buff = new char[std::strlen(source.str)+1];
    for (size_t i=0, y=strlen(source.str)-1; i < std::strlen(source.str); i++, y--)
        buff[i] = source.str[y];
    buff[std::strlen(source.str)] = '\0';
    source = buff;
    delete [] buff;
    return source;
}

/* Post-increment -- overloaded operator - rewrites the string backwars
 * 1. Create a temporary object initiated with source.
 * 2. Call pre incremented -- operator
 * 3. Return the temporary object (with old values before the increment)
 */
Mystring operator--(Mystring &source, int) {
    Mystring temp{source};
    operator--(source);
    return temp;
}
