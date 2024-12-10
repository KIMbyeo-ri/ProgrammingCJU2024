#include <stdio.h>
#include <math.h>

// ������ �����ϱ� ���� ������ ���� �յ� ������
int generateRandom(int seed, int lower, int upper) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff; // ���� �յ� ������
    return lower + (seed % (upper - lower + 1)); // ���� �� ���� ����
}

// ��� ��� �Լ�
void calculateStatistics(int* arr, int size, int* sum, double* variance, double* std_dev) {
    double mean = 0;
    *sum = 0;

    // ���� ���
    for (int i = 0; i < size; i++) {
        *sum += arr[i];
    }

    // ��� ���
    mean = (double)(*sum) / size;

    // �л� ���
    *variance = 0;
    for (int i = 0; i < size; i++) {
        *variance += pow((arr[i] - mean), 2);
    }
    *variance /= size;

    // ǥ������ ���
    *std_dev = sqrt(*variance);
}

int main(void) {
    int numbers[100];   // 100���� ������ ������ �迭
    int selectedRange[10]; // ���õ� 10���� ������ ������ �迭
    int sum = 0;          // ����
    double variance = 0;  // �л�
    double std_dev = 0;   // ǥ������
    int lowerBound, upperBound;
    int startIndex, endIndex;
    int seed = 12345; // ���� ������ ���� �ʱ� �õ� ��

    // ����� �Է�: ���� ������ ���� ����
    printf("������ ������ ���� (����, ����)�� �Է��ϼ���: ");
    scanf_s("%d %d", &lowerBound, &upperBound);

    printf("������ ������ ���� �ε����� �� �ε����� �Է��ϼ��� (0���� ����): ");
    scanf_s("%d %d", &startIndex, &endIndex);

    if (endIndex - startIndex + 1 != 10 || startIndex < 0 || endIndex >= 1000) {
        printf("10���� ���ڸ� �����Ϸ��� ������ �ε����� �Է��ϼ���.\n");
        return 1;
    }

    // ���� ����
    for (int i = 0; i < 100; i++) {
        seed += i; // �� ��ȸ���� �õ带 ����
        numbers[i] = generateRandom(seed, lowerBound, upperBound);
    }

    // ���õ� ������ �� ����
    for (int i = startIndex; i <= endIndex; i++) {
        selectedRange[i - startIndex] = numbers[i];
    }

    // ��� ���
    calculateStatistics(selectedRange, 10, &sum, &variance, &std_dev);

    // ��� ���
    printf("���õ� ������ ����:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", selectedRange[i]);
    }
    printf("\n");
    printf("����: %d\n", sum);
    printf("�л�: %.2lf\n", variance);
    printf("ǥ������: %.2lf\n", std_dev);

    return 0;
}
