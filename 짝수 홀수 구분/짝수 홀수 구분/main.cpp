#include <stdio.h>

// ¦���� Ȧ���� �и��Ͽ� �����ϴ� �Լ�
// �Է�: ���� �迭(input), �迭 ũ��(size)
// ���: ¦�� �迭(evenArr), Ȧ�� �迭(oddArr), ¦���� Ȧ���� ����
void CalcEvenOddArray(const int* input, int size, int* evenArr, int* oddArr, int* evenCount, int* oddCount) {
    *evenCount = 0; // ¦�� ���� �ʱ�ȭ
    *oddCount = 0;  // Ȧ�� ���� �ʱ�ȭ

    for (int i = 0; i < size; ++i) {
        if (input[i] % 2 == 0) { // ¦������ Ȯ��
            evenArr[*evenCount] = input[i];
            (*evenCount)++;
        }
        else { // Ȧ���� ���
            oddArr[*oddCount] = input[i];
            (*oddCount)++;
        }
    }
}

// �迭�� ����ϴ� �Լ�
// �Է�: �迭(arr), �迭 ũ��(size), ���� ������ ũ��(validSize)
// ���: �迭�� ��� ��Ҹ� ����ϸ�, ��ȿ���� ���� �ε����� "_"�� ǥ��
void PrintArray(const int* arr, int size, int validSize) {
    for (int i = 0; i < size; ++i) {
        if (i < validSize)
            printf("%d ", arr[i]); // ���� ������ ���
        else
            printf("_ "); // ������ ���� ������ "_"�� ���
    }
    printf("\n"); // �ٹٲ�
}

// ���� �Լ�
int main(void) {
    int size = 10;              // ���� �迭 ũ��
    int inputArr[10];           // ���� �迭
    int evenArr[10] = { -1 };     // ¦�� �迭 (-1�� �ʱ�ȭ)
    int oddArr[10] = { -1 };      // Ȧ�� �迭 (-1�� �ʱ�ȭ)
    int evenCount = 0;          // ¦�� ����
    int oddCount = 0;           // Ȧ�� ����
    int range = 101;            // ���� ���� (0~100)

    // �ʱ� �õ� �� ����
    int seed = (int)&size ^ (int)&inputArr ^ (int)&evenArr; // �޸� �ּ� ������ ���� ���� �õ� ����

    // ���� ���� �迭 ����
    printf("���� ���� �ڵ����� �����մϴ�.\n");
    for (int i = 0; i < size; ++i) {
        seed = (seed * 31 + i * 17 + (seed >> 2)) % 10007; // �õ� ���
        if (seed < 0) seed = -seed; // �õ� �� ��� ��ȯ
        inputArr[i] = seed % range; // 0~100 ������ ���� ����
    }

    // ������ �迭 ���
    printf("������ �迭: ");
    PrintArray(inputArr, size, size);

    // ¦���� Ȧ�� �и�
    CalcEvenOddArray(inputArr, size, evenArr, oddArr, &evenCount, &oddCount);

    // ¦�� �迭 ���
    printf("¦�� �迭: ");
    PrintArray(evenArr, size, evenCount);

    // Ȧ�� �迭 ���
    printf("Ȧ�� �迭: ");
    PrintArray(oddArr, size, oddCount);

    return 0;
}
