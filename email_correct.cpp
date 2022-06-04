//
// Created by Андрей on 04.06.2022.
//
#include <iostream>
bool first_part_email_correct (std::string str);
bool second_part_email_correct (std::string str);

void email_correct (){
    std::string email;
std::cout << "Input email address: ";
std::cin >> email;

std::string first_part;
std::string second_part;

bool one_dogs = true;
bool dog = false;
int dogs = 0;
    for (int i = 0; i<email.length(); i++){
        if (email[i] == '@'){ dog = true; dogs++;}
        if (dogs > 1){one_dogs = false; break;}
        if (!dog) { first_part += email[i]; }
        if (dog && email[i] != '@') {second_part += email[i];} // если нет собаки во второй части не будет символов
    }

    if (one_dogs && first_part_email_correct(first_part) && second_part_email_correct(second_part) ) {std::cout<<"Yes";}
    else {std::cout << "No";}
}