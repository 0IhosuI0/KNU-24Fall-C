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
    srand(time(NULL));
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            random = rand() % 20 + 1 ;
            array[i][j] = random;
        }
    } 
}

void printArray(int array[SIZE][SIZE]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%3d", array[i][j]);
        }
        printf("\n");
    } 
}

void movePointer(void* array){
    int x = 0, y = 0, val, n, nn;
    void* cur = array;
    
    while(1){    
        val = *((int*)cur);
        cur=(int*)cur + val;
       
        printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x, y, val);
        y = y + val; 
        if(x == 8 && y >= 20 || x == 9 && y >= 10){
            y = y - val;
            break;
        }
        if(y > 9 && x < 9){
            x = x + y / 10;
            y = y % 10;
        }
        
    }
    printf("더 이상 이동 할 수 없습니다. \n");
    printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", x, y, val);
}