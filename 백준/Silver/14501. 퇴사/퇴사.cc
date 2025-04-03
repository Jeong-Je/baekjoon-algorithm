#include <iostream>
#include <vector>

#define MAX 16

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
        int deadline = i + schedule[i].first;
        
        if(deadline > N+1) {
            income[i] = income[i+1];
        } else {
            income[i] = max(income[i+1], income[deadline] + schedule[i].second);
        }
        
    }
    
    cout << income[1];
}