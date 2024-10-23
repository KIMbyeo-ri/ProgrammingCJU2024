#include <stdio.h>

int main(void) {
    int num;

    //수 입력
    printf("수 입력 (2-9 또는 0입력):");
    scanf_s("%d", &num);

    if (num == 0) {
        //0 입력 시 전체 구구단 출력(2*1 ~ 9*9까지 출력)
        for (int i = 2; i <= 9; i++) {
            printf("%d단:\n", i);
            for (int j = 1; j <= 9; j++) {
                printf("%d * %d = %d\n", i, j, i * j);
            }
            printf("\n");
        }
    }
    else if (num >= 2 and num <= 9) {
        //입력된 단만 출력
        printf("%d단:\n", num);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", num, i, num * i);
        }
    }
    else {
        //유효x
        printf("유효하지 않은 숫자.\n");
    }

    return 0;
}
