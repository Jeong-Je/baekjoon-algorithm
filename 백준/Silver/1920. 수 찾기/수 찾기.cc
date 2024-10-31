#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    int m;
    cin >> m;
    vector<int> v(m);

    for(int i=0;i<m;i++)
        cin >> v[i];

    sort(a.begin(), a.end());


    // 바이너리 탐색
    for(int i=0;i<m;i++){
        int left = 0, right = n-1;

        while(left <= right){
            int mid = (left + right) / 2;
            
            if(a[mid] == v[i]){
                cout<<"1\n";
                break;
            }

            if(v[i] < a[mid]) {
                right = mid - 1;
            }
            else if(v[i] > a[mid])
            {
                left = mid + 1;
            }

            // 끝까지 못찾은 경우
            if(left > right){
                cout<<"0\n";
            }
        }
    }

    

    return 0;
}