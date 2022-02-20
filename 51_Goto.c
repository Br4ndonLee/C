// 위로 점프하는 안좋은 예시이다. goto문은 항상 아래로만 쓸 것!
#include <stdio.h>

void calculate_factorial(const unsigned int n) {    // n 팩토리얼을 계산 후 출력함
    unsigned int result = 1;    // result를 1로 세팅
    unsigned int i = 1;         // i를 1로 세팅. 이것은 카운터

    goto begin_loop;            // goto 문을 이용해 begin_loop 레이블로 점프

    // this is a bad practice
exit_loop:                      // goto 문의 안 좋은 사용 예. 절대 위로 점프하지 말 것.
    printf("%d factorial : %d\n", n, result);
    return;

begin_loop:                     // 9~14번째 줄을 완전히 건너뜀
    while (i <= n) {            // begin_loop 레이블 아래 있는 코드 실행. i <= n일 동안
        result *= i;            // i를 result에 곱한 뒤, i를 증가
        ++i;
    }
    goto exit_loop;             // 왠진 모르겠지만 return을 하는 대신 위의 exit_loop로 점프
}

void find_number(int arr[3][3], const int n) {
    size_t i;                   // i, j를 선언. 행렬을 순회할 때 카운터로 사용할 예정
    size_t j;
    // 4x4 행렬의 정의. 숫자 n이 3x3 행렬 안에 없다면 default_matrix 안에서 n을 찾아볼 것
    int default_matrix[4][4] = {
        {4, 1, 3, 1},
        {9, 2, -1, 6},
        {6, 0, 10, 5},
        {1, 2, 3, 3},
    };

    for (i = 0; i < 3; ++i) {   // 이중 for 반복문
        for (j = 0; j<3; ++j) {
            if (arr[i][j] == n) {   // n을 발견하면, 콘솔창에 출력하고 found 레이블로 점프
                printf("%d found in arr.", n);
                goto found;     // 0이 3x3 행렬 안에 있었다면 found 레이블로 점프
            }
        }
    }

    for (i = 0; j < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (default_matrix[i][j] == n) {
                printf("%d found in default_matrix.", n);
                goto found;
            }
        }
    }

found:
    printf("Number : %d\n", n);     // 숫자 n과 그 숫자가 발견된 행렬 속 위치 출력
    printf("Index positions : (%zu, %zu)\n", i, j); // 발견된 숫자로 0이, 색인 위치로 (0,0) 출력
}

int main(void) {
    int square_matrix[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    calculate_factorial(4);         // 4의 팩토리얼을 구하자
    find_number(square_matrix, 0);  // 3x3 행렬에서 0을 찾았으니 4x4 행렬에서 찾는 for문은 건너뜀
    find_number(square_matrix, -1);
    // 3x3 행렬에서 -1이 없기 때문에 if (arr[i][j]==n)이 절대 true가 되지 않음
    // 3x3 행렬을 다 훑은 뒤에 4x4 행렬 반복문 도착. -1을 찾으면 found 레이블로 점프

    return 0;
}

// 가독성을 위해 goto문은 아래로만 점프할 것!!!!