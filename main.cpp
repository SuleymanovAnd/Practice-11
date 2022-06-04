#include <iostream>
std::string encrypt_caesar (std::string s, int n){
    std::string  enStr;
    for(int i = 0; i < s.length();i++){
        if (s[i] >= 65 && s[i]<= 90) {
            enStr += (char) (((s[i] - 'A' + n)%26) + 'A');
        }
        else if(s[i] >= 97 && s[i]<= 122){
            enStr +=(char) (((s[i] - 'a' + n)%26) + 'a');
        }
        else if (s[i] == 32) {
            enStr += (char) s[i];
        }
    }
    return enStr;
}

std::string decrypt_caesar (std::string s, int n){

    return encrypt_caesar (s, (26 -n));
}
int main() {

    std::string str;
    std::cout << "Input string: ";
    std::getline (std::cin,str );

    int number;
    std::cout << "Input the key: ";
    std::cin >> number;
std::string outStr = encrypt_caesar (str, number); // зашифрованная строка
   std::cout << outStr<< std::endl << decrypt_caesar(outStr,number) ;
}
