#include <stdio.h>  // ����� �Լ� ����� ���� ��� ����
#include <math.h>   // ���� �Լ� ����� ���� ��� ���� (sqrt �Լ� ����)

// 3���� �������� ���� ��Ÿ���� ����ü ����
struct Point3D 
{
    double x; // ���� x��ǥ
    double y; // ���� y��ǥ
    double z; // ���� z��ǥ
};


 // @brief �� �� ������ ��Ŭ���� �Ÿ�(Euclidean Distance)�� ����ϴ� �Լ�
 // @param p1 ù ��° ���� ������
 // @param p2 �� ��° ���� ������
 // @return �� �� ������ �Ÿ�

 // ��Ŭ���� �Ÿ� ����:
 //   ��((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
double calculateDistance(struct Point3D* p1, struct Point3D* p2) 
{
    // �� ���� �� ��ǥ ���̸� ���
    double dx = p2->x - p1->x; // x��ǥ�� ����
    double dy = p2->y - p1->y; // y��ǥ�� ����
    double dz = p2->z - p1->z; // z��ǥ�� ����

    // ��Ŭ���� �Ÿ� ���� ����
    return sqrt(dx * dx + dy * dy + dz * dz);
}


 // @brief ����ڷκ��� 3���� ���� ��ǥ�� �Է¹޴� �Լ�
 // @param point �Է¹��� ��ǥ�� ������ struct Point3D ����ü�� ������
 // @param name ���� �̸� (��¿�)

void inputPoint(struct Point3D* point, const char* name)
{
    printf("%s�� ��ǥ�� �Է��ϼ��� (x, y, z): ", name);
    // scanf�� x, y, z ���� �Է¹޾� ����ü�� ����� ����
    scanf_s("%lf %lf %lf", &point->x, &point->y, &point->z);
}


//  @brief 3���� ���� ��ǥ�� ����ϴ� �Լ�
// @param point ����� struct Point3D ����ü�� ������
// @param name ���� �̸� (��¿�)

void printPoint(struct Point3D* point, const char* name) 
{
    // ����ü�� x, y, z ���� �о�� ���
    printf("%s: (%.2f, %.2f, %.2f)\n", name, point->x, point->y, point->z);
}

int main(void) 
{
    struct Point3D points[2]; // �� ���� 3���� ���� ������ �迭 ����

    // ù ��° ���� ��ǥ�� �Է¹���
    inputPoint(&points[0], "Point 1");
    // �� ��° ���� ��ǥ�� �Է¹���
    inputPoint(&points[1], "Point 2");

    // �Է¹��� �� ���� ��ǥ�� ���
    printPoint(&points[0], "Point 1");
    printPoint(&points[1], "Point 2");

    // �� �� ������ ��Ŭ���� �Ÿ��� ���
    double distance = calculateDistance(&points[0], &points[1]);
    // ���� �Ÿ��� ���
    printf("�� �� ������ ��Ŭ���� �Ÿ���: %.2f\n", distance);

    return 0;
}

