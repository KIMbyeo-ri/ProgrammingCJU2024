#include <stdio.h>
#include <math.h> // sqrt

// 함수 선언
void generateRandomNumbers(int numbers[], int count, int seed);
int calculateSum(int numbers[], int count);
double calculateVariance(int numbers[], int count, double mean);
double calculateStandardDeviation(double variance);

int main(void) {
    int numbers[10];
    int sum;
    double mean, variance, standardDeviation;

    // 난수 생성
    int seed;
    printf("Enter a seed value (any integer): ");
    scanf_s("%d", &seed);
    generateRandomNumbers(numbers, 10, seed);

    // 생성된 숫자 출력
    printf("Generated numbers: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 총합 계산
    sum = calculateSum(numbers, 10);

    // 평균 계산
    mean = (double)sum / 10;

    // 분산 계산
    variance = calculateVariance(numbers, 10, mean);

    // 표준편차 계산
    standardDeviation = calculateStandardDeviation(variance);

    // 결과 출력
    printf("Sum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", standardDeviation);

    return 0;
}

// 난수 생성 함수
void generateRandomNumbers(int numbers[], int count, int seed) {
    int min = 1, max = 100; // 난수 범위 설정
    for (int i = 0; i < count; i++) {
        seed = (seed * 1103515245 + 12345 + i) % 2147483647; // i를 추가해 변화 도입
        numbers[i] = min + (seed % (max - min + 1));         // min에서 max 사이의 난수 생성
    }
}

// 총합 계산 함수
int calculateSum(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

// 분산 계산 함수
double calculateVariance(int numbers[], int count, double mean) {
    double variance = 0.0;
    for (int i = 0; i < count; i++) {
        variance += (numbers[i] - mean) * (numbers[i] - mean);
    }
    return variance / count;
}

// 표준편차 계산 함수
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}
