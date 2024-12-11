#include <iostream>
#include "header.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << " Программа проверяет, делится ли введенное пользователем число на 3, 37, 89.(Вариант 1)"
              << "\nПрограмма написана Саранцевой Дарьей, учащейся группы 453502" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "*********";
    }

    while (true)
    {
        std::cout << "\nВведите 1, если хотите начать программу, введите 2, если хотите закончить программу." << std::endl;

        int status = IncorrectInput();

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
            std::cout << "Введите число, которое вы хотите проверить. \nУчтите, что у нуля бесконечно много делителей, и число не может быть делителем большего числа" << std::endl;
            int num = IncorrectInput();

            solve(num, 3);
            solve(num, 37);
            solve(num, 89);
            break;
        }
    }
}