//
//  string_comparer.c
//  240_String_Comparer
//
//  Created by Brandon on 2022/02/28.
//

#include <string.h>
#include "string_comparer.h"

// 예전에 봤던 시그지처하고 같다.
int compare_string(const void* a, const void* b) {
    const char** w0 = (const char**)a;
    const char** w1 = (const char**)b;
    /* 이중 포인터로 캐스팅. qsort()는 배열 속에 저장된 각 요소들의 주소를 전달해 줌. 이번에 배열에 저장되어 있는 데이터는 const char* 형
     따라서 const char*형의 주소는 const char**이다. */
    
    return strcmp(*w0, *w1);
    /* 이제 간단히 strcmp()를 호출해서 0, 음수, 양수 중에 하나를 올바르게 반환하면 끝 */
}

// 차이점은 매개변수 word의 순서가 바뀌는게 끝
int compare_string_desc(const void* a, const void* b) {
    const char** w0 = (const char**)a;
    const char** w1 = (const char**)b;
    
    return strcmp(*w1, *w0);
    // 이렇게 하지 않고 return -strcmp(*w0, *w1);을 해도 된다.
}
