#include <stdio.h>
#include <math.h>

int Check_Solutions(int a, int b, int c);
void Solutions(int a, int b, int c, int Chkd_Sol);

int main(){
    int a, b, c;
    printf("이차방정식의 근을 구하는 프로그램(근은 소수점 둘쨰 자리 까지만 출력됨)\n\n");
    while(1){
        printf("최고차항의 계수 부터 공백( )으로 구분하여 입력해 주십시오\n");
        printf("예시)2x^2 + 3x + 3 -- > 2 3 3\n");
        printf("모두 0을 입력 할 시 프로그램이 종료됩니다\n");
        printf("input : ");
        scanf("%d %d %d", &a, &b, &c);
        printf("\n");

        if(a == 0 && b == 0 && c == 0){
            break;
        }

        Solutions(a, b, c, Check_Solutions(a, b, c));
        printf("\n");
    }
    printf("프로그램이 종료되었습니다.\n");
}

int Check_Solutions(int a, int b, int c){
    if((pow(b, 2) - 4*a*c ) == 0){
        return 0;
    }
    else if((pow(b, 2) - 4*a*c ) > 0){
        return 1;
    }
    else if((pow(b, 2) - 4*a*c ) < 0){
        return -1;
    }
}

void Solutions(int a, int b, int c, int Chkd_Sol){
    double result1, result2;
    switch(Chkd_Sol){
        case 1:
            result1 = ((-1) * b + sqrt(pow(b, 2) - 4*a*c)) / 2*a;
            result2 = ((-1) * b - sqrt(pow(b, 2) - 4*a*c)) / 2*a;
            printf("2차 방적식 %dx^2 + %dx + %d 의 [첫번째 근 : %.2f, 두번쨰 근 : %.2f]\n", a, b, c, result1, result2);
            break;
        case 0:
            result1 = ((-1) * b + sqrt(pow(b, 2) - 4*a*c)) / 2*a;
            printf("2차 방적식 %dx^2 + %dx + %d 의 [중근 : %.2f]\n", a, b, c, result1);
            break;
        case -1:
            printf("다음 방정식은 허근을 갖습니다! 결과값을 출력하지 않습니다!\n");
            break;
    }
}