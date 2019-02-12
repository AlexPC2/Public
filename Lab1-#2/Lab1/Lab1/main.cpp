//
//  main.cpp
//  Lab1
//
//  Created by Александр Ноянов on 05/02/2019.
//  Copyright © 2019 MPEI. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <math.h>
#include <iomanip>


// tet
typedef wchar_t char_t;
typedef std::wstring string;
//typedef std::wcin cin;

int char2int(char_t c, const std::set<char_t> dict)
{
    return (int)std::distance(dict.begin(), dict.find(c));
}

int main(int argc, const char * argv[])
{
    //Установка кодовой страницы
    setlocale(LC_ALL, ".1251");

    std::cout << ">";
    string s;
    std::wcin >> s;

    // compute unique set of chars
    std::set<char_t> dict;
    for(char_t c : s) {
        //std::cout << c << " ";
        if(c == 0xd0 || c == 0xd1) // skip unicode delimiter
            continue;
        dict.insert(c);
    }

    //std::cout << "\n";

    // generate unique integer value for each unique simbole in the set
    int valuesForChars[256];
    memset(valuesForChars, 0, sizeof(valuesForChars));
    int valueForChar = 0;
    for(char_t c : dict) {
        valuesForChars[c%256] = valueForChar++;
        //std::cout << c << " ";
    }

    //std::cout << "\n";
    
    int uniq_count = (int)dict.size();
    int signs = log2(uniq_count);
    
    for(char_t c : s) {
        if(c == 0xd0 || c == 0xd1)
            continue;
        //int v = char2int(c, dict);
        int v = valuesForChars[c%256];
//        std::cout << std::setw(signs) << std::setfill('0') << v << " ";
//        std::cout << c << " ";
        for (int i = signs; i >= 0; i--)
            std::cout << ((v >> i) & 1);
        std::cout << " ";
    }
    
    char c;
    std::cin >> c;

//    int counts[256];
//    for(int i = 0; i < 256; i++)
//        counts[i] = 0;
//
//    for(int i = 0; i < s.length(); i++) {
//        char c = s[i];
//        counts[c]++;
//    }
//
//    int uniq_count = 0;
//    for(int i = 0; i < 256; i++)
//        if(counts[i] != 0)
//            uniq_count++;
    
    
    
    return 0;
}
