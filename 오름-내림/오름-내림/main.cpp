#include <stdio.h>

// 배열을 정렬하는 함수
void CalcSortArray(double arr[], int size, int ascending)
{
    // 버블 정렬 알고리즘: 배열의 값을 오름차순 또는 내림차순으로 정렬
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1]))
            {
                double temp = arr[j]; // 교환을 위한 임시 변수
                arr[j] = arr[j + 1];  // 값 교환
                arr[j + 1] = temp;    // 값 교환
            }
        }
    }
}

// 배열을 출력하는 함수
void PrintArray(const double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%.1f ", arr[i]); // 소수점 한 자리까지 출력
    }
    printf("\n"); // 출력 후 줄바꿈
}

int main(void)
{
    double arr[10];         // 배열 선언
    int size = 10;          // 배열 크기
    double minVal = -100.0; // 실수 난수 최소값
    double maxVal = 100.0;  // 실수 난수 최대값
    int intMinVal = -100;   // 정수 난수 최소값
    int intMaxVal = 100;    // 정수 난수 최대값
    int range = intMaxVal - intMinVal; // 정수 난수 범위
    int option;             // 난수 옵션 (1: 실수, 0: 정수)
    int ascending;          // 정렬 방향 (1: 오름차순, 0: 내림차순)
    int seed = (int)&arr;   // 초기 시드 값을 배열 메모리 주소로 설정

    // 난수 생성 옵션 선택
    printf("난수 유형을 선택하세요 (1: 실수, 0: 정수): ");
    scanf_s("%d", &option);

    // 배열 생성
    printf("랜덤 값을 자동으로 생성합니다.\n");
    for (int i = 0; i < size; ++i)
    {
        seed = (seed * 31 + i * 17 + (seed >> 2)) % 10007; // 시드 계산
        if (seed < 0) seed = -seed; // 시드 값을 양수로 변환

        if (option)
        {
            // 실수 생성: 0.0에서 0.999까지의 값을 범위(minVal ~ maxVal)로 변환
            arr[i] = (seed % 1000) / 1000.0 * (maxVal - minVal) + minVal;
        }
        else
        {
            // 정수 생성: 정수 범위(intMinVal ~ intMaxVal)로 변환
            arr[i] = seed % range + intMinVal;
        }
    }

    // 생성된 배열 출력
    printf("생성된 배열: ");
    PrintArray(arr, size);

    // 정렬 방식 선택
    printf("정렬 방식을 선택하세요 (1: 오름차순, 0: 내림차순): ");
    scanf_s("%d", &ascending);

    // 선택된 방식으로 배열 정렬
    CalcSortArray(arr, size, ascending);

    // 정렬된 배열 출력
    printf("%s으로 정렬된 배열: ", ascending ? "오름차순" : "내림차순"); //? = 삼항 조건 연산자 : 참(1) or 거짓(0) 구분
    PrintArray(arr, size);

    return 0;
}
