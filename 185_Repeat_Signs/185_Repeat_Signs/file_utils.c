//
//  file_utils.c
//  185_Repeat_Signs
//
//  Created by Brandon on 2022/02/18.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "file_utils.h"

#define TRUE (1)
#define FALSE (0)

void print_with_repeats(const char* filename)
{
// 악보에 등장하는 도돌이표를 흉내내보자. |: <음표 음표 음표> :| 이것 처럼
// 이 함수는 파일을 열어서 그 속에 있는 내용을 한 글자씩 stdout에 출력함. 그러다가 한 쌍의 ':' 문자들로 좌우가 감싸진 구간ㅇ르 만나면 그 구간에 있는 문자들은 두 번 출력
// 예 : 'ab:CDE:fg:h:' -> 'abCDECDEfgHH'
    long pos = -1L;         // 나중에 되돌아와 반복을 시작할 위치를 기억하는 함수. 아직 위치 없으므로 -1로 초기화
    int repeating = FALSE;  // 현재 위치를 처음 방문하는 건지 아니면 두 번째인지 말해줌
    int c;
    FILE* file;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("error while opening");
        return;
    // 파일을 읽기 전용, 텍스트 모드로 엶. 이진 파일을 stdout에 출력하는건 말이 안됨
    }
    
    c = fgetc(file);
    while (c != EOF) {      // EOF 만날 때까지 한 글자씩 읽음
        if (c != ':') {     // 읽은 문자가 ':' 아니면 그 문자 출력 후 다음 문자로
            putchar(c);
            goto next_char;
        }
        
        if (!repeating) {       // 반복 모드가 거짓이니 ':' 사이에 있는 문자들은 처음 출력하는 얘들
            if (pos < 0) {      // pos가 유효한 파일 위치가 아니면 현재 문자는 반복할 구간을 여는 도돌이표
                /* start mark */
                pos = ftell(file);  // 현재 파일 속 위치를 가져와서 기억해 둠
                // 이미 ':'를 읽었다. 따라서 파일 위치를 읽으면 이는 ':' 바로 다음에 오는 문자를 가리킴
                perror("error while getting start position");
                break;
                // ftell이 위치를 찾아오는데 실패하면 그냥 함수 실행을 관둔다
            } else {    // pos가 유효한 위치를 가지고 있다면(즉, 음수가 아니라며) 여는 도돌이표를 이미 지났단 의미. 따라서 현재 문자는 닫는 도돌이표다.
                /* end mark */
                repeating = TRUE;
                
                if (fseek(file, pos, SEEK_SET) != 0) {
                // 이 경우에는 pos 위치로 돌아간다. 그리고 반복 모드를 거짓으로 바꿔 다음 번에 다시 ':'를 지나칠 떄는 반복할 필요가 없다는 것을 기억
                    perror("error while fseek() to start position");
                    break;
                }
            }
            
            goto next_char;
        }
        
        /* revisited end mark */
        repeating = FALSE;
        pos = -1;
        // 여기까지 오면 ':' 사이에 있는 모든 문자들을 출력한 후다. 어떤 구간을 반복할 때 여는 도돌이표 바로 다음 문자부터 시작하니 그 다음에 ':'를 다시 만나면 이것은 닫는 도돌이표를 두 번째 만나는 경우.
        // 이제 반복 모드를 끄고 pos를 다시 -1로 리셋하여 다른 도돌이표 구간을 만날 준비를 함
        
    next_char:
        c = fgetc(file);
    // while 블록 끝나기 바로 전, 여기서 c를 다음 글자로 업데이트
    // goto를 안 쓰면 이 반복문 안에서 사용하는 여러 if 문에서 getchar()를 여러 번 호출해야 함
        // 다음 문자. 어떤 경로를 따라가던 이 코드는 언제나 호출됨
    }
    
    if (fclose(file) == EOF) {
        perror("error while closing");
    }
}
