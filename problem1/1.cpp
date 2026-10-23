#include <iostream>


const char* int_to_ans(int x) {
    if (x == -1)
        return "less";
    if (x == 1)
        return "greater";
    return "equal";
}


int main(int argc, char* argv[]) {
    if (argc < 2)
        throw std::invalid_argument("Недостаточно аргументов!");
    
    const char* s1 = argv[1];
    const char* s2 = argv[2];
    
    if (s1[0] == '-' && s2[0] != '-') {
        std::cout << "less";
        return 0;
    }
    if (s1[0] != '-' && s2[0] == '-') {
        std::cout << "greater";
        return 0;
    }
    int sign = 1;
    if (s1[0] == '-' && s2[0] == '-')
        sign = -1;

    int p1 = 0, p2 = 0;
    if (s1[0] < '0' || s1[0] > '9')
        p1++;
    if (s2[0] < '0' || s2[0] > '9')
        p2++;

    int lex = 0; // Лексикографическое сравнение s1 и s2
    while (true) {
        if (s1[p1] == 0 && s2[p2] == 0) {
            std::cout << int_to_ans(sign * lex);
            return 0;
        }
        if (s1[p1] == '.' && s2[p2] != '.' && s2[p2] != 0 || s1[p1] == 0) {
            std::cout << int_to_ans(sign * -1);
            return 0;
        }
        if (s2[p2] == '.' && s1[p1] != '.' && s1[p1] != 0 || s2[p2] == 0) {
            std::cout << int_to_ans(sign * 1);
            return 0;
        }
        if (lex == 0) {
            if (s1[p1] < s2[p2])
                lex = -1;
            else if (s1[p1] > s2[p2])
                lex = 1;
        }
        p1++; p2++;
    }
}
