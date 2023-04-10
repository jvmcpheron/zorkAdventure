#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function prototypes
void printIntro();
void playGame();
void handleInput(const string& input);
void printEnding(bool isVictorious);
vector<string> splitString(const string& input, char delimiter);

int main() {
    printIntro();
    playGame();
    return 0;
}

void printIntro() {
    cout << "Welcome to the Zork-like game!" << endl;
    cout << "You find yourself in a mysterious cave..." << endl;
    cout << "Your goal is to find the treasure and escape." << endl;
    cout << "Good luck!" << endl;
}

void playGame() {
    bool isVictorious = false;
    string input;
    
    while (!isVictorious) {
        cout << "Enter your action: ";
        getline(cin, input);
        handleInput(input);
    }
    
    printEnding(isVictorious);
}

void handleInput(const string& input) {
    // Split input into words
    vector<string> words = splitString(input, ' ');
    
    if (words.empty()) {
        cout << "Invalid input. Try again." << endl;
        return;
    }
    
    string action = words[0];
    
    if (action == "look") {
        cout << "You see a dimly lit room with three doors: red, blue, and green." << endl;
    } else if (action == "go") {
        if (words.size() < 2) {
            cout << "Invalid input. Try again." << endl;
            return;
        }
        
        string direction = words[1];
        
        if (direction == "red") {
            cout << "You enter the red door and are eaten by a dragon. Game over." << endl;
            exit(0);
        } else if (direction == "blue") {
            cout << "You enter the blue door and fall into a pit. Game over." << endl;
            exit(0);
        } else if (direction == "green") {
            cout << "You enter the green door and find a treasure chest! You win!" << endl;
            exit(0);
        } else {
            cout << "Invalid direction. Try again." << endl;
            return;
        }
    } else if (action == "take") {
        cout << "There is nothing to take here." << endl;
    } else if (action == "quit") {
        cout << "You quit the game. Better luck next time!" << endl;
        exit(0);
    } else {
        cout << "Invalid action. Try again." << endl;
    }
}

void printEnding(bool isVictorious) {
    if (isVictorious) {
        cout << "Congratulations! You have won the game!" << endl;
    } else {
        cout << "Sorry, you have lost the game." << endl;
    }
}

vector<string> splitString(const string& input, char delimiter) {
    vector<string> words;
    stringstream ss(input);
    string word;
    
    while (getline(ss, word, delimiter)) {
        words.push_back(word);
    }
    
    return words;
}
