/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted;

int kk = 0;
int count = 0;

void merge(vector<int> &list, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        } else {
            sorted[k++] = list[j++];
        }
    }
    
    int l;
    if(i > mid){
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    } else {
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];
    }
    
    for (l = left; l <= right; l++) {
        count ++;
		list[l] = sorted[l];
		if(count == kk) {
		    cout << list[l];
		}
	}
	
}

void merge_sort(vector<int> &list, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid ,right);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n >> kk;
    
    vector<int> list(n);
    sorted.resize(n);
    
    for(int i =0;i<n;i++){
        cin >> list[i];
    }
    
    merge_sort(list, 0, n-1);
    if(kk > count)
        cout<<"-1";
    /*
    for(int i=0;i<n;i++){
        cout << list[i]<< " ";
    }
    */

    return 0;
}