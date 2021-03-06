#include <stdio.h>   //표준 입출력 함수 헤더 파일을 포함합니다.
#include <stdbool.h> // bool 타입을 사용하기 위해 해당 헤더 파일을 포함합니다.

int main(void)                                    //프로그램 코드가 실행될 때 가장 먼저 불리는 main 함수를 사용합니다.
{                                                 //중괄호를 이용하여 main 함수를 열어줍니다.
    int num = 0;                                  //인풋값으로 쓰이는 변수를 선언 및 0으로 초기화 해줍니다.
    int odd_total_num = 0;                        //홀수의 총합인 변수를 선언 및 0으로 초기화 해줍니다.
    int even_total_num = 0;                       //짝수의 총합인 변수를 선언 및 0으로 초기화 해줍니다.
    printf("1~100 사이 숫자를 입력 하세요 : \n"); //사용자에게 입력을 요청하기 위해 printf 함수로 이를 출력합니다.
    scanf("%d", &num);                            //사용자로부터 입력값을 받기 위해 scanf 함수를 사용합니다.

    if (0 < num && num <= 100) // 1이상 100 이하의 양수를 입력할 경우 해당 구문이 실행됩니다.
    {                          //중괄호를 이용하여 if 구문을 열어줍니다.
        while (num >= 1)       // 1이상이면서 입력된 값 이하인 홀수와 짝수의 각 총 합을 구하야 하므로 num 은 1 이상일 경우 계속 실행됩니다.
        {                      //중괄호를 이용하여 while 구문을 열어줍니다.
            /*
            bool 타입의 변수를 생성하여 num 이 홀수일 경우 true, 짝수일 경우 false 를 반환합니다.
            num 을 2로 나누었을 때 나머지가 1일 경우 이는 홀수에 해당합니다.
            */
            bool isOdd = num % 2 == 1;
            if (isOdd)                                                             // num 이 홀수일 경우 해당 구문이 실행됩니다.
                odd_total_num += num;                                              // odd_total_num 에 num 을 더해줍니다.
            else                                                                   // num 이 짝수일 경우 해당 구문이 실행됩니다.
                even_total_num += +num;                                            // even_total_num 에 num 을 더해줍니다.
            num--;                                                                 // if 또는 else 실행 후 while 문의 한 사이클이 끝났으므로 num 을 1씩 감소시켜 줍니다.
        }                                                                          //중괄호를 이용하여 while 구문을 닫아줍니다.
        printf("홀수 값의 총 합계 : %d \n", odd_total_num);                        // 홀수의 총 합계를 출력합니다.
        printf("짝수 값의 총 합계 : %d \n", even_total_num);                       // 짝수의 총 합계를 출력합니다.
    }                                                                              //중괄호를 이용하여 if 구문을 닫아줍니다.
    else                                                                           //입력값이 조건을 만족하지 않을 경우, 해당 구문이 실행됩니다.
    {                                                                              //중괄호를 이용하여 else 구문을 열어줍니다.
        printf("입력값이 1이상 100이하 값이 아닙니다. 입력값을 확인해주세요. \n"); //입력값이 조건에 맞지 않을 경우, printf 로 해당 문구를 출력합니다.
    }                                                                              //중괄호를 이용하여 else 구문을 열어줍니다.
} //중괄호를 이용하여 main 함수를 닫아줍니다.
