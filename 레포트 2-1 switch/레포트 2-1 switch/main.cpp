#include <stdio.h>

int main(void) {
    int num;

    printf("������ �Է��ϼ���:");
    scanf_s("%d", &num);

    switch (num % 2) {
   
    case 0:
        printf("%d�� ¦���Դϴ�.\n", num);
       
        break;
   
    case 1:
        printf("%d�� Ȧ���Դϴ�.\n", num);
      
        break;
    }

    return 0;
}
