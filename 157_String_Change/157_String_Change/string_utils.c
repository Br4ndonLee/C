//
//  string_utils.c
//  157_String_Change
//
//  Created by Brandon on 2022/02/12.
//

#include "string_utils.h"

int is_alpha(int c) {
    return (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z');
}
/* 글자가 아스키 코드여서 A와 Z 사이, a와 z 사이에 있는지만 검사하면 됨 */

int to_upper(int c) {
    if (is_alpha(c)) {
        return c & ~0x20;   // 비트 마스킹. c로부터 32를 빼는 것과 마찬가지
    }
/* 문자가 알파벳인지 검사. 알파벳이 아니라면 아무것도 안하고 그냥 반환
 알파벳이라면 대문자로 변화해서 반환
 0x20은 십진수로 32. 32는 2의 승수이기 때문에 비트 패턴으로 보면 딱 1이 들어가 있다.
 즉 그 비트만 32가 들어가는 비트, 그거 하나만 바꾸겠다.
 32, 이것은 아스키 값으로 보면 동일한 대문자와 소문자 간의 차이
 a와 z의 비트 패턴은 110 0001, 111 1010
 32를 나타내는 비트는 010 0000을 빼면 그 알파벳의 대문자
 " ~ " 물결 표시는 뒤집는거. bitwise NOT. 010 0000을 뒤집으면 101 1111
 AND(&)를 하면 1로 되어 있는 건 다 그대로 원본값을 가져오고 0으로 되어있는건 지운다.
 비트 패턴을 알면 간단하게 변환할 수 있다. -32, +32보다 훨씬 바른 방법*/
    
    return  c;
}

int to_lower(int c) {
    if (is_alpha(c)) {
        return c | 0x20;
    }
    
    return c;
}
// 사실 상 c에 32를 더하는 것

void string_toupper(char* str) {
// to_lower와 to_upper 함수를 만들어 뒀으니 string_toupper 함수 만드는 건 매우 쉽다.
    while (*str != '\0') {
        *str = to_upper(*str);
        ++str;
    // 해야 할 일이라곤 널 캐릭터를 볼때까지 각 문자마다 to_upper() 함수를 호출하는 것
    }
}

void string_tolower(char* str) {
    while (*str != '\0') {
        *str = to_lower(*str);
        ++str;
    }
}
