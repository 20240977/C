#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define FILE_NAME "product_data.txt"


typedef struct {
    int id;
    char name[50];
    int price;
    int stock;
    int sales;
    int total_sales_amount;
} Product;

Product products[MAX_PRODUCTS];
int product_count = 0;


void menu();
void add_stock();
void sell_product();
void view_product();
void view_all_products();
void save_products();
void load_products();

int main() {
    int choice;

    
    load_products();

    while (1) {
        menu();
        printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü��Ȳ, 5. ����, 6. �ҷ�����, 7. ����): ");
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
            save_products();
            break;
        case 6:
            load_products();
            break;
        case 7:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }
    return 0;
}


void menu() {
    printf("\n===== ���θ� ��� ���� �ý��� =====\n");
}


void add_stock() {
    if (product_count >= MAX_PRODUCTS) {
        printf("�� �̻� ��ǰ�� �߰��� �� �����ϴ�. �ִ� 5���� ��ǰ�� �����մϴ�.\n");
        return;
    }

    int id, stock, price;
    char name[50];

    printf("��ǰID: ");
    scanf("%d", &id);

    
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("�̹� �����ϴ� ��ǰ�Դϴ�. �԰� ������ ������Ʈ�մϴ�.\n");
            printf("�߰� �԰�: ");
            scanf("%d", &stock);
            products[i].stock += stock;
            printf("��ǰ '%s'�� ���ο� ���: %d\n", products[i].name, products[i].stock);
            return;
        }
    }

    
    products[product_count].id = id;
    printf("��ǰ��: ");
    scanf("%s", name);
    strcpy(products[product_count].name, name);

    printf("�԰�: ");
    scanf("%d", &stock);
    products[product_count].stock = stock;

    printf("�ǸŰ���: ");
    scanf("%d", &price);
    products[product_count].price = price;

    products[product_count].sales = 0; // �ʱ� �Ǹŷ� 0
    products[product_count].total_sales_amount = 0; // �ʱ� ���Ǹűݾ� 0
    product_count++;

    printf("��ǰ '%s'��(��) �߰��Ǿ����ϴ�.\n", name);
}


void sell_product() {
    int id, sell_quantity;

    printf("��ǰID: ");
    scanf("%d", &id);

    
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("�Ǹŷ�: ");
            scanf("%d", &sell_quantity);

            if (sell_quantity > products[i].stock) {
                printf("��� �����մϴ�. ���� ���: %d\n", products[i].stock);
            }
            else {
                products[i].stock -= sell_quantity;
                products[i].sales += sell_quantity;
                products[i].total_sales_amount += sell_quantity * products[i].price;
                printf("'%s' �Ǹ� �Ϸ�. ���� ���: %d\n", products[i].name, products[i].stock);
            }
            return;
        }
    }

    printf("�ش� ID�� ��ǰ�� �������� �ʽ��ϴ�.\n");
}


void view_product() {
    int id;
    printf("��ǰID: ");
    scanf("%d", &id);

    
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("===== ��ǰ ���� =====\n");
            printf("��ǰ ID: %d\n", products[i].id);
            printf("��ǰ��: %s\n", products[i].name);
            printf("����: %d\n", products[i].price);
            printf("���: %d\n", products[i].stock);
            printf("�Ǹŷ�: %d\n", products[i].sales);
            printf("�� �Ǹ� �ݾ�: %d\n", products[i].total_sales_amount);
            return;
        }
    }

    printf("�ش� ID�� ��ǰ�� �������� �ʽ��ϴ�.\n");
}


void view_all_products() {
    if (product_count == 0) {
        printf("��ϵ� ��ǰ�� �����ϴ�.\n");
        return;
    }

    printf("===== ��ü ��ǰ ���� =====\n");
    for (int i = 0; i < product_count; i++) {
        printf("��ǰ ID: %d\n", products[i].id);
        printf("��ǰ��: %s\n", products[i].name);
        printf("����: %d\n", products[i].price);
        printf("���: %d\n", products[i].stock);
        printf("�Ǹŷ�: %d\n", products[i].sales);
        printf("�� �Ǹ� �ݾ�: %d\n\n", products[i].total_sales_amount);
    }
}


void save_products() {
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("���� ���� �� ������ �߻��߽��ϴ�.\n");
        return;
    }

    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", products[i].id, products[i].name, products[i].price, products[i].stock, products[i].sales, products[i].total_sales_amount);
    }

    fclose(file);
    printf("��ǰ ������ ���Ͽ� ����Ǿ����ϴ�.\n");
}


void load_products() {
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("���Ͽ��� �����͸� �ҷ��� �� �����ϴ�. ���� �����մϴ�.\n");
        return;
    }

    product_count = 0;
    while (fscanf(file, "%d %s %d %d %d %d", &products[product_count].id, products[product_count].name, &products[product_count].price, &products[product_count].stock, &products[product_count].sales, &products[product_count].total_sales_amount) != EOF) {
        product_count++;
    }

    fclose(file);
    printf("���Ͽ��� ��ǰ ������ �ҷ��Խ��ϴ�.\n");
}
