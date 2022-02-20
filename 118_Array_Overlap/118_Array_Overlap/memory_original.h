//
//  memory.h
//  118_Array_Overlap
//
//  Created by Brandon on 2022/02/09.
//

#ifndef memory_h        // 인클루드 가드 사용
#define memory_h

#define TRUE (1)        // 매크로를 사용해 true, false 반환 정의
#define FALSE (0)

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
// 배열의 길이를 계산하는 매크로를 정의

int is_overlap(int nums1[], const size_t length1, int nums2[], const size_t length2);
// 두 배열이 겹치는지 검사하는 함수를 선언.
// 배열을 2개 받는다. nums1과 nums2. 이 두 배열이 메모리 위치가 겹치는 부분이 있냐 그것을 보고 싶은 함수

#endif /* memory_h */
