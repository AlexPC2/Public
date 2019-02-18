//
//  main.cpp
//  Lab2-#2
//
//  Created by Alex Noyanov on 19.02.19.
//  Copyright © 2019 Popoff Developer Studio. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int chet(const std::string& A)          // Проверка на четность
{
    int n = 0;
    for(char c : A) {
        if(c == '1')
            n++;
    }
    return n % 2;
}

string isk(string& A,int n)
{
    string resStr = A;
    for(int i = 0; i < n; i++){
        resStr[i] = resStr[i] == '1' ? '0' : '1';
    }
    return resStr;
}

void printChet()
{
    
}

int main(int argc, const char * argv[]) {
    std::string A;
    //int N;
    
    cout << "         ==== Лабортаорная работа №2 ====" << endl;
    
    std::cout << "A=";
    std::cin >> A;
    if(chet(A) == 0) cout << " Четное" << endl;
    else
        cout <<" He четное" << endl;
    //std::cout << chet(A) << std::endl;
    
    cout << endl << " Искаженное число в одном разряде:";
    
    A[1] = A[1] == '1' ? '0' : '1';
    std::cout << "Aisk1=" << A << std::endl;
    std::cout << chet(A) << std::endl;
    //std::cout << "N=";
    
    //std::cin >> N;
//    char c;
//    for(int i = 0; i < N; i++) {
//        std::cin >> c;
//        num += c;
//    }
    
    
    
    return 0;
}
