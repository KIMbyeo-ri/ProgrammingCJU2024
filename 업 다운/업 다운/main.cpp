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

    printf("컴퓨터가 1부터 100 사이의 정수 생성.\n");
    printf("110회 안에 맞추시오.\n");

    for (int i = 1; i <= attempts; i++) {
        printf("시도 %d/%d: 숫자 입력: ", i, attempts);
        scanf_s("%d", &guess);

        if (guess < target) {
            printf("업.\n");
        }
        else if (guess > target) {
            printf("다운.\n");
        }
        else {
            printf("정답!\n");
            return; // 게임 종료
        }
    }

    printf("기회 모두 소진. 정답은 %d.\n", target);
}

int main(void) {
    playGame(); // 게임 실행
    return 0;
}
