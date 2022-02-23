//
//  simpleio.c
//  218_Simple_Format_Designator
//
//  Created by Brandon on 2022/02/24.
//

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "simpleio.h"

static void print_int_recursive(unsigned int val) {
// 이 함수는 스스로를 호출하는 재귀 함수. static을 붙인 건 이 파일 안에서만 호출할 함수이기 때문.
// 가장 오른쪽 자리에서 시작해서 더 이상 유효한 비트가 없을 때까지 왼쪽으로 한 자리씩 이동한다.
    if (val == 0) {
        return;
    }
    // val ==0이면 더 이상 유효한 비트가 없단 이야기. 따라서 재귀에서 탈출
    
    print_int_recursive(val / 10);
    // 그게 아니라면 이제 곧 완성할 이 마법 같은 함수를 호출하여 현재 자리보다 위에 있는 자리들을 다 출력해달라 부탁한다.
    putchar('0' + val % 10);
    // 그리고 나서 현재 자리를 출력. '0'(문자 0)에 현재 자리의 수를 더하는게 보이는데. '0'의 아스키 코드가 뭔지는 모르겠지만 이렇게 하면 언제나 현재 자리의 수에 맞는 아스키코드를 구할 수 있다.
}
// 참고로 이 함수는 unsigned int만 가능. 음수도 처리하고 싶다면 그 절댓값에 같은 로직을 실행한 뒤 앞에 음수 기호만 붙여주면 된다.

static void print_int(unsigned int val) {
    if (val == 0) {
        putchar('0');
        return;
    }
    // 값이 0이면 그냥 0을 출력하고 반환
    print_int_recursive(val);
    // 그게 아니라면 print_int_recursive() 함수를 호출
}


void printf_simple(const char* format, ...) {
// 이 함수의 시그니처는 printf(0와 동일하다. ...로 많은 변수를 받는다.
    va_list ap;
    
    va_start(ap, format);
    // va_list가 첫 번째 가변 인자를 가리키도록 초기화 중. 그러려면 제대로 매개변수를 인자로 넣어줘야 한다.
    {
        while (*format != '\0') {   // 이 속에 있는 문자를 하나씩 읽을 것
            unsigned val;
            const char* str;
            
            switch (*format) {  // 이 문자는 서식 지정자일 수도 보통 문자일 수도 있다.
                case 's' :  // 문자열이라면
                    str = va_arg(ap, const char*);
                    while (*str != '\0') {
                        putchar(*str++);
                    }
                    break;
                // 이것을 conat char* 형으로 읽은 뒤 그 문자열을 한 문자씩 출력하낟. printf()를 쓰지 않는 이유는 쓴다면 그냥 반칙이니까
                    
                case 'c':
                    val = va_arg(ap, unsigned int);
                    putchar(val);
                    break;
                // char는 쉽다. 그냥 읽은 뒤 putchar()에 넣어주면 끝. 하지만 char 인자는 int로 승격된다. 따라서 int로 읽어와야 한다.
                    
                case 'd':
                    val = va_arg(ap, unsigned int);
                    print_int(val);
                    break;
                /* % 10 연산 뒤 그 숫자를 오른쪽으로 1자리만큼 이동시켜주는 것을 반복하면 한 자리씩 출력은 가능. 그러나 결과는 좌우가 뒤집힌 숫자
                 재귀 함수가 이 숫자르 ㄹ다시 좌우로 뒤집어 줄 수 있다.*/
                    
                default:
                    putchar(*format);
                    break;
            }
            
            ++format;
        }
    }
    va_end(ap);
}
