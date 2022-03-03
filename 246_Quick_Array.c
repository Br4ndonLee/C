#include <assert.h>
#include <stdio.h>

enum {MAX_NUMS = 8};
enum {INVALID_INDEX = -1};

int s_nums[MAX_NUMS];
size_t s_nums_count = 0;
// 수업 중  배열의 삽입 삭제 연산을 어떻게 구현하는지 살펴봤다.
// 이 둘은 O(n) 연산들이지만 언제나 배열 제일 뒤에 삽입하면 삽입 연산은 O(1)으로 줄일 수 있다.

void print_array(void) {
    size_t i;

    for (i = 0; i < s_nums_count; ++i) {
        printf("%d ", s_nums[i]);
    }

    puts("");
}
/* 간단한 배열 출력 함수. 이 함수를 여러 번 호출하면서 옛 삭제 함수와 새 삭제 함수가 어떻게 다르게 동작하는지 볼 것 */

// 삽입
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

// 검색
size_t find_index(int n) {
    size_t i;

    for (i = 0; i < s_nums_count; ++i) {
        if (s_nums[i] == n) {
            return i;
        }
    }

    return INVALID_INDEX;
}

// 삭제
void remove_at(size_t index) {
    size_t i;

    assert(index < s_nums_count);

    --s_nums_count;
    for (i = index; i < s_nums_count; ++i) {
        s_nums[i] = s_nums [i + 1];
    }
}

// 새로운 삭제 연산. 이름에서 알 수 있듯이 삭제 후에 남은 요소들의 순서가 유지되지 않음. O(1)
void remove_at_unordered(size_t index) {
    assert(index < s_nums_count);

    s_nums[index] = s_nums[--s_nums_count];
    /* 요소 하나 삭제 후에 그 뒤의 모든 요소를 왼쪽으로 한 칸씩 이동(shift)하는 대신
    요소를 삭제해서 빈 슬롯에 그냥 배열의 마지막 요소를 이동해 옴.
    배열 속에 저장된 데이터의 순서가 중요하지 않다면 이 꼼수를 이용하여 배열의 삭제 연산을 언제나 O(1)로 만들 수 있다.
    참고로 삭제 후에 배열이 비면 더 이상 이 코드를 실행하지 않는게 개념상으로는 옳음. 하지만 이대로 둬도 안전한 코드 */
}

// 두 삭제 함수들이 어떻게 다르게 동작하는지 보자
int main(void) {
    insert_at(0, 0);        // 6개의 숫자 추가
    insert_at(1, 1);
    insert_at(2, 2);
    insert_at(3, 3);
    insert_at(4, 4);
    insert_at(5, 5);

    // 0, 1, 2, 3, 4, 5 가 출력
    print_array();

    remove_at(1);   // 색인 1에서 한 요소 삭제
    // 0, 2, 3, 4, 5 가 출력. 순서 그래도 유지
    print_array();

    remove_at_unordered(1); // 색인 1에서 한 요소를 삭제하고 마지막 요소를 이 슬롯으로 이동
    // 0, 5, 3, 4. 3과 4가 이동하지 않았다. 이 버전이 더 빠름
    print_array();

    return 0;
}