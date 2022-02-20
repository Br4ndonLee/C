//
//  memory.c
//  118_Array_Overlap
//
//  Created by Brandon on 2022/02/08.
//

#include "memory.h"

int is_overlap(int nums1[], const size_t length1, int nums2[], const size_t length2) {
    return (nums1 <= nums2     // 만약 nums1(주소)가 nums2(주소) 이하라면
/* 만약 첫 번째 배열의 시작 위치가 두 번째 배열의 시작위치보다 작다면, 왼쪽에 있다면
 첫 번쨰 배열의 끝나는 위치가 두 번째 배열의 시작 위치보다 오른쪽에 있는지 비교.
 첫 번째 배열의 시작, 끝 위치가 있을때 두 번째 배열의 시작 위치가 이 중간에 있다는 의미*/
    
        ? nums1 + length1 > nums2   // nums1 + length1이 nums2보다 큰지 검사한다.
    // 두 배열이 겹치지 않기 위해서는 nums1 + length1이 nums2 이하여야 한다. 만약 그렇지 않다면, 그건 두 배열이 겹친다는 의미
        : nums2 + length2 > nums1);
    // 마찬가지로 nums2가 nums1보다 작다면 nums2 + length2가 nums1 보다 큰지 검사
}
