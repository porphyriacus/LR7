#include <iostream>
#include <vector>
#include "header.h"

typedef long long ll;


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << " Программа находит сумму двоичных чисел, заданных в естественной форме."
              << " Сложение выполняется в дополнительном коде. Ответ выражается в прямом коде.(Вариант 1)"
              << "\nПрограмма написана Саранцевой Дарьей, учащейся группы 453502" << std::endl;

    for (int i = 0; i < 10; i++)
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
            std::cout << "\nВведите первое ваше число. Оно должно быть целочисленным." << std::endl;
            getchar();
            std::vector<int> number1 = numberToVector();
              
            if (number1[0])
            {
                std::vector<int> number11 = translate(number1);
                number1 = sum(number11, std::vector<int>{0, 1});
            }

            std::cout << "\nВведите второе ваше число. Оно должно быть целочисленным." << std::endl;
            
            std::vector<int> number2 = numberToVector();

            if (number2[0])
            {
                std::vector<int> number22 = translate(number2);
                number2 = sum(number22, std::vector<int>{0, 1});
            }

            std::cout << "Ваши числа, представленное в дополнительном коде, согласно порядку их ввода:\n";
            for (std::vector<int>::iterator it = number1.begin(); it != number1.end(); ++it)
            {
                std::cout << *it;
            }
            std::cout << '\n'
                      << std::endl;
            for (std::vector<int>::iterator it = number2.begin(); it != number2.end(); ++it)
            {
                std::cout << *it;
            }
            std::cout << '\n'
                      << std::endl;

            std::vector<int> result = sum(number1, number2);
            if (result[0])
            {
                result = sum(result, std::vector<int>{ 1, 1});
                result = translate(result);
            }

            std::cout << "Сумма чисел, представленная в прямом коде:\n";

            for (int digit : result)
            {
                std::cout << digit;
            }
            std::cout << '\n'
                      << std::endl;
            break;
        }
    }
}