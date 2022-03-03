#include <assert.h>
#include <stdio.h>

enum {MAX_NUMS = 8};
enum {INVALID_INDEX = -1};

int s_nums[MAX_NUMS];
size_t s_nums_count = 0;
// ���� ��  �迭�� ���� ���� ������ ��� �����ϴ��� ����ô�.
// �� ���� O(n) ����������� ������ �迭 ���� �ڿ� �����ϸ� ���� ������ O(1)���� ���� �� �ִ�.

void print_array(void) {
    size_t i;

    for (i = 0; i < s_nums_count; ++i) {
        printf("%d ", s_nums[i]);
    }

    puts("");
}
/* ������ �迭 ��� �Լ�. �� �Լ��� ���� �� ȣ���ϸ鼭 �� ���� �Լ��� �� ���� �Լ��� ��� �ٸ��� �����ϴ��� �� �� */

// ����
void insert_at(size_t index, int n) {
    size_t i;

    assert(index <= s_nums_count);
    assert(s_nums_count < MAX_NUMS);

    for(i = s_nums_count; i > index; --i) {
        s_nums[i] = s_nums[i - 1];
    }

    s_nums[index] = n;
    ++s_nums_count;
}

// �˻�
size_t find_index(int n) {
    size_t i;

    for (i = 0; i < s_nums_count; ++i) {
        if (s_nums[i] == n) {
            return i;
        }
    }

    return INVALID_INDEX;
}

// ����
void remove_at(size_t index) {
    size_t i;

    assert(index < s_nums_count);

    --s_nums_count;
    for (i = index; i < s_nums_count; ++i) {
        s_nums[i] = s_nums [i + 1];
    }
}

// ���ο� ���� ����. �̸����� �� �� �ֵ��� ���� �Ŀ� ���� ��ҵ��� ������ �������� ����. O(1)
void remove_at_unordered(size_t index) {
    assert(index < s_nums_count);

    s_nums[index] = s_nums[--s_nums_count];
    /* ��� �ϳ� ���� �Ŀ� �� ���� ��� ��Ҹ� �������� �� ĭ�� �̵�(shift)�ϴ� ���
    ��Ҹ� �����ؼ� �� ���Կ� �׳� �迭�� ������ ��Ҹ� �̵��� ��.
    �迭 �ӿ� ����� �������� ������ �߿����� �ʴٸ� �� �ļ��� �̿��Ͽ� �迭�� ���� ������ ������ O(1)�� ���� �� �ִ�.
    ����� ���� �Ŀ� �迭�� ��� �� �̻� �� �ڵ带 �������� �ʴ°� ��������δ� ����. ������ �̴�� �ֵ� ������ �ڵ� */
}

// �� ���� �Լ����� ��� �ٸ��� �����ϴ��� ����
int main(void) {
    insert_at(0, 0);        // 6���� ���� �߰�
    insert_at(1, 1);
    insert_at(2, 2);
    insert_at(3, 3);
    insert_at(4, 4);
    insert_at(5, 5);

    // 0, 1, 2, 3, 4, 5 �� ���
    print_array();

    remove_at(1);   // ���� 1���� �� ��� ����
    // 0, 2, 3, 4, 5 �� ���. ���� �׷��� ����
    print_array();

    remove_at_unordered(1); // ���� 1���� �� ��Ҹ� �����ϰ� ������ ��Ҹ� �� �������� �̵�
    // 0, 5, 3, 4. 3�� 4�� �̵����� �ʾҴ�. �� ������ �� ����
    print_array();

    return 0;
}