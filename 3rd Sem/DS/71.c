
// Implementation of Queue using Array in C

#include <stdio.h>
#include <stdlib.h>

#define n 5  //queue array size (predefined)
int main()
{
    int queue[n], ch=1, front = 0, rear = 0, i, j = 1, x = n;
    printf("\nQueue using Array\n");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
    while (ch)
    {
        printf("\nEnter the Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (rear == x)   //rear is at end
                printf("\n Queue is Full");
            else
            {
                printf("\n Enter no %d:", j++);
                scanf("%d", &queue[rear++]);  //inserts a number and rear increments
            }
            break;
        case 2:
            if (front == rear)
            {
                printf("\n Queue is empty");
            }
            else
            {
                printf("\n Deleted Element is %d", queue[front++]);  //Deletes a number and front moves 1 cell
                x++;
            }
            break;
        case 3:
            printf("\nQueue Elements are:\n ");
            if (front == rear)
                printf("\n Queue is Empty");
            else
            {
                for (i = front; i < rear; i++)
                {
                    printf("%d ", queue[i]);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
            }
        }
    }
    return 0;
}
