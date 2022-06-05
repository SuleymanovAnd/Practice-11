//
// Created by Андрей on 04.06.2022.
// тут функции для первой и второй работ
#include <iostream>
bool correct_part (std::string str, std::string dictionary);

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
// функции для второго задания
bool first_part_email_correct (std::string str){
    std::string dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'*+-/=?^_`{|}~0123456789.-";
    if (str.length()<1 || str.length() > 64){return false;} //проверяем длину первой части
    return correct_part(str,dictionary);

}
bool second_part_email_correct (std::string str){
    if (str.length()<1 || str.length() > 63){return false;} // проверяем длину второй части
    std::string dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";

return correct_part(str,dictionary);
}

bool correct_part (std::string str, std::string dictionary) {
    for (int i = 0; i < str.length(); i++) {
        bool match = false;
        if (str[0] == '.' || str[str.length() - 1] == '.') {return false; } // если точка первый символ или последний
        if (str[i] == '.' && str[i + 1] == '.') {return false; } // если две точки подряд
        for (int k = 0; k < dictionary.length() && !match; k++) { //проверяем символ со словарем
            if (str[i] == dictionary[k]) { match = true; }
        }
        if (match) { match = false; } // если символ совпал со словарем - совпадение возводим в изначальное false
        else { return false; } // если символ не совпал со словарем
    }
    return true;
}