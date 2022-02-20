//
//  algorithm.c
//  103_Min_Max
//
//  Created by Brandon on 2022/02/06.
//

#include <assert.h>         // assert()를 사용하려면 assert.h를 인클루드 해야함
#include <stddef.h>
#include "algorithm.h"

// pre-condition : Length >= 1  함수의 선조건 : length는 반드시 1 이상이어야 한다.
void get_min_max(const int nums[], const size_t length, int* out_min, int* out_max) {    // get_min_max 함수 정의
    size_t i;
    
    assert(length >= 1);    // 디버그 모드에서만 검사. assert 함수를 사용하여
    
    *out_min = nums[0];
    *out_max = nums[0];
    // 선조건에 따르면 배열이 반드시 1개의 요소는 가지고 있으니 이것을 최솟값, 최댓값으로 두고 시작
    // 어떤 주소에 저장되어 있는 값에 접근하려면 반드시 역참조 연산자를 사용해야 함
    for (i = 1; i < length; ++i) {
    // 두 번째 요소부터 시작해서 nums를 순회하면서 최솟값 및 최댓값을 찾음
        
        if (*out_min > nums [i]) {
            *out_min = nums[i];
        // 만약 nums[i]가 out_min이 가리키는 값보다 작으면 이것이 새로운 최솟값. *out_min으 ㄹ이 값으로 덮어쓴다.
        }
        
        if (*out_max < nums[i]) {
            *out_max = nums[i];
        // 만약 nums[i] out_max가 가리키는 값보다 크면 이것이 새로운 최댓값. *out_max를 이 값으로 덮어쓴다.
        }
    }
    
}
