#include <stdio.h> // ����� �Լ� ����� ���� ��� ����

// �Լ� ����
void calculateDotProduct(int* v1, int* v2, int* dotProduct); // ���� ��� �Լ�
void calculateCrossProduct(int* v1, int* v2, int* crossProduct); // ���� ��� �Լ�

int main(void) {
    // 3���� ���͸� ������ �迭 ����
    int vector1[3], vector2[3];

    // ���� ����� ������ ����
    int dotProduct = 0;

    // ���� ����� ������ �迭
    int crossProduct[3];

    // ���� 1 �Է�
    printf("���� 1�� x, y, z ���� �Է��ϼ���: ");
    scanf_s("%d %d %d", &vector1[0], &vector1[1], &vector1[2]); // ����ڰ� ���� 1�� ���� �Է�

    // ���� 2 �Է�
    printf("���� 2�� x, y, z ���� �Է��ϼ���: ");
    scanf_s("%d %d %d", &vector2[0], &vector2[1], &vector2[2]); // ����ڰ� ���� 2�� ���� �Է�

    // ���� ���
    calculateDotProduct(vector1, vector2, &dotProduct); // vector1�� vector2�� ���� ����� dotProduct�� ����

    // ���� ���
    calculateCrossProduct(vector1, vector2, crossProduct); // vector1�� vector2�� ���� ����� crossProduct �迭�� ����

    // ��� ��� ���
    printf("\n���� ���: %d\n", dotProduct); // ���� ��� ���
    printf("���� ���: (%d, %d, %d)\n", crossProduct[0], crossProduct[1], crossProduct[2]); // ���� ��� ���

    return 0; // ���α׷� ����
}

// ���� ��� �Լ�
void calculateDotProduct(int* v1, int* v2, int* dotProduct) {
    // ���� ��� ����: v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]
    *dotProduct = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    // ���� ���� dotProduct ������ ����
}

// ���� ��� �Լ�
void calculateCrossProduct(int* v1, int* v2, int* crossProduct) {
    // ������ �� ���� ���
    crossProduct[0] = v1[1] * v2[2] - v1[2] * v2[1]; // x ���� ���
    crossProduct[1] = v1[2] * v2[0] - v1[0] * v2[2]; // y ���� ���
    crossProduct[2] = v1[0] * v2[1] - v1[1] * v2[0]; // z ���� ���
    // ���� ���� crossProduct �迭�� ����
}
