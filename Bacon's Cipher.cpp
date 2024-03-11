#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

// Define a map to store the mapping between characters and their Bacon Cipher sequences
map<char, string> encrypt = {
        {'A', "aaaaa"}, {'B', "aaaab"}, {'C', "aaaba"}, {'D', "aaabb"}, {'E', "aabaa"},
        {'F', "aabab"}, {'G', "aabba"}, {'H', "aabbb"}, {'I', "abaaa"}, {'J', "abaab"},
        {'K', "ababa"}, {'L', "ababb"}, {'M', "abbba"}, {'N', "abbab"}, {'O', "abbba"},
        {'P', "abbbb"}, {'Q', "baaaa"}, {'R', "baaab"}, {'S', "baaba"}, {'T', "baabb"},
        {'U', "babaa"}, {'V', "babab"}, {'W', "babba"}, {'X', "babbb"}, {'Y', "bbaaa"},
        {'Z', "bbaab"}
};

// Function to encode plaintext to Bacon Cipher
string encodeBaconCipher(const string& plaintext) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char upperC = toupper(c);
            ciphertext += encrypt[upperC] + ' ';
        } else if (isdigit(c)) {
            ciphertext += c; // Keep numbers unchanged
        } else {
            ciphertext += c; // Keep non-alphabetic characters unchanged
        }
    }
    return ciphertext;
}

// Function to decode Bacon Cipher to plaintext
string decodeBaconCipher(const string& ciphertext) {
    string plaintext = "";
    string binary = "";
    for (char c : ciphertext) {
        if (c == 'a' || c == 'b') {
            binary += c;
            if (binary.size() == 5) {
                char decodedChar = ' ';
                for (auto& entry : encrypt) {
                    if (entry.second == binary) {
                        decodedChar = entry.first;
                        break;
                    }
                }
                plaintext += decodedChar;
                binary = "";
            }
        } else {
            plaintext += c; // Keep non-binary characters unchanged
        }
    }
    return plaintext;
}

int main() {
    int choice;
    string inputText, outputText;

    while (true) {
        cout << "Bacon's Cipher Menu:" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the plaintext: ";
                cin.ignore(); // Clear input buffer
                getline(cin, inputText);
                outputText = encodeBaconCipher(inputText);
                cout << "Encrypted text: " << outputText << endl;
                break;
            case 2:
                cout << "Enter the ciphertext: ";
                cin.ignore(); // Clear input buffer
                getline(cin, inputText);
                outputText = decodeBaconCipher(inputText);
                cout << "Decrypted text: " << outputText << endl;
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    }

    return 0;
}
