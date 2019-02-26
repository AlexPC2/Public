//
//  main.cpp
//  Yandex-#1
//
//  Created by Alex Noyanov on 21.02.19.
//  Copyright © 2019 Popoff Developer Studio. All rights reserved.
//

#include <iostream>

using namespace std;

string f(string strIn, char toDel)
{
    int i = 0;
    string resStr ="";
    
    while(strIn[i] != '\0')
    {
        if(strIn[i] != toDel)
            resStr += strIn[i];
        i++;
    }
    return resStr;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    cout << "-> " << f("Hello,world!",'o') << endl;
    return 0;
}
