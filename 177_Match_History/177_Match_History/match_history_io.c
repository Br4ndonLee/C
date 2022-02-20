//
//  match_history_io.c
//  177_Match_History
//
//  Created by Brandon on 2022/02/17.
//

#define _CRT_SECURE_NO_WARNINGS
// 윈도우에서 clang을 사용하면 파일 및 문자열 관련 함수를 사용할 때마다 그 대신 _s가 달린 함수를 쓰라는 컴파일러 경고가 나온다. 이 경고를 끄기 위해 사용

#include <stdio.h>
#include <string.h>

#include "match_history_io.h"

#define LINE_LENGTH (4096)

void write_match_history(char* buffer, size_t buffer_size, const char* names[], const int wins[], const int losses[], const float kills[], const float deaths[], const float assists[], size_t count)
// size_t buffe_size 함수를 호출할 때 전달했던 버퍼의 크기가 buffer_size다. size_t count는 챔피언의 수
{
    char line[LINE_LENGTH];
    // 한 줄에 한 챔피언의 전적을 저장할 것이기 때문에 줄의 길이를 충분히 길게 잡아줘야 한다.
    size_t i;
    size_t remaining_buffer_size;
    /* 이 변수를 사용해서 아직 버퍼 속에 남아있는 공간을 기억해둠. 버퍼 오버플로를 막기 위해 */
    
    remaining_buffer_size = buffer_size -1;
    // 초기화는 buffer_size - 1. 널 문자가 들어갈 곳이 필요하기 때문에
    buffer[0] = '\0';
    // C에서 빈 문자열을 정의하는 방법
    
    for (i = 0; i < count; ++i) {
        size_t num_written;
        
        sprintf(line, "%8s %.2f %.2f %.2f %d %d\n",
                names[i],   // 이름을 8자까지 제어
                kills[i], deaths[i], assists[i],    // 숫자의 경우 소수점 이하 2자리까지
                wins[i], losses[i]);
        /* 포맷을 예쁘게 해서 line에 쓰기. 문자열형 인자인 경우 그 길이를 확실히 제어해야만 버퍼 오버플로를 막을 수 있다.
         첫 번째 챔피언을 출력하면 '***Akali*6.11*3.65*4.63*52*62' (*는 빈칸) */
        
        num_written = strlen(line);
        // strlen을 사용해서 line에 몇 글자가 저장됐는지 알아낸다.
        if (num_written > remaining_buffer_size) {
            break;
        }
        // 이 결과를 이용해서 버퍼에 새로운 줄을 저장하기에 충분한 공간이 있는지 확인할 것임
        // 공간이 충분치 않다면 break
        
        strcpy(buffer, line);
        // line에 들어 있는 내용을 버퍼에 복사
        buffer += num_written;
        // 이제 널 문자가 있는 위치로 버퍼를 이동함. buffer는 포인터여서 가능
        // strcat 함수와 똑같은 일을 한다. 전체 버퍼를 처음부터 훑으면서 널 문자의 위치를 찾을 필요가 없으니 조금 더 효율적이다.
        /* 보통 상황에서 버퍼는 시작부터 덮어 쓰기 때문에 그걸 방지하기 위해 버퍼의 위치를 널 캐릭터로 이동시켜 줬다. */
        remaining_buffer_size -= num_written;
        // 버퍼에 남은 공간을 기억하는 변수 업데이트
    }
}

void read_match_history(char* buffer)
// 이 함수는 위에서 저장해 놓았던 결과를 버퍼로부터 읽어와 약간의 계산을 한 뒤, 모든 결과를 포맷해서 보여줌
{
    const char* DELIM = "\n";
    char* tokenizer;
    // DELIM이 나오는 이유 : 토큰화
    // 데이터는 엄청 큰 문자열 하나에 저장되어 있다. 이것을 한 줄씩 읽으려면 \n 문자를 구분문자로 사용해서 문자열을 분리시켜야 함
    
    printf("%8s %7s %7s %7s %7s %6s %6s %9s\n",
           "Champ", "Kills", "Death", "Assists",
           "KDA", "Wins", "Losses", "Win Ratio");   // 새로 계산할 데이터
    // 표 제목 출력
    
    tokenizer = strtok(buffer, DELIM);
    while (tokenizer != NULL) {
    // 한 줄씩 토큰화, while 문 제일 마지막에서 토큰 업데이트. 토큰이 더 이상 없으면 strtok가 NULL 반환
        char name[LINE_LENGTH];
        // 일단 충분히 크긴 한데 누군가 버퍼 속에서 이름을 굉장히 길게 바꿔놓았을 수도 있다. 따라서 100% 안전하다고 할 수는 없다.
        float kills;
        float deaths;
        float assists;
        int wins;
        int losses;
        
        float kda;
        float win_ratio;
        
        if (sscanf(tokenizer, "%s %f %f %f %d %d",
                   name, &kills, &deaths, &assists,
                   &wins, &losses) != 6) {
            
            continue;
        };
        // 문자열로부터 6개 값을 모두 읽어오기. 읽기 연산이 실패하지 않았는지 확인. 실패했다면 이 챔피언은 그냥 패스
        
        kda = (kills + assists) / deaths;
        win_ratio = wins * 100.0f / (wins + losses);
        // KDA와 승률 계산
        
        printf("%8s %7.2f %7.2f %7.2f %7.2f %6d %6d %8.2f%%\n",
               name, kills, deaths, assists,
               kda, wins, losses, win_ratio);

        tokenizer = strtok(NULL, DELIM);
        // 더 이상 읽을 토큰이 없을 떄까지 반복
    }
}
