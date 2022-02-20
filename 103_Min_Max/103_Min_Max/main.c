//
//  main.c
//  103_Min_Max
//
//  Created by Brandon on 2022/02/06.
//

#include <stdio.h>
#include "algorithm.h"

#define LENGTH (5)

int main(void) {
    const int nums[LENGTH] = {3, 10, 9, 8, 7};
    // 길이 5짜리 배열을 선언 및 초기화
    int min;
    int max;

    get_min_max(nums, LENGTH, &min, &max);
    // get_min_max 함수 호출
    // 포인터는 주소를 저장하는 변수. 따라서 get_min_max 함수에 포인터 인자를 넣어주기 위해 &min, &max를 사용

    printf("Min : %d\n", min);
    printf("Max : %d\n", max);

    return 0;
}
