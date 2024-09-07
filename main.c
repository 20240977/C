/******************************************************************************

1주차 3. 배열실습 - 성적 구하기

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SZIE 100
int main()
{
    int number[SZIE];
    int total = 0;
    int max, min;
    float avg = 0.0;
    srand(time(NULL));
    
    for(int i = 0; i<SZIE; i++){
        number[i] = (rand() % 100) + 1;
    }

    for(int i = 0; i<SZIE; i++){
        printf("%3d\t", number[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    for(int i = 0; i<SZIE; i++){
       total += number[i];
    }
    avg = (float)total / SZIE;
        
    max = number[0];
    min = number[0];
           for(int i = 0; i<SZIE; i++){
       if(max < number[i]) max = number [i];
         if(min < number[i]) min = number [i];
    }
    printf("avg = %f, max= %d, min = %d\n", avg, max,min);
    return 0; 
}