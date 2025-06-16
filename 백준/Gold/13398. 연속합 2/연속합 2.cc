#include <iostream>
#include <algorithm>

using namespace std;


static int arr[100000];
static int no_del[100000];
static int one_del[100000];

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }


    no_del[0] = arr[0];
    one_del[0] = 0;
    int result = arr[0];

    for(int i=1;i<N;i++){
        no_del[i] = max(arr[i], no_del[i-1] + arr[i]);
        one_del[i] = max(one_del[i-1]+arr[i], no_del[i-1]);
        result = max({result, no_del[i], one_del[i]});
    }

    cout << result;
    
}