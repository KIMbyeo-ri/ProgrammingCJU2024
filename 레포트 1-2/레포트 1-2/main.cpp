#include <stdio.h>

int main(void)
{
	int insert = 0;
	int price = 0;
	int change = 0;
	int money100 = 0;
	int money500 = 0;
	int money1000 = 0;


	printf("������ �ݾ� �Է�:");
	scanf_s("%d", &insert);
	printf("���� �Է�:");
	scanf_s("%d", &price);


	change = insert - price;
	printf("�Ž����� %d \n", change);

	money1000 = change / 1000;
	change = change % 1000;

	money500 = change / 500;
	change = change % 500;

	money100 = change / 100;
	change = change % 100;

	printf("1000�� : %d��\n", money1000);
	printf("500�� : %d��\n", money500);
	printf("100�� : %d��\n", money100);

	return 0;


}