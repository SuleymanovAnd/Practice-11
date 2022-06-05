//
// Created by Андрей on 05.06.2022.
//
#include <iostream>
#include "overflow.h"
bool incorrect_inp(std::string str);
char value_at_coordinates (std::string Up,std::string Mid, std::string Dwn, int x, int y);

void tic_tac_toe () {
    std::cout << "Введите табличку игры Крестики/Нолики!\nНолик (ENG) \"0\", Крестик (ENG) \"X\", Пустое место \" . \": ";
    std::string Up_str, Mid_str, Dwn_str;
    std::cin >> Up_str; while(overflow()){std::cin >> Up_str;}

    std::cin >> Mid_str; while(overflow()){std::cin >> Mid_str;}

    std::cin >> Dwn_str; while(overflow()){std::cin >> Dwn_str;}

    if(incorrect_inp(Up_str)||incorrect_inp(Mid_str)||incorrect_inp(Dwn_str)){std::cout << "Incorrect";}
    else{

    }
}
bool incorrect_inp(std::string str){
    if (str.length() != 3) return true;
    for (int i =0;i<3;i++){
        if(str[i] != 'O'&& str[i] != 'X' && str[i] != '.'){return true;}
    }
    return false;
}

char value_at_coordinates (std::string Up,std::string Mid, std::string Dwn, int x, int y){
    for (int i = 1; i<4;i++){
        if (x==1 && y == i){return Up[i];}
        if (x==2 && y == i){return Mid[i];}
        if (x==3 && y == i){return Dwn[i];}
    }
}