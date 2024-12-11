#include <iostream>
#include <vector>

std::vector<int> translate(std::vector<int> str) { // O(n) в худшем случае, где n - длина вектора
    std::vector<int> back = str; // O(n)
    if (str[0] == 0) { 
        return back; 
    }

    back[0] = 1; 
    int i = 1; 

    for (std::vector<int>::iterator it = str.begin() + 1; it != str.end(); ++it, ++i) {
        if (*it) {
            back[i] = 0; 
        } else {
            back[i] = 1; 
        }
    }
    return back; 
}


