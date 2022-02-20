#include <stdio.h>

enum champ {        // è�Ǿ���� ��Ÿ���� �������� ����
    CHAMP_ZED,      // 0
    CHAMP_JAX,      // 1
    CHAMP_VAYNE,    // 2
    CHAMP_LULU,     // 3
    CHAMP_LEESIN    // 4
};

enum role {         // ���ҵ��� ��Ÿ���� �������� ����
    ROLE_TOP,
    ROLE_MID,
    ROLE_JUNGLE,
    ROLE_BOTTOM,
    ROLE_SUPPORTER
};

int main(void) {
    enum champ my_champ = CHAMP_VAYNE;      // CHAMP_VAYNE�� my_champ�� ����
    enum role my_role = ROLE_BOTTOM;        // ROLE_BOTTOM�� my_role�� ����

    printf("my_champ : %d\n", my_champ);
    printf("my_role : %d\n", my_role); 
    printf("\n");

    my_role = CHAMP_LEESIN;                 // CHAMP_LEESIN�� my_role�� ����. �������̶� ����
    printf("my_role : %d\n", my_role);      // ����ϸ� 4�� ��� (�Ǽ��� ������ �ִ�. ����!!)

    return 0;
}