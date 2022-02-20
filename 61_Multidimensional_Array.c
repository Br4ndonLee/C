#include <stdio.h>

int main(void) {
    int grades[2][3] = {        // 2차원 배열 하나를 초기화
        { 65, 90, 75 },
        { 70, 40, 50 }
    };
    int average = 0;
    int i;
    int j;

    for (i = 0; i < 2; ++i) {           // 2D 배열 안에 있는 모든 값을 합한다.
        for (j = 0; j < 3; ++j) {
            average += grades[i][j];
        }
    }
    average /= (i * j);     // 요소 수로 나눠 평균을 구함

    printf("Average : %d\n", average);
    
    return 0;
}