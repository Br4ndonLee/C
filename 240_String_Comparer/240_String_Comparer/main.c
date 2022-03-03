//
//  main.c
//  240_String_Comparer
//
//  Created by Brandon on 2022/02/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "string_comparer.h"

// 전에는 구조체 정렬을 해봤다. 이번에는 단어들을 정렬하는 예를 보자
enum { NUM_WORDS = 6};

int main(void) {
    size_t i;
    const char* words[NUM_WORDS] = {
        "premium", "level", "cultured",
        "moaning", "skinny", "curve"
    };
   // 정렬할 6개의 단어
    
    puts("\n== sort ascending ==");
    
    qsort(words, NUM_WORDS, sizeof(const char*), compare_string);
    // 전에 qsort() 봤던 거 기억하자. 바뀐게 없다. compare_string 함수만 보면 된다.
    for (i = 0; i < NUM_WORDS; ++i) {
        printf("%s\n", words[i]);
    }
    // 모든 단어가 오름차순으로 정렬
    
    puts("\n== sort descending ==");
    
    qsort(words, NUM_WORDS, sizeof(const char*), compare_string_desc);
    for(i = 0; i < NUM_WORDS; ++i) {
        printf("%s\n", words[i]);
    }
    // 내림차순으로 정렬
    
    return 0;
}
