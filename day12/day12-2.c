#include <iostream>
using namespace std;

int solution(int n)
{
    int k = 0;

    while(n > 0){
        if(n % 2 == 0){
            n = n/2;
        }
        else{
            n--;
            k++;
            n= n/2;
        }
    }   
    
    return k;
}