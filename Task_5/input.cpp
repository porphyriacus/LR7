#include <iostream>
typedef long long ll;
ll IncorrectInput()
{
    ll a;

    while (!(std::cin >> a) || (std::cin.peek() != '\n')) // cin.peek() возвращает целочисленное представление следующего символа в буфере потока, не прочитав его
    {
        std::cin.clear();              // очищаем cin, приводим его в рабочее состояние
        while (std::cin.get() != '\n') // Читаем всю оставшуюся строку посимвольно(т.е. пока не встретим '\n')
        {
        }

        std::cout << "Неверный формат ввода." << std::endl;
    }

    return a;
}