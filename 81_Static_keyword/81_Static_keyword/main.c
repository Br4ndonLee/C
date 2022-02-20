//
//  main.c
//  81_Static_keyword
//
//  Created by Brandon on 2022/02/05.
//

#include <stdio.h>
#include "bank_account.h"

extern unsigned int g_chequing;
extern unsigned int g_saving;
extern unsigned int s_fee;
extern void set_fee(const unsigned int fee);
// 81_bank_account.c에 들어있는 전역 변수들을 81_Static_keyword.c에서 사용하기 위해 extern 키워드로 선언

int main(void) {
    printf("g_chequing : %u\n", g_chequing);    // 0
    printf("s_saving : %u\n", g_saving);        // 0

    // this is a linker error
    // printf("s_fee : %u", s_fee);     s_fee를 출력하려고 했는데 이렇게 하면 링커 오류. static이기 때문

    deposit_into_chequing(300u);
    deposit_into_saving(700u);
    // this is a linker error
    // set_fee(100)         s_fee와 같이 set_fee 함수 또한 81_bank_account.c를 제외한 다른 파일에서 사용할 수 없음

    printf("g_chequing : %u\n", g_chequing);    // 280
    printf("s_saving : %u\n", g_saving);        // 680
    
    // this is a linker error
    // printf("s_fee : %u", s_fee);

    return 0;
}
