#include<iostream>

using namespace std;

int arr[21];

void reverse(int a, int b);

int main()
{
    for(int i=1;i<=20;i++)
    {
        arr[i] = i;
    }
    
    
    for(int i=0;i<10;i++)
    {
        int a, b;
        cin >> a >> b;
        
        reverse(a, b);
    }
    
    for(int i=1;i<=20;i++)
    {
        cout << arr[i]<< " ";
    }
}

void reverse(int a, int b)
{
    int left = a, right = b;
    
    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
}