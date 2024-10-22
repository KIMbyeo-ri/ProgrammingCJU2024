#include <stdio.h>

int main(void)
{
    float score;
    char grade;

    printf("정적 입력(0.0~100.0): ");
    scanf_s("%f", &score);

    switch ((int)score / 10) {
    case 10:
    case 9:
        grade = 'A';
        break;

    case 8:
        grade = 'B';
        break;

    case 7:
        grade = 'C';
        break;

    case 6:
        grade = 'C';
        break;

    case 5:
        grade = 'D';
        break;

    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
        grade = 'F';
        break;
    default:
        printf("잘못된 점수입니다.\n");
        return 1;
    }

    printf("학점: %c\n", grade);
    return 0;
}