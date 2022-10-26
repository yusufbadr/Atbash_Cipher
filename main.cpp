
/* Program Name : Atbash Cipher
 * Program Description: Takes a string and encrypts/decrypts such that A becomes Z, B becomes Y and vice versa.
 * Last Modification Date: 25/03/2022
 * Author: Yusuf Badr | Student at Faculty of Computers and Artificial Intelligence, Cairo University
 * Email: yusufbadr@yahoo.com
 * LinkedIn: linkedin.com/in/yusufbadr/
 */


#include <iostream>
#include <string>
#include <cctype>
# include <regex>

using namespace std;

string encrypt(string plainText);
string decrypt(string cipherText);
void displayWelcomeMessage();
void displayMenu();
int getValidatedMenuOption(); // returns a validated user input of the menu option as an integer

int main() {
    displayWelcomeMessage();
    int menuOption = getValidatedMenuOption();
    while (menuOption != 3){
        if (menuOption == 1){ // plain -> cipher
            string userInput;
            cout << "Enter plain text:\n";
            getline(cin, userInput) ;//
            cout << "Your ciphertext is:\n" << encrypt(userInput) << "\n\n";

        } else if (menuOption == 2) {
            string userInput;
            cout << "Enter ciphertext:\n";
            getline(cin, userInput);
            cout << "Original plain text:\n" << decrypt(userInput) << "\n\n";

        }
        menuOption = getValidatedMenuOption();
    }

    return 0;
}


string encrypt(string plainText) {
    string cipherText;
    char cipherLetter;
    for (auto i: plainText){
        if (isupper(i)){
            cipherLetter = i + 25 - 2 * (i - 'A'); // equation to get new cipher letter
        } else if (islower(i)) {
            cipherLetter = i + 25 - 2 * (i - 'a');
        } else {
            cipherLetter = i;
        }
        cipherText += cipherLetter;
    }
    return cipherText;
}
string decrypt(string cipherText) {
    string plainText;
    char plainLetter;
    for (auto i: cipherText){
        if (isupper(i)){
            plainLetter = i - 25 + 2 * ('Z' - i); // equation to get new plain letter
        } else if (islower(i)) {
            plainLetter = i - 25 + 2 * ('z' - i);
        } else {
            plainLetter = i;
        }
        plainText += plainLetter;
    }
    return plainText;

}

void displayWelcomeMessage(){
    cout << "!Welcome to the Atbash Cipher!\n";
}


void displayMenu(){
    cout << "Please choose one of the following numbers\n"
            "1. Encrypt your message (plain text -> ciphertext)\n"
            "2. Decrypt your message (ciphertext -> plain text)\n"
            "3. Exit\n"
            "Number:\n";
}

int getValidatedMenuOption(){ // returns a validated user input of the menu option as an integer
    displayMenu();
    string inNumberString;
    getline(cin, inNumberString);
    regex validInt("[1-3]{1}");
    while (!regex_match(inNumberString, validInt)) {
        cout << "Enter 1, 2 or 3:\n";
        getline(cin, inNumberString);
        regex_match(inNumberString, validInt);
    }
    return stoi(inNumberString);
}
