//
//  print_ascii_table.c
//  160_Draw_ASCII_table
//
//  Created by Brandon on 2022/02/14.
//

#include <stdio.h>
#include "print_ascii_table.h"

void print_ascii_table(void) {
    const int MIN_ASCII = 32;       // 화면에 출력 가능한 가장 작은 아스키 코드 문자 번호
    const int MAX_ASCII = 126;      // 화면에 출력 가능한 가장 큰 문자
    const int NUM_CHARS = MAX_ASCII - MIN_ASCII + 1;    // 실제 총 몇 개의 문자가 있는지
    const int NUM_COLS = 3;         // 컬럼 3개로 그려보자.
    const int NUM_ROWS = (NUM_CHARS + NUM_COLS - 1) / NUM_COLS;     // 총 행 수. -1을 하는 이유는 실제 아스키 표의 마지막 줄에서 마지막 열이 비어있다. 그래서 나누기 3을 하면 실제보다 한 줄이 조금 나와서 그것까지 나오게 하기 위해 NUM_COLS - 1을 더한 다음에 나누기
    // 올림 연산 하기 위해
    // 아스키 표를 만들 때 도움이 될 만한 상수들을 정의
    
    int r;
    int ch;
    // for 문에서 사용할 변수
    
    printf("Dec Hex  Char\tDec Hex   Char\tDec Hex   Char\n");
    // 표의 제목줄 출력. \t는 탭 문자
    
    for (r = 0; r < NUM_ROWS - 1; ++r) {    // 각 줄을 그리는데 마지막 줄은 생략
        ch = MIN_ASCII + r;
        printf("%03d %#X %c\t", ch, ch, ch);
        // 첫 번째 열의 글자를 10진수 숫자, 16진수 숫자, 문자로 출력
        
        ch += NUM_ROWS;
        printf("%03d %#X %c\t", ch, ch, ch);
        // 두 번째 열의 문자에도 같은 일을 함. NUM_ROWS를 더하고 있는 이유는 각 열에 들어가는 문자의 수가 행의 수와 같기 때문
        
        ch += NUM_ROWS;
        printf("%03d %#X %c\t", ch, ch, ch);
        // 세 번째 열도 출력
    }
    
    /* Last row doesn't have all colums */
    for (ch = MIN_ASCII + r; ch <= MAX_ASCII; ch += NUM_ROWS) {
        printf("%03d %#X %c\t", ch, ch, ch);
    /* 마지막 행은 따로 출력함. 출력할 열이 3개가 안 되기 때문
     앞서 돌렸던 for 문에서 이미 r값이 마지막 행을 가리키도록 없데이트 되었음. 이제 MAX_ASCII까지 출력만 하면 됨 */
    }
}
