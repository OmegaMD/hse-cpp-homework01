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


void reverse(int* a, int l, int r) { // на полу-интервалах
    for (int i = 0; i < (r - l) / 2; i++)
        std::swap(a[l + i], a[r - 1 - i]);
}


int main(int argc, char* argv[]) {
    if (argc < 2)
        throw std::invalid_argument("Недостаточно аргументов!");
    int n = string_to_int(argv[1]);
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int k;
    std::cin >> k;
    k = (k % n + n) % n; // нормализация сдвига массива

    reverse(a, 0, n);
    reverse(a, 0, k);
    reverse(a, k, n);

    for (int i = 0; i < n; i++) 
        std::cout << a[i] << '\n';
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
    delete[] a;
}
