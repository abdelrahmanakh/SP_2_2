#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string upper(string str){
    for (int i=0;i<str.size();i++){
        if(str[i]>=97 && str[i]<=122){
            str[i] = char(str[i]-32);
        }
    }
    return str;
}

string encrypt(string msg, string keyword){
    string encrypted;
    msg = upper(msg);
    keyword = upper(keyword);
    for (int i=0,j=0;i<msg.size();i++,j++){
        if(msg[i]<65||msg[i]>90){
            encrypted += char(msg[i]);
            continue;
        }
        encrypted += char(((msg[i]+keyword[j])%26)+65);
        if (j==keyword.size()-1)
            j=-1;
    }
    return encrypted;
}

int main() {
    string msg, keyword, en;
    getline(cin, msg);
    getline(cin, keyword);
    en = encrypt(msg, keyword);
    cout<<en;


}
