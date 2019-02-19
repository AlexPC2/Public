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

string isk(string& A,int n)             // Искажение
{
    string resStr = A;
    for(int i = 0; i < n; i++){
        resStr[i] = resStr[i] == '1' ? '0' : '1';
    }
    return resStr;
}

void printChet(int v)
{
        if(v == 0 )
        {
          cout << " Четное" << endl;
        }else{
          cout <<" He четное" << endl;
        }
}

int main(int argc, const char * argv[]) {
    std::string A;
    //int N;
    
    cout << "         ==== Лабортаорная работа №2 ====" << endl;
    
    std::cout << "A=";
    std::cin >> A;
    printChet(chet(A));
   // if(chet(A) == 0) cout << " Четное" << endl;
    //else
    //    cout <<" He четное" << endl;
    //std::cout << chet(A) << std::endl;
    
    cout << endl << " Искаженное число в одном разряде:" << endl;
    
    string Aisk = A;
    
    Aisk[1] = Aisk[1] == '1' ? '0' : '1';
    std::cout << "Aisk1=" << Aisk << std::endl;
    printChet(chet(Aisk));
    //std::cout << chet(A) << std::endl;
    //std::cout << "N=";
    
    cout << endl << " Искаженное число в трех разрядах:" << endl;
    
    string Aisk3 = isk(A,3);
    
    cout << "Aisk3=" << Aisk3 << endl;
    
    printChet(chet(Aisk3));
    
    //cout <<  << endl;
    //std::cin >> N;
//    char c;
//    for(int i = 0; i < N; i++) {
//        std::cin >> c;
//        num += c;
//    }
    
    
    
    return 0;
}
