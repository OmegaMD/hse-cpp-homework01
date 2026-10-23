#include <iostream>


int string_to_int(const char* s) {
    int n = 0;
    for (int i = 0; s[i] != 0; i++)
        if ('0' <= s[i] && s[i] <= '9')
            n = 10 * n + (s[i] - '0');
        else
            throw std::invalid_argument("Аргумент не является натуральным числом");
    return n;
}


int main(int argc, char* argv[]) {
    if (argc < 2)
        throw std::invalid_argument("Недостаточно аргументов!");
    int n = string_to_int(argv[1]);
    double* a = new double[n];
    double dot_product = 0;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    double bi = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> bi;
        dot_product += a[i] * bi;
    }
    std::cout << dot_product;
    delete[] a;
}
