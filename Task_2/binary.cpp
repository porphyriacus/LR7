#include <iostream>
#include <vector>
#include <algorithm>

static std::vector<int> vectorToBinary(std::vector<int> digits);
static std::vector<int> divideByTwo(const std::vector<int> &digits);

std::vector<int> numberToVector() {//  O(n^2)
    
    std::vector<int> digits; 
    char ch;
    bool isNegative = false; 

    //std::cout << "Введите число: ";
    ch = getchar(); 
    
    if (ch == '-') {
        isNegative = true; 
        digits.push_back(1);  
        ch = getchar(); 
    } else {
        digits.push_back(0);  
    }
    
    while (ch != '\n') {
        if (isdigit(ch)) {
            digits.push_back(ch - '0'); 
        }
        ch = getchar();
    }

    std::vector<int> binary = vectorToBinary(digits); O(n^2)

    return binary; 
}

static std::vector<int> divideByTwo(const std::vector<int> &digits)
{
    std::vector<int> result; 
    int carry = 0; 

    
    result.push_back(digits[0]); 
    for (size_t i = 1; i < digits.size(); ++i)
    {
        int current = carry * 10 + digits[i]; 
        result.push_back(current / 2); 
        carry = current % 2; 
    }

    // Убираем ведущие нули
    while (result.size() > 1 && result[1] == 0)
    {
        result.erase(result.begin() + 1); O(n)
    }

    return result; 
}

static std::vector<int> vectorToBinary(std::vector<int> digits)
{
    std::vector<int> binary; 

    // Добавляем знак
    binary.push_back(digits[0]); 
    binary.push_back(0); 

    std::vector<int> tempBinary; 
    while (digits.size() > 1 || digits[1] != 0)
    {
        tempBinary.push_back(digits.back() % 2); 
        digits = divideByTwo(digits); // Деление вектора на 2, временная сложность: O(n)
    }

    std::reverse(tempBinary.begin(), tempBinary.end()); // Обратный порядок элементов: O(n)
    binary.insert(binary.end(), tempBinary.begin(), tempBinary.end()); // Вставка элементов в основной вектор: O(n)

    return binary;
}


