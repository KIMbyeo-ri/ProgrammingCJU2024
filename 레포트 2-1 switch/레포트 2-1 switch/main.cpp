#include <stdio.h>

int main(void) {
    int num;
    printf("정수를 입력하세요:");
    scanf_s("%d", &num);

    switch (num % 2)
    {
    case 0:
        printf("%d는 짝수 입니다.\n", num);
        break;

    case 1:
        printf("%d는 홀수 입니다.\n", num);
        break;
    }


    return 0;
}