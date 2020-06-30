#include <iostream>


int fibonacci_fast(int n) {
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<n+1; i++) {
        arr[i] = arr[i-1]+arr[i-2];
    }

    return arr[n];
}
 
long long get_fibonacci_huge_naive(long long n, long long m) {
    long long arr[10*m];
    arr[0]=0;
    arr[1]=1;
    for(long long i=2; i< 10*m; i++) {
        arr[i] = (arr[i-1]%m+arr[i-2]%m)%m;
    }
    int repeat = 0;
    if (m == 2) repeat = 3;
    else if (m==3) repeat = 8;
    else {
        bool cond = true;
        for (int i=3; i< 10*m-3; i++) {
            if (arr[i] == arr[0] && arr[i+1] == arr[1] && arr[i+2] == arr[2]) {

                repeat = i;
                break;
            }
        }
    }
    return arr[n%repeat];
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
