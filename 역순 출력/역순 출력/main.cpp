#include <stdio.h>

// 배열을 역순으로 계산하는 함수
// 입력: 원본 배열 포인터(input), 배열 크기(size)
// 출력: 역순으로 계산된 배열(output)
void CalcInverseArray(const double* input, double* output, int size)
{
    for (int i = 0; i < size; ++i)
    {
        // 입력 배열의 마지막 요소부터 값을 복사하여 출력 배열에 저장
        output[i] = input[size - i - 1];
    }
}

// 배열을 출력하는 함수
// 입력: 배열 포인터(arr), 배열 크기(size)
void PrintArray(const double* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        // 배열의 각 요소를 소수점 한 자리까지 출력
        printf("%.1f ", arr[i]);
    }
    printf("\n"); // 한 줄 출력이 끝난 뒤 줄바꿈
}

// 메인 함수
int main(void)
{
    // 배열 크기를 상수로 정의
#define size 10
    double arr[size];       // 원본 배열 선언
    double reversed[size];  // 역순 배열 선언
    double minVal = -100.0; // 배열 값의 최소 범위
    double maxVal = 100.0;  // 배열 값의 최대 범위
    double range = maxVal - minVal; // 난수 생성 범위 계산
    int seed = (int)&arr;   // 배열 메모리 주소를 기반으로 난수 생성 시드 초기화
    int isInteger;          // 정수(1) 또는 실수(0) 선택을 저장하는 변수

    // 사용자 입력: 정수/실수 선택
    printf("배열에 사용할 값의 유형을 선택하세요 (1: 정수, 0: 실수): ");
    scanf_s("%d", &isInteger); // 사용자 입력값을 읽어와 isInteger에 저장

    // 배열 값 생성
    printf("랜덤 값을 자동으로 생성합니다.\n");
    for (int i = 0; i < size; ++i)
    {
        // 난수를 생성하기 위한 계산. seed 값을 계속 변화시켜 난수 다양성 증가
        seed = (seed * 31 + i * 17 + (seed >> 2)) % 10007;
        if (seed < 0) seed = -seed; // seed 값을 양수로 변환

        // 사용자 선택에 따라 정수 또는 실수 값 생성
        if (isInteger)
        {
            arr[i] = (int)((seed % 1000) / 1000.0 * range + minVal); // 정수 생성
        }
        else
        {
            arr[i] = (seed % 1000) / 1000.0 * range + minVal; // 실수 생성
        }
    }

    // 생성된 배열 출력
    printf("생성된 배열: ");
    PrintArray(arr, size);

    // 배열의 역순 계산
    CalcInverseArray(arr, reversed, size);

    // 역순 배열 출력
    printf("역순 배열: ");
    PrintArray(reversed, size);

    return 0;
}
