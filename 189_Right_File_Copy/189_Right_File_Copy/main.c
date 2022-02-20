//
//  main.c
//  189_Right_File_Copy
//
//  Created by Brandon on 2022/02/19.
//

#include <stdio.h>
#include <string.h>

#include "file_utils.h"

int main(int argc, const char* argv[]) {
// void가 아닌 2개의 매개변수를 커맨드 라인에 전달된 인자로부터 받아온다.
// 예를 들어 'program.exe src.txt dst.txt'라 하면 argc는 인자의 개수인데 이건 2가 아니라 3. 왜냐하면 argv의 첫 번째 요소는 실행 파일의 경로이기 때문. 따라서 실제 커맨드 라인 인자는 argv[1]부터 시작
    if (argc != 3) {
    // 실제 인자로 2개를 받는 프로그램. 원본 파일 이름과 복사본 파일 이름. 사용자가 올바른 인자를 전달해주지 않았다면 이 프로그램의 사용법을 보여줘야 함
        FILE* out;
        
        if (argc == 2 && strcmp(argv[1], "--help") == 0) {
            out = stdout;
        } else {
            out = stderr;
        }
        // 그러나 언제나 stderr에 보여주고 싶지는 않다. 왜냐면 사용자의 실수가 아닐 수도 있으니까.
        // 사용자가 '--help'란 인자를 사용했다면(그 명령어 좀 보여줘, 메뉴얼 좀 보여줘. err는 이상하니까) stdout에 사용법을 보여줌. 아니라면 stderr에
        
        fprintf(out, "+-------------------------------------+\n");
        fprintf(out, "|         New File Copier v1+\n");
        fprintf(out, "+-------------------------------------+\n");
        fprintf(out, "  usage: copy <src> <dst>\n");
        fprintf(out, "  usage: copy --hlep to see help page");
        // 사용법을 출력
        
        if (out == stderr) {
            fprintf(out, "\nerror: invalid arguments\n");
        }
        // out이 stderr라면 추가적인 오류 메시지도 출력
        
        return 1;
        // 그리고 1을 반환. 프로그램이 제대로 실행되지 않으면 0이 아닌 값을 반환하는게 약속
    }
    
    copy_file(argv[1], argv[2]);
    
    return 0;
    // 프로그램이 올바르게 호출되었다면 copy_file() 함수를 호출
}
