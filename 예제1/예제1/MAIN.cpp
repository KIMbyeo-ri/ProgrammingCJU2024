#include <stdio.h>

int main() {
    int num1, num2;
    char ca;
    int answer;

    printf("������ �Է��ϼ��� : ");
    scanf_s("%d %c %d", &num1, &ca, 1, &num2);

    if (ca == '+') {
        answer = num1 + num2;
    }
    else if (ca == '-') {
        answer = num1 - num2;
    }
    else if (ca == '*') {
        answer = num1 * num2;
    }
    else if (ca == '/') {
        if (num2 != 0) {
            answer = num1 / num2;
        }
        else {
            printf("0���� ���� �� �����ϴ�.\n");
            return 1; 
        }
    }
    else {
        printf("�߸��� a�Դϴ�.\n");
        return 1; 
    }

    
    printf("���: %d\n", answer);
    return 0;
}