#include <stdio.h>

int main(void) {
    int counter = 5;
    while (counter >= 0) {          // while ���� counter�� 0 �̻��� ���� ����
        if (counter) {              // ���� counter ������ 0�� �ƴϸ�, true�� �ǹ�
            printf("Hello beautiful world\n");
        } else {
            printf("Goodbye cruel world\n");
        }
        --counter;                  // while���� ���������� counter ������ �پ���
    }
    return 0;
}