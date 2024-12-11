#include <iostream>
typedef long long ll;

ll IncorrectInput()//O(n) в худшем случае
{
    ll a;

    while (!(std::cin >> a) || (std::cin.peek() != '\n')) // O(1) за каждую проверку, общее время — O(n) в худшем случае
    {
        std::cin.clear();              
        while (std::cin.get() != '\n') // O(n)
        {
        }

        std::cout << "Неверный формат ввода." << std::endl; 
    }

    return a; 
}


