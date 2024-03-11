#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <cctype>

using namespace std;

//to convert the keyword and the message letters to uppercase
string upper(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = char(str[i] - 32);//Difference between ASCII of small char and its Capital is 32
        }
    }
    return str;
}

//to check if the key has only alphabetic characters or no || if the keyword exceeds 8 chars
bool is_valid_key(string keyword) {
    int length = 0;
    for (int i = 0; i < keyword.size(); i++) {
        if (!((keyword[i] >= 97 && keyword[i] <= 122) || (keyword[i] >= 65 && keyword[i] <=
                                                                              90))) {//if character is not between [97,122] and [65,90] then it is not alpha
            return false;
        }
    }
    if (keyword.size() <= 8) { //length of keyword exceeds 8 chars
        return true;
    }
    return false;
}

//to encryptMorse or decryptMorse the message using Vignere Cipher
void vignere_cipher(int n) {
    string encrypted, decrypted;
    string msg, keyword;
    cin.ignore();//ignore the last cin to not conflict with the next cin call
    while (true) {
        cout << "Enter your message:";
        getline(cin, msg);//get the whole line with spaces as input
        cout << "Enter your keyword:";
        getline(cin, keyword);//get the whole line with spaces as input

        //checking the constraints
        if (!is_valid_key(keyword)) {
            cout << "please enter only 8 alphabetic letters for the keyword" << endl;
            continue;
        }
        if (msg.size() > 80) {
            cout << "message size shouldn't be greater than 80 characters, please try again!!" << endl;
            continue;
        }
        break;
    }
    msg = upper(msg);
    keyword = upper(keyword);
    //loop through each letter in the message
    for (int i = 0, j = 0; i < msg.size(); i++, j++) {
        if (msg[i] < 65 || msg[i] > 90) {
            if (n == 1)
                encrypted += char(msg[i]);//if the character is not alphabetic add it to the encrypted message as it is
            else
                decrypted += char(msg[i]);//if the character is not alphabetic add it to the encrypted message as it is
            continue;
        }
        if (n == 1)
            encrypted += char(((msg[i] + keyword[j]) % 26) +
                              65);//Vignere Cipher add the ASCII of msg[i] to corresponding keyword[i] get the modulo of that by 26 add it to 65 the ASCII of 'A'
        else
            decrypted += char(((msg[i] - keyword[j] + 26) % 26) +
                              65);//Vignere DeCipher subtract the ASCII of keyword[i] from msg[i], add 26, then get the modulo of that by 26 add it to 65 the ASCII of 'A'
        if (j == keyword.size() - 1)
            j = -1;//if we looped through all the letters of the keyword start over
    }
    if (n == 1)
        cout << encrypted << endl;
    else
        cout << decrypted << endl;
}

// ** For Bacon's Cipher **
// Define arrays for English uppercase letters and Bacon Cipher sequences
const string englishLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string baconCipher[26] = {
        "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb",
        "abaaa", "abaab", "ababa", "ababb", "abbba", "abbab", "abbba", "abbbb",
        "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb",
        "bbaaa", "bbaab"
};

//** For Morse Cipher **
// a map to store each letter corresponds to which morse combination
map<char, string> encryptMorse = {
        {'A',  ".-"},
        {'B',  "-..."},
        {'C',  "-.-."},
        {'D',  "-.."},
        {'E',  "."},
        {'F',  "..-."},
        {'G',  "--."},
        {'H',  "...."},
        {'I',  ".."},
        {'J',  ".---"},
        {'K',  "-.-"},
        {'L',  ".-.."},
        {'M',  "--"},
        {'N',  "-."},
        {'O',  "---"},
        {'P',  ".--."},
        {'Q',  "--.-"},
        {'R',  ".-."},
        {'S',  "..."},
        {'T',  "-"},
        {'U',  "..-"},
        {'V',  "...-"},
        {'W',  ".--"},
        {'X',  "-..-"},
        {'Y',  "-.--"},
        {'Z',  "--.."},
        {'1',  ".----"},
        {'2',  "..---"},
        {'3',  "...--"},
        {'4',  "....-"},
        {'5',  "....."},
        {'6',  "-...."},
        {'7',  "--..."},
        {'8',  "---.."},
        {'9',  "----."},
        {'0',  "-----"},
        {',',  "--..--"},
        {':',  "---..."},
        {';',  "-.-.-."},
        {'.',  ".-.-.-"},
        {'"',  ".-..-."},
        {'(',  "-----."},
        {')',  ".-----"},
        {'\'', "-.--.-"},
        {'&',  ".-..."},
        {'@',  ".--.-."},
        {'=',  "-...-"},
        {'!',  "-.-.--"},
        {'.',  ".-.-.-"},
        {'-',  "-....-"},
        {'+',  ".-.-."},
        {'\"', ".-..-."},
        {'?',  "..--.."},
        {'/',  "-..-."},

};

// a map to store each morse combination corresponds to which letter
map<string, char> decryptMorse;

// initializing decryptMorse map from encryptMorse map
void initialize_dectrptMorse_map() {
    for (auto &it: encryptMorse) {
        decryptMorse[it.second] = it.first;
    }
}

// Function to encode plaintext to Bacon Cipher
string encodeBaconCipher(const string &plaintext) {
    string ciphertext = "";
    for (char c: plaintext) {
        if (isalpha(c)) { // If the character is alphabetic
            int index = toupper(c) - 'A'; // Convert character to uppercase and get its index
            ciphertext += baconCipher[index] + ' '; // Append the corresponding Bacon Cipher sequence
        } else if (isdigit(c)) { // If the character is a digit
            ciphertext += c; // Keep numbers unchanged
        } else { // If the character is not alphabetic or numeric
            ciphertext += c; // Keep non-alphabetic characters unchanged
        }
    }
    return ciphertext;
}

// Function to decode Bacon Cipher to plaintext
string decodeBaconCipher(const string &ciphertext) {
    string plaintext = "";
    string binary = "";
    for (char c: ciphertext) {
        if (c == 'a' || c == 'b') { // If the character is 'a' or 'b' (part of Bacon Cipher)
            binary += c; // Append 'a' or 'b' to binary sequence
            if (binary.size() == 5) { // If binary sequence is complete
                int index = -1;
                // Search for the index of the binary sequence in the Bacon Cipher array
                for (int i = 0; i < 26; ++i) {
                    if (baconCipher[i] == binary) { // If found
                        index = i; // Store the index
                        break;
                    }
                }
                if (index != -1) // If valid index found
                    plaintext += englishLetters[index]; // Append the corresponding letter to plaintext
                binary = ""; // Reset binary sequence for next character
            }
        } else { // If the character is not 'a' or 'b' (part of Bacon Cipher)
            plaintext += c; // Keep non-binary characters unchanged
        }
    }
    return plaintext; // Return the decoded plaintext
}

// This function encrypts the message in Morse form
bool EncryptionMorse(string txt) {
    // store the new value
    string morse_text;

    int sz = txt.length();
    for (int i = 0; i < sz; ++i) {
        char ch = txt[i];

        // if it is lowercase, convert it to uppercase
        ch = toupper(ch);

        // if a space was found
        if (ch == ' ') {

            // if there is a space before it in the original text, i.e. two spaces between word, then add only two spaces
            // because there is a pace that is already conatined in the 'morse_text'
            if (i - 1 >= 0 && txt[i - 1] != ' ')
                morse_text += "  ";

                // if not add three spaces
            else
                morse_text += "   ";

            // if the character is not valid, return false and print the invalid character for the user
        } else if (encryptMorse.find(ch) == encryptMorse.end()) {
            cout << "Don't use \'" << ch << "\'\n";
            return false;

            // if the character is valid add its encryption
        } else
            morse_text += encryptMorse[ch] + ' ';
    }

    // remove the extra space at the end
    morse_text.pop_back();

    // print the Morse text
    cout << "Morse text is " << morse_text << '\n';
    return true;


}

// This function decrypts the message in Morse form
bool DecryptionMorse(string txt) {

    // store the temporary substring of the morse code to be replaced
    string tmp;

    // store the final original text
    string original_text;
    int sz = txt.length(), i = 0;
    while (i < sz) {

        // while no space found, add the character to 'tmp'
        while (i < sz && txt[i] != ' ')
            tmp += txt[i], ++i;

        // if we found no characters i.e. only spaces, then check for its validation
        if (tmp == "") {
            if (i + 1 >= sz)
                continue;

            // if it is one space, ignore it
            if (txt[i] == ' ' && txt[i + 1] != ' ')
                ++i;

                // if it is three spaces add only one space in the decryption process
            else if (txt[i] == ' ' && txt[i + 1] == ' ' && txt[i + 2] == ' ')
                original_text += ' ', i += 3;

                // if neither one nor three spaces then the sequence is invalid
            else
                return false;

            // if the sequence is not valid, return false
        } else if (decryptMorse.find(tmp) == decryptMorse.end())
            return false;

            // if the character is valid add its decryption
        else
            original_text += decryptMorse[tmp];

        // empty the value of 'tmp'
        tmp = "";
    }

    // print the original text
    cout << "The original text is \"" << original_text << "\"\n";
    return true;
}


//user menu
void Cipher_menu() {

    while (true) {
        int choice;
        cout << "=============================================================";
        cout << "\n1)Vignere Cipher\n2)Baconian Cipher\n3)Morse Code\n4)return\n";

        //if the input is not integer ask print error message
        if (!(cin >> choice)) {
            // If input failed, clear the fail state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        //user chose exit
        if (choice == 4) {
            break;
        } else if (choice == 1 || choice == 2 || choice == 3) {

            if (choice == 1) {//user chose Vignere Cipher
                vignere_cipher(1);
            } else if (choice == 2) {
                string text;
                cout << "Enter the message: ";
                cin.ignore();
                getline(cin, text);

                string encodedText = encodeBaconCipher(text);
                cout << "Encoded text: " << encodedText << endl;

            } else if (choice == 3) {
                string input;
                cout << "Enter your message: ";
                cin.ignore();

                // get the word to encryptMorse
                getline(cin, input);

                // The 'EncryptionMorse' function do the encryption process and return false if the input is invalid
                if (!EncryptionMorse(input))
                    cout << "You have entered an invalid text for encryption!\n\n";
            }
        } else {//unexpected value
            cout << "Please enter 1, 2, 3 or 4" << endl;
            continue;
        }
    }
}

void deCipher_menu() {
    while (true) {
        int choice;
        cout << "=============================================================";
        cout << "\n1)Vignere deCipher\n2)Baconian deCipher\n3)Morse deCode\n4)return\n";
        //if the input is not integer ask print error message
        if (!(cin >> choice)) {
            // If input failed, clear the fail state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        //user chose exit
        if (choice == 4) {
            break;
        } else if (choice == 1 || choice == 2 || choice == 3) {

            if (choice == 1) {//user chose Vignere deCipher
                vignere_cipher(2);
            } else if (choice == 2) {
                string text;
                cout << "Enter the message: ";
                cin.ignore();
                getline(cin, text);

                string decodedText = decodeBaconCipher(text);
                cout << "Decoded text: " << decodedText << endl;

            } else if (choice == 3) {
                decryptMorse.clear();

                // initialize the 'decryptMorse' map
                initialize_dectrptMorse_map();
                string input;
                cout << "Enter your message: ";
                cin.ignore();

                // get the word to decryptMorse
                getline(cin, input);

                // The 'DecryptionMorse' function do the decryption process and return false if the input is invalid
                if (!DecryptionMorse(input))
                    cout << "You have entered an invalid text for decryption\n\n";
            } else
                cout << "You have entered an invalid option, try again1!\n\n";
        } else {//unexpected value
            cout << "Please enter 1, 2, 3 or 4" << endl;
            continue;
        }
    }
}

int main() {
    cout << "Hello my dear user this is our cipher program, we have:\n";
    while (true) {
        int choice;
        cout << "=============================================================";
        cout << "\n1)Cipher\n2)Decipher\n3)exit\n";
        //if the input is not integer ask print error message
        if (!(cin >> choice)) {
            // If input failed, clear the fail state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (choice == 1)
            Cipher_menu();
        else if (choice == 2)
            deCipher_menu();
        else if (choice == 3)
            break;
        else {
            cout << "Please enter 1, 2 or 3" << endl;
            continue;
        }
    }
}