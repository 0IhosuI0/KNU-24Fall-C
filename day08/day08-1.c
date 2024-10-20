#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Str_Err(char* str);
void revert_Str(char* rev_Str);

int OK = 0;

int main(){
    char* character; 
    character = (char*)malloc(sizeof(char)); 
    //문자열 포인터 선언
    //동적 할당하며 포인터를 초기화 
    printf("문자열을 입력해 주세요 : ");
    scanf("%s", character, 100);
    Str_Err(character);
    //Str_Err() 함수에서 문자열에 공백, 특수문자의 유무를 확인
    //공백이나 특수문자가 없다면 문자열을 뒤집는 함수 실행

    free(character);
    character = NULL;
    //메모리 동적 할당을 해제하고 포인터를 초기화

    return 0;
}

void Str_Err(char* str){
    for (int i = 0; i < strlen(str); i++){
        if(str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122){
            OK++;
        }
    }
    //문자열 길이만큼 한글자씩 특수문자가 있는지 확인
    //특수문자가 아니라면 OK변수를 1씩 증가
    if (OK == strlen(str)){
        revert_Str(str);
    }
    else{
        printf("공백과 특수문자는 허용되지 않습니다! 영어를 입력해주세요! \n");
    }
    //OK변수의 값이 문자열의 길이와 같다면 문자열을 뒤집는 함수 revert_Str())을 실행
    //같지 않다면 예외처리 문장을 출력하고 프로그램 종료 
}

void revert_Str(char* rev_Str){
    char* start, * end;
    char tmp;
    start = rev_Str;
    end = rev_Str + strlen(rev_Str) - 1;
    //포인터 각각 선언하고 초기화
    //서로 값을 바꿀때 임시로 저장할 변수 선언
    //포인터의 초기화는 문자열 처음 위치와 문자열의 마지막 위치
    for(int i = 0; i < strlen(rev_Str)/2; i++){
        tmp = *(start);
        *(start) = *(end);
        *(end) = tmp;
        *(start)++;
        *(end)--;
    }
    //tmp에 start값을 저장, start에 end값을 저장
    //end에 tmp값을 저장
    //strat의 주소를 +1, end의 주소를 -1 계산
    //안쪽의 글자를 뒤집음으로서 문자열의 모든 문자를 뒤집음
    
    printf("뒤집어진 문자열 : %s", rev_Str, sizeof(rev_Str));
    printf("\n");

}