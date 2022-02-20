#include <stdio.h>

int main(void) {
    int x = 3;
    switch (x) {                    // switch 문에는 오직 정수 값만 쓸 수 있다.
        case 0:                     // x 는 3이므로 case 0,1,2는 건너뛴다.
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
            /* intentional fallthrough */       // break가 없으니 default 레이블 출력
        decault:
            printf("Default case\n");
            break;
    }

    return 0;
}