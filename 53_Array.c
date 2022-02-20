#include <stdio.h>

int main (void) {
    int grades[5] = {70, 60, 85, 55, 90};   // 지역변수 초기화, grades 배열 생성
    int average = 0;
    int i;

    for (i = 0; i < 5; ++i) {               // 배열 안에 있는 모든 값을 average에 저장
        average += grades[i];
    }
    average /= i;                           // 배열의 길이로 나눔
    printf("Average : %d\n", average);

    return 0;
}