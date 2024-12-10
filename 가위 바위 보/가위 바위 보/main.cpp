#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rock_scissors_paper 3
#define rock 0
#define paper 1
#define scissors 2
#define INITSTATUS 100
#define END_COND 999

void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

void DetermineWinner(unsigned int player, unsigned int computer)
{
    if (player == computer)
    {
        printf("비겼습니다\n");
    }
    else if ((player == rock && computer == scissors) ||
             (player == paper && computer == rock) ||
             (player == scissors && computer == paper))
    {
        printf("Player 승리\n");
    }
    else
    {
        printf("Computer 승리\n");
    }
}

int main(void)
{
    // 난수 생성을 위한 시드 설정
    GenRandSeed();

    unsigned int nComRps = INITSTATUS;
    unsigned int nPlyRps = INITSTATUS;

    while (1)
    {
        // 사용자 입력 받기
        printf("가위 바위 보 입력(0 = 가위, 1 = 바위, 2 = 보):\n");
        printf("종료하려면 999를 입력하세요\n");
        scanf_s("%d", &nPlyRps);

        // 종료 조건 확인
        if (nPlyRps == END_COND)
        {
            printf("게임을 종료합니다...\n");
            break;
        }
        else if (nPlyRps < 0 || nPlyRps >= rock_scissors_paper)
        {
            printf("잘못된 입력입니다. 다시 입력하세요.\n\n");
            continue;
        }

        // 컴퓨터의 가위바위보 선택
        nComRps = GenRandNum(rock_scissors_paper);

        // 결과 출력
        printf("(Player, Computer): (%d, %d)\n", nPlyRps, nComRps);

        // 승자 판단
        DetermineWinner(nPlyRps, nComRps);
        printf("\n");
    }

   
    return 0;
}
