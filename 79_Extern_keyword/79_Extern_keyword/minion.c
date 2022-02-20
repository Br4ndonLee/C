//
//  minion.c
//  79_Extern_keyword
//
//  Created by Brandon on 2022/02/05.
//

#include "minion.h"   // 79_Extern_minion.h 안에 선언된 함수들을 정의하기 위해 인클루드

unsigned int g_hp = 100u;
unsigned int g_strength = 10u;
unsigned int g_gold = 15u;
// 미니언의 체력, 공격력, 골드의 양을 기억하는 전역 변수들을 정의

void go_berserk(void) {     // go_berserk()함수를 정의. 미니언이 더 강해진다.
    g_hp += 50u;
    g_strength += 20u;
}

void add_gold(unsigned int gold) {  // add_gold()함수를 정의
    g_gold += gold;
}
