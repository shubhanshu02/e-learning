#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return ((double)a.first/a.second > (double)b.first/b.second); 
} 

int n;

double get_optimal_value(int capacity,  pair<double , double> pairs[]) {
	double value = 0.0;
	int cap=0;

	for(int i=0; i<n;i++) {
		if (cap >= capacity) break;
		if (cap + pairs[i].second < capacity) {
			cap += pairs[i].second;
			value += pairs[i].first;
		}
		else {
			double t =  (double) (capacity-cap)*pairs[i].first/pairs[i].second;
			cap = capacity;
			value = value + t;
			break;
		}
	}
	return value;
}


int main() {
	
	int capacity;
	cin >> n >> capacity;
	int x,y;
	pair <double , double> p[n];
	for (int i = 0; i < n; i++) {
	  // Values and weights
	  cin >> p[i].first >> p[i].second;
	}	
	sort(p, p + n, sortbysec);

	double optimal_value = get_optimal_value(capacity, p);	

	cout.precision(10);
	cout << optimal_value << std::endl;
	return 0;
}
