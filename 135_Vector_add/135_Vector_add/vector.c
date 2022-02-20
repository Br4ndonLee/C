//
//  vector.c
//  135_Vector_add
//
//  Created by Brandon on 2022/02/09.
//

#include "vector.h"

void add_vec3(const int* v1, const int* v2, int* out_v3) {
    int i = 0;
    for (i = 0; i < VECTOR_LENGTH; ++i) {
        *out_v3++ = *v1++ + *v2++;
    // v1와 v2의 합을 out_v3에 대입
    // 연산자 우선순위에 따르면 *out_v3++은 *(out_v3++)과 같다
    // 후위 증가 연산자를 사용해서 out_v3를 증가시키므로 역참조 연산 후에 out_v3이 증가한다.
    }
}
