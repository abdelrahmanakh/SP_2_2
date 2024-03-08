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
        if((keyword[i]>=97 && keyword[i]<=122)||(keyword[i]>=65 && keyword[i]<=90)){
            length += 1;
        }
        else{
            break;
        }
    }
    if (length==keyword.size()&&length<=8){ //if length < keyword.size() this means there is at least one non-alphabetic char
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
//user menu
void menu() {
    cout<<"Hello my dear user this is our cipher program, we have:";
    while (true) {
        int choice;
        cout<<"\n=============================================================";
        cout<< "\n1)Vignere Cipher\n2)Baconian Cipher\n3)Morse Code\n4)exit\n";
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
                    cout<<"please enter only 8 alphabetic letters for the keyword";
                    continue;
                }
                if (msg.size()>80){
                    cout<<"message size shouldn't be greater than 80 characters, please try again!!";
                    continue;
                }
                encryption = vignere_cipher_encryption(msg, keyword);
            }

            else if(choice==2){

            }

            else if(choice==3){

            }

            cout<<encryption;
        }
        else{//unexpected value
            continue;
        }
    }
}

int main() {
    menu();
}
