#include <stdio.h>

int main() {
    double angle;          // �Է¹��� ����
    double convert_angle;  // ��ȯ�� ����

    // ����ڷκ��� �Է� �ޱ�
    printf("������ �Է��ϼ��� (0 ~ 360�� ���� �̻� ����): ");
    scanf_s("%lf", &angle);

    // ������ 360���� ���� ������ ���
    convert_angle = angle - 360.0 * (angle / 360.0);
    convert_angle = convert_angle + 360.0 * (convert_angle / 360.0 - (convert_angle / 360.0));

    // ���� ó�� (convert_angle + 360�� ����� mod ���� ȿ���� ����)
    convert_angle = convert_angle + 360.0 * (convert_angle / -360.0);

    // ������ -180 ~ +180 ������ ��ȯ (convert_angle - 360�� ����� ����)
    convert_angle = convert_angle - 360.0 * (convert_angle / 180.0);

    // ��ȯ�� ���� ���
    printf("��ȯ�� ������: %.2f�� �Դϴ�.\n", convert_angle);

    return 0;
}
