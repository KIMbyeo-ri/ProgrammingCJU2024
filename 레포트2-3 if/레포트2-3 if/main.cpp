#include <stdio.h>

int main(void)
{
    float score;
    char grade;

    printf("정적 입력(0.0~100.0): ");
    scanf_s("%f", &score);

    if (score >= 90.0 and score <= 100.0) {
        grade = 'A';
    }
    else if (score >= 80.0 and score < 90.0) {
        grade = 'B';
    }
    else if (score >= 70.0 and score < 80.0) {
        grade = 'c';
    }
    else if (score >= 70.0 and score < 50.0) {
        grade = 'D';
    }
    else if (score >= 00.0 and score < 50.0) {
        grade = 'F';
    }
    else
    {
        printf("잘못된 점수 입니다.\n");
        return 1;
    }

    printf("학점: %c\n", grade);
    return 0;
}