/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    map<int, int> m;
    
    double sum = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
        if(m.find(v[i]) == m.end()){
            m[v[i]] = 1;
        } else {
            m[v[i]]++;
        }
    }
    
    
    cout << int(round(sum / n)) << "\n";   // 산술 평균 출력
    
    sort(v.begin(), v.end());

    cout << v[n/2] <<"\n"; // 중앙값 출력
    
    
    // 최빈값 출력
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    if(vec.size() >= 2) {
        if(vec[vec.size()-1].second == vec[vec.size()-2].second) {
            int count = 0;
            for(int i = 0 ; i < vec.size() ; i++){
                if(vec[i].second == vec[vec.size()-1].second) {
                    count++;
                }
                if(count == 2){
                    cout << vec[i].first <<"\n";
                    break;
                }
            }
        } else {
            cout << vec[vec.size()-1].first << "\n";
        }
    } else {
        cout << vec[vec.size()-1].first <<"\n";
    }
    
    
    int max = v[n-1];
    int min = v[0];
    cout << max - min << "\n"; // 범위 출력

    return 0;
}