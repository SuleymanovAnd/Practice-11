//
// Created by Андрей on 05.06.2022.
//
#include <iostream>
#include "overflow.h"
bool incorrect_inp(std::string str);
char value_at_coordinates (std::string Up,std::string Mid, std::string Dwn, int x, int y);
bool str_win (const std::string& st1,const std::string& st2,const std::string& st3,char who,int str_num);
bool stb_win (const std::string& st1,const std::string& st2,const std::string& st3,char who,int stb_num);
bool diagonal_win(const std::string& st1,const std::string& st2,const std::string& st3,char who,int diag_num);
int smb_count (std::string st1,std::string st2,std::string st3, char who);
bool correct (int who,int count_X, int count_O);

void tic_tac_toe () {
    std::cout << "Input table for game!\nZero (ENG) \"0\", X (ENG) \"X\", void \" . \": ";
    std::string Up_str, Mid_str, Dwn_str;
    std::cin >> Up_str; while(overflow()){std::cin >> Up_str;}

    std::cin >> Mid_str; while(overflow()){std::cin >> Mid_str;}

    std::cin >> Dwn_str; while(overflow()){std::cin >> Dwn_str;}

    if(incorrect_inp(Up_str)||incorrect_inp(Mid_str)||incorrect_inp(Dwn_str)){std::cout << "Incorrect";}
    else{
bool Petya_Won;
bool Vanya_Won;
Petya_Won = (str_win(Up_str,Mid_str,Dwn_str,'X',0)
          ||str_win(Up_str,Mid_str,Dwn_str,'X',1)
          ||str_win(Up_str,Mid_str,Dwn_str,'X',2)
          ||stb_win(Up_str,Mid_str,Dwn_str,'X',0)
          ||stb_win(Up_str,Mid_str,Dwn_str,'X',1)
          ||stb_win(Up_str,Mid_str,Dwn_str,'X',2)
          ||diagonal_win (Up_str,Mid_str,Dwn_str,'X',0)
          ||diagonal_win (Up_str,Mid_str,Dwn_str,'X',1));

Vanya_Won =(str_win(Up_str,Mid_str,Dwn_str,'O',0)
            ||str_win(Up_str,Mid_str,Dwn_str,'O',1)
            ||str_win(Up_str,Mid_str,Dwn_str,'O',2)
            ||stb_win(Up_str,Mid_str,Dwn_str,'O',0)
            ||stb_win(Up_str,Mid_str,Dwn_str,'O',1)
            ||stb_win(Up_str,Mid_str,Dwn_str,'O',2)
            ||diagonal_win (Up_str,Mid_str,Dwn_str,'O',0)
            ||diagonal_win (Up_str,Mid_str,Dwn_str,'O',1));

//std::cout << "Petya " << Petya_Won << "\tVanya " <<Vanya_Won<<std::endl;
int countX= smb_count(Up_str,Mid_str,Dwn_str,'X');
int countO = smb_count(Up_str,Mid_str,Dwn_str,'O');

if(Petya_Won && Vanya_Won) {std::cout << "Incorrect";
} else if (Petya_Won ){
    if( correct (0,countX,countO)){
        std::cout << "Petya won!";}
    else{std::cout << "Incorrect";}
} else if (Vanya_Won){
    if (correct (1,countX,countO)){
        std::cout << "Vanya won!";}
    else {std::cout << "Incorrect";}
}else {std::cout << "Nobody";}

    }
}

//          ФУНКЦИИ
//проверка на ввод
bool incorrect_inp(std::string str){
    if (str.length() != 3) return true;
    for (int i =0;i<3;i++){
        if(str[i] != 'O'&& str[i] != 'X' && str[i] != '.'){return true;}
    }
    return false;
}

//значение в координатах
char value_at_coordinates (std::string Up,std::string Mid, std::string Dwn, int x, int y){
    for (int i = 0; i<3;i++){
        if (x==0 && y == i){return Up[i];}
        if (x==1 && y == i){return Mid[i];}
        if (x==2 && y == i){return Dwn[i];}
    }
}

//выиграла строка
bool str_win (const std::string& st1,const std::string& st2,const std::string& st3,char who,int str_num){
    char a = value_at_coordinates ( st1,st2,st3,str_num, 0);
    char b = value_at_coordinates ( st1,st2,st3,str_num, 1);
    char c =value_at_coordinates ( st1,st2,st3,str_num, 2);

    if(a==b&&b==c&&c==who){
return true;
    }
    else {;return false;}
}

// выиграл столбец
bool stb_win (const std::string& st1,const std::string& st2,const std::string& st3,char who,int stb_num){
    char a = value_at_coordinates ( st1,st2,st3,0, stb_num);
    char b = value_at_coordinates ( st1,st2,st3,1, stb_num);
    char c = value_at_coordinates ( st1,st2,st3,2, stb_num);
    if( a == b && b == c && c == who){
        return true;
    }
    else return false;
}
// выиграла диагональ
bool diagonal_win(const std::string& st1,const std::string& st2,const std::string& st3,char who,int diag_num){
    if(diag_num == 0){
        bool match = true;
        for (int i =0;i<3;i++){
            if(value_at_coordinates ( st1,st2,st3,i, diag_num+i)!=who){match = false;}
        }
        return match;
    } else if (diag_num == 1){
        char a = value_at_coordinates ( st1,st2,st3,0, diag_num+1);
        char b = value_at_coordinates ( st1,st2,st3,1, diag_num);
        char c = value_at_coordinates ( st1,st2,st3,2, diag_num-1);
        if( a == b && b ==c  && c ==who){
            return true;
        }
        else return false;
    }
}

//считаем количество отдельного символа
int smb_count (std::string st1,std::string st2,std::string st3, char who){
    int count;
    for (int i = 0; i<3;i++){
        if(st1[i]==who) count++;
        if(st2[i]==who) count++;
        if(st3[i]==who) count++;
    }
    return count;
}

//проверяем корректность выигрыша
bool correct (int who,int count_X, int count_O){
    if(who == 0){
        if (count_X > count_O) return true;
        else return false;
    }
    if(who == 1){
        if (count_X == count_O) return true;
        else return false;
    }
}