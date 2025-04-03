#include <iostream>
#include <vector>

#define MAX 1500001

using namespace std;

typedef pair<int, int> tp;
static vector<tp> schedule(MAX);
static vector<int> income(MAX);

int main(){
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        int t, p;
        cin >> t >> p;
        schedule[i] = {t, p};
    }
    
    for(int i=N;i>0;i--){
        int end = i + schedule[i].first;
        
        if(end > N+1) {
            income[i] = income[i+1];
        } else {
            income[i] = max(income[i+1], income[end] + schedule[i].second);
        }
        
    }
    
    cout << income[1];
}