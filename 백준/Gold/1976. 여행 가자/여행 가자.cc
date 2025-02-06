// 1976 여행 가자 (https://www.acmicpc.net/problem/1976)
#include <iostream>

using namespace std;

int parent[201];

void unions(int a, int b);
int find(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int dosi[201][201];

    int N, M;
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> dosi[i][j];
        }
    }
    
    int route[1001];
    
    for(int i=1;i<=M;i++){
        cin >> route[i];
    }
    
    for(int i=1;i<=N;i++){
        parent[i] = i;   
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(dosi[i][j]) {
                unions(i, j);
            }
        }
    }

    
    int idx = find(route[1]);
    
    for(int i=2;i<=M;i++){
        if(idx != find(route[i])) {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
    return 0;
}

void unions(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a!=b){
        parent[a] = b;
    }
}
int find(int a) {
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}