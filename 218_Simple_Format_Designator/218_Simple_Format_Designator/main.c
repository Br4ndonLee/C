//
//  main.c
//  218_Simple_Format_Designator
//
//  Created by Brandon on 2022/02/24.
//

#include "simpleio.h"

int main (void) {
    printf_simple("c\n", 'A');
    printf_simple("d\n", 10);
    printf_simple("s\n", "Hello");
    /* 3개의 서식 지정자만을 지원할 건데 % 표시도 생략할 것이다.
     c는 문자 하나 출력
     d는 unsigned int형
     s는 C 스타일 문자열
     \n은 실제로 줄 바꿈을 해준다. 우리가 지원하는 서식 지정자 중에 하나가 아니기 때문 */
    
    printf_simple("\n");
    // printf()와 달리 이 함수에 매개변수 하나만 전달해줘도 clang 컴파일러가 경고를 하지 않음. 그 경고는 clang이 printf() 함수가 무슨 일을 하는 함수인지 알기 때문에 과도의 친절을 베풀어 준 것 뿐. clang 컴파일러는 우리 함수에 대해서는 전혀 알지 못한다.
    printf_simple("c d s\n", 'A', 10, "Hello");
    // 스페이스도 서식 지정자가 아니기에 그대로 출력
    
    return 0;
}
