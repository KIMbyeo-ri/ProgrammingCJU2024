#include<stdio.h>
#include<string.h>

// 단어를 뒤집는 함수
// 주어진 시작 포인터(start)와 끝 포인터(end) 사이의 문자열을 뒤집음
void reverseWord(char* start, char* end) 
{
    while (start < end) 
    { 
        // 시작 포인터가 끝 포인터보다 작을 때까지 반복
        char temp = *start; // 임시 변수에 시작 포인터 값을 저장
        *start = *end;      // 끝 포인터 값을 시작 포인터에 복사
        *end = temp;        // 임시 변수 값을 끝 포인터에 복사
        start++;            // 시작 포인터를 다음 문자로 이동
        end--;              // 끝 포인터를 이전 문자로 이동
    }
}

int main(void) 
{
    char input[100]; // 사용자 입력을 저장할 배열

    printf("문장 입력 : ");
    fgets(input, sizeof(input), stdin); // 사용자로부터 문자열 입력 받음

   
    // fgets로 입력받으면 줄바꿈 문자('\n')도 포함 -> \n 제거
    input[strcspn(input, "\n")] = '\0'; // '\n' 문자를 '\0'(문자열 끝)로 대체

   
    printf("before reversing words : \"%s\"\n", input); // 원본 문자열 출력

   
    char* wordStart = NULL; // 현재 단어의 시작 위치를 저장할 포인터
    char* temp = input;     // 입력 문자열을 순회하기 위한 포인터

   
    // 입력 문자열을 한 글자씩 순회
    while (*temp != '\0') 
    { 
        // 문자열 끝('\0')에 도달할 때까지 반복
        if (wordStart == NULL && *temp != ' ') 
        {
            
            // 현재 문자가 공백이 아니고, 단어의 시작 위치가 아직 설정되지 않은 경우
            wordStart = temp; // 단어의 시작 위치 설정
       
        }

        if (wordStart != NULL && (*temp == ' ' || *(temp + 1) == '\0'))
        {
       
            // 단어의 끝을 만났을 때 (공백 문자이거나 문자열 끝인 경우)
            char* wordEnd = (*temp == ' ') ? (temp - 1) : temp; // 단어의 끝 위치 설정
            reverseWord(wordStart, wordEnd); // 현재 단어를 뒤집음
            wordStart = NULL; // 다음 단어를 위해 단어 시작 위치 초기화
        
        }

        temp++; // 다음 문자로 이동
    }

    printf("after reversing words : \"%s\"\n", input); // 결과 문자열 출력

    return 0;
}
