//
//  file_utils.c
//  183_File_Copy
//
//  Created by Brandon on 2022/02/17.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "file_utils.h"

void copy_file(const char* src, const char* dst) {
// 파일 하나를 다른 파일로 복사. src와 dst는 둘 다 파일의 전체 경로
// C 표준에는 파일 복사 함수가 없음. 따라서 직접 구현해야 함
    FILE* src_file;
    FILE* dst_file;
    // 원본 파일과 복사본 파일의 파일 포인터를 선언
    int c;
    // 원본으로부터 읽은 문자 하나를 기억하기 위해. 한 글자씩 읽을 것이기 떄문
    
    src_file = fopen(src, "rb");    // 읽기 전용, 이진 모드로 파일을 연다. 이 파일을 바꾸지 않을 것임
    if (src_file == NULL) {
        perror("error while opening source file");
        return;
    // 파일을 열다가 실패하면 fopen이 NULL을 반환. 그럼 그냥 때려쳐
    }
    
    dst_file = fopen(dst, "wb");    // 복사본 파일을 쓰기 전용, 이진 모드로 연다. 만약 파일이 이미 존재한다면 기존의 내용은 덮어 씀
    if (dst_file == NULL) {
        perror("error while creating target file");
    // 실패해도 원본 파일이 아직 열려있다. 따라서 제대로 닫아줘야 함
        goto close_source;
        // goto를 따라오면 원본 파일을 닫아주는 함수로.
    }
    
    c = fgetc(src_file);
    while (c != EOF) {
        fputc(c, dst_file);
        c = fgetc(src_file);
    // 복사본 파일을 성공적으로 열었다면 원본으로부터 한 글자씩 읽어 복사본에 적다가 EOF를 만나면 끝냄
    }
    
    if (fclose(dst_file) == EOF) {
        perror("error while closing target file");
    // 다 끝났다면 복사본 파일을 닫고 아래 원본 파일도 닫기
    }
    
close_source:
    if (fclose(src_file) == EOF) {  // 파일을 닫음. 실패하면 EOF 반환
        perror("error while closing source file");
    }
// 이 코드는 함수의 제일 마지막에 위치. 따라서 어떤 실행 경로를 따라가던 최종적으로는 여기로 오게 된다. 복사본 파일을 열다 실패하면 코드의 중간 부분을 다 건너뛰고 원본 파일을 닫는 코드만 실행
}
