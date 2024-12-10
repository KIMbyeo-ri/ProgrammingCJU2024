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
        printf("�����ϴ�\n");
    }
    else if ((player == rock && computer == scissors) ||
             (player == paper && computer == rock) ||
             (player == scissors && computer == paper))
    {
        printf("Player �¸�\n");
    }
    else
    {
        printf("Computer �¸�\n");
    }
}

int main(void)
{
    // ���� ������ ���� �õ� ����
    GenRandSeed();

    unsigned int nComRps = INITSTATUS;
    unsigned int nPlyRps = INITSTATUS;

    while (1)
    {
        // ����� �Է� �ޱ�
        printf("���� ���� �� �Է�(0 = ����, 1 = ����, 2 = ��):\n");
        printf("�����Ϸ��� 999�� �Է��ϼ���\n");
        scanf_s("%d", &nPlyRps);

        // ���� ���� Ȯ��
        if (nPlyRps == END_COND)
        {
            printf("������ �����մϴ�...\n");
            break;
        }
        else if (nPlyRps < 0 || nPlyRps >= rock_scissors_paper)
        {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n\n");
            continue;
        }

        // ��ǻ���� ���������� ����
        nComRps = GenRandNum(rock_scissors_paper);

        // ��� ���
        printf("(Player, Computer): (%d, %d)\n", nPlyRps, nComRps);

        // ���� �Ǵ�
        DetermineWinner(nPlyRps, nComRps);
        printf("\n");
    }

   
    return 0;
}
