#include <stdio.h>

int main(void)
{
	int insert = 0;
	int price = 0;
	int change = 0;
	int money100 = 0;
	int money500 = 0;
	int money1000 = 0;


	printf("투입한 금액 입력:");
	scanf_s("%d", &insert);
	printf("가격 입력:");
	scanf_s("%d", &price);


	change = insert - price;
	printf("거스름돈 %d \n", change);

	money1000 = change / 1000;
	change = change % 1000;

	money500 = change / 500;
	change = change % 500;

	money100 = change / 100;
	change = change % 100;

	printf("1000원 : %d개\n", money1000);
	printf("500원 : %d개\n", money500);
	printf("100원 : %d개\n", money100);

	return 0;


}