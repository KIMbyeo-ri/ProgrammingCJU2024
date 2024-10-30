#include <stdio.h>

int main(void) 
{
    int choice;           
    double T, CT;          


    printf("온도 변환 프로그램\n");
    printf("1: 섭씨 -> 화씨\n");
    printf("2: 화씨 -> 섭씨\n");
    printf("변환 방법 선택 (1 또는 2):");

 
    scanf_s("%d", &choice);

    //섭씨 -> 화씨 변환
    if (choice == 1) {
        printf("섭씨 온도를 입력하세요: ");

        //섭씨 온도를 입력받아 C에 저장
        scanf_s("%lf", &T);

        //섭씨 -> 화씨 변환 공식
        CT = (T * 9 / 5) + 32;

        //변환 결과를 화씨 온도로 출력
        printf("화씨 온도: %.2f°F\n", CT);
    }

    //화씨 -> 섭씨 변환
    else if (choice == 2) {
        printf("화씨 온도를 입력하세요: ");

        //화씨 온도를 입력받아 C에 저장
        scanf_s("%lf", &T);

        //화씨 -> 섭씨 변환 공식
        CT = (T - 32) * 5 / 9;

        //변환 결과를 섭씨 온도로 출력
        printf("섭씨 온도: %.2f°C\n", CT);
    }

    //잘못된 입력
    else {
       
        //오류 메시지 출력
        printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
    }

    return 0;
}

