#include <stdio.h>
#include <math.h> // sqrt

// �Լ� ����
void generateRandomNumbers(int numbers[], int count, int seed);
int calculateSum(int numbers[], int count);
double calculateVariance(int numbers[], int count, double mean);
double calculateStandardDeviation(double variance);

int main(void) {
    int numbers[10];
    int sum;
    double mean, variance, standardDeviation;

    // ���� ����
    int seed;
    printf("Enter a seed value (any integer): ");
    scanf_s("%d", &seed);
    generateRandomNumbers(numbers, 10, seed);

    // ������ ���� ���
    printf("Generated numbers: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // ���� ���
    sum = calculateSum(numbers, 10);

    // ��� ���
    mean = (double)sum / 10;

    // �л� ���
    variance = calculateVariance(numbers, 10, mean);

    // ǥ������ ���
    standardDeviation = calculateStandardDeviation(variance);

    // ��� ���
    printf("Sum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", standardDeviation);

    return 0;
}

// ���� ���� �Լ�
void generateRandomNumbers(int numbers[], int count, int seed) {
    int min = 1, max = 100; // ���� ���� ����
    for (int i = 0; i < count; i++) {
        seed = (seed * 1103515245 + 12345 + i) % 2147483647; // i�� �߰��� ��ȭ ����
        numbers[i] = min + (seed % (max - min + 1));         // min���� max ������ ���� ����
    }
}

// ���� ��� �Լ�
int calculateSum(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

// �л� ��� �Լ�
double calculateVariance(int numbers[], int count, double mean) {
    double variance = 0.0;
    for (int i = 0; i < count; i++) {
        variance += (numbers[i] - mean) * (numbers[i] - mean);
    }
    return variance / count;
}

// ǥ������ ��� �Լ�
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}
