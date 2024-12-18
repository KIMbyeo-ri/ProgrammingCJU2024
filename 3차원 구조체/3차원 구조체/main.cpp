#include <stdio.h>  // 입출력 함수 사용을 위한 헤더 파일
#include <math.h>   // 수학 함수 사용을 위한 헤더 파일 (sqrt 함수 포함)

// 3차원 공간에서 점을 나타내는 구조체 정의
struct Point3D 
{
    double x; // 점의 x좌표
    double y; // 점의 y좌표
    double z; // 점의 z좌표
};


 // @brief 두 점 사이의 유클리드 거리(Euclidean Distance)를 계산하는 함수
 // @param p1 첫 번째 점의 포인터
 // @param p2 두 번째 점의 포인터
 // @return 두 점 사이의 거리

 // 유클리드 거리 공식:
 //   √((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
double calculateDistance(struct Point3D* p1, struct Point3D* p2) 
{
    // 두 점의 각 좌표 차이를 계산
    double dx = p2->x - p1->x; // x좌표의 차이
    double dy = p2->y - p1->y; // y좌표의 차이
    double dz = p2->z - p1->z; // z좌표의 차이

    // 유클리드 거리 공식 적용
    return sqrt(dx * dx + dy * dy + dz * dz);
}


 // @brief 사용자로부터 3차원 점의 좌표를 입력받는 함수
 // @param point 입력받은 좌표를 저장할 struct Point3D 구조체의 포인터
 // @param name 점의 이름 (출력용)

void inputPoint(struct Point3D* point, const char* name)
{
    printf("%s의 좌표를 입력하세요 (x, y, z): ", name);
    // scanf로 x, y, z 값을 입력받아 구조체의 멤버에 저장
    scanf_s("%lf %lf %lf", &point->x, &point->y, &point->z);
}


//  @brief 3차원 점의 좌표를 출력하는 함수
// @param point 출력할 struct Point3D 구조체의 포인터
// @param name 점의 이름 (출력용)

void printPoint(struct Point3D* point, const char* name) 
{
    // 구조체의 x, y, z 값을 읽어와 출력
    printf("%s: (%.2f, %.2f, %.2f)\n", name, point->x, point->y, point->z);
}

int main(void) 
{
    struct Point3D points[2]; // 두 개의 3차원 점을 저장할 배열 선언

    // 첫 번째 점의 좌표를 입력받음
    inputPoint(&points[0], "Point 1");
    // 두 번째 점의 좌표를 입력받음
    inputPoint(&points[1], "Point 2");

    // 입력받은 두 점의 좌표를 출력
    printPoint(&points[0], "Point 1");
    printPoint(&points[1], "Point 2");

    // 두 점 사이의 유클리드 거리를 계산
    double distance = calculateDistance(&points[0], &points[1]);
    // 계산된 거리를 출력
    printf("두 점 사이의 유클리드 거리는: %.2f\n", distance);

    return 0;
}

