#include <iostream>
#include <cassert>
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<n+1; i++) {
        arr[i] = (arr[i-1]%10+arr[i-2]%10)%10;
    }
    return arr[n];
}

void test_solution() {
    assert(get_fibonacci_last_digit_naive(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 20; ++n) {
        std::cout << "CHECKING FOR N: " << n << std::endl;
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
        std::cout << "SUCCESS" << std::endl;
    }
}


int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    //test_solution();
}
