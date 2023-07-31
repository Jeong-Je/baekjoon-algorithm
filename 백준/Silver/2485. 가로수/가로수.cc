// 1735

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Euclidean(int a, int b) { return b ? Euclidean(b, a % b) : a; }


int main() {
	int n,result,gcd;
	cin >> n;
	vector<int> v(n);
	vector<int> dis;
	for (int i = 0; i < n; i++)
		cin >> v.at(i);

	for (int i = 0; i < n-1; i++) 
		dis.push_back(v[i + 1] - v[i]);
	

	gcd = dis[0];
	for (int i = 1; i < n - 1; i++)
		gcd = Euclidean(gcd, dis[i]);

	result = (v.at(n - 1) - v.at(0)) / gcd + 1 - v.size();
	cout << result;
	

}