/******************************************************************************

1주차 2. 배열실습 - 난수생성 과제제

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number[10];
    
    srand(time(NULL));
    
    for(int i = 0; i<10; i++){
        number[i] = (rand() % 100) + 1;
    }
    
    
    for(int i = 0; i<10; i++){
        printf("number = %d\n", number[i]);
    }
    return 0; 
}