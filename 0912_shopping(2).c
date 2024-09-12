#include <stdio.h>

int main() {
    int n;
    printf("상품 개수(종류) 입력: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("상품의 종류는 1에서 100 사이여야 합니다.\n");
        return 1;
    }

    int stock[100] = { 0 };
    int sales[100] = { 0 };
    int inventory[100] = { 0 };

 
    printf("상품 별 입고수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

 
    printf("상품 별 판매수량 입력: ");
    int total_sales = 0;  
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
        inventory[i] = stock[i] - sales[i];  
        total_sales += sales[i];  
    }


    int max_sales = sales[0], min_sales = sales[0];
    int max_id = 0, min_id = 0;
    for (int i = 1; i < n; i++) {
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_id = i;
        }
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_id = i;
        }
    }


    printf("\n모든 상품의 재고 수량: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", inventory[i]);
    }

   
    int total_stock = 0;
    for (int i = 0; i < n; i++) {
        total_stock += stock[i];
    }
    double sales_rate = (double)total_sales / total_stock * 100;
    printf("\n총 판매량: %d (판매율 %.2f%%)\n", total_sales, sales_rate);

 
    printf("가장 많이 판매된 상품: ID%d, 판매량 %d\n", max_id + 1, max_sales);
    printf("가장 적게 판매된 상품: ID%d, 판매량 %d\n", min_id + 1, min_sales);

  
    for (int i = 0; i < n; i++) {
        if (inventory[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, inventory[i]);
        }
    }
    return 0;
}




