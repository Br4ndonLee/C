//
//  vector.h
//  135_Vector_add
//
//  Created by Brandon on 2022/02/09.
//

#ifndef vector_h
#define vector_h

#define VECTOR_LENGTH (3)

void add_vec3(const int* v1, const int* v2, int* out_v3);
// 두 벡터 v1, v2를 더해 다른 벡터 v3에 대입하는 함수. 3개짜리 배열을 더하는 것이기 때문에 3개짜리 배열을 반환할 수 없기 때문에 입력값, 출력값을 포인터로 전달해 준다.
// v1, v2는 const가 붙어서 바꿀 수 없다. v3는 바꿀 수 있는 배열


#endif /* vector_h */
