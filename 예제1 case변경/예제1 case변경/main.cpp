#include <stdio.h>

int main(void)
{
    int num1, num2;
    char ca;
    int answer;

    printf("수식을 입력하세요 : ");
    scanf_s("%d %c %d", &num1, &ca, sizeof(ca), &num2);

    switch (ca)
    {
    case '+':
        answer = num1 + num2;
        printf("결과: %d\n", answer);
        break;

    case '-':
        answer = num1 - num2;
        printf("결과: %d\n", answer);
        break;

    case '*':
        answer = num1 * num2;
        printf("결과: %d\n", answer);
        break;

    case '/':
        answer = num1 / num2;
        printf("결과: %d\n", answer);
        break;

    default:
        printf("잘못된 연산자 입니다");
        break;



    }
    return 0;
}




                     


         