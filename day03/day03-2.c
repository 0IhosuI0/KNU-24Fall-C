#include <stdio.h>

int Pac(int num_r);

int main(){
    int num_t, result;

    printf("계산할 팩토리얼 값 입력 : ");
    scanf("%d", &num_t);
    result = Pac(num_t);
    printf("%d! = %d \n", num_t, result);

    return 0;
}

int Pac(int num_r){
    int pac_num;
    
    if(num_r == 1){
        return 1;
    }
    else if(num_r == 0){
        pac_num = 1;
    }
    else{
        pac_num = num_r*Pac(num_r - 1);
    }

    return pac_num;
}
