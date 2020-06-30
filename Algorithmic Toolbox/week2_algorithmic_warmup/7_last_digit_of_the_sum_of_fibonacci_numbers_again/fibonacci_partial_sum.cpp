#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (from == to && to == 0) return 0;
    if (to == 1) return 1;
    if (from > 60) from = from - (from/60) * 60;    
    if (to > 60) to = to - (to/60) * 60;   
    if (to < from) to+= 60;
    long long arr[to+1];
    arr[0]=0;
    arr[1]=1;
    long long t = 0;
    for(long long i=2; i<to+1; i++) {
        arr[i] = (arr[i-1]%10+arr[i-2]%10)%10;
        if (i >= from) {
            t += arr[i];
        }
    }
    if (from <= 1 && to >=1) t+=1;
    t = t%10;
    return t;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
