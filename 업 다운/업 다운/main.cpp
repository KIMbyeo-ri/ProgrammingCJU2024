#include <stdio.h>

// 난수 생성 함수 (1부터 100까지)
int generatePseudoRandomNumber() {
    static unsigned int seed = 12345; // 고정된 시드 값
    seed = (seed * 1103515245 + 12345) & 0x7fffffff; // 의사 난수 생성
    return (seed % 100) + 1; // 1부터 100까지의 숫자로 변환
}

// 게임 로직 함수
void playGame() {
    int target = generatePseudoRandomNumber(); // 목표 숫자 생성
    int guess; // 사용자 입력
    int attempts = 10; // 시도 횟수 제한

    printf("컴퓨터가 1부터 100 사이의 정수를 생성했습니다.\n");
    printf("10번의 기회 안에 숫자를 맞추세요!\n");

    for (int i = 1; i <= attempts; i++) {
        printf("시도 %d/%d: 숫자를 입력하세요: ", i, attempts);
        scanf_s("%d", &guess);

        if (guess < target) {
            printf("업! 더 큰 숫자를 시도하세요.\n");
        }
        else if (guess > target) {
            printf("다운! 더 작은 숫자를 시도하세요.\n");
        }
        else {
            printf("축하합니다! 숫자를 맞췄습니다!\n");
            return; // 게임 종료
        }
    }

    printf("기회를 모두 소진했습니다. 정답은 %d였습니다.\n", target);
}

int main(void) {
    playGame(); // 게임 실행
    return 0;
}
