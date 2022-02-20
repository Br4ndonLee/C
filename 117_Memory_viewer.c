#include <stdio.h>

int main(void) {
    const int NUM = 0x12345678;         // NUM�� �ʱ�ȭ : ���ڴ� �ּ� �ƴ�
    const char* NUM_ADDRESS = (char*)&NUM;  // NUM�� �ּҷ� �ʱ�ȭ
    // �� �ּҸ� char �����ͷ� ĳ�����ϴ� ��. �̷��� �� ���� 4����Ʈ�� �ƴ϶� 1����Ʈ�� ������ �� �ִ�.
    size_t i;

    for (i = 0; i < sizeof(NUM); ++i) {
        printf("%hhx ", *(NUM_ADDRESS + i));
    }
    // NUM�� ���� 1����Ʈ�� 16���� �������� ���
    // �� ����� ��ǻ�Ϳ��� �� ���α׷��� ������ 12 34 56 78�� ��µȴ�.
    printf("\n");

    printf("NUM in hex form : 0x%x\n", NUM);
    // NUM�� 16���� �������� ���. 0x12345678�� ��µ�

    return 0;
}