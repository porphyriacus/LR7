#include <iostream>
#include <vector>

typedef long long ll;

int ost = 0;

std::vector<int> sum(std::vector<int> num1, std::vector<int> num2)//O(n^2) в худшем случае из-за вставок в начало вектора
{
    ll size1 = num1.size(); 
    ll size2 = num2.size(); 
    ll maxsize = std::max(size1, size2) + 1; 

    std::vector<int> result; 

    if (num1[0] == 0)
    {
        while (num1.size() < maxsize)
        {
            num1.insert(num1.begin() + 1, 0); // Вставка нуля, временная сложность: O(n)
        }
    }
    else
    {
        while (num1.size() < maxsize)
        {
            num1.insert(num1.begin() + 1, 1); // O(n)
        }
    }

    if (num2[0] == 0)
    {
        while (num2.size() < maxsize)
        {
            num2.insert(num2.begin() + 1, 0); //O(n)
        }
    }
    else
    {
        while (num2.size() < maxsize)
        {
            num2.insert(num2.begin() + 1, 1); // O(n)
        }
    }

    for (ll i = maxsize - 1; i >= 0; --i)
    {
        int sum = num1[i] + num2[i] + ost; 
        result.insert(result.begin(), sum % 2); //  O(n)
        ost = sum / 2; 
    }

    ost = 0; 
    return result; 
}
