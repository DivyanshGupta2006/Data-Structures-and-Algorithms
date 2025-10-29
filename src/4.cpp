#include <iostream>

unsigned long long factorial(int n) {
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

unsigned long long catalan(int n) {
    if (n <= 1) {
        return 1;
    }
    // Catalan(n) = (2n)! / ((n+1)! * n!)
    unsigned long long c = 1;
    for (int i = 0; i < n; ++i) {
        c = c * 2 * (2 * i + 1) / (i + 2);
    }
    return c;
}

int main() {
    int n;
    std::cout << "Enter the number of distinct keys (n): ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Number of keys cannot be negative." << std::endl;
        return 1;
    }
    
    std::cout << "The total number of distinct BSTs with " << n
              << " keys is: " << catalan(n) << std::endl;

    return 0;
}