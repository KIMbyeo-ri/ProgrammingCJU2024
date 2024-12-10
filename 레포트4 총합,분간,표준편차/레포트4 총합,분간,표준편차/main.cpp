#include <stdio.h>
#include <math.h>

// 난수를 생성하기 위한 간단한 선형 합동 생성기
int generateRandom(int seed, int lower, int upper) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff; // 선형 합동 생성기
    return lower + (seed % (upper - lower + 1)); // 범위 내 난수 생성
}

// 통계 계산 함수
void calculateStatistics(int* arr, int size, int* sum, double* variance, double* std_dev) {
    double mean = 0;
    *sum = 0;

    // 총합 계산
    for (int i = 0; i < size; i++) {
        *sum += arr[i];
    }

    // 평균 계산
    mean = (double)(*sum) / size;

    // 분산 계산
    *variance = 0;
    for (int i = 0; i < size; i++) {
        *variance += pow((arr[i] - mean), 2);
    }
    *variance /= size;

    // 표준편차 계산
    *std_dev = sqrt(*variance);
}

int main(void) {
    int numbers[100];   // 100개의 정수를 저장할 배열
    int selectedRange[10]; // 선택된 10개의 정수를 저장할 배열
    int sum = 0;          // 총합
    double variance = 0;  // 분산
    double std_dev = 0;   // 표준편차
    int lowerBound, upperBound;
    int startIndex, endIndex;
    int seed = 12345; // 난수 생성을 위한 초기 시드 값

    // 사용자 입력: 난수 범위와 선택 범위
    printf("난수를 생성할 범위 (하한, 상한)을 입력하세요: ");
    scanf_s("%d %d", &lowerBound, &upperBound);

    printf("선택할 숫자의 시작 인덱스와 끝 인덱스를 입력하세요 (0부터 시작): ");
    scanf_s("%d %d", &startIndex, &endIndex);

    if (endIndex - startIndex + 1 != 10 || startIndex < 0 || endIndex >= 1000) {
        printf("10개의 숫자를 선택하려면 적절한 인덱스를 입력하세요.\n");
        return 1;
    }

    // 난수 생성
    for (int i = 0; i < 100; i++) {
        seed += i; // 각 순회마다 시드를 변경
        numbers[i] = generateRandom(seed, lowerBound, upperBound);
    }

    // 선택된 범위의 값 추출
    for (int i = startIndex; i <= endIndex; i++) {
        selectedRange[i - startIndex] = numbers[i];
    }

    // 통계 계산
    calculateStatistics(selectedRange, 10, &sum, &variance, &std_dev);

    // 결과 출력
    printf("선택된 범위의 숫자:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", selectedRange[i]);
    }
    printf("\n");
    printf("총합: %d\n", sum);
    printf("분산: %.2lf\n", variance);
    printf("표준편차: %.2lf\n", std_dev);

    return 0;
}
