#include <stdio.h>
 
int g_x = 100;          // 전역변수 g_x 에 100 저장. 전역 변수는 어디서든 접근 가능

void increase_number(void) {
    int y = 200;        // 지역 변수의 범위는 선언된 블록 내로 한정됨
    y += 100;
    g_x += 100;
}

int main(void) {
    printf("g_x : %d\n", g_x);  // 100
    increase_number();          // 함수 호출
    printf("g_x : %d\n", g_x);  // 200
    // below does not compile. y는 다른 함수 안에 선언된 지역변수이기 때문
    // printf("y : %d\n", y);

    return 0;
}