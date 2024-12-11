#include<stdio.h>
#include<string.h>

// �ܾ ������ �Լ�
// �־��� ���� ������(start)�� �� ������(end) ������ ���ڿ��� ������
void reverseWord(char* start, char* end) 
{
    while (start < end) 
    { 
        // ���� �����Ͱ� �� �����ͺ��� ���� ������ �ݺ�
        char temp = *start; // �ӽ� ������ ���� ������ ���� ����
        *start = *end;      // �� ������ ���� ���� �����Ϳ� ����
        *end = temp;        // �ӽ� ���� ���� �� �����Ϳ� ����
        start++;            // ���� �����͸� ���� ���ڷ� �̵�
        end--;              // �� �����͸� ���� ���ڷ� �̵�
    }
}

int main(void) 
{
    char input[100]; // ����� �Է��� ������ �迭

    printf("���� �Է� : ");
    fgets(input, sizeof(input), stdin); // ����ڷκ��� ���ڿ� �Է� ����

   
    // fgets�� �Է¹����� �ٹٲ� ����('\n')�� ���� -> \n ����
    input[strcspn(input, "\n")] = '\0'; // '\n' ���ڸ� '\0'(���ڿ� ��)�� ��ü

   
    printf("before reversing words : \"%s\"\n", input); // ���� ���ڿ� ���

   
    char* wordStart = NULL; // ���� �ܾ��� ���� ��ġ�� ������ ������
    char* temp = input;     // �Է� ���ڿ��� ��ȸ�ϱ� ���� ������

   
    // �Է� ���ڿ��� �� ���ھ� ��ȸ
    while (*temp != '\0') 
    { 
        // ���ڿ� ��('\0')�� ������ ������ �ݺ�
        if (wordStart == NULL && *temp != ' ') 
        {
            
            // ���� ���ڰ� ������ �ƴϰ�, �ܾ��� ���� ��ġ�� ���� �������� ���� ���
            wordStart = temp; // �ܾ��� ���� ��ġ ����
       
        }

        if (wordStart != NULL && (*temp == ' ' || *(temp + 1) == '\0'))
        {
       
            // �ܾ��� ���� ������ �� (���� �����̰ų� ���ڿ� ���� ���)
            char* wordEnd = (*temp == ' ') ? (temp - 1) : temp; // �ܾ��� �� ��ġ ����
            reverseWord(wordStart, wordEnd); // ���� �ܾ ������
            wordStart = NULL; // ���� �ܾ ���� �ܾ� ���� ��ġ �ʱ�ȭ
        
        }

        temp++; // ���� ���ڷ� �̵�
    }

    printf("after reversing words : \"%s\"\n", input); // ��� ���ڿ� ���

    return 0;
}
