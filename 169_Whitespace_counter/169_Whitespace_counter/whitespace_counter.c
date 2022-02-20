//
//  whitespace_counter.c
//  169_Whitespace_counter
//
//  Created by Brandon on 2022/02/16.
//

#include <ctype.h>
#include <stdio.h>
#include "whitespace_counter.h"

void print_whitespace_stat(void) {
// 사용자 입력으로부터 들어오는 공백문자의 수를 세보자.
// 공백문자 하면 보통 스페이스('  ')만 생각하는데 그 외 다른 것들도 있다.
    int c;      // 'c'는 표준 입력장치로부터 읽어오는 문자를 저장
    size_t num_whitespaces = 0u;        // 공백문자의 수
    size_t num_newlines = 0u;           // 새 줄 문자 \n도 공백문자
    
    c = getchar();
    while (c != EOF) {                  // EOF에 도달할 때까지 한 글자씩 읽음
        if (isspace(c)) {       // 공백문자를 찾는 것은 isspace 함수가 담당. ctype.h에 있다. \n, \t 등도 공백문자
            ++num_whitespaces;  // 공백문자의 수를 기억하는 변수를 증가
            
            if (c == '\n') {    // 별도로 새 줄 문자의 수도 셈
                ++num_newlines;
        // 공백 문자의 수만 셀 것이기 때문에 공백 문자가 아닌 다른 문자는 무시
            }
        }
        
        c = getchar();
    }
    
    printf("# whitespaces : %5zu\n", num_whitespaces);
    printf("# new lines : %5zu\n", num_newlines);
}   // 공백 문자와 새 줄 문자의 개수를 출력
