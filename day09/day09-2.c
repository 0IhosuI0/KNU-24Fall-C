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
    for(int i = 0; i < 5; i++){
        printf("상품 정보를 입력하세요 (입력 중단은 ID에 0 입력)\n");
        printf("상풍 ID : ");
        scanf("%d", &Products[i].ID);
        if (Products[i].ID == 0){
             break;
        }
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
    
    return 0;
}

void printProduct(struct Product Product){
        printf("상품 ID : %d\n", Product.ID);
        printf("상품명 : %s\n", Product.Product_Name, 100);
        printf("가격 : %d원\n\n", Product.cost);
}