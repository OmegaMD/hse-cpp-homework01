#include <iostream>


int string_to_int(const char* s) {
    int n = 0;
    for (int i = 0; s[i] != 0; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}


int main(int argc, char* argv[]) {
    int n = string_to_int(argv[1]);
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    int k;
    std::cin >> k;
    for (int i = 0; i < n; i++) 
        std::cout << a[(i + k) % n] << '\n';
    for (int i = 0; i < n; i++)
        std::cout << a[(i + k) % n] << ' ';
    std::cout << std::endl;
    delete[] a;
}
