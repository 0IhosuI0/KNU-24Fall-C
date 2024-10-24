#include<stdio.h>

struct Vec{
    int x;
    int y;
    int z;
};

void Vec_Sum(int x, int y, int z, int xx, int yy, int zz);
void Vec_Sub(int x, int y, int z, int xx, int yy, int zz);
void Vec_Cross(int x, int y, int z, int xx, int yy, int zz);
void Vec_Dot(int x, int y, int z, int xx, int yy, int zz);

int main(){
    struct Vec vec1;
    struct Vec vec2;
    int choice;

    printf("첫번째 벡터(x, y, z) : ");
    scanf("%d, %d, %d", &vec1.x, &vec1.y, &vec1.z);
    printf("두번째 벡터(x, y, z) : ");
    scanf("%d, %d, %d", &vec2.x, &vec2.y, &vec2.z);
    
    while(choice != 5){
        printf("\n입력된 첫번쨰 벡터\t%d,\t%d,\t%d\n", vec1.x, vec1.y, vec1.z);
        printf("입력된 첫번쨰 벡터\t%d,\t%d,\t%d\n", vec2.x, vec2.y, vec2.z);
        printf("\n----------------------------\n");
        printf("1. 벡터의 합\n");
        printf("2. 벡터의 차\n");
        printf("3. 벡터의 외적\n");
        printf("4. 벡터의 내적\n");
        printf("5. 종료\n");
        printf("\n----------------------------\n");
        printf("명령 입력 : ");
        scanf("%d", &choice);

        if(choice == 1){
            Vec_Sum(vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);
        }
        else if(choice == 2){
            Vec_Sub(vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);
        }
        else if(choice == 3){
            Vec_Cross(vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);
        }
        else if(choice == 4){
            Vec_Dot(vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);
        }
        else{
            if(choice != 5) printf("잘못된 입력입니다. 다시 시도해주십시오\n");
        }
        printf("\n----------------------------\n");
    }

    return 0;
}

void Vec_Sum(int x, int y, int z, int xx, int yy, int zz){
    int resultX, resultY, resultZ;
    resultX = (x + xx);
    resultY = (y + yy);
    resultZ = (z + zz);
    printf("벡터의 합(x, y, z)\n");
    printf("%d, %d, %d", resultX, resultY, resultZ);
}
void Vec_Sub(int x, int y, int z, int xx, int yy, int zz){
    int resultX, resultY, resultZ;
    resultX = (x - xx);
    resultY = (y - yy);
    resultZ = (z - zz);
    printf("벡터의 차(x, y, z)\n");
    printf("%d, %d, %d", resultX, resultY, resultZ);
}
void Vec_Cross(int x, int y, int z, int xx, int yy, int zz){
    int resultX, resultY, resultZ;
    resultX = (y * zz - z * yy);
    resultY = (z * xx - x * zz);
    resultZ = (x * yy - y * xx);
    printf("벡터의 외적(x, y, z)\n");
    printf("%d, %d, %d", resultX, resultY, resultZ);
}
void Vec_Dot(int x, int y, int z, int xx, int yy, int zz){
    int result;
    result = x * xx + y * yy + z * zz;
    printf("벡터의 내적");
    printf("vec1 ⋅ vec2 = %d\n", result);
}
