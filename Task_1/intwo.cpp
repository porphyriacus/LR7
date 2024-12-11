#include <iostream>
#include <vector>

typedef long long ll;

std::vector<int> convert(ll num) {//  O(n^2) в худшем случае из-за вставок в начало вектора
    const int base = 2;
    std::vector<int> result; 
    bool isNegative = num < 0; 

    if (isNegative) {
        num = -num; 
    }

   
    while (num > 0) {
        int remainder = num % base; 
        num /= base; 
        result.insert(result.begin(), remainder); // O(n), где n - количество элементов в векторе
    }

    
    if (isNegative) {
        result.insert(result.begin(), 1); //  O(n)
    } else {
        result.insert(result.begin(), 0); //  O(n)
    }

    
    return result.empty() ? std::vector<int>{0} : result;

}


