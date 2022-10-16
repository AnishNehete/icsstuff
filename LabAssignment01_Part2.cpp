#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

string encrypt(string s) {
    char normalChar[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
            'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
            's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    char codedChar[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
            'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
            'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

    string encryptedString = "";

    for(int i=0;i<s.length();i++){
        for(int j=0;j<26;j++){

            if(s.charAt(i) == normalChar[j]){
                encryptedString += normalChar[j];
            }

            if(s.charAt(i)<'a' || s.charAt(i)>'z'){
                encryptedString += s.charAt(i);
            }
        }
    }

    return encryptedString;
}

int main(){

    string s = "cryptography";
    cout<<"Plain text: "<<s<<endl;

    string encryptedString = encrypt(s.toLowerCase());

    cout<<"Encrypted Text: "<<encryptedString<<endl;

    return 0;
}