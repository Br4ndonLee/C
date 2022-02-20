//
//  main.c
//  135_Vector_add
//
//  Created by Brandon on 2022/02/09.
//

#include <stdio.h>
#include "vector.h"

int main(void) {
    const int v1[VECTOR_LENGTH] = {1, 2, 3};
    const int v2[VECTOR_LENGTH] = {1, 2, 8};
    int v3[VECTOR_LENGTH];
    // v1, v2 만들고 v3는 빈 곳으로
    
    add_vec3(v1, v2, v3);
    // v1, v2를 더한다. 이미 배열이기 때문에 이름을 넣는 것만으로 주소가 들어간다.
    
    printf("v3 : %d, %d, %d\n", v3[0], v3[1], v3[2]);
    
    return 0;
}
