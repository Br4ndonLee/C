//
//  main.c
//  79_Extern_keyword
//
//  Created by Brandon on 2022/02/05.
//

#include <stdio.h>
#include "minion.h"

extern unsigned int g_hp;           // 다른 파일의 전역 변수를 사용하기 위해 extern 키워드를 사용해 선언
extern unsigned int g_strength;

int main(void) {
    printf("Normal minion : \n");           // 미니언의 체력과 공격력 출력
    printf("hp : %u\n", g_hp);              // 100
    printf("strength : %u\n", g_strength);  // 10
    // this does not compile. 파일 안에 g_gold를 선언하지 않았기 때문
    // printf("gold : %u\n", g_gold);       // 15

    printf("\n");

    go_berserk();
    add_gold(10u);

    printf("Berserk minion : \n");
    printf("hp : %u\n", g_hp);              // 150
    printf("strength : %u\n", g_strength);  // 30

    // this does not compile
    // printf("gold : %u\n", g_gold);       // 25

    return 0;
}
