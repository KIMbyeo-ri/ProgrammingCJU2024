#include <stdio.h>

int main() {
    double angle;          // 입력받은 각도
    double convert_angle;  // 변환된 각도

    // 사용자로부터 입력 받기
    printf("각도를 입력하세요 (0 ~ 360도 범위 이상도 가능): ");
    scanf_s("%lf", &angle);

    // 각도를 360도로 나눈 나머지 계산
    convert_angle = angle - 360.0 * (angle / 360.0);
    convert_angle = convert_angle + 360.0 * (convert_angle / 360.0 - (convert_angle / 360.0));

    // 음수 처리 (convert_angle + 360을 계산해 mod 연산 효과를 얻음)
    convert_angle = convert_angle + 360.0 * (convert_angle / -360.0);

    // 각도를 -180 ~ +180 범위로 변환 (convert_angle - 360을 계산해 조정)
    convert_angle = convert_angle - 360.0 * (convert_angle / 180.0);

    // 변환된 각도 출력
    printf("변환된 각도는: %.2f도 입니다.\n", convert_angle);

    return 0;
}
