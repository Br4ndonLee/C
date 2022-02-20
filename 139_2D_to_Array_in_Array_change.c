#include <stdio.h>

int main(void) {
    const int nums[3][5] = {
        { 35, 50, 65, 24, 71 },
        { 32, 93, 30, 18, 83 },
        { 72, 53, 41, 88, 69 }
    };
    const int* nums2[3];    // nums2를 선언. 포인터의 배열이다.

    nums2[0] = nums[0];
    nums2[1] = nums[1];
    nums2[2] = nums[2];
    // 배열을 포인터에 대입할 수 있으므로 nums의 행들을 nums2의 요소에 대입할 수 있다.

    printf("nums[0] address : %p\n", (void*)nums[0]);
    printf("nums[1] address : %p\n", (void*)nums[1]);
    printf("nums[2] address : %p\n", (void*)nums[2]);
    // 각 행의 주소를 출력. 주소가 40바이트씩 떨어져 있다.
    printf("nums[2]'s offset from nums[0] : %ld\n", nums[2] - nums[0]);  // 10
    // nums[0]으로부터 nums[2]까지의 오프셋은 10 (첫 번째 행의 시작위치부터 세 번째 행이 시작하는 그 사이에 오프셋)
    printf("nums[1]'s offset from nums[0] : %ld\n", nums[1] - nums[0]);  // 5
    // nums[0]으로부터 nums[2]까지의 오프셋은 5
    // 2D 배열에서 한 줄씩 건너뛴다는 것은 그 행에 있던 모든 데이터 한 줄에 있는 모든 데이터를 건너 뛴다는 것

    printf("\n");

    printf("nums2[0] address : %p\n", (void*)&nums2[0]);
    printf("nums2[1] address : %p\n", (void*)&nums2[1]);
    printf("nums2[2] address : %p\n", (void*)&nums2[2]);
    printf("nums2[2]'s offset from nums2[0] : %ld\n", &nums2[2] - &nums2[0]);  // 2
    // 포인터 배열에는 주솟값이 저장되어 있다. 실제 모든 데이터가 일렬로 저장되어 있는 것이 아니다. 위의 예와 다른 의미
    printf("nums2[1]'s offset from nums2[0] : %ld\n", &nums2[1] - &nums2[0]);  // 1
    // 이 포인터 배열에는 어차피 주소만 3개 저장돼있어, 데이터가 실제 저장되어 있는게 아니야.
    // 그러면 당연히 주소 다음 줄 가면 주소가 있고 그게 전부이다.
    //개념상 배열의 배열이지 실제 배열이 거기 자리 잡고 있는게 아니라 그냥 주소만 있다.

    return 0;
}