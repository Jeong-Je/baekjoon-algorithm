/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int count;

int recursion(char *s, int l, int r){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(char *s){
    printf("%d ", recursion(s, 0, strlen(s)-1));
    return count;
}


int main()
{
    int t;
    scanf("%d", &t);
    char s[1001];
    for(int i=0;i<t;i++){
        count = 0;
        scanf("%s", s);
        printf("%d\n", isPalindrome(s));
    }

    return 0;
}