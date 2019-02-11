//
//  main.cpp
//  Lab1-#1
//
//  Created by Александр Ноянов on 08/02/2019.
//  Copyright © 2019 MPEI. All rights reserved.
//


// Лабораторная работа #1
// Задание #1

//                      Задание №1.
// Составить программу для определения какое количество информации несет сообщение о том, что горит красный и желтый сигнал светофора,
// среднее количество информации о том, что загорелся любой из трех сигналов.

// Формулы:

/*
 
 i  = log(1/p)  - Количество информации при наступлении события х
     x
 
 p - Вероятность наступления события х
 
  р = k/n
 
 Время горения светофора:
 
 - Красный 108
 - Желтый 4
 - Зеленый 16
 
 Всего: 128 секунд
 
 Вероятности:
 pR = 0,84357
 pY = 0,03125
 pG = 0,125
 
 
 Какое количество информации несет сообщение о том, что загорелся любой из трех сигналов:
 
                 n
                 __
        H =     \
                /__  (p * log(1/px))
                x = 1        2
 
 Для сфетофора n = 3, вероятности даны.
 */

#include <iostream>
#include <math.h>
#include <numeric>

using namespace std;

//// Класс "Светофор"
//class stopLight
//{
//    // Время горения светофора:
//    int timeRed = 108;
//    int timeYellow = 4;
//    int timeGreen = 16;
//    
//public:
//    //double RedYellowProbability();
//    //double
//    
//};

// Количество информации о том, что горит красный и желтый сигнал
double Propability(const double* px, int n)                     // Массив - все вероятности, n - до какого идти
{
    double result = 0;
    for(int i = 0 ; i < n; i++)
    {
        result = result +  px[i] * log2(1.0/px[i]);       // Используем формулу
    }
    return result;
}

/*
double f(double const& px)
{
    return px * log2(1 / px);
}
*/
 
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
//    double pR = 108.0/128.0;                                // Вероятность того, что загорится красный сигнал
//    double pY = 4.0/128.0;                                  // желтый
//    double pG = 16.0/128.0;                                 // зеленый
    
    const int N = 3;
    double p[N] = { 108.0/128.0, 4.0/128.0, 16.0/128.0 };
    
    //double H1 = std::accumulate<const double*, double>(begin(p), begin(p)+2, 0, [](double current_sum, double const& px) { return current_sum + f(px); });
    //double H2 = std::accumulate<const double*, double>(begin(p), end(p), 0, [](double current_sum, double const& px) { return current_sum + f(px); });

    //std::cout << "H1=" << H1 << std::endl;
    //std::cout << "H2=" << H2 << std::endl;

    cout << "   ==== Лабораторная работа #1 ====" << endl;
    cout << "Какое количество информации несет сообщение о том, что горит красный и желтый" << endl;
    cout << "сигнал светофора:" << Propability(p,2) <<endl;
    
    cout << endl << "Какое количество информации несет сообщение о том, что горят" << endl << "все сигналы светофора:" << Propability(p,3)
    << endl << endl;
    
    //cout <<  << endl;
    
    return 0;
}
