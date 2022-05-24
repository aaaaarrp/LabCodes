
#include <bits/stdc++.h>

int mutex = 1;   // operation can happen
int Balance = 0; // operation goin on

void down(int mutex)
{
    mutex--;
}

void up(int mutex)
{
    mutex++;
}

void deposit()
{
    down(mutex);
    printf("\nEnter the amount to be deposited:");
    int x;
    scanf("%d", &x);
    Balance += x;
    printf("\nAmount Deposited: %d", x);
    up(mutex);
}

void withdraw()
{
    down(mutex);
    printf("\nEnter the amount to be withdrawn:");
    int x;
    scanf("%d", &x);
    if (Balance >= x)
    {
        Balance -= x;
        printf("\nAmount withdrawn: %d", x);
    }
    else
    {
        Balance = 0;
        printf("\nYou can only withdraw %d:", x - Balance);
        printf("\nAmount withdrawn: %d", x - Balance);
    }

    up(mutex);
}

int main()
{
    int ch;

    printf("\n1.Deposit\n2.Withdraw\n3.Show Balance\n4.Exit");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (mutex == 1)
                deposit();
            else
                printf("Cannot deposit now!!");
            break;
        case 2:
            if (mutex == 1)
                withdraw();
            else
                printf("Can't Withdraw now!!");
            break;
        case 3:
            printf("\nBalance Amount: %d", Balance);
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
