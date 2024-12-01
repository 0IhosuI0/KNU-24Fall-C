#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10000

int solution(int topping[], size_t topping_len){
    int cheolsoo_top[MAX + 1] = {0, };
    int brother_top[MAX + 1] = {0, };
    int num_ctop = 0, num_btop = 0;
    int num_fair = 0;
    
    for(int i = 0; i < topping_len; i++){ //동생이 다 먹을 때
        int top = topping[i];
        if(brother_top[top] == 0) num_btop++;
        brother_top[top]++;
    }

    for(int i = 0; i < topping_len; i++){ //철수가 왼쪽부터 하나씩 가져감
        int top = topping[i];
        brother_top[top]--;
        if(brother_top[top] == 0) num_btop--;

        if(cheolsoo_top[top] == 0) num_ctop++;
        cheolsoo_top[top]++;

        if(num_ctop == num_btop) num_fair++;
        
    }

    return num_fair;
}