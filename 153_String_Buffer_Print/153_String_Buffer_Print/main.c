//
//  main.c
//  153_String_Buffer_Print
//
//  Created by Brandon on 2022/02/11.
//

#include "buffered_print.h"

int main(void) {
    buffered_print("Hello, ");          // Hello,
    buffered_print("World. ");          // Hello, world.
    buffered_print("C is awesome! ");   // Hello, world. C is awesome!
    /* 'Hello, ', 'world. ', 'C is awesome! '을 버퍼에 추가 */
    buffered_print("C# is awesome too! ");  // Hello, world. C is awesome! C#
    /* 버퍼가 가득 찼다. 하지만 'C#'까지만 출력.
     반복문이 내부에서 반복이 될테니까(버퍼가 비어졌으니) 나머지 부분을 또 버퍼에 추가로 작성 */
    buffered_print("Is C++ better? "); // is awesome too! Is C++ better?
    
    return 0;
}
