/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int n;  
    printf("상품 개수(종류) 입력: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("상품의 종류는 1에서 100 사이여야 합니다.\n");
        return 1;  
    }

    int stock[100] = {0};  
    int sales[100] = {0};  
    int inventory[100] = {0};  

    
    printf("상품 별 입고수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    
    printf("상품 별 판매수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
        inventory[i] = stock[i] - sales[i];  
    }

    
    int id;
    printf("ID 입력: ");
    scanf("%d", &id);

    if (id < 1 || id > n) {
        printf("잘못된 ID입니다.\n");
        return 1;
    }

    printf("ID %d에 해당하는 제품의 재고 수량: %d\n", id, inventory[id - 1]);

    
    printf("모든 상품의 재고 수량: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    return 0;
}
