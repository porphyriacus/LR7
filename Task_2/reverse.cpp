#include <iostream>
#include <vector>

typedef long long ll;

//переворотик если первый символ 1

std::vector <int> translate(std::vector <int> str) { //O(n)
    std::vector <int> back = str; 
    if (str[0] == 0 ) { 
        return back;
    }

    back[0] = 1; 
    int i = 1;

    for (std::vector<int> ::iterator it = str.begin() + 1; it != str.end(); ++it, ++i) {
        if (*it) { // Проверка символа '1'
            back[i] = 0;
        } else {
            back[i] = 1;
        }
    }
    return back;
}
