#include <stdio.h>
 
int g_x = 100;          // �������� g_x �� 100 ����. ���� ������ ��𼭵� ���� ����

void increase_number(void) {
    int y = 200;        // ���� ������ ������ ����� ��� ���� ������
    y += 100;
    g_x += 100;
}

int main(void) {
    printf("g_x : %d\n", g_x);  // 100
    increase_number();          // �Լ� ȣ��
    printf("g_x : %d\n", g_x);  // 200
    // below does not compile. y�� �ٸ� �Լ� �ȿ� ����� ���������̱� ����
    // printf("y : %d\n", y);

    return 0;
}