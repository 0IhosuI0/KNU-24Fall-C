#include <stdio.h>

int main(){
    int num;

    printf("몇 층 피라미드를 만드시겠습니까? : ");
    scanf("%d", &num); //피라미드의 층 수를 지정
    printf("%d층 피라미드\n");
    
    for(int i = 1; i <= num; i++){ //n층의 피라미드를 만들기 위한 for문
        for (int j = 0; j <= num-i; j++){ //가운데 정렬의 피라미드를 만들기 위해 num-i만큼의 공백을 출력
            printf(" ");
        }
        
        for(int v = 1; v <= i*2-1; v++){ //한 층당 홀수 개의 *을 출력, 층이 늘어날 때 마다  *의 개수가 2개씩 늘어남
            printf("*");
        }
        printf("\n"); //다음 층으로 줄 넘김
    }
    
    return 0;
}