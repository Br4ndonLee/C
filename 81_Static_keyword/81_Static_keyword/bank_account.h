//
//  bank_account.h
//  81_Static_keyword
//
//  Created by Brandon on 2022/02/05.
//

#ifndef bank_account_h
#define bank_account_h

void deposit_into_chequing(const unsigned int amount);
// 일반 통장에 돈을 입금하는 함수를 선언
void deposit_into_saving(const unsigned int amount);
// 저축 통장에 돈을 입금하는 함수를 선언
// 인자에 const를 붙였네? 함수 안에서 인자 값을 바꿀 수 없음을 의미

#endif /* bank_account_h */
