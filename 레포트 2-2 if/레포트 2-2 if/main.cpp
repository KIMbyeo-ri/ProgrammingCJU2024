#include <stdio.h>

int main(void)
{
    int num1, num2;

    printf("첫 번째 정수를 입력하세요:");
    scanf_s("%d", &num1);
    
    printf("두 번째 정수를 입력하세요:");
    scanf_s("%d", &num2);

    if (num2 != 0 && num1 % num2 == 0) {
        printf("%d는 %d의 배수입니다.\n", num1, num2);
    }
    else {
        printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
    }

    return 0;
}