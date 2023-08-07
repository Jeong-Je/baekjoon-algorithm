#include <iostream>

using namespace std;

int main(){
    int n, result=0;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        result++;
    }
    cout<<result;
}