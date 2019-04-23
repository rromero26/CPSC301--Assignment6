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

digit * writeNum(ifstream & file);
int digcmp(digit * left, digit *right);
char getOperator(ifstream & file);
void writeNum(digit * num, ofstream & file);
void deleteNum(digit * num);
digit * addNumbers(digit * left, digit * right);
digit * subNumbers(digit * left, digit * right);
void writeRecursive(digit * num, ofstream & file);
void setNeg(digit * num);
void printNum(digit * num);
void printRecursive(digit * num);
void subtractCarry(digit * head, digit * prev);
digit * clearLeadingZeros(digit * num);

//-----------------PROVIDED BY INSTRUCTOR-----------------
int main() {
    digit * left, * right, * result;
    int test;
    char op;
    ofstream outFile ("output.txt");
    ifstream inFile ("largeNumbers.txt");

    while (!inFile.eof()){
        left  = writeNum(inFile);
        right = writeNum(inFile);
        if (left == nullptr || right == nullptr) {
            // check after two reads if we didn't get numbers
            // in case of one extra newline at end of file
            break;
        }
        op = getOperator(inFile);

        if (op == '+'){
            result = addNumbers(left, right);
        } else {
            test = digcmp(left, right);
            if (test > 0) {
                result = subNumbers(left, right); // result will be positive
                result = clearLeadingZeros(result);
            } else if (test < 0) {
                result = subNumbers(right, left); // result will be negative
                result = clearLeadingZeros(result);
                setNeg(result);
            } else {
                result = new digit; // result of subtraction was zero
            }
        }
        writeNum(result, outFile);
        deleteNum(left);
        deleteNum(right);
        deleteNum(result);
        left = nullptr;
        right = nullptr;
        result = nullptr;
    }

    outFile.close();
    inFile.close();
    return 0;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
/* returns a number <0 || 0 || >0
*  <0 right number is larger
*   0  the numbers are equal
*  >0 left number is larger
*  only works if the number is stored with lowest significant at front of the list
*/
int digcmp(digit * left, digit * right){
    int result= 0;
    do // the assignment guarantees there will not be zero length numbers
    {
        if (left->data - right->data == 0){
        } // take no action
        else {
            result= left->data - right->data;
        }
        left = left->next;
        right = right->next;
    } while (left != nullptr && right != nullptr);
    if (left == nullptr && right != nullptr) {
        // right number is longer and therefore larger
        result= -1;
    }
    if (left != nullptr && right == nullptr) {
        // left number is longer and therefore larger
        result= 1;
    }
    return result;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
digit * writeNum(ifstream & file){
    if (file.eof())
    return nullptr;
    digit * head = new digit;
    digit * dig = head;

    char aChar;
    int num;

    file.get(aChar);
    while (aChar != '\n' && !file.eof()){
        num = int(aChar - '0');
        head->data = num;
        file.get(aChar);
        if (aChar != '\n'){
            dig = head;
            head = new digit;
            head->next = dig;
        }
    }
    return head;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
char getOperator(ifstream & file){
    char aChar;
    string toss;

    file.get(aChar);
    getline(file, toss);

    return aChar;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
void printRecursive(digit * num){
    if (num == nullptr)
    return;
    printRecursive(num->next);
    cout << num->data;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
void printNum(digit * num){
    printRecursive(num);
    cout << endl;

}

//-----------------PROVIDED BY INSTRUCTOR-----------------
void writeRecursive(digit * num, ofstream & file) {
    if (num == nullptr)
    return;
    file << num->data;
    writeRecursive(num->next, file);
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
void writeNum(digit * num, ofstream & file){
    writeRecursive(num, file);
    file << endl;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
void deleteNum(digit * num){
    digit * n;
    while (num != nullptr)
    {
        n = num->next;
        delete num;
        num = n;
    }
}


digit * addNumbers(digit * left, digit * right){
    //  Left and Right point to entire lists.
    //  They're in reverse order (ie: 123 = 3->2->1-> null)

    digit *myNum = new digit;     // create new linklist
    digit *head = myNum;          // create ptr to linklist

    int temp = 0;                 //tempary int holder
    int carry = 0;                //holds 1 if carry is needed for next node

    //----counts left and right linklist--------------------------------------//
                                                                              //
    digit *tempLeft = left;       //create tempPtr to count digits on Left    //
    digit *tempRight = right;     //create tempPtr to count digits in Right   //
    int leftCounter = 0;                                                      //
    int rightCounter = 0;                                                     //
                                                                              //
    while (tempLeft != NULL){       //counter: how long Left linklist is      //
      leftCounter++;                                                          //
      tempLeft = tempLeft->next;                                              //
    }                                                                         //
                                                                              //
    while (tempRight != NULL){      //counter: how long right linklist is     //
      rightCounter++;                                                         //
      tempRight = tempRight->next;                                            //
    }                                                                         //
    //------------------------------------------------------------------------//

    // ERROR: FROM HERE CORE DUMP COMES UP

    if (leftCounter == rightCounter){                 //If Left and RIght are the same, do this
        while ( (left != NULL) && (right != NULL) ){
            temp = left->data + right->data + carry;
            if (temp >= 10){
              carry = 1;
              temp = temp - 10;
              myNum->data = temp;
            }
            else {
              carry = 0;
              myNum->data = temp;
            }
              left = left->next;
              right = right->next;
              myNum = myNum->next;
          }
        return head;
      }
    //-------------------------------------------------------------------------------------------------//
    if (rightCounter > leftCounter){    //switches Left and Right; makes Left have the larger number   //
      digit *tempPtr = left;            // and contiue as to last part of function where Left > Right  //
      left = right;                                                                                    //
      right = tempPtr;                                                                                 //
    }                                                                                                  //
    //-------------------------------------------------------------------------------------------------//
    //string test;
    cout <<"All works from here?";
    cin >> test;

    //--- From here on, left will always contain longer linklist ---

    while (right != NULL){
        temp = left->data + right->data + carry;
        if (temp >= 10){
          carry = 1;
          temp = temp - 10;
          myNum->data = temp;
        }
        else{
          carry = 0;
          myNum->data = temp;
        }
          left = left->next;
          right = right->next;
          myNum = myNum->next;
    }
    while (left != NULL){
        temp = left->data + carry;
        carry = 0;
        myNum->data = temp;

        left = left->next;
    }

    return head;
  }

//-----------------PROVIDED BY INSTRUCTOR-----------------
void subtractCarry(digit * head, digit * prev){
    if (head == nullptr){
        return;
        } // safety check only, this should never happen!
    if (head->data == 0){
        head->data = 9;
        subtractCarry(head->next, head);
    } else {
        head->data -= 1;
    }
}

// TODO: Implement function to subtract 2 numbers stored in 2 linked lists. Use provided helper functions
digit * subNumbers(digit * left, digit * right){
    return nullptr;
}

//-----------------PROVIDED BY INSTRUCTOR-----------------
digit * clearLeadingZeros(digit * num){
    digit * next;
    while (num->data == 0) {
        next = num->next;
        delete num;
        num = next;
        }
        return num;
    }
void setNeg(digit * num){
    num->data = -num->data;
}
