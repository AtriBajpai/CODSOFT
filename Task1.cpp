#include <iostream>   
#include <cstdlib>    
#include <ctime>     

using namespace std;

int main() {
  srand(time(0));

   int secretNumber = rand() % 100 + 1;
    int guess;

    cout << "------------------------------------------" << endl;
    cout << "      Welcome to the Number Guessing Game" << endl;
    cout << "------------------------------------------" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low! Try a higher number.";
        } else if (guess > secretNumber) {
            cout << "Too high! Try a lower number.";
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
            break; 
        }
    }

    return 0;
}

