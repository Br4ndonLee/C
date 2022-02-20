//
//  minion.h
//  79_Extern_keyword
//
//  Created by Brandon on 2022/02/05.
//

#ifndef MINION_H
/* 인클루드 가드. 선언을 두 번 포함하는 일을 방지.
ifndef는 if not defined의 약자로 ~을 정의하지 않았다면 이라는 뜻
ifndef 매크로 이름 : "매크로 이름"이 정의되었다면 이 부분이 코드에 포함되고
그렇지 않다면 코드에 포함되지 않는다. */
#define MINION_H

void go_berserk(void);          // go_berserk 함수 선언
void add_gold(unsigned int gold); // add_gold 함수 선언

#endif  // MINION_H              endif 까먹지 말자
