//
//  buffered_print.c
//  153_String_Buffer_Print
//
//  Created by Brandon on 2022/02/11.
//

#include <stdio.h>
#include <string.h>

#include "buffered_print.h"

#define BUFFER_LENGTH (32)  // 버퍼의 크기는 32

static size_t s_buffer_index = 0u;      // 버퍼 속 현재 위치 변수
static char s_buffer[BUFFER_LENGTH];    // 버퍼가 어디까지 차 있는지 표시하는 버퍼 속 위치
/* BUFFER_LENGTH를 사용하여 실제 버퍼를 만들고, 버퍼 속 현재 위치도 선언
 버퍼를 계속 기억해야 하기 때문에 함수 안에 있는 버퍼는 안된다. 지역변수라 날아간다.
그래서 함수 밖에 만들어 놨고, 외부의 다른 파일에서 접근 못하게 하려고 static 사용 */

void buffered_print(const char* src) {
    size_t num_left;
    const char* p = src;    // src 문자열 속에서 현재 위치를 기억할 포인터
    // 반복문에 사용할 변수들을 선언 및 정의
    
    num_left = strlen(src);
    // 아직 src에서 버퍼로 복사하지 않은 글자소. 처음에는 src의 길이와 동일
    // strlen()함수를 사용하기 위해서 string.h 인클루드
    
    while (num_left > 0) {  // str의 모든 문자를 버퍼로 복사할 때까지 반복문 진행
        size_t copy_count = BUFFER_LENGTH - 1 - s_buffer_index;
        // 버퍼로 복사할 문자 수 = 버퍼의 최고 크기 - 널 캐릭터 - 현재 버퍼에 몇 개 들어갔는지
        // 최대값은 31. 버퍼 끝에 널 문자를 넣어야 해서
        
        const int buffer_empty = s_buffer_index == 0;
        
        if (num_left < copy_count) {    // 버퍼로 복사할 문자수보다 버퍼 안에 남은 공간이 크면
            copy_count = num_left;      // num_left만큼 그대로 복사
        }
        
        s_buffer_index += copy_count;
        // 버퍼 속 현재 위치를 copy_count만큼 증가시킴
        num_left -= copy_count;
        // src에는 (num_left - copy_count)만큼의 문자가 남음. 몇 개 남았는지 차감
        
        if (buffer_empty) {
            strncpy(s_buffer, p, copy_count);
            s_buffer[s_buffer_index] = '\0';    // 복사한 마지막 문자 뒤 널 문자
        /* 만약 버퍼가 비어있다면 src 문자열에서 버퍼로 copy_count만큼의 문자열을 복사해야 함
         (strncpy를 해서 실제 copy_count만큼 카피하고 안전하기 위해서 마지막 s_buffer_index에
         벌써 플러스(+)를 해놨다)*/
        } else {
            strncat(s_buffer, p, copy_count);
        /* 버퍼가 비어있지 않다면 copy_count만큼의 문자를 덧붙여줌.
         날려버리지 않고 뒤부터 복사하기 위해 strncat()을 이용
         (strncat은 자동적으로 널 붙여줘서 따로 널 캐릭터를 넣지 않았다) */
        }
        
        p += copy_count;    // src 속에서의 위치를 업데이트
        
        if (s_buffer_index == BUFFER_LENGTH - 1) {
            printf("%s\n", s_buffer);
            s_buffer_index = 0;
        /* 버퍼가 꽉 찼다면 s_buffer를 출력하고 버퍼 속 위치를 0으로 리셋 */
        }
    }   // while 반복문 돌아가면 src 안에 문자가 남아있지 않을 때까지(num_left가 0이 될 때까지) 반복
}

