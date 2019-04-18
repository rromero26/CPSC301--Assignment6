// Name
// Section
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class digit
{
    public:
    int data;
    digit *next = nullptr;
};

// Suggested functions
digit * loadNumber(ifstream & file);
int digcmp(digit * left, digit *right);
char getOperator(ifstream & file);
void writeNumber(digit * num, ofstream & file);
void deleteNumber(digit * num);
digit * addNumbers(digit * left, digit * right);
digit * subNumbers(digit * left, digit * right);
void writeRecursive(digit * num, ofstream & file);
void setNeg(digit * num);
void printNumber(digit * num);
void printRecursive(digit * num);
void subCarry(digit * head, digit * prev);
digit * clearLeadingZeros(digit * num);

int main() {
    digit * left, * right, * result;
    ofstream outFile ("output.txt");
    ifstream inFile ("largeNumbers.txt");

    while (!inFile.eof()){
        // implement program logic here
    }

    outFile.close();
    inFile.close();
    return 0;
}

/* returns a number <0 || 0 || >0
*  <0 right number is larger
*   0  the numbers are equal
*  >0 left number is larger
*  only works if the number is stored lowest significant to greatest significant.
*/
int digcmp(digit * left, digit * right) {
    int result = 0;
    do {
        if (left->data - right->data == 0) {
        } // take no action
        else {
            result = left->data - right->data;
        }
        left = left->next;
        right = right->next;

    } while (left != nullptr && right != nullptr);

    if (left == nullptr && right != nullptr) {
        // right number is larger
        result = -1;
    }

    if (left != nullptr && right == nullptr) {
        // left number is larger
        result = 1;
    }
    return result;
}

digit * loadNumber(ifstream & file) {
    return nullptr;
}

char getOperator(ifstream & file) {
    // hint: use get() and look at ASCII table
    return '0';
}

void printRecursive(digit * num) {

}

void printNumber(digit * num) {

}

void writeRecursive(digit * num, ofstream & file) {

}

void writeNumber(digit * num, ofstream & file) {

}

void deleteNumber(digit * num) {

}

digit * addNumbers(digit * left, digit * right) {
    return nullptr;
}

void subCarry(digit * head, digit * prev) {

}

digit * subNumbers(digit * left, digit * right) {
    return nullptr;
}

digit * clearLeadingZeros(digit * num) {
    return nullptr;
}

void setNeg(digit * num) {

}
