//
//  main.c
//  150_String_compare
//
//  Created by Brandon on 2022/02/11.
//

#include <stdio.h>
#include "string_utils.h"

int main(void) {
    int diff;
    
    diff = string_case_insensitive_compare("hello", "HELL");
    // hello와 HELL을 비교. 반환값은 1. hello 문자열에 아직 'o'가 남아있기 때문
    printf("hello to HELL : %d\n", diff);   // 1
    
    diff = string_case_insensitive_compare("hello", "yellow");
    // hello와 yellow을 비교. 반환값은 -1.  'h'가 'y'보다 작기 때문
    printf("hello to yellow : %d\n", diff); // -1
    
    diff = string_case_insensitive_compare("hello", "HELLO");
    // hello와 yellow을 비교. 반환값은 0.  대소문자 빼면 일치하기 때문
    printf("hello to HELLO : %d\n", diff);  // 0

    return 0;
}
