#include <iostream>
// 60 repeats
int fibonacci_sum_naive(long long unsigned n) {
    if (n > 60) n = n - (n/60) * 60;    
    if (n==0) return 0;
    long long arr[n+1];
    arr[0]=0;
    arr[1]=1;
    long long t = 1;
    for(long long i=2; i<n+1; i++) {
        arr[i] = (arr[i-1]%10+arr[i-2]%10)%10;
        t += arr[i];
    }
    t = t%10;
    return t;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n) << '\n';
}
