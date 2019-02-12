//
//  main.cpp
//  Lab1-#1-V2.0
//
//  Created by Александр Ноянов on 11/02/2019.
//  Copyright © 2019 MPEI. All rights reserved.
//

/*
 
 Задание №2.
 Для кодирования строки равномерным двоичным кодом, например, для слова «машина», алфавит: м,а,ш,н,и – 5 букв, достаточно 3 бита.
 Кодовый словарь:
 М    001
 А    010
 Ш    011
 И    100
 Н    101
 Слово «машина» кодируется сообщением 001010011100101010.
 Составить программу, которая кодирует строку любой длины, составляет  кодовый словарь  и выводит закодированное сообщение
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <iomanip>
#include <math.h>

using namespace std;

typedef wchar_t char_t;
//typedef std::wstring string;

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    cout << "   ==== Lab1 #2 ====" << endl;
    cout << ">";
    string strIn;
    cin >> strIn;
    
   // vector<char> dictioanry;                        // Словарь уникальных символов
    set<char> dict;
    
    // Пытаемся составить словарь из уникальных символов:
    
    for(char s : strIn)
    {
        if(s == 0xd0)
            continue;
        else
            dict.insert(s);
    }
    
    int charCode[256];                                // Даем всем символам номера
    memset(charCode, 0, sizeof(charCode));
    int valueForChar = 0;
    for(char c : dict)
        charCode[c] = valueForChar++;
    
    
    
    int uniq_count = (int)dict.size();               // Количество уникальных символов
    int signs = log2(uniq_count);                    // Количество нулей - длина каждого кода знака
    
    for(char c : strIn) {
        //if(c == 0xd0)
        //    continue;
        //int v = char2int(c, dict);
        int v = charCode[c];
        //        std::cout << std::setw(signs) << std::setfill('0') << v << " ";
        //        std::cout << c << " ";
        for (int i = signs; i >= 0; i--)
            std::cout << ((v >> i) & 1);
        std::cout << " ";
    }
    
    char c;
    std::cin >> c;
    
    /*
    int valuesForChars[256];
    memset(valuesForChars, 0, sizeof(valuesForChars));
    int valueForChar = 0;
    for(wchar_t c : dict)
        valuesForChars[c] = valueForChar++;
    
    int uniq_count = (int)dict.size();
    int signs = log2(uniq_count);
    
    for(wchar_t c : strIn) {
        if(c == 0xd0)
            continue;
        //int v = char2int(c, dict);
        int v = valuesForChars[c];
        //        std::cout << std::setw(signs) << std::setfill('0') << v << " ";
        //        std::cout << c << " ";
        for (int i = signs; i >= 0; i--)
            std::cout << ((v >> i) & 1);
        std::cout << " ";
    }
    
     */
     
    // Teстируем вывод map
    /*
    
    for(char s : dict)
    {
        cout << s << " ";
    }
    */
    return 0;
}
