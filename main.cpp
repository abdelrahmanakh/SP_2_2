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

//to encrypt the message using Vignere Cipher
string vignere_cipher_encryption(string msg, string keyword){
    string encrypted;
    msg = upper(msg);
    keyword = upper(keyword);
    //loop through each letter in the message
    for (int i=0,j=0;i<msg.size();i++,j++){
        if(msg[i]<65||msg[i]>90){
            encrypted += char(msg[i]);//if the character is not alphabetic add it to the encrypted message as it is
            continue;
        }
        encrypted += char(((msg[i]+keyword[j])%26)+65);//Vignere Cipher add the ASCII of msg[i] to corresponding keyword[i] get the modulo of that by 26 add it to 65 the ASCII of 'A'
        if (j==keyword.size()-1)
            j=-1;//if we looped through all the letters of the keyword start over
    }
    return encrypted;
}


string vignere_cipher_decryption(string msg, string keyword){
    string decrypted;
    msg = upper(msg);
    keyword = upper(keyword);
    //loop through each letter in the message
    for (int i=0,j=0;i<msg.size();i++,j++){
        if(msg[i]<65||msg[i]>90){
            decrypted += char(msg[i]);//if the character is not alphabetic add it to the encrypted message as it is
            continue;
        }
        decrypted += char(((msg[i]-keyword[j]+26)%26)+65);//Vignere DeCipher subtract the ASCII of keyword[i] from msg[i], add 26, then get the modulo of that by 26 add it to 65 the ASCII of 'A'
        if (j==keyword.size()-1)
            j=-1;//if we looped through all the letters of the keyword start over
    }
    return decrypted;
}
//user menu
void Cipher_menu() {
    while (true) {
        int choice;
        cout<<"=============================================================";
        cout<< "\n1)Vignere Cipher\n2)Baconian Cipher\n3)Morse Code\n4)return\n";
        cin>>choice;
        //user chose exit
        if (choice == 4){
            break;
        }
        else if(choice==1||choice==2||choice==3){
            string msg, keyword, encryption;

            cin.ignore();//ignore the last cin to not conflict with the next cin call
            cout<<"Enter your message:";
            getline(cin, msg);//get the whole line with spaces as input
            cout<<"Enter your keyword:";
            getline(cin, keyword);//get the whole line with spaces as input

            if(choice==1){//user chose Vignere Cipher
                if(!is_valid_key(keyword)){
                    cout<<"please enter only 8 alphabetic letters for the keyword"<<endl;
                    continue;
                }
                if (msg.size()>80){
                    cout<<"message size shouldn't be greater than 80 characters, please try again!!"<<endl;
                    continue;
                }
                encryption = vignere_cipher_encryption(msg, keyword);
            }

            else if(choice==2){

            }
            else if(choice==3){

            }
            cout<<encryption<<endl;
        }
        else{//unexpected value
            continue;
        }
    }
}

void deCipher_menu(){
    while (true){
        int choice;
        cout<<"=============================================================";
        cout<< "\n1)Vignere deCipher\n2)Baconian deCipher\n3)Morse deCode\n4)return\n";
        cin>>choice;
        //user chose exit
        if (choice == 4){
            break;
        }
        else if(choice==1||choice==2||choice==3){
            string msg, keyword, decryption;

            cin.ignore();//ignore the last cin to not conflict with the next cin call
            cout<<"Enter your message:";
            getline(cin, msg);//get the whole line with spaces as input
            cout<<"Enter your keyword:";
            getline(cin, keyword);//get the whole line with spaces as input

            if(choice==1){//user chose Vignere deCipher
                if(!is_valid_key(keyword)){
                    cout<<"please enter only 8 alphabetic letters for the keyword"<<endl;
                    continue;
                }
                if (msg.size()>80){
                    cout<<"message size shouldn't be greater than 80 characters, please try again!!"<<endl;
                    continue;
                }
                decryption = vignere_cipher_decryption(msg, keyword);
            }

            else if(choice==2){

            }
            else if(choice==3){

            }
            cout<<decryption<<endl;
        }
        else{//unexpected value
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
        cin >> choice;
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