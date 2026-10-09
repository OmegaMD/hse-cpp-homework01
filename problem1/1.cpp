#include <iostream>


float string_to_float(const char* s) {
    float x = 0.0;
    int sign = 1;
    int m = 1;
    for (int i = 0; s[i] != 0; i++)
        if (s[i] == '+')
            continue;
        else if (s[i] == '-')
            sign = -1;
        else if (s[i] == '.')
            m = 0.1;
        else if (m == 1)
            x = 10 * x + (s[i] - '0');
        else {
            x += (s[i] - '0') * m;
            m *= 0.1;
        }
    return sign * x;
}


int main(int argc, char* argv[]) {
    float x = string_to_float(argv[1]), y = string_to_float(argv[2]);
    if (x < y)
        std::cout << "less";
    else if (x > y)
        std::cout << "greater";
    else
        std::cout << "equal";
}
