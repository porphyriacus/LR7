#include <iostream>

#define ll long long

// если 0 то не пил из бочки
// 1 пил в первый день
// 2 пил во второй день

// Функция для преобразования числа в троичную систему
static char* to3(ll a) { //  O(log(a))
    char* s = new char[6]; 
    s[5] = '\0'; 
    int index = 4; 
    while (a != 0) {
        s[index--] = '0' + (a % 3);
        a /= 3;
    }
    while (index >= 0) {
        s[index--] = '0';
    }
    return s;
}

// Проверяет, является ли символ строки s на позиции i равным '0'
static bool check(const char* s, ll i) {
    return s[i] == '0'; 
}

// Проверяет дополнительные условия
static bool check1(const char* s, ll i, short int* live) {
    if (s[i] == '1') {
        for (ll j = 0; j < 5; j++) {
            if (live[j + 1] == 0 && s[j] != '0')
                return false;
        }
        return true; 
    }
    return false; 
}

void solve(long long n) { //O(n log n), где n - количество бочек
    char* nums[241]; 
    bool used[241]; 
    short int live[6] = { 1, 1, 1, 1, 1, 1 }; 

    // инициализация номеров бочек с использованием троичной системы
    std::cout << "Инициализация номеров бочек...\n";
    for (int i = 1; i <= 240; i++) {
        nums[i] = to3(i); //O(log(i))
        used[i] = false; 
    }
    std::cout << "Номера бочек успешно инициализированы.\n";

    // ввод номера отравленной бочки
    ll s = 81;
  
    char after[6];
    std::cout << "\nDAY 1:\n";
    std::cout << "Определяем, какие рабы пили из бочек в первый день...\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Раб " << i << " пил из бочек: ";
        for (int j = 1; j <= 240; j++) {
            if (check(nums[j], i - 1)) {
                std::cout << j << " ";
                if (j == n) {
                    live[i] = 0;
                    after[i - 1] = '0';
                }
            }
        }
        std::cout << '\n';
        if (live[i]) {
            live[i] = 2;
            after[i - 1] = '1';
        }
    }

    after[5] = '\0'; // завершаем строку нулевым символом

    std::cout << "\nРезультаты первого дня:\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Раб " << i << ": " << ((after[i - 1] == '0') ? "Умер" : "Жив") << '\n';
    }

    std::cout << "\nDAY 2:\n";
    std::cout << "Определяем, какие рабы пили из бочек во второй день...\n";
    std::cout << "Состояние рабов: " << after << '\n';

    ll found = 0;
    for (int i = 1; i <= 5; i++, s /= 3) {
        if (after[i - 1] == '0') {
            continue; // Пропускаем рабов, которые умерли
        }
        std::cout << "Раб " << i << " пил из бочек: ";
        for (int j = 1; j <= 240; j++) {
            if (check1(nums[j], i - 1, live)) {
                std::cout << j << " ";
                if (j == n) {
                    live[i] = 1;
                }
            }
        }
        std::cout << '\n';
        found += live[i] * s;
    }

    std::cout << "\nРезультаты второго дня:\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Раб " << i << ": " << ((live[i] == 1 || after[i - 1] == '0') ? "Умер" : "Жив") << '\n';
    }

    std::cout << "\nОтравленная бочка: " << n << "\n";
    std::cout << "Итоговый номер бочки: " << found << '\n';

   

    for (int i = 1; i <= 240; i++) {
        delete[] nums[i]; 
    }
    num = nullptr;
}

