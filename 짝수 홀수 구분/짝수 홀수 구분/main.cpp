#include <stdio.h>

// 짝수와 홀수를 분리하여 저장하는 함수
// 입력: 원본 배열(input), 배열 크기(size)
// 출력: 짝수 배열(evenArr), 홀수 배열(oddArr), 짝수와 홀수의 개수
void CalcEvenOddArray(const int* input, int size, int* evenArr, int* oddArr, int* evenCount, int* oddCount) {
    *evenCount = 0; // 짝수 개수 초기화
    *oddCount = 0;  // 홀수 개수 초기화

    for (int i = 0; i < size; ++i) {
        if (input[i] % 2 == 0) { // 짝수인지 확인
            evenArr[*evenCount] = input[i];
            (*evenCount)++;
        }
        else { // 홀수인 경우
            oddArr[*oddCount] = input[i];
            (*oddCount)++;
        }
    }
}

// 배열을 출력하는 함수
// 입력: 배열(arr), 배열 크기(size), 실제 데이터 크기(validSize)
// 출력: 배열의 모든 요소를 출력하며, 유효하지 않은 인덱스는 "_"로 표시
void PrintArray(const int* arr, int size, int validSize) {
    for (int i = 0; i < size; ++i) {
        if (i < validSize)
            printf("%d ", arr[i]); // 실제 데이터 출력
        else
            printf("_ "); // 사용되지 않은 공간은 "_"로 출력
    }
    printf("\n"); // 줄바꿈
}

// 메인 함수
int main(void) {
    int size = 10;              // 원본 배열 크기
    int inputArr[10];           // 원본 배열
    int evenArr[10] = { -1 };     // 짝수 배열 (-1로 초기화)
    int oddArr[10] = { -1 };      // 홀수 배열 (-1로 초기화)
    int evenCount = 0;          // 짝수 개수
    int oddCount = 0;           // 홀수 개수
    int range = 101;            // 값의 범위 (0~100)

    // 초기 시드 값 설정
    int seed = (int)&size ^ (int)&inputArr ^ (int)&evenArr; // 메모리 주소 조합을 통한 랜덤 시드 설정

    // 랜덤 정수 배열 생성
    printf("랜덤 값을 자동으로 생성합니다.\n");
    for (int i = 0; i < size; ++i) {
        seed = (seed * 31 + i * 17 + (seed >> 2)) % 10007; // 시드 계산
        if (seed < 0) seed = -seed; // 시드 값 양수 변환
        inputArr[i] = seed % range; // 0~100 사이의 정수 생성
    }

    // 생성된 배열 출력
    printf("생성된 배열: ");
    PrintArray(inputArr, size, size);

    // 짝수와 홀수 분리
    CalcEvenOddArray(inputArr, size, evenArr, oddArr, &evenCount, &oddCount);

    // 짝수 배열 출력
    printf("짝수 배열: ");
    PrintArray(evenArr, size, evenCount);

    // 홀수 배열 출력
    printf("홀수 배열: ");
    PrintArray(oddArr, size, oddCount);

    return 0;
}
