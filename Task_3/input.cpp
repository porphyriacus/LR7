#include <iostream>


int IncorrectInput()//O(n) в худшем случае
{
    int a;

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
void str(std::string& str) { //O(n)
    bool checkipecki = true;
    while (checkipecki) {
        int check = 0, i;
        checkipecki = false;

        while ((i = getchar()) != '\n') {
            if ((i < 48 && (i != 45 || check != 0)) || (i > 57 && i < 65) || (i > 90)) {
                std::cout << "При вводе вашего числа используйте только цифры и заглавные буквы латинского алфавита."
                          << "Если вы хотите чтобы ваше число было отрицательным поставьте знак минуса перед числом ' - '. Нажмите ENTER, чтобы закончить ввод."
                          << "\nПопробуйте ввести строку ещё раз :3\n"
                          << std::endl;
                checkipecki = true;
                while ((getchar()) != '\n');
                check = 0;
                break;
            }
            str += i;
            check++;
        }
    }
}