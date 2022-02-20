#include <stdio.h>

int main(void) {
    const int nums[3][5] = {
        { 35, 50, 65, 24, 71 },
        { 32, 93, 30, 18, 83 },
        { 72, 53, 41, 88, 69 }
    };
    const int* nums2[3];    // nums2�� ����. �������� �迭�̴�.

    nums2[0] = nums[0];
    nums2[1] = nums[1];
    nums2[2] = nums[2];
    // �迭�� �����Ϳ� ������ �� �����Ƿ� nums�� ����� nums2�� ��ҿ� ������ �� �ִ�.

    printf("nums[0] address : %p\n", (void*)nums[0]);
    printf("nums[1] address : %p\n", (void*)nums[1]);
    printf("nums[2] address : %p\n", (void*)nums[2]);
    // �� ���� �ּҸ� ���. �ּҰ� 40����Ʈ�� ������ �ִ�.
    printf("nums[2]'s offset from nums[0] : %ld\n", nums[2] - nums[0]);  // 10
    // nums[0]���κ��� nums[2]������ �������� 10 (ù ��° ���� ������ġ���� �� ��° ���� �����ϴ� �� ���̿� ������)
    printf("nums[1]'s offset from nums[0] : %ld\n", nums[1] - nums[0]);  // 5
    // nums[0]���κ��� nums[2]������ �������� 5
    // 2D �迭���� �� �پ� �ǳʶڴٴ� ���� �� �࿡ �ִ� ��� ������ �� �ٿ� �ִ� ��� �����͸� �ǳ� �ڴٴ� ��

    printf("\n");

    printf("nums2[0] address : %p\n", (void*)&nums2[0]);
    printf("nums2[1] address : %p\n", (void*)&nums2[1]);
    printf("nums2[2] address : %p\n", (void*)&nums2[2]);
    printf("nums2[2]'s offset from nums2[0] : %ld\n", &nums2[2] - &nums2[0]);  // 2
    // ������ �迭���� �ּڰ��� ����Ǿ� �ִ�. ���� ��� �����Ͱ� �Ϸķ� ����Ǿ� �ִ� ���� �ƴϴ�. ���� ���� �ٸ� �ǹ�
    printf("nums2[1]'s offset from nums2[0] : %ld\n", &nums2[1] - &nums2[0]);  // 1
    // �� ������ �迭���� ������ �ּҸ� 3�� ������־�, �����Ͱ� ���� ����Ǿ� �ִ°� �ƴϾ�.
    // �׷��� �翬�� �ּ� ���� �� ���� �ּҰ� �ְ� �װ� �����̴�.
    //����� �迭�� �迭���� ���� �迭�� �ű� �ڸ� ��� �ִ°� �ƴ϶� �׳� �ּҸ� �ִ�.

    return 0;
}