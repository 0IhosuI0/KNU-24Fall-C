#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Str_Err(char* str);
void revert_Str(char* rev_Str);

int OK = 0;

int main(){
    char* character;
    character = (char*)malloc(sizeof(char));

    printf("문자열을 입력해 주세요 : ");
    scanf("%s", character, 100);
    Str_Err(character);

    free(character);
    character = NULL;

    return 0;
}

void Str_Err(char* str){
    for (int i = 0; i < strlen(str); i++){
        if(str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122){
            OK++;
        }
    }
    if (OK == strlen(str)){
        revert_Str(str);
    }
    else{
        printf("공백과 특수문자는 허용되지 않습니다! 영어를 입력해주세요! \n");
    }
}

void revert_Str(char* rev_Str){
    char* start, * end;
    char tmp;
    start = rev_Str;
    end = rev_Str + strlen(rev_Str) - 1;
    
    for(int i = 0; i < strlen(rev_Str)/2; i++){
        tmp = *(start);
        *(start) = *(end);
        *(end) = tmp;
        *(start)++;
        *(end)--;
    }
    
    printf("뒤집어진 문자열 : %s", rev_Str, sizeof(rev_Str));
    printf("\n");

}