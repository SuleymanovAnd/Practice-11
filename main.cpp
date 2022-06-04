#include <iostream>
std::string encrypt_caesar (std::string s, int n);

std::string decrypt_caesar (std::string s, int n);

void email_correct ();
int main() {
std::cout << "Exercise 1\n\n";
    std::string str;
    std::cout << "Input string: ";
    std::getline (std::cin,str );

    int number;
    std::cout << "Input the key: ";
    std::cin >> number;
std::string outStr = encrypt_caesar (str, number); // зашифрованная строка
   std::cout << outStr<< std::endl << decrypt_caesar(outStr,number) ;

    std::cout << "\n\nExercise 2\n\n";
  email_correct ();


}
