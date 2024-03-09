#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//to convert the keyword and the message letters to uppercase
string upper(string str){
    for (int i=0;i<str.size();i++){
        if(str[i]>=97 && str[i]<=122){
            str[i] = char(str[i]-32);//Difference between ASCII of small char and its Capital is 32
        }
    }
    return str;
}

//to check if the key has only alphabetic characters or no || if the keyword exceeds 8 chars
bool is_valid_key(string keyword){
    int length = 0;
    for (int i=0;i<keyword.size();i++){
        if(!((keyword[i]>=97 && keyword[i]<=122)||(keyword[i]>=65 && keyword[i]<=90))){//if character is not between [97,122] and [65,90] then it is not alpha
            return false;
        }
    }
    if (keyword.size()<=8){ //length of keyword exceeds 8 chars
        return true;
    }
    return false;
}

//to encrypt or decrypt the message using Vignere Cipher
void vignere_cipher(int n){
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
    for (int i=0,j=0;i<msg.size();i++,j++){
        if(msg[i]<65||msg[i]>90){
            if(n==1)
                encrypted += char(msg[i]);//if the character is not alphabetic add it to the encrypted message as it is
            else
                decrypted += char(msg[i]);//if the character is not alphabetic add it to the encrypted message as it is
            continue;
        }
        if(n==1)
            encrypted += char(((msg[i]+keyword[j])%26)+65);//Vignere Cipher add the ASCII of msg[i] to corresponding keyword[i] get the modulo of that by 26 add it to 65 the ASCII of 'A'
        else
            decrypted += char(((msg[i]-keyword[j]+26)%26)+65);//Vignere DeCipher subtract the ASCII of keyword[i] from msg[i], add 26, then get the modulo of that by 26 add it to 65 the ASCII of 'A'
        if (j==keyword.size()-1)
            j=-1;//if we looped through all the letters of the keyword start over
    }
    if(n==1)
        cout<<encrypted<<endl;
    else
        cout<<decrypted<<endl;
}


//user menu
void Cipher_menu() {

    while (true) {
        int choice;
        cout<<"=============================================================";
        cout<< "\n1)Vignere Cipher\n2)Baconian Cipher\n3)Morse Code\n4)return\n";

        //if the input is not integer ask print error message
        if (!(cin >> choice)) {
            // If input failed, clear the fail state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        //user chose exit
        if (choice == 4){
            break;
        }
        else if(choice==1||choice==2||choice==3){

            if(choice==1){//user chose Vignere Cipher
                vignere_cipher(1);
            }

            else if(choice==2){

            }
            else if(choice==3){

            }
        }
        else{//unexpected value
            cout<<"Please enter 1, 2, 3 or 4"<<endl;
            continue;
        }
    }
}

void deCipher_menu(){
    while (true){
        int choice;
        cout<<"=============================================================";
        cout<< "\n1)Vignere deCipher\n2)Baconian deCipher\n3)Morse deCode\n4)return\n";
        //if the input is not integer ask print error message
        if (!(cin >> choice)) {
            // If input failed, clear the fail state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        //user chose exit
        if (choice == 4){
            break;
        }
        else if(choice==1||choice==2||choice==3){

            if(choice==1){//user chose Vignere deCipher
                vignere_cipher(2);
            }

            else if(choice==2){

            }
            else if(choice==3){

            }
        }
        else{//unexpected value
            cout<<"Please enter 1, 2, 3 or 4"<<endl;
            continue;
        }
    }
}

int main() {
    cout << "Hello my dear user this is our cipher program, we have:\n";
    while (true) {
        int choice;
        cout<<"=============================================================";
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
            cout<<"Please enter 1, 2 or 3"<<endl;
            continue;
        }
    }
}