#include <stdio.h>

#define MAX_PRODUCTS 5

void displayMenu() {
    printf("\n[쇼핑몰 관리 프로그램]\n");
    printf("> 원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
}

void inputStock(int stock[], int n) {
    int option;
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("전체 상품의 입고수량을 입력하세요: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &stock[i]);
        }
    }
    else if (option == 2) {
        int id, qty;
        printf("상품 ID: ");
        scanf("%d", &id);
        printf("입고수량: ");
        scanf("%d", &qty);
        if (id >= 1 && id <= n) {
            stock[id - 1] += qty;
        }
        else {
            printf("잘못된 상품 ID입니다.\n");
        }
    }
    else {
        printf("잘못된 선택입니다.\n");
    }
}

void inputSales(int stock[], int sales[], int n) {
    int option;
    printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("전체 상품의 판매수량을 입력하세요: ");
        for (int i = 0; i < n; i++) {
            int qty;
            scanf("%d", &qty);
            if (qty <= stock[i]) {
                sales[i] += qty;
                stock[i] -= qty;
            }
            else {
                printf("상품 ID %d의 재고가 부족합니다. (남은 재고: %d)\n", i + 1, stock[i]);
            }
        }
    }
    else if (option == 2) {
        int id, qty;
        printf("상품 ID: ");
        scanf("%d", &id);
        if (id >= 1 && id <= n) {
            printf("판매수량: ");
            scanf("%d", &qty);
            if (qty <= stock[id - 1]) {
                sales[id - 1] += qty;
                stock[id - 1] -= qty;
            }
            else {
                printf("재고가 부족합니다. (남은 재고: %d)\n", stock[id - 1]);
            }
        }
        else {
            printf("잘못된 상품 ID입니다.\n");
        }
    }
    else {
        printf("잘못된 선택입니다.\n");
    }
}

void displayStatus(int stock[], int sales[], int n) {
    int total_sales = 0, total_stock = 0;
    int max_sales = sales[0], min_sales = sales[0];
    int max_id = 1, min_id = 1;

    // 재고 상태 출력 및 최대/최소 판매량 찾기
    printf("모든 상품의 재고 수량: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", stock[i]);
        total_sales += sales[i];
        total_stock += (stock[i] + sales[i]);  // 현재 재고 + 판매된 수량으로 총 입고량 계산

        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_id = i + 1;
        }
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_id = i + 1;
        }
    }

    double sales_rate = (double)total_sales / total_stock * 100;
    printf("\n총 판매량: %d (판매율 %.2f%%)\n", total_sales, sales_rate);
    printf("가장 많이 판매된 상품: ID%d, 판매량 %d\n", max_id, max_sales);
    printf("가장 적게 판매된 상품: ID%d, 판매량 %d\n", min_id, min_sales);

    // 재고 부족 경고 (재고 수량이 2 이하인 경우)
    for (int i = 0; i < n; i++) {
        if (stock[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, stock[i]);
        }
    }
}

int main() {
    int stock[MAX_PRODUCTS] = { 0 };  // 초기 입고 수량 0
    int sales[MAX_PRODUCTS] = { 0 };  // 초기 판매 수량 0
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputStock(stock, MAX_PRODUCTS);
            break;
        case 2:
            inputSales(stock, sales, MAX_PRODUCTS);
            break;
        case 3:
            displayStatus(stock, sales, MAX_PRODUCTS);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }

    return 0;
}
