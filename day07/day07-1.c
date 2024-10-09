#include <stdio.h>

int main(){
    int num;

    printf("몇 층 피라미드를 만드시겠습니까? : ");
    scanf("%d", &num);
    printf("%d층 피라미드\n");
    
    for(int i = 1; i <= num; i++){
        for (int j = 0; j <= num-i; j++){
            printf(" ");
        }
        
        for(int v = 1; v <= i*2-1; v++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}