#include <stdio.h>

enum champ {        // 챔피언들을 나타내는 열거형을 선언
    CHAMP_ZED,      // 0
    CHAMP_JAX,      // 1
    CHAMP_VAYNE,    // 2
    CHAMP_LULU,     // 3
    CHAMP_LEESIN    // 4
};

enum role {         // 역할들을 나타내는 열거형을 선언
    ROLE_TOP,
    ROLE_MID,
    ROLE_JUNGLE,
    ROLE_BOTTOM,
    ROLE_SUPPORTER
};

int main(void) {
    enum champ my_champ = CHAMP_VAYNE;      // CHAMP_VAYNE을 my_champ에 저장
    enum role my_role = ROLE_BOTTOM;        // ROLE_BOTTOM을 my_role에 저장

    printf("my_champ : %d\n", my_champ);
    printf("my_role : %d\n", my_role); 
    printf("\n");

    my_role = CHAMP_LEESIN;                 // CHAMP_LEESIN을 my_role에 저장. 정수형이라 가능
    printf("my_role : %d\n", my_role);      // 출력하면 4가 출력 (실수할 여지가 있다. 주의!!)

    return 0;
}