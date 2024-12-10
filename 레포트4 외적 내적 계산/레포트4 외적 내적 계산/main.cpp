#include <stdio.h> // 입출력 함수 사용을 위한 헤더 파일

// 함수 선언
void calculateDotProduct(int* v1, int* v2, int* dotProduct); // 내적 계산 함수
void calculateCrossProduct(int* v1, int* v2, int* crossProduct); // 외적 계산 함수

int main(void) {
    // 3차원 벡터를 저장할 배열 선언
    int vector1[3], vector2[3];

    // 내적 결과를 저장할 변수
    int dotProduct = 0;

    // 외적 결과를 저장할 배열
    int crossProduct[3];

    // 벡터 1 입력
    printf("벡터 1의 x, y, z 값을 입력하세요: ");
    scanf_s("%d %d %d", &vector1[0], &vector1[1], &vector1[2]); // 사용자가 벡터 1의 성분 입력

    // 벡터 2 입력
    printf("벡터 2의 x, y, z 값을 입력하세요: ");
    scanf_s("%d %d %d", &vector2[0], &vector2[1], &vector2[2]); // 사용자가 벡터 2의 성분 입력

    // 내적 계산
    calculateDotProduct(vector1, vector2, &dotProduct); // vector1과 vector2의 내적 결과를 dotProduct에 저장

    // 외적 계산
    calculateCrossProduct(vector1, vector2, crossProduct); // vector1과 vector2의 외적 결과를 crossProduct 배열에 저장

    // 계산 결과 출력
    printf("\n내적 결과: %d\n", dotProduct); // 내적 결과 출력
    printf("외적 결과: (%d, %d, %d)\n", crossProduct[0], crossProduct[1], crossProduct[2]); // 외적 결과 출력

    return 0; // 프로그램 종료
}

// 내적 계산 함수
void calculateDotProduct(int* v1, int* v2, int* dotProduct) {
    // 내적 계산 공식: v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]
    *dotProduct = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    // 계산된 값을 dotProduct 변수에 저장
}

// 외적 계산 함수
void calculateCrossProduct(int* v1, int* v2, int* crossProduct) {
    // 외적의 각 성분 계산
    crossProduct[0] = v1[1] * v2[2] - v1[2] * v2[1]; // x 성분 계산
    crossProduct[1] = v1[2] * v2[0] - v1[0] * v2[2]; // y 성분 계산
    crossProduct[2] = v1[0] * v2[1] - v1[1] * v2[0]; // z 성분 계산
    // 계산된 값을 crossProduct 배열에 저장
}
