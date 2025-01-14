#include <iostream>
#include <vector>
#include "header.h"

typedef long long ll;


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << " Патриций решил устроить праздник и для этого приготовил 240 бочек вина. Однако к нему пробрался недоброжелатель по имени Пользователь,"
            << " который подсыпал яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба неизвестна, но ходят слухи, что он проверяет "
            << "консольный ввод в аду в качестве наказания, однако сейчас не об этом. Про яд известно, что человек, который его выпил, умирает в течение 24 часов."
            << " До праздника осталось два дня, то есть 48 часов. У патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд."
            << " Вы близкий друг Патриция и совершенно не хотите стать одним из тех рабов, что будут проверять вино на наличие яда. "
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
            std::cout << "\nВведите первое ваше число. Оно должно быть натуральным не превышающим 240" << std::endl;
            long long n = IncorrectInput();
            if( n < 1 || n > 240){
                std::cout<<"\nНекорректный ввод. Попробуйте ещё раз." << std::endl;
                continue;
            }
            solve(n);
            break;
        }
    }
}