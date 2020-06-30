#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n==2) return 2;
    if (n > 60) n = n - (n/60) * 60;   
    int arr[n+2];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<n+2; i++) {
        arr[i] = (arr[i-1]%10+arr[i-2]%10)%10;
    }
    return (arr[n]*arr[n+1])%10;
} 

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n) << '\n';
}
