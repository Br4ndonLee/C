//
//  file_utils.c
//  189_Right_File_Copy
//
//  Created by Brandon on 2022/02/19.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "file_utils.h"

void copy_file(const char* src, const char* dst) {
// 예전에 봤던 copy_file 함수와 같은 함수
    FILE* src_file;
    FILE* dst_file;
    int c;
    
    src_file = fopen(src, "rb");
    if (src_file == NULL) {
        perror("error while opening source file");
        return;
    }
    
    dst_file = fopen(dst, "wb");
    if (dst_file == NULL) {
        perror("error while creating target file");
        goto close_source;
    }
    
    c = fgetc(src_file);
    while (c != EOF) {
        fputc(c, dst_file);
        c = fgetc(src_file);
    }
    
    if (fclose(dst_file) == EOF) {
        perror("error while closing target file");
    }
    
close_source:
    if (fclose(src_file) == EOF) {
        perror("error while closing source file");
    }
}
