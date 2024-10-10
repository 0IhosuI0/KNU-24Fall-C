#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 


int main(){
    double x = 0; 
    double y = 0;
    double PI;
    int count = 1, circle = 0, cnt = 0; 
    //count : 난수를 생성하고 원 안에 있는 점을 구한 횟수
    //cnt : 실제 계산 횟수
    //circle : 원 안의 점의 갯수
    
     srand(time(NULL)); //rand의 seed값을 시간에 따라 변하게 조정
    
    for(int i = 1; i <= 100; i++){ //100번의 반복으로 1%~100% 까지 구현
       while (count <= 10000000){  //10억번 반복하기위해 100*100만번의 실행
            x = (double)rand() / (double)RAND_MAX; //x의 값을 0~1 사이의 실수로 랜덤하게 지정
            y = (double)rand() / (double)RAND_MAX; //y의 값을 0~1 사이의 실수로 랜덤하게 지정
            if (sqrt(pow(x, 2) + pow(y, 2)) < 1){ //sqrt(pow(x, 2)+(pow(y, 2)) < 1)을 만족하면 원 안에 있는 점
                circle++; //원안에 있는 점 을 의미하는 변수를 +1 함
            }
            count ++;
            cnt ++; //count 변수가 100만번마다 초기화 되므로 새로운 카운트 값을 1씩 증가
         }
        count = 1; //100만번을 100번 돌리므로 100만번의 while문 실행 후 count 값을 0 으로 초기화
        PI = 4 * ((double)circle / (double)cnt); //PI = 4*(원 안의 점 / 생성한 점)임을 이용하여 계산
        printf("%3d%% 진행.. 원주율 : %lf  ",i , PI); //계산중인 원주율 표시
        printf("{"); //진행바 시작 {                    }
        for(int j = 0; j < 20; j++){ //5% 마다 진행바가 한칸씩 늘어나므로 20회로 나누어 연산
            if((i / 5) > j){ //5%마다 =이 한개씩 더 출력
                printf("=");
            }
            else{ // 나머지 칸의 공백
                printf(" ");
            }
        }
        printf("}\n");
    }

    printf("\n원주율 : %lf\n", PI); //원주율 최종 계산 값 출력
    return 0;
}