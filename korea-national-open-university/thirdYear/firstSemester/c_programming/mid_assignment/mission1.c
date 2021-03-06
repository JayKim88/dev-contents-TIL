#include <stdio.h> // 표준 입출력 함수 헤더 파일을 포함합니다.
#include <math.h>  // floor 함수를 사용하기 위해 수학함수 헤더파일을 포함합니다.

int main(void) // 프로그램 코드가 실행될 때 가장 먼저 불리는 main 함수를 사용합니다.
{              // 중괄호를 이용하여 main 함수를 열어줍니다.
    int jumsu; // //인풋값으로 쓰이는 변수를 선언해줍니다.

    printf("0점에서 100점수 사이의 점수를 입력하세요. \n"); // 사용자에게 입력을 요청하기 위해 printf 함수를 이용합니다.
    scanf("%d", &jumsu);                                    // scanf 함수를 이용하여 사용자로부터 입력값을 받습니다. 해당 입력값은 선언되어 있는 jumsu 에 할당됩니다.

    int quotient = floor(jumsu / 10); // 해당 점수를 10으로 나눈 값의 몫을 이용하여 해당하는 학점을 찾습니다.

    switch (quotient)                            // 판단할 값을 대입해줍니다.
    {                                            // 중괄호를 이용하여 switch 구문을 열어줍니다.
    case 10:                                     // 10에 해당하는 경우, 즉 100점을 받은 경우와,
    case 9:                                      // 9에 해당하는 경우, 즉 90점 이상-100점 미만을 받은 경우에 아래 코드가 실행됩니다.
        printf("%d점은 A학점입니다. \n", jumsu); // printf 함수를 이용, A학점임을 출력합니다.
        break;                                   // switch-case 조건문을 빠져나갑니다.
    case 8:                                      // 8에 해당하는 경우, 즉 80점 이상-90점 미만을 받은 경우에 아래 코드가 실행됩니다.
        printf("%d점은 B학점입니다. \n", jumsu); // printf 함수를 이용, B학점임을 출력합니다.
        break;                                   // switch-case 조건문을 빠져나갑니다.
    case 7:                                      // 7에 해당하는 경우, 즉 70점 이상-80점 미만을 받은 경우에 아래 코드가 실행됩니다.
        printf("%d점은 C학점입니다. \n", jumsu); // printf 함수를 이용, C학점임을 출력합니다.
        break;                                   // switch-case 조건문을 빠져나갑니다.
    case 6:                                      // 6에 해당하는 경우, 즉 60점 이상-70점 미만을 받은 경우에 아래 코드가 실행됩니다.
        printf("%d점은 D학점입니다. \n", jumsu); // printf 함수를 이용, D학점임을 출력합니다.
        break;                                   // switch-case 조건문을 빠져나갑니다.
    default:                                     // 60점이상 100점 이하에 해당하지 않는 경우 아래의 코드가 실행됩니다.
        printf("%d점은 F학점입니다. \n", jumsu); // printf 함수를 이용, F학점임을 출력합니다.
    }                                            // 중괄호를 이용하여 switch 구문을 닫아줍니다.
} // 중괄호를 이용하여 main 함수를 닫아줍니다.
