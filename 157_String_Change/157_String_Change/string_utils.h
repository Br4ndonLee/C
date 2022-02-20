//
//  string_utils.h
//  157_String_Change
//
//  Created by Brandon on 2022/02/12.
//

#ifndef string_utils_h
#define string_utils_h

int is_alpha(int c);
// 문자가 알파벳인지 판단하는 함수

int to_upper(int c);
int to_lower(int c);
// 표준 라이브러리가 int를 받고 int를 반환한다.

void string_toupper(char* str);
void string_tolower(char* str);

#endif /* string_utils_h */
