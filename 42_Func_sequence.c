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
결과가 정의되지 않음(undefined behavior)
어떤 일이 일어날지 모른다.
첫 번째 인자가 먼저 평가될 경우 : float result = divide(1, 2); => 1/2 = 0.5
두 번째 인자가 먼저 평가될 경우 : float result = divide(2, 1); => 2/1 = 2.0
동시에 평가될 수도 있음 : 알 수 없음 => ?? / ?? = ??
*/