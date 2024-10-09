#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

int inCircle(int x, int y, int r);

int main(){
    double x = 0;
    double y = 0;
    double PI;
    int count = 1, circle = 0, cnt = 0;
    
     srand(time(NULL));
    
    for(int i = 1; i <= 100; i++){
       while (count <= 10000000){
            x = (double)rand() / (double)RAND_MAX;
            y = (double)rand() / (double)RAND_MAX;
            if (sqrt(pow(x, 2) + pow(y, 2)) < 1){
                circle++;
            }
            count ++;
            cnt ++;
        }
        count = 0;
        PI = 4 * ((double)circle / (double)cnt);
        printf("%d%% 진행.. 원주율 : %lf",i , PI);
        printf("{");
        for(int j = 0; j < 20; j++){
            if((i / 5) > j){
                printf("=");
            }
            else{
                printf(" ");
            }
        }
        printf("}\n");
    }

    printf("\n원주율 : %lf\n", PI);
    return 0;
}