#include <iostream>
#include "overflow.h"
std::string encrypt_caesar (std::string s, int n);
std::string decrypt_caesar (std::string s, int n);
void email_correct ();
std::string  get_address_part (std::string str, int oct);
bool ip_part_correct (std::string str);
void tic_tac_toe ();

int main() {
std::cout << "Exercise 1\n\n";
    std::string str;
    std::cout << "Input string: ";
    std::getline (std::cin,str );
    while (overflow ( )){std::getline (std::cin,str );}

    int number;
    std::cout << "Input the key: ";
    std::cin >> number;
    while (overflow ( )){std::cin >> number;}
std::string outStr = encrypt_caesar (str, number); // зашифрованная строка
   std::cout << outStr<< std::endl << decrypt_caesar(outStr,number) ;

    std::cout << "\n\nExercise 2\n\n";
  email_correct ();

    std::cout << "\n\nExercise 3\n\n";
    std::cout << "Input IP address:";
    std::string ip;
    std::cin >> ip;
    while (overflow ( )){std::cin >> ip;}

    bool Valid = true;
    int point_count = 0;
    for(int n =0;n<ip.length();n++){
        if (ip[n]=='.') point_count++;
    }
    if (point_count != 3) Valid = false;
    for (int i = 1; i<=4 && Valid;i++){
     Valid =  ip_part_correct ( get_address_part(ip,i));
       //* std::cout << Valid << " Valid" << std::endl; вывод проверки валидности по частям для наглядности
    }
   std::cout << (Valid ? "Valid": "Invalid");


    std::cout << "\n\nExercise 4\n\n";
    tic_tac_toe ();
}
