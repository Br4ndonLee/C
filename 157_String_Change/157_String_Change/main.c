//
//  main.c
//  157_String_Change
//
//  Created by Brandon on 2022/02/12.
//

#include <stdio.h>
#include "string_utils.h"

int main(void) {
    char str[20] = "Fucking C Memory";
    
    printf("Is space alphabet? : %s\n", is_alpha(' ') ? "Yes" : "NO");  // No
    // 공백 문자는 알파벳이냐? -> NO
    
    printf("m in uppercase : %c\n", to_upper('m'));     // M
    printf("W in lowercase : %c\n", to_lower('W'));     // W
    // to_upper와 to_lower 함수가 제대로 작동하는지 확인
    
    string_toupper(str);
    printf("Uppercase : %s\n", str);    // WELCOME TO C
    // 문자열 전체 대문자
    
    string_tolower(str);
    printf("Lowercase : %s\n", str);    // welcome to c
    // 다시 소문자
    
    return 0;
}

