#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int tank,int stops[], int n) {
    int numrefil = 0, currefil = 0;
    while (currefil <= n)
    {
        int last = currefil;
        while (currefil <= n && stops[currefil+1]-stops[last] <= tank)
        {
            currefil++;
        }
        if (currefil == last) return -1;
        if (currefil <= n) numrefil++;
    }
    return numrefil;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    int stops[n+2];
    stops[0] = 0;

    for (size_t i = 1; i <= n; ++i) {
        cin >> stops[i];
    }
    stops[n+1]=d;
    cout << compute_min_refills(m, stops,n) << "\n";

    return 0;
}
