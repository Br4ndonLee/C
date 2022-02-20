#include <stdio.h>

int main(void) {
    const int NUM = 0x12345678;         // NUM을 초기화 : 숫자다 주소 아님
    const char* NUM_ADDRESS = (char*)&NUM;  // NUM의 주소로 초기화
    // 이 주소를 char 포인터로 캐스팅하는 중. 이러면 한 번에 4바이트가 아니라 1바이트씩 점프할 수 있다.
    size_t i;

    for (i = 0; i < sizeof(NUM); ++i) {
        printf("%hhx ", *(NUM_ADDRESS + i));
    }
    // NUM의 값을 1바이트씩 16진수 형식으로 출력
    // 빅 엔디언 컴퓨터에서 이 프로그램을 돌리면 12 34 56 78이 출력된다.
    printf("\n");

    printf("NUM in hex form : 0x%x\n", NUM);
    // NUM을 16진수 형식으로 출력. 0x12345678이 출력됨

    return 0;
}