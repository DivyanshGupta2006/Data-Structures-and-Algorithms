#include <iostream>
#include "Stack_LinkedList.h"
#include "Stack_Array.h"

using namespace std;

bool isPalindrome(const std::string &str) {
    Stack_LinkedList<char> charStack;

    for (char c: str) {
        charStack.push(c);
    }

    for (char c: str) {
        if (charStack.isEmpty() || charStack.pop() != c) {
            return false;
        }
    }

    return charStack.isEmpty();
}

int main() {
    int size = 10;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    cout << "Array before reversing is :" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;

    Stack_Array<int> tempStack;

    for (int i = 0; i < size; ++i) {
        tempStack.push(arr[i]);
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = tempStack.pop();
    }

    cout << "Array after reversing is :" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;

    string str1 = "Hello World!";
    string str2 = "radar";

    cout << str1 << " is Palindrome: " << (isPalindrome(str1) ? "Yes" : "No") << endl;
    cout << str2 << " is Palindrome: " << (isPalindrome(str2) ? "Yes" : "No") << endl;

    return 0;
}
