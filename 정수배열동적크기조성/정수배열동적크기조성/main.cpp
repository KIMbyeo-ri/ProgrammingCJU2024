#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �Լ� ����
// �Լ� �̸�: calculate_statistics
// �� �Լ��� �迭�� ��踦 ����մϴ�. (�հ�, ���, �л�, ǥ������)
// �Ű�����:
// - array: ���� �迭 (��� ���)
// - size: �迭�� ũ��
// - sum, mean, variance, std_dev: ��� ����� ������ ������ ������
void calculate_statistics(int* array, int size, double* sum, double* mean, double* variance, double* std_dev) 
{
    *sum = 0; // �հ踦 0���� �ʱ�ȭ
    for (int i = 0; i < size; i++)  // �迭�� ��� ��Ҹ� ����
    {
        *sum += array[i];
    }
    *mean = *sum / size; // ��� ���

    *variance = 0; // �л��� 0���� �ʱ�ȭ
    for (int i = 0; i < size; i++) // �л� ���: (�� - ���)^2�� ��
    {
        *variance += pow(array[i] - *mean, 2);
    }
    *variance /= size; // �л� = �հ� / ũ��
    *std_dev = sqrt(*variance); // ǥ������ = �л��� ������
}

int main(void)
{
    int initial_size, additional_size; // �ʱ� �迭 ũ��� �߰� �迭 ũ�⸦ ������ ����
    double sum, mean, variance, std_dev; // ��� ����� ������ ����

    // �ʱ� �迭 ũ�� �Է¹ޱ�
    printf("�ʱ� �迭 ũ��: ");
    scanf_s("%d", &initial_size); // ����ڷκ��� �ʱ� �迭 ũ�� �Է�

    // ���� �޸� �Ҵ�
    // ����ڷκ��� �Է¹��� ũ�⸸ŭ ���� �迭 ����
    int* array = (int*)malloc(initial_size * sizeof(int));
    if (array == NULL)  // �޸� �Ҵ� ���� �� ���α׷� ����
    {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    // �迭 �� �Է¹ޱ�
    printf("�Է��� ��: ");
    for (int i = 0; i < initial_size; i++) 
    {
        scanf_s("%d", &array[i]); // ����ڰ� �迭�� �� ���� �Է�
    }

    // ��� ���: �迭�� �հ�, ���, �л�, ǥ������ ���
    calculate_statistics(array, initial_size, &sum, &mean, &variance, &std_dev);
    // ��� ��� ���
    printf("�հ�: %.2lf\n", sum);
    printf("���: %.2lf\n", mean);
    printf("�л�: %.2lf\n", variance);
    printf("ǥ������: %.2lf\n", std_dev);

    // �߰� �迭 ũ�� �Է¹ޱ�
    printf("�߰� �迭 ũ��: ");
    scanf_s("%d", &additional_size); // �߰� �迭 ũ�� �Է�

    // ���� �迭 ũ�� Ȯ��
    // ���� �迭�� �߰� ũ�⸸ŭ �޸� ���Ҵ�
    array = (int*)realloc(array, (initial_size + additional_size) * sizeof(int));
    if (array == NULL) // �޸� ���Ҵ� ���� �� ���α׷� ����
    {
        printf("�޸� ���Ҵ� ����\n");
        return 1;
    }

    // �߰� �� �Է¹ޱ�
    printf("�߰��� ��: ");
    for (int i = 0; i < additional_size; i++) 
    {
        // ���ο� �迭�� Ȯ��� �κп� ���� �Է�
        scanf_s("%d", &array[initial_size + i]);
    }

    // Ȯ��� �迭�� ���� ��� ���
    calculate_statistics(array, initial_size + additional_size, &sum, &mean, &variance, &std_dev);
    // ���ο� ��� ��� ���
    printf("���ο� �հ�: %.2lf\n", sum);
    printf("���ο� ���: %.2lf\n", mean);
    printf("���ο� �л�: %.2lf\n", variance);
    printf("���ο� ǥ������: %.2lf\n", std_dev);

    // �������� �Ҵ�� �޸� ����
    free(array);
    return 0; // ���α׷� ���� ����
}
