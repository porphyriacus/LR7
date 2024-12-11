#include <iostream>
#include <string>
#include <algorithm>

// Декларации функций
std::string addInBase(const std::string &num1, const std::string &num2, const int base);//O(n), где n - длина чисел
std::string subtractInBase(const std::string &num1, const std::string &num2, const int base);//O(n), где n - длина чисел

std::string subtractInBase(const std::string &num1, const std::string &num2, const int base)
{
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    bool isNegativeResult = false;
    std::string n1 = num1;
    std::string n2 = num2;

    
    if (num1[0] == '-' && num2[0] != '-')
    {
        return "-" + addInBase(num1.substr(1), num2, base); 
    }
    else if (num2[0] == '-' && num1[0] != '-')
    {
        return addInBase(num1, num2.substr(1), base); 
    }
    else if (num1[0] == '-' && num2[0] == '-')
    {
        return subtractInBase(num2.substr(1), num1.substr(1), base); 
    }

    // Дополнение чисел нулями слева для одинаковой длины
    int maxLen = std::max(n1.size(), n2.size());
    n1 = std::string(maxLen - n1.size(), '0') + n1; // O(n)
    n2 = std::string(maxLen - n2.size(), '0') + n2; //  O(n)

    if (n1 < n2)
    {
        std::swap(n1, n2); // Перестановка чисел, если n1 < n2
        isNegativeResult = true; 
    }

    std::string result;
    int borrow = 0;

    // Вычитание справа налево
    for (int i = maxLen - 1; i >= 0; --i)
    {
        int digit1 = std::find(digits.begin(), digits.end(), n1[i]) - digits.begin(); 
        int digit2 = std::find(digits.begin(), digits.end(), n2[i]) - digits.begin(); 

        int diff = digit1 - digit2 - borrow; 
        if (diff < 0)
        {
            diff += base; // Если разница отрицательная, добавляем основание
            borrow = 1; 
        }
        else
        {
            borrow = 0; 
        }

        result += digits[diff]; //  O(1)
    }

    // Удаление ведущих нулей
    while (result.size() > 1 && result.back() == '0')
    {
        result.pop_back(); 
    }

    // Переворачиваем результат, чтобы восстановить правильный порядок цифр
    std::reverse(result.begin(), result.end()); //  O(n)

    if (isNegativeResult)
    {
        result.insert(result.begin(), '-'); 
    }

    return result; 
}


std::string addInBase(const std::string &num1, const std::string &num2, const int base)
{
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    bool isNegativeResult = false;
    std::string n1 = num1;
    std::string n2 = num2;

    
    if (num1[0] == '-' && num2[0] != '-')
    {
        return subtractInBase(num2, num1.substr(1), base); 
    }
    else if (num2[0] == '-' && num1[0] != '-')
    {
        return subtractInBase(num1, num2.substr(1), base);
    }
    else if (num1[0] == '-' && num2[0] == '-')
    {
        isNegativeResult = true; 
        n1 = num1.substr(1); 
        n2 = num2.substr(1); 
    }

    // Дополнение чисел нулями слева для одинаковой длины
    int maxLen = std::max(n1.size(), n2.size()); 
    n1 = std::string(maxLen - n1.size(), '0') + n1; //  O(n)
    n2 = std::string(maxLen - n2.size(), '0') + n2; //  O(n)

    std::string result;
    int carry = 0;

    // Сложение чисел справа налево
    for (int i = maxLen - 1; i >= 0; --i)
    {
        int digit1 = std::find(digits.begin(), digits.end(), n1[i]) - digits.begin(); 
        int digit2 = std::find(digits.begin(), digits.end(), n2[i]) - digits.begin(); 

        int sum = digit1 + digit2 + carry; 
        carry = sum / base;
        sum %= base; 

        result += digits[sum];
    }

    if (carry > 0)
    {
        result += digits[carry]; 
    }

    // Переворачиваем результат, чтобы восстановить правильный порядок цифр
    std::reverse(result.begin(), result.end()); // Переворот строки, временная сложность: O(n)

    if (isNegativeResult)
    {
        result.insert(result.begin(), '-'); 
    }

    return result; 
}



