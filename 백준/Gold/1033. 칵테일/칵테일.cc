#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> A[10];
long long D[10];

long long gcd(long long a, long long b); // 최대 공약수
void DFS(short node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long lcm = 1; // 최대 공배수
    
    short N;
    cin >> N;
    
    for(int i=0;i<N-1;i++){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));
        lcm = lcm * (p*q/gcd(p,q));
    }
    
    //cout << lcm;
    
    D[0] = lcm;
    DFS(0);
    
    /*
    for(int i=0;i<N;i++){
        cout << D[i] << " ";
    }
    */
    
    
    long long mgcd = lcm;
    
    for(int i=1;i<N;i++){
        mgcd = gcd(mgcd, D[i]);
    }
    
    //cout << "mgcd = " << mgcd << endl;
    
    for(int i=0;i<N;i++){
        cout << D[i] / mgcd << " ";
    }
    
    return 0;
}

long long gcd(long long a,long long b) { // 최대 공약수
    return b ? gcd(b, a % b) : a;
}


void DFS(short node) {
    for(tuple<int, int, int> i : A[node]) {
        int next = get<0>(i);
        if(!D[next]) { // D에 값이 들어있는지 여부로 방문을 판단함
            D[next] = D[node] * get<2>(i) / get<1>(i);
            DFS(next);
        }
    }
}