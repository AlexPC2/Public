//
//  main.cpp
//  Lab2-1
//
//  Created by Alex Noyanov on 12.02.19.
//  Copyright © 2019 Popoff Developer Studio. All rights reserved.
//

// Лабораторная 2  Задача #1

/*
 
 Задача №1
 Выполнить преобразование Фурье для функции
 
 Период функции равен T = 2*pi
 
 a0 = 1,
 am = 0,
 
             m
         (-1) + 1
 bm =   _____________
          pi * m
 
 1. Проверить формулы.
 
 2. Составить программу, которая вычисляет разложение функции f(x) для различных m определить  максимальную разность между значениями функции f(x) и c помощью  разложения Фурье.
 3.  Построить график при различных m  сравнить визуально схожесть графиков исходной функции и разложения Фурье.

                       n
                      ____
            a0       \    |
 g(t) =    ____  +    \      [am* cos(mx) + bm*sin(mx)]
            2         /
                     /____|
                     m = 1
 
 F(g(t)) =    A/(pi*f) * sin(pi+T)
 
 */

#include <iostream>
#include <math.h>

using namespace std;

double b(double m)
{
    double bm = (pow(-1,m)+1)/(M_PI * m);
    return bm;
}

double g(int  x)
{
    double result = 0;
    double sum = 0;
    
    for(int i = 0; i < x ; i++)
    {
        cout << "B(" << i << ")" << "=" << b(i) << endl;
        sum = sum + b(i) * sin(i);
    }
    result = 1.0/2.0 + sum;
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    double yourValue;
    
    cout << ">";
    cin >> yourValue;
    cout << "Result:" << g(yourValue) << endl;
    
    return 0;
}
