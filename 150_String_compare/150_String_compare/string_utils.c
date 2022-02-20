//
//  string_utils.c
//  150_String_compare
//
//  Created by Brandon on 2022/02/11.
//

#include <ctype.h>
#include "string_utils.h"

int string_case_insensitive_compare(const char* str0, const char* str1) {
// 함수의 구현부
    int c1;
    int c2;
    
    c1 = tolower(*str0);
    c2 = tolower(*str1);
    // str0과 str1의 첫 글자를 소문자로 바꿔 c1, c2초기화
    // 이 두 변수를 사용해 한 글자씩 비교
    // tolower() 함수는 <ctype.h>헤더에 있다
    
    while (c1 != '\0' && c1 == c2) {
    // c1이 널 문자가 아니고 c1과 c2가 같다면
        c1 = tolower(*++str0);
        c2 = tolower(*++str1);
        // str0, str1에서 다음 글자들을 가져와 소문자로 바꿔 c1, c2에 대입
        // 사실상 str0과 str1을 동시에 훑으면서 한 글자씩 비교하는 것
    }
    
    if (c1 == c2) {
        return 0;
    // 반복문을 탈출했다면 c1이 널 문자거나 c1 != c2 라는 의미
    // c1 == c2 면 c1, c2 모두 널 문자
    }
    
    return c1 > c2 ? 1 : -1;
    // c1과 c2가 다르다면 c1, c2를 비교하여 1 혹은 -1을 반환
}
