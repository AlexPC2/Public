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
 
 Максимальную разность среди элементов
 
 */

#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
    while (x > M_PI*2) {
        x -= M_PI*2;
    }
    if(x <= M_PI)
        return 1.0;
    else
        return 0.0;
}

/*
double pow1(int m)
{
    if(m%2 == 1)
        return 1;
    else
        return -1;
}
*/
double b(double m)                              // Функция b(m)
{
    double bm = (pow(-1,m+1)+1)/(M_PI * m);
    //double bm = (pow1(m)+1.0)/(M_PI * m);
    return bm;
}

double a2(int m)
{
    double sum = 0;
    const double dx = 0.01;
    for(double x = 0; x < M_PI*2; x += dx) {
        sum += f(x)*cos(m*x)*dx;
    }
    double integral = sum / M_PI;
    return integral;
}
double b2(int m)
{
    double sum = 0;
    const double dx = 0.01;
    for(double x = 0; x < M_PI*2; x += dx) {
        sum += f(x)*sin(m*x)*dx;
    }
    double integral = sum / M_PI;
    return integral;
}

/*
double g1(double  x, int mmax)                               // Функция g(x)
{
    double a0 = 1.0;
    double amm, bmm;
    double ds;
    
    double sum = a0 / 2.0;

    for(int m = 1; m < mmax; m++)
    {
        amm = a2(m);
        bmm = b2(m);
        ds = amm*cos(m*x) + bmm*sin(m*x);
        sum += ds;
    }

    return sum;
}
*/

double g2(double  x, int mmax)                               // Функция g(x)
{
    double a0 = 1.0;
    double bm = 0;
    double ds;
    double sum = a0 / 2.0;

    for(int m = 1; m < mmax; m++)
    {
        bm = b(m);                                          // Значение b(i)
        ds = bm*sin(m*x);
        sum += ds;
    }
    return sum;
}

int main(int argc, const char * argv[])
{
    
    double maxDelta = 0;
    const int mmax = 50;
    for(int i = 1; i < mmax; i++)
        printf("b[%d]=%.6f = %.3f/pi\n", i, b(i), b(i)*M_PI);
    printf("\n");
    
    for(double x = 0; x <= M_PI; x+= M_PI/8) {
        double gx = g2(x, mmax);
        double fx = f(x);
        double dfx = fx - gx;
        printf("x=%.4lf |  %.3lf - %.3lf = %.3lf\n", x, fx, gx, dfx);
        
        if(dfx > maxDelta) maxDelta = dfx;
    }
    
    
    cout << endl << "Max delta = " << maxDelta << endl;
    
//    double yourValue;
//    double d = 0;
//
//    cout << "Input m: ";
//    cin >> yourValue;
//    cout << "Result:" << g(yourValue, &d) << endl;
//
//    cout << "Max delta:" << d << endl;
    
    return 0;
}
