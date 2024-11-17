#include <stdio.h>

int main(void) {
    // ���� ����
    int numFlip = 10000;  //������ ���� Ƚ��
    int heads = 0;
    int tails = 0; // �ո�� �޸��� ���� Ƚ���� ������ ����

    // �ǻ� ������ ���� �ʱ� �õ� ��
    int seed = 1; // ������ �����ϱ� ���� �ʱⰪ. �ǻ� ���� ������ ����

    // ���� ������ �ݺ�
    for (int i = 0; i < numFlip; i++) {
        seed += i; // �õ� ���� ������Ʈ�Ͽ� �ǻ� ���� ������ ��ȭ�� ��
        int result = (seed * 1103515245 + 12345) % 2; // ���� ���� ��
        // 0 �Ǵ� 1 ���� ����
        // `seed` ���� ���������� ó���� ��¥ ������ �����ϸ�,
        // `% 2`�� ����� ����� 0(�޸�) �Ǵ� 1(�ո�)���� ����

        // ���ù��� ����Ͽ� ����� �з�
        if (result == 1) {
            heads++; // ����� 1�� ���, �ո� ī��Ʈ�� ����
        }
        else {
            tails++; // ����� 0�� ���, �޸� ī��Ʈ�� ����
        }
    }

    // Ȯ�� ���
    double headsProbability = (double)heads / numFlip * 100; // �ո� Ȯ�� ���
    double tailsProbability = (double)tails / numFlip * 100; // �޸� Ȯ�� ���
    // �� ����� ���� �� Ƚ��(numFlips)�� ������ ������� ��ȯ

    // ��� ���
    printf("�� ���� ������ Ƚ��: %d\n", numFlip);
    // ������ ���� �� Ƚ�� ���
    printf("�ո�: %d�� (%.2f%%)\n", heads, headsProbability);
    // �ո��� ���� Ƚ���� Ȯ�� ���
    printf("�޸�: %d�� (%.2f%%)\n", tails, tailsProbability);
    // �޸��� ���� Ƚ���� Ȯ�� ���

    return 0;
}
