#include <stdio.h>

int main(void) {
    int num1;
    int num2;
    int gcd;
    int lcm;
    int a;
    int b;

    // 두 숫자 입력 받기
    printf("두 숫자를 입력하세요: ");
    scanf_s("%d %d", &num1, &num2);

    a = num1;
    b = num2;

    //최대공약수 계산 (유클리드 호제법 사용)
    do {
        int temp = b;
        b = a % b;
        a = temp;
    } while (b != 0); //b가 0이 될 때까지 반복

    gcd = a;

    //최소공배수 계산
    lcm = (num1 * num2) / gcd;

    //결과 출력
    printf("최대공약수(GCD): %d\n", gcd);
    printf("최소공배수(LCM): %d\n", lcm);

    return 0;
}
