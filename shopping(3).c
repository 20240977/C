#include <stdio.h>

#define MAX_PRODUCTS 5

void displayMenu() {
    printf("\n[���θ� ���� ���α׷�]\n");
    printf("> ���ϴ� �޴��� �����ϼ���. (1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n");
}

void inputStock(int stock[], int n) {
    int option;
    printf("�԰���� �Է�: ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("��ü ��ǰ�� �԰������ �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &stock[i]);
        }
    }
    else if (option == 2) {
        int id, qty;
        printf("��ǰ ID: ");
        scanf("%d", &id);
        printf("�԰����: ");
        scanf("%d", &qty);
        if (id >= 1 && id <= n) {
            stock[id - 1] += qty;
        }
        else {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
        }
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
    }
}

void inputSales(int stock[], int sales[], int n) {
    int option;
    printf("�Ǹż��� �Է�: ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("��ü ��ǰ�� �Ǹż����� �Է��ϼ���: ");
        for (int i = 0; i < n; i++) {
            int qty;
            scanf("%d", &qty);
            if (qty <= stock[i]) {
                sales[i] += qty;
                stock[i] -= qty;
            }
            else {
                printf("��ǰ ID %d�� ��� �����մϴ�. (���� ���: %d)\n", i + 1, stock[i]);
            }
        }
    }
    else if (option == 2) {
        int id, qty;
        printf("��ǰ ID: ");
        scanf("%d", &id);
        if (id >= 1 && id <= n) {
            printf("�Ǹż���: ");
            scanf("%d", &qty);
            if (qty <= stock[id - 1]) {
                sales[id - 1] += qty;
                stock[id - 1] -= qty;
            }
            else {
                printf("��� �����մϴ�. (���� ���: %d)\n", stock[id - 1]);
            }
        }
        else {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
        }
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
    }
}

void displayStatus(int stock[], int sales[], int n) {
    int total_sales = 0, total_stock = 0;
    int max_sales = sales[0], min_sales = sales[0];
    int max_id = 1, min_id = 1;

    // ��� ���� ��� �� �ִ�/�ּ� �Ǹŷ� ã��
    printf("��� ��ǰ�� ��� ����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", stock[i]);
        total_sales += sales[i];
        total_stock += (stock[i] + sales[i]);  // ���� ��� + �Ǹŵ� �������� �� �԰� ���

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
    printf("\n�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", total_sales, sales_rate);
    printf("���� ���� �Ǹŵ� ��ǰ: ID%d, �Ǹŷ� %d\n", max_id, max_sales);
    printf("���� ���� �Ǹŵ� ��ǰ: ID%d, �Ǹŷ� %d\n", min_id, min_sales);

    // ��� ���� ��� (��� ������ 2 ������ ���)
    for (int i = 0; i < n; i++) {
        if (stock[i] <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", i + 1, stock[i]);
        }
    }
}

int main() {
    int stock[MAX_PRODUCTS] = { 0 };  // �ʱ� �԰� ���� 0
    int sales[MAX_PRODUCTS] = { 0 };  // �ʱ� �Ǹ� ���� 0
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
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }

    return 0;
}
