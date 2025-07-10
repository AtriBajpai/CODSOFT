#include <iostream>
using namespace std;

int main() {
    double num1, num2; 
    char op;         
    char again;        

    cout << "=== Basic Calculator ===" << endl;

    do {
      
        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        if (op == '+') {
            cout << "Result: " << num1 + num2 << endl;
        } else if (op == '-') {
            cout << "Result: " << num1 - num2 << endl;
        } else if (op == '*') {
            cout << "Result: " << num1 * num2 << endl;
        } else if (op == '/') {
            if (num2 == 0) {
                cout << "Error! Division by zero not allowed." << endl;
            } else {
                cout << "Result: " << num1 / num2 << endl;
            }
        } else {
            cout << "Invalid operator!" << endl;
        }

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for using the calculator!" << endl;

    return 0;
}
