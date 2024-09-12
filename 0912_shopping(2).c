#include <stdio.h>

int main() {
    int n;
    printf("��ǰ ����(����) �Է�: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("��ǰ�� ������ 1���� 100 ���̿��� �մϴ�.\n");
        return 1;
    }

    int stock[100] = { 0 };
    int sales[100] = { 0 };
    int inventory[100] = { 0 };

 
    printf("��ǰ �� �԰���� �Է�: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

 
    printf("��ǰ �� �Ǹż��� �Է�: ");
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


    printf("\n��� ��ǰ�� ��� ����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", inventory[i]);
    }

   
    int total_stock = 0;
    for (int i = 0; i < n; i++) {
        total_stock += stock[i];
    }
    double sales_rate = (double)total_sales / total_stock * 100;
    printf("\n�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", total_sales, sales_rate);

 
    printf("���� ���� �Ǹŵ� ��ǰ: ID%d, �Ǹŷ� %d\n", max_id + 1, max_sales);
    printf("���� ���� �Ǹŵ� ��ǰ: ID%d, �Ǹŷ� %d\n", min_id + 1, min_sales);

  
    for (int i = 0; i < n; i++) {
        if (inventory[i] <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", i + 1, inventory[i]);
        }
    }
    return 0;
}




