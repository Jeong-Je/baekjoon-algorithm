// 1043 거짓말 (https://www.acmicpc.net/problem/1043)
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> human_T;
vector<vector<int>> party;

void unionfunc(int a,int b);
int find(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, T;
    cin >> N >> M >> T;
    
    parent.resize(N+1);
    party.resize(M);
    human_T.resize(T);
    
    for(int i=0;i<T;i++){
        cin >> human_T[i];
    }

    for(int i=0;i<M;i++){
        int size;
        cin >> size;
        
        for(int j=0;j<size;j++){
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }

    for(int i=1;i<=N;i++){
        parent[i] = i;
    }

    for(int i=0;i<M;i++){
        int tmp = party[i][0];
        
        for(int j=1;j<party[i].size(); j++){
            unionfunc(tmp, party[i][j]);
        }
    }
    

    
    int count = 0;
    for(int i=0;i<M;i++){
        int head = party[i][0];
        bool check = true;
        for(int j=0;j<T;j++){
            if(find(head) == find(human_T[j])){
                check = false;
                break;
            }
        }
        if(check){
            count++;
        }
    }
    
    cout << count;
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a!=b){
        parent[b] = a;
    }
}

int find(int a){
    if(parent[a] == a) return a;
    else {
        return parent[a] = find(parent[a]);
    }
}