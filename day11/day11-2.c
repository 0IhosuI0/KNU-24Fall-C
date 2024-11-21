#include <stdio.h>
#include <math.h>

int main(){
    int start, end, cnt;
    double x, width, height, result = 0, Real_Result;

    printf("적분할 시작 값을 입력하세요 : ");
    scanf("%d", &start);
    printf("적분할 끝 값을 입력하세요 : ");
    scanf("%d", &end);
    printf("시행할 횟수를 입력하세요 : ");
    scanf("%d", &cnt);

    for(unsigned int i = 1; i <= pow(2, cnt); i = i*2){
        x = start;
        Real_Result = 0;
        width = (double)(end - start) / i;
        for(int j = 0; j < i; j++){
            //height = (pow(x, 2) + 1);
            height = (-1) * log(1/x) + sin(x);
            result = height * width; 
            Real_Result += result;
            x += width;
        }
        printf("구간 : %d, 적분 결과 : %f\n", i, Real_Result);
    }
}