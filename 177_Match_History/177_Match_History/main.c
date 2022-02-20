//
//  main.c
//  177_Match_History
//
//  Created by Brandon on 2022/02/17.
//

#include <stdio.h>
#include "match_history_io.h"

#define MATCH_COUNT (5)
#define NUM_CHAMPS (5)

#define BUFFER_LENGTH (4096)

int main(void) {
    const char* names[NUM_CHAMPS] = {
        "Akali",
        "Sylas",
        "Yasuo",
        "Leblanc",
        "Aatrox"
    };
    /* 이 챔피언들의 게임 전적을 제대로 포맷해서 문자열 버퍼에 쓰고 싶음
    NUM_CHAMPS는 위에서 5로 define 되어 있다. 이렇게 하면 요소 대입법으로 여러 배열들을 초기화 할 때 요소 수가 일치하지 않는 실수을 일찍 잡을 수 있다. */
    const int wins[NUM_CHAMPS] = {
        52, 55, 28, 34, 32
    };
    const int losses[NUM_CHAMPS] = {
        62, 38, 31, 21, 21
    };
    // 각 챔피언의 승수와 패수를 정의
    
    const float average_kills[NUM_CHAMPS] = {
        6.11f, 6.62f, 4.81f, 5.95f, 5.19f
    };
    const float average_deaths[NUM_CHAMPS] = {
        3.65f, 3.87f, 3.97f, 3.05f, 3.23f
    };
    const float average_assists[NUM_CHAMPS] = {
        4.63f, 6.68f, 4.47f, 5.25f, 6.02f
    };
    // 각 챔피언의 평균 kill, death, assist 수
    
    char buffer[BUFFER_LENGTH];
    /* 모든 게임 전적을 문자열 버퍼 하나에 저장할 건데 개념 상 한 파일에 저장하는 것과 같다고 생각하자 */
    
    write_match_history(buffer, BUFFER_LENGTH, names, wins, losses, average_kills, average_deaths, average_assists, NUM_CHAMPS);
    // write_match_history 함수가 이 버퍼에 모든 전적을 저장
    // BUFFER_LENGTH도 함수 인자로 전달해 줘서 이 함수가 버퍼 범위를 넘어서 쓰는 경우를 방지
    
    read_match_history(buffer);
    // 이 함수는 문자열 버퍼에서 전적을 읽어서 간략한 계산 몇 개를 한 뒤, 그 모든 결과를 콘솔창에 보여줌
    
    return 0;
}
