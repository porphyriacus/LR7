#include <iostream>

void solve(int a, int b)// O(log a) в худшем случае, так как значение a делится на 2 в цикле
{   
    int k = a; 
    int c = (b + 1) >> 1; 

    while (a > b)
    {
        a = (a >> 1) + ((a & 1) ? c : 0); 
    }

    bool res = (a == b || a == 0); 
    if (res)
    {
        std::cout << "Число " << b << " является делителем числа " << k << std::endl; 
    }
    else
    {
        std::cout << "Число " << b << " не является делителем числа " << k << std::endl; 
    }
}


