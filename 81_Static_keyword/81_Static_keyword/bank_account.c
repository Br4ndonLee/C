//
//  bank_account.c
//  81_Static_keyword
//
//  Created by Brandon on 2022/02/05.
//

#include "bank_account.h"

unsigned int g_chequing = 0u;
unsigned int g_saving = 0u;
// 일반 통장과 저축 통장을 나타내는 전역변수 정의
static unsigned int s_fee = 20u;
/* 수수료를 나타내는 s_fee 정적 전역 변수를 정의
static 키워드를 사용해서 다른 파일들이 이 변수에 접근하는 것을 막음.
은행 직원만 수수료를 변경할 수 있기 때문
s_fee의 범위는 81_bank_account.c로 한정 */

void deposit_into_chequing(const unsigned int amount) {     // 함수 정의
    // this could underflow
    g_chequing += (amount - s_fee);
}

void deposit_into_saving(const unsigned int amount) {
    // this could underflow
    g_saving += (amount - s_fee);
    // 매개 변수로 받은 금액보다 s_fee가 클 경우 언더플로 발생 가능
}

static void set_fee(const unsigned int fee) {   // s_fee용 setter 함수 set_fee()를 정의
    s_fee = fee;
}
