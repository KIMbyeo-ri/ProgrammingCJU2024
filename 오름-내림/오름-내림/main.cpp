#include <stdio.h>

// �迭�� �����ϴ� �Լ�
void CalcSortArray(double arr[], int size, int ascending)
{
    // ���� ���� �˰���: �迭�� ���� �������� �Ǵ� ������������ ����
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1]))
            {
                double temp = arr[j]; // ��ȯ�� ���� �ӽ� ����
                arr[j] = arr[j + 1];  // �� ��ȯ
                arr[j + 1] = temp;    // �� ��ȯ
            }
        }
    }
}

// �迭�� ����ϴ� �Լ�
void PrintArray(const double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%.1f ", arr[i]); // �Ҽ��� �� �ڸ����� ���
    }
    printf("\n"); // ��� �� �ٹٲ�
}

int main(void)
{
    double arr[10];         // �迭 ����
    int size = 10;          // �迭 ũ��
    double minVal = -100.0; // �Ǽ� ���� �ּҰ�
    double maxVal = 100.0;  // �Ǽ� ���� �ִ밪
    int intMinVal = -100;   // ���� ���� �ּҰ�
    int intMaxVal = 100;    // ���� ���� �ִ밪
    int range = intMaxVal - intMinVal; // ���� ���� ����
    int option;             // ���� �ɼ� (1: �Ǽ�, 0: ����)
    int ascending;          // ���� ���� (1: ��������, 0: ��������)
    int seed = (int)&arr;   // �ʱ� �õ� ���� �迭 �޸� �ּҷ� ����

    // ���� ���� �ɼ� ����
    printf("���� ������ �����ϼ��� (1: �Ǽ�, 0: ����): ");
    scanf_s("%d", &option);

    // �迭 ����
    printf("���� ���� �ڵ����� �����մϴ�.\n");
    for (int i = 0; i < size; ++i)
    {
        seed = (seed * 31 + i * 17 + (seed >> 2)) % 10007; // �õ� ���
        if (seed < 0) seed = -seed; // �õ� ���� ����� ��ȯ

        if (option)
        {
            // �Ǽ� ����: 0.0���� 0.999������ ���� ����(minVal ~ maxVal)�� ��ȯ
            arr[i] = (seed % 1000) / 1000.0 * (maxVal - minVal) + minVal;
        }
        else
        {
            // ���� ����: ���� ����(intMinVal ~ intMaxVal)�� ��ȯ
            arr[i] = seed % range + intMinVal;
        }
    }

    // ������ �迭 ���
    printf("������ �迭: ");
    PrintArray(arr, size);

    // ���� ��� ����
    printf("���� ����� �����ϼ��� (1: ��������, 0: ��������): ");
    scanf_s("%d", &ascending);

    // ���õ� ������� �迭 ����
    CalcSortArray(arr, size, ascending);

    // ���ĵ� �迭 ���
    printf("%s���� ���ĵ� �迭: ", ascending ? "��������" : "��������"); //? = ���� ���� ������ : ��(1) or ����(0) ����
    PrintArray(arr, size);

    return 0;
}
