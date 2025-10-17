#include <iostream>
#include <cstdlib>  
#include <ctime>   
using namespace std;
int main() {
    srand(time(0)); 
    int randomNumber = rand() % 50 + 1; 
    int guess;
    int attempts = 0; 
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 50." << endl;
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess < 1 || guess > 50) {
            cout << "? Please enter a number between 1 and 50 only." << endl;
            continue;
        }
        attempts++; 
        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "?? Congratulations! You guessed the correct number: " 
                 << randomNumber << endl;
            cout << "It took you " << attempts << " attempts!" << endl;
        }

    } while (guess != randomNumber);

    return 0;
}
