// 1717 집합의 표현 (https://www.acmicpc.net/problem/1717)
#include <iostream>
#include <vector>

using namespace std;

static vector<int> v;

void unions(int a,int b);
int find(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    v.resize(n+1);
    
    for(int i=0;i<=n;i++){
        v[i] = i;
    }
    
    for(int i=0;i<m;i++){
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 0) {
            unions(a, b);
        } else {
            if(find(a) == find(b)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
}

void unions(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a!=b){
        v[a] = b;
    }
}

int find(int a){
    if(v[a] == a) return a;
    else {
        return v[a] = find(v[a]); // ★ 재귀 형태로 노드의 value 값 수정해주기 ★
    }
}