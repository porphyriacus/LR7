#include <iostream>
#include <vector>
#include "header.h"
typedef long long ll;
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << " Программа переводит числа из прямого кода в обратный. (Вариант 1)"
              << "\nПрограмма написана Саранцевой Дарьей, учащейся группы 453502" << std::endl;

    for (int i = 0; i < 10; i++) //O(n)
    {
        std::cout << "*********";
    }

    while (true)
    {
        std::cout << "\nВведите 1, если хотите начать программу, введите 2, если хотите закончить программу." << std::endl;

        ll status = IncorrectInput();

        if (status != 1 && status != 2)
        {
            std::cout << "Неверный формат ввода.";
            continue;
        }

        if (status == 2)
        {
            break;
        }
        while (true)
        {
            std::cout << "\nВведите ваше число. Оно должно быть целочисленным." << std::endl;

            ll num = IncorrectInput();

            std::vector <int> number = convert(num);

            std::cout<<"Ваше число, представленное в прямом коде:\t";
            for(std::vector<int>::iterator it = number.begin(); it != number.end(); ++it){ //O(n)
                std::cout << *it;
            }

            std::cout<<std::endl;
            std::cout<<"Ваше число, переведенное из прямого кода в обратный:\t";
            std::vector <int> back = translate(number);

            for(std::vector<int>::iterator it = back.begin(); it != back.end(); ++it){ //O(n)
                std::cout << *it;
            }
            std::cout<<'\n'<<std::endl;
            break;

        }

        
    }
}