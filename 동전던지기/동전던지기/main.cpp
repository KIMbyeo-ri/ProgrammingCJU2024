#include <stdio.h>

int main(void) {
    // 변수 선언
    int numFlip = 10000;  //동전을 던질 횟수
    int heads = 0;
    int tails = 0; // 앞면과 뒷면이 나온 횟수를 저장할 변수

    // 의사 난수를 위한 초기 시드 값
    int seed = 1; // 난수를 생성하기 위한 초기값. 의사 난수 생성에 사용됨

    // 동전 던지기 반복
    for (int i = 0; i < numFlip; i++) {
        seed += i; // 시드 값을 업데이트하여 의사 난수 생성에 변화를 줌
        int result = (seed * 1103515245 + 12345) % 2; // 난수 생성 식
        // 0 또는 1 값을 생성
        // `seed` 값을 수학적으로 처리해 가짜 난수를 생성하며,
        // `% 2`를 사용해 결과를 0(뒷면) 또는 1(앞면)으로 제한

        // 선택문을 사용하여 결과를 분류
        if (result == 1) {
            heads++; // 결과가 1일 경우, 앞면 카운트를 증가
        }
        else {
            tails++; // 결과가 0일 경우, 뒷면 카운트를 증가
        }
    }

    // 확률 계산
    double headsProbability = (double)heads / numFlip * 100; // 앞면 확률 계산
    double tailsProbability = (double)tails / numFlip * 100; // 뒷면 확률 계산
    // 각 결과를 던진 총 횟수(numFlips)로 나누어 백분율로 변환

    // 결과 출력
    printf("총 동전 던지기 횟수: %d\n", numFlip);
    // 동전을 던진 총 횟수 출력
    printf("앞면: %d번 (%.2f%%)\n", heads, headsProbability);
    // 앞면이 나온 횟수와 확률 출력
    printf("뒷면: %d번 (%.2f%%)\n", tails, tailsProbability);
    // 뒷면이 나온 횟수와 확률 출력

    return 0;
}
