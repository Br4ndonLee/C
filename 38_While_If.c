#include <stdio.h>

int main(void) {
    int counter = 5;
    while (counter >= 0) {          // while 문은 counter가 0 이상일 때만 돈다
        if (counter) {              // 만약 counter 변수가 0이 아니면, true를 의미
            printf("Hello beautiful world\n");
        } else {
            printf("Goodbye cruel world\n");
        }
        --counter;                  // while문의 마지막에서 counter 변수가 줄어든다
    }
    return 0;
}