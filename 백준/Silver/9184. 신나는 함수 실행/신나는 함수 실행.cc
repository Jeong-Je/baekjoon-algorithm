#include <iostream>

using namespace std;

static int arr[21][21][21];

int wfunc(int a, int b, int c);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    
    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1)break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << wfunc(a, b, c) << '\n';
    }
}

int wfunc(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    
    if(a >20 || b>20 || c >20) return wfunc(20, 20, 20);
    
    if(arr[a][b][c]) return arr[a][b][c];
    
    if(a < b && b < c) {
        arr[a][b][c] = wfunc(a, b, c-1) + wfunc(a,b-1,c-1) - wfunc(a, b-1, c);
        return arr[a][b][c];
    }
    
    arr[a][b][c] = wfunc(a-1, b, c) + wfunc(a-1,b-1,c) + wfunc(a-1, b, c-1) - wfunc(a-1, b-1, c-1);
    return arr[a][b][c];
}