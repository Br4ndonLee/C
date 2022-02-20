// ���� �����ϴ� ������ �����̴�. goto���� �׻� �Ʒ��θ� �� ��!
#include <stdio.h>

void calculate_factorial(const unsigned int n) {    // n ���丮���� ��� �� �����
    unsigned int result = 1;    // result�� 1�� ����
    unsigned int i = 1;         // i�� 1�� ����. �̰��� ī����

    goto begin_loop;            // goto ���� �̿��� begin_loop ���̺�� ����

    // this is a bad practice
exit_loop:                      // goto ���� �� ���� ��� ��. ���� ���� �������� �� ��.
    printf("%d factorial : %d\n", n, result);
    return;

begin_loop:                     // 9~14��° ���� ������ �ǳʶ�
    while (i <= n) {            // begin_loop ���̺� �Ʒ� �ִ� �ڵ� ����. i <= n�� ����
        result *= i;            // i�� result�� ���� ��, i�� ����
        ++i;
    }
    goto exit_loop;             // ���� �𸣰����� return�� �ϴ� ��� ���� exit_loop�� ����
}

void find_number(int arr[3][3], const int n) {
    size_t i;                   // i, j�� ����. ����� ��ȸ�� �� ī���ͷ� ����� ����
    size_t j;
    // 4x4 ����� ����. ���� n�� 3x3 ��� �ȿ� ���ٸ� default_matrix �ȿ��� n�� ã�ƺ� ��
    int default_matrix[4][4] = {
        {4, 1, 3, 1},
        {9, 2, -1, 6},
        {6, 0, 10, 5},
        {1, 2, 3, 3},
    };

    for (i = 0; i < 3; ++i) {   // ���� for �ݺ���
        for (j = 0; j<3; ++j) {
            if (arr[i][j] == n) {   // n�� �߰��ϸ�, �ܼ�â�� ����ϰ� found ���̺�� ����
                printf("%d found in arr.", n);
                goto found;     // 0�� 3x3 ��� �ȿ� �־��ٸ� found ���̺�� ����
            }
        }
    }

    for (i = 0; j < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (default_matrix[i][j] == n) {
                printf("%d found in default_matrix.", n);
                goto found;
            }
        }
    }

found:
    printf("Number : %d\n", n);     // ���� n�� �� ���ڰ� �߰ߵ� ��� �� ��ġ ���
    printf("Index positions : (%zu, %zu)\n", i, j); // �߰ߵ� ���ڷ� 0��, ���� ��ġ�� (0,0) ���
}

int main(void) {
    int square_matrix[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    calculate_factorial(4);         // 4�� ���丮���� ������
    find_number(square_matrix, 0);  // 3x3 ��Ŀ��� 0�� ã������ 4x4 ��Ŀ��� ã�� for���� �ǳʶ�
    find_number(square_matrix, -1);
    // 3x3 ��Ŀ��� -1�� ���� ������ if (arr[i][j]==n)�� ���� true�� ���� ����
    // 3x3 ����� �� ���� �ڿ� 4x4 ��� �ݺ��� ����. -1�� ã���� found ���̺�� ����

    return 0;
}

// �������� ���� goto���� �Ʒ��θ� ������ ��!!!!