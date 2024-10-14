#include <stdio.h>

int main() {
    int num1, num2;
    char ca;
    int answer;

    printf("수식을 입력하세요 : ");
    scanf_s("%d %c %d", &num1, &ca, 1, &num2);

    if (ca == '+') {
        answer = num1 + num2;
    }
    else if (ca == '-') {
        answer = num1 - num2;
    }
    else if (ca == '*') {
        answer = num1 * num2;
    }
    else if (ca == '/') {
        if (num2 != 0) {
            answer = num1 / num2;
        }
        else {
            printf("0으로 나눌 수 없습니다.\n");
            return 1; 
        }
    }
    else {
        printf("잘못된 a입니다.\n");
        return 1; 
    }

    
    printf("결과: %d\n", answer);
    return 0;
}