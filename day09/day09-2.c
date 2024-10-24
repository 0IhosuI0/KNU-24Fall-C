#include <stdio.h>

struct Product{
    int ID;
    char Product_Name[100];
    int cost;
};

void printProduct(struct Product Product);

int main(){
    int cnt = 0;
    struct Product Products[5];
    //구조체 배열 선언
    for(int i = 0; i < 5; i++){
        printf("상품 정보를 입력하세요 (입력 중단은 ID에 0 입력)\n");
        printf("상풍 ID : ");
        scanf("%d", &Products[i].ID);
        if (Products[i].ID == 0){
             break;
        }
        //구조체의 ID부분에 0이 입력되면 반복문에서 빠져나옴
        cnt++;
        printf("상품명 : ");
        scanf("%s", Products[i].Product_Name);
        printf("가격 : ");
        scanf("%d", &Products[i].cost);
    }
    printf("\n======================================\n\n");
    printf("<<입력된 상품 목록>>\n");
    for(int j = 0; j < cnt; j++){
        printProduct(Products[j]);
    }
    //Product 배열의 j번째 정보를 인수로 printProduct를 선언
    //한개의 인수로 입력한 횟수만큼 출력할 수 있도록 인수를 보내주고 출력함  
    
    return 0;
}

void printProduct(struct Product Product){
        printf("상품 ID : %d\n", Product.ID);
        printf("상품명 : %s\n", Product.Product_Name, 100);
        printf("가격 : %d원\n\n", Product.cost);
}
//배열의 j번째 정보를 받고 출력