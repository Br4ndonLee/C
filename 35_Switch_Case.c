#include <stdio.h>

int main(void) {
    int x = 3;
    switch (x) {                    // switch ������ ���� ���� ���� �� �� �ִ�.
        case 0:                     // x �� 3�̹Ƿ� case 0,1,2�� �ǳʶڴ�.
            printf("Case 0\n");
            break;
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
        case 3:
            printf("Case 3\n");
            /* intentional fallthrough */       // break�� ������ default ���̺� ���
        decault:
            printf("Default case\n");
            break;
    }

    return 0;
}