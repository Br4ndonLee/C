//
//  byte_conversion_chart.c
//  161_Byte_Conversion_chart
//
//  Created by Brandon on 2022/02/14.
//
#include <stdio.h>

#include "byte_conversion_chart.h"

#define SCALE (1024.0f)

#define BYTE (1.0f)
#define KB (SCALE * BYTE)
#define MB (SCALE * KB)
#define GB (SCALE * MB)
#define TB (SCALE * GB)
#define PB (SCALE * TB)

#define LENGTH (6)
// 매크로를 무더기로 정의. 1024씩 증가시켜 나가는 코드


static const char* const DATA_STORAGE_NAMES[LENGTH] = {"Byte", "Kilobyte", "Megabyte", "Gigabyte", "Terabyte", "petabyte" };
// 데이터 단위들을 변환할 때 사용할 표를 만들 예정

void print_byte_conversion_chart(void) {
    double divisor = 1.0;
    size_t i;
    
    printf("%9s", "");
    
    for (i = 0; i < LENGTH; ++i) {
        printf("%17s ", DATA_STORAGE_NAMES[i]);
    }
    // 표의 제목 줄을 출력
    
    printf("\n%4s", "");
    
    for (i = 0; i < LENGTH; ++i) {
        printf("%s %17.15f %17.12f %17.9f %17.6f %17.3f %17.0f\n", DATA_STORAGE_NAMES[i], BYTE / divisor, KB / divisor, MB / divisor, GB / divisor, TB / divisor, PB / divisor);
    // 각 데이터 단위의 변환율을 출력
    // 첫 번째 행은 바이트로 변환했을 때 크기, 두 번째는 킬로바이트, 세 번째는 메가바이트 등
    // %17.12f 는 최소 너비 17에 소수점 이하 정밀도 12
        divisor *= SCALE;
    }
}

void print_byte_conversion_chart_scientific(void) { // 바로 전에 본 함수랑 동일. 차이점은 변환값에 과학적 표기법 사용
    double divisor = 1.0;
    size_t i;
    
    printf("%9s", "");
    
    for (i = 0; i < LENGTH; ++i) {
        printf("%17s ", DATA_STORAGE_NAMES[i]);
    }
    
    printf("\n%4s", "");
    
    for (i = 0; i < LENGTH; ++i) {
        printf("%s %17.2e %17.2e %17.2e %17.2e %17.2e %17.2e\n", DATA_STORAGE_NAMES[i], BYTE / divisor, KB / divisor, MB / divisor, GB / divisor, TB / divisor, PB / divisor);
    // 차이점은 변환 값에 과학적 표기법 사용. "e"
    // 여전히 최소 너비 17을 사용하나 소수점 이하 정밀도는 2
        
        divisor *= SCALE;
    }
}
