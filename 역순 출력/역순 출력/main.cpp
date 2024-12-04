#include <stdio.h>

// �迭�� �������� ����ϴ� �Լ�
// �Է�: ���� �迭 ������(input), �迭 ũ��(size)
// ���: �������� ���� �迭(output)
void CalcInverseArray(const double* input, double* output, int size)
{
    for (int i = 0; i < size; ++i)
    {
        // �Է� �迭�� ������ ��Һ��� ���� �����Ͽ� ��� �迭�� ����
        output[i] = input[size - i - 1];
    }
}

// �迭�� ����ϴ� �Լ�
// �Է�: �迭 ������(arr), �迭 ũ��(size)
void PrintArray(const double* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        // �迭�� �� ��Ҹ� �Ҽ��� �� �ڸ����� ���
        printf("%.1f ", arr[i]);
    }
    printf("\n"); // �� �� ����� ���� �� �ٹٲ�
}

// ���� �Լ�
int main(void)
{
    // �迭 ũ�⸦ ����� ����
#define size 10
    double arr[size];       // ���� �迭 ����
    double reversed[size];  // ���� �迭 ����
    double minVal = -100.0; // �迭 ���� �ּ� ����
    double maxVal = 100.0;  // �迭 ���� �ִ� ����
    double range = maxVal - minVal; // ���� ���� ���� ���
    int seed = (int)&arr;   // �迭 �޸� �ּҸ� ������� ���� ���� �õ� �ʱ�ȭ
    int isInteger;          // ����(1) �Ǵ� �Ǽ�(0) ������ �����ϴ� ����

    // ����� �Է�: ����/�Ǽ� ����
    printf("�迭�� ����� ���� ������ �����ϼ��� (1: ����, 0: �Ǽ�): ");
    scanf_s("%d", &isInteger); // ����� �Է°��� �о�� isInteger�� ����

    // �迭 �� ����
    printf("���� ���� �ڵ����� �����մϴ�.\n");
    for (int i = 0; i < size; ++i)
    {
        // ������ �����ϱ� ���� ���. seed ���� ��� ��ȭ���� ���� �پ缺 ����
        seed = (seed * 31 + i * 17 + (seed >> 2)) % 10007;
        if (seed < 0) seed = -seed; // seed ���� ����� ��ȯ

        // ����� ���ÿ� ���� ���� �Ǵ� �Ǽ� �� ����
        if (isInteger)
        {
            arr[i] = (int)((seed % 1000) / 1000.0 * range + minVal); // ���� ����
        }
        else
        {
            arr[i] = (seed % 1000) / 1000.0 * range + minVal; // �Ǽ� ����
        }
    }

    // ������ �迭 ���
    printf("������ �迭: ");
    PrintArray(arr, size);

    // �迭�� ���� ���
    CalcInverseArray(arr, reversed, size);

    // ���� �迭 ���
    printf("���� �迭: ");
    PrintArray(reversed, size);

    return 0;
}
