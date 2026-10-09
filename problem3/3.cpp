#include <iostream>


int string_to_int(const char* s) {
    int n = 0;
    for (int i = 0; s[i] != 0; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}


int main(int argc, char* argv[]) {
    int n = string_to_int(argv[1]);
    float* a = new float[n];
    float dot_product = 0;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    float bi = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> bi;
        dot_product += a[i] * bi;
    }
    std::cout << dot_product;
    delete[] a;
}
