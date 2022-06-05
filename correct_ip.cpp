//
// Created by Андрей on 05.06.2022.
//
#include <iostream>

std::string get_address_part (std::string str,int oct){
int n_point = 1;
std::string part;
    for (int i = 0; i < str.length();i++){
        if(str[i]=='.'){n_point ++;}
        if(n_point == oct && str[i]!='.'){part += str[i];}
    }

    return part;
}

bool ip_part_correct (std::string str){
    if (str.length() > 3||str.length () == 0) {return false;}
    int sum = 0;
for (int i = 0; i <str.length();i++){
    if (str[i] <'0' || str[i]>'9'){return false;}

    if (str[0]=='0'&& str.length()>1){return false;}
    if(str.length() ==3) { // условие с длиной части = 3
        sum += (int) (str[i]-'0');

        if (str[0] != '1' && str[0] != '2') { return false; }
        if (str[0] == '1') { return true; }
        if (sum > 12 || sum < 0) { return false; }

    }
}
return true;
}