#include <stdio.h>

float divide(int op1, int op2) {
    printf("%d / %d = ", op1, op2);
    return op1 / (float)op2;
}

int main(void){
    int num = 0;
    float result = divide(++num, ++num);

    printf("%f\n", result);
    return 0;
}
/*
����� ���ǵ��� ����(undefined behavior)
� ���� �Ͼ�� �𸥴�.
ù ��° ���ڰ� ���� �򰡵� ��� : float result = divide(1, 2); => 1/2 = 0.5
�� ��° ���ڰ� ���� �򰡵� ��� : float result = divide(2, 1); => 2/1 = 2.0
���ÿ� �򰡵� ���� ���� : �� �� ���� => ?? / ?? = ??
*/