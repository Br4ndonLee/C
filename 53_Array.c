#include <stdio.h>

int main (void) {
    int grades[5] = {70, 60, 85, 55, 90};   // �������� �ʱ�ȭ, grades �迭 ����
    int average = 0;
    int i;

    for (i = 0; i < 5; ++i) {               // �迭 �ȿ� �ִ� ��� ���� average�� ����
        average += grades[i];
    }
    average /= i;                           // �迭�� ���̷� ����
    printf("Average : %d\n", average);

    return 0;
}