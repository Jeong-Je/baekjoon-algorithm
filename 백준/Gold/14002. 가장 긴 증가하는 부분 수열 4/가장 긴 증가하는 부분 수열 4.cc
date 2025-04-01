#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int arr[1001];
static vector<vector<int>> result(1001);

bool cmp(vector<int> &a, vector<int> &b) {
    return a.size() > b.size();
}

int main(){
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    
    for(int i=1;i<=N;i++){
        result[i].push_back(arr[i]);
        for(int j=1;j<i;j++){
            if(arr[j] < arr[i] && result[j].size() + 1 > result[i].size()) {
                result[i] = result[j];
                result[i].push_back(arr[i]);
            }
        }
    }
    
    sort(result.begin() + 1, result.begin() + N + 1, cmp);
    
    cout << result[1].size() << "\n";
    
    for(int i=0;i<result[1].size();i++){
        cout << result[1][i] << " ";
    }
}