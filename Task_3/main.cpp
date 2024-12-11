#include <iostream>

#include "header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << " Пользователь вводит основание системы счисления. Программа щсуществляет"
              << " сложение и вычитание чисел в заданной системе счисления."
              << "\nПрограмма написана Саранцевой Дарьей, учащейся группы 453502" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "*********";
    }

    while(52){
         std::cout << "\nВведите 1, если хотите начать программу, введите 2, если хотите закончить программу." << std::endl;

        int status = IncorrectInput();

        if (status != 1 && status != 2)
        {
            std::cout << "Неверный формат ввода.";
            continue;
        }

        if (status == 2)
        {
            return 0;
        }
    while (true)
    {   
        getchar();
        std::string num1, num2;

        std::cout << "\nПри вводе вашего числа используйте только цифры и заглавные буквы латинского алфавита."
                  << "\nЕсли вы хотите чтобы ваше число было отрицательным поставьте знак минуса перед числом ' - '.\nНажмите ENTER, чтобы закончить ввод." << std::endl;
        std::cout << "Введите первое число:\n"<<std::endl;
        str(num1);
        std::cout << "Введите второе число:\n"<<std::endl;
        str(num2);
        std::cout << "Введите систему счисления. (натуральное число большее 1)\n"<<std::endl;
        int base = IncorrectInput();

        if (base < 2)
        {
            std::cout << "Основание системы счисления должно быть больше 1.\n";
            return 1;
        }

        std::string sum = addInBase(num1, num2, base);
        std::cout << "Сумма чисел: " << sum << "\n";

        std::string result = subtractInBase(num1, num2, base);
        std::cout << "Разность чисел: " << result << "\n";
        break;
    }
    }
}
