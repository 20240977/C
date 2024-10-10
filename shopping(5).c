#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5

// 상품 구조체 정의
typedef struct {
    int id;
    char name[50];
    int price;
    int stock;
    int sales;
    int total_sales_amount;
} Product;

Product products[MAX_PRODUCTS]; // 상품 배열
int product_count = 0; // 등록된 상품 수

// 메뉴 함수 선언
void menu();
void add_stock();
void sell_product();
void view_product();
void view_all_products();

int main() {
    int choice;
    while (1) {
        menu();
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_stock();
            break;
        case 2:
            sell_product();
            break;
        case 3:
            view_product();
            break;
        case 4:
            view_all_products();
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
        }
    }
    return 0;
}

// 메뉴 출력
void menu() {
    printf("\n===== 쇼핑몰 재고 관리 시스템 =====\n");
}

// 입고 함수
void add_stock() {
    if (product_count >= MAX_PRODUCTS) {
        printf("더 이상 상품을 추가할 수 없습니다. 최대 5개의 상품만 가능합니다.\n");
        return;
    }

    int id, stock, price;
    char name[50];

    printf("상품ID: ");
    scanf("%d", &id);

    // 상품이 이미 존재하는지 확인
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("이미 존재하는 상품입니다. 입고 수량을 업데이트합니다.\n");
            printf("추가 입고량: ");
            scanf("%d", &stock);
            products[i].stock += stock;
            printf("상품 '%s'의 새로운 재고량: %d\n", products[i].name, products[i].stock);
            return;
        }
    }

    // 새로운 상품 등록
    products[product_count].id = id;
    printf("상품명: ");
    scanf("%s", name);
    strcpy(products[product_count].name, name);

    printf("입고량: ");
    scanf("%d", &stock);
    products[product_count].stock = stock;

    printf("판매가격: ");
    scanf("%d", &price);
    products[product_count].price = price;

    products[product_count].sales = 0; // 초기 판매량 0
    products[product_count].total_sales_amount = 0; // 초기 총판매금액 0
    product_count++;

    printf("상품 '%s'이(가) 추가되었습니다.\n", name);
}

// 판매 함수
void sell_product() {
    int id, sell_quantity;

    printf("상품ID: ");
    scanf("%d", &id);

    // 상품 ID 검색
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("판매량: ");
            scanf("%d", &sell_quantity);

            if (sell_quantity > products[i].stock) {
                printf("재고가 부족합니다. 현재 재고: %d\n", products[i].stock);
            }
            else {
                products[i].stock -= sell_quantity;
                products[i].sales += sell_quantity;
                products[i].total_sales_amount += sell_quantity * products[i].price;
                printf("'%s' 판매 완료. 남은 재고: %d\n", products[i].name, products[i].stock);
            }
            return;
        }
    }

    printf("해당 ID의 상품이 존재하지 않습니다.\n");
}

// 개별 상품 정보 출력
void view_product() {
    int id;
    printf("상품ID: ");
    scanf("%d", &id);

    // 상품 ID 검색
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("===== 상품 정보 =====\n");
            printf("상품 ID: %d\n", products[i].id);
            printf("상품명: %s\n", products[i].name);
            printf("가격: %d\n", products[i].price);
            printf("재고량: %d\n", products[i].stock);
            printf("판매량: %d\n", products[i].sales);
            printf("총 판매 금액: %d\n", products[i].total_sales_amount);
            return;
        }
    }

    printf("해당 ID의 상품이 존재하지 않습니다.\n");
}

// 전체 상품 정보 출력
void view_all_products() {
    if (product_count == 0) {
        printf("등록된 상품이 없습니다.\n");
        return;
    }

    printf("===== 전체 상품 정보 =====\n");
    for (int i = 0; i < product_count; i++) {
        printf("상품 ID: %d\n", products[i].id);
        printf("상품명: %s\n", products[i].name);
        printf("가격: %d\n", products[i].price);
        printf("재고량: %d\n", products[i].stock);
        printf("판매량: %d\n", products[i].sales);
        printf("총 판매 금액: %d\n\n", products[i].total_sales_amount);
    }
}
