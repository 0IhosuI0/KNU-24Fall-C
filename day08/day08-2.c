#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(){
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array);
    movePointer(array);

    return 0;
}

void fillRandom(int array[SIZE][SIZE]){
    int random;
    srand(time(NULL)); //
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            random = rand() % 20 + 1 ;
            array[i][j] = random;
        }
    }
    //1~20사이의 랜덤값을 배열에 대입
}

void printArray(int array[SIZE][SIZE]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%3d", array[i][j]);
        }
        printf("\n");
    } 
}
//배열의 값을 3자리수 형태로 출력

void movePointer(void* array){
    int x = 0, y = 0, val, n, nn;
    void* cur = array;
    //현재 위치의 주소를 저장할 포인터 변수 선언
    
    while(1){    
        val = *((int*)cur);
        cur=(int*)cur + val;
        //val에 현재 값을 대입
        //cur의 위치를 val만큼 이동
       
        printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x, y, val);
        y = y + val; 
        //y가 val값 만큼 증가
        if(x == 8 && y >= 20 || x == 9 && y >= 10){
            y = y - val;
            break;
        }
        //좌표 값을 표시해주는 값이 배열의 범위를 넘어가지 않게끔 반복문 정지
        if(y > 9 && x < 9){
            x = x + y / 10;
            y = y % 10;
        }
        //x에 y를 10으로 나눈 값(10의 자리)
        //y에 y를 10으로 나눈 나머지 (1의 자리) 대입

    }
    printf("\n");
    printf("더 이상 이동 할 수 없습니다. \n");
    printf("\n");
    printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", x, y, val);
}