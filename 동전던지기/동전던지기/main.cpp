#include <stdio.h>

int main(void) {
    // 변수 선언
    int numFlips = 10000;
    int heads = 0, tails = 0;

    // 의사 난수를 위한 초기 시드 값
    int seed = 1; // 초기값 설정 (임의의 숫자)

    // 동전 던지기 반복
    for (int i = 0; i < numFlips; i++) {
        seed += i; // 의사 난수 생성을 위한 변동
        int result = (seed * 1103515245 + 12345) % 2; // 0 또는 1 생성

        // 선택문을 사용하여 결과를 분류
        if (result == 1) {
            heads++;
        }
        else {
            tails++;
        }
    }

    // 확률 계산
    double headsProbability = (double)heads / numFlips * 100;
    double tailsProbability = (double)tails / numFlips * 100;

    // 결과 출력
    printf("총 동전 던지기 횟수: %d\n", numFlips);
    printf("앞면: %d번 (%.2f%%)\n", heads, headsProbability);
    printf("뒷면: %d번 (%.2f%%)\n", tails, tailsProbability);

    return 0;
}