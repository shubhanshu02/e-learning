#include <bits/stdc++.h>
using namespace std;
#define max_size 1000
vector<pair<int,int> > v;
 int n;
int parent(int i) {
    return (i-1)/2;
}
int leftchild(int i) {
    return 2*i+1;
}
int rightchild(int i) {
    return 2*i+2;
}

void siftDown(int i, int H[]) {
    int maxIndex = i;
    int size = n;
    int l = leftchild(i), r = rightchild(i);
    if (l < size && H[l]<H[maxIndex]) maxIndex = l;
    if (r < size && H[r]<H[maxIndex]) maxIndex = r;
    if (i != maxIndex) {
        v.push_back(make_pair(i,maxIndex));
        swap(H[maxIndex], H[i]);
        siftDown(maxIndex, H);
    }
}


int main() {
    
    int t;
    cin >> n;
    int arr[n];
    for (int i=0; i<n;i++) {
        cin >> arr[i];
    }
    for (int i=n/2; i>=0;i--) {
        siftDown(i,arr);
    }cout << v.size()<<endl;
    for (int i=0; i<v.size();i++) {
        cout << v[i].first << " "<<v[i].second<<endl;
    }
}
