#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    getchar();
    
    char c;
    short cnt = 0;
    for(int i=0;i<N;i++){
        c = getchar();
        if(c == 'a' || c == 'i' || c == 'u' || c =='e' || c =='o'){
            cnt ++;
        }
    }
    printf("%d", cnt);
}