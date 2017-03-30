#include<stdio.h>
#define MAX 5
int a[100],top = -1;
int f = -1,r = -1;
void enque(int x)
{
    if(f == -1 && r == -1)
    {
        f = r = 0;
        a[r++] = x;
     }
     else
     { 
        a[r++] = x; 
     }
}
int deque()
{
    if(f == -1 && r == -1)
    {
         printf("Empty\n");
    }
    return a[f++];
}
void show()
{
   int i;
   for(i = f; i < r; i++ )
   printf("%d\n",a[i]);
}
main()
{
    int n,x;
    printf("Enter 1 to Push element\n");
    printf("Enter 2 to POP element\n");
    printf("Enter 3 to PRINT stack\n");
    printf("Enter -1 to end\n");
    scanf("%d",&n);
    while(n != -1)
    {
    if(n == 1)
    {
        printf("Enter element to push\n");
        scanf("%d",&x);
        enque(x);
    }
    else if(n == 2)
    {
        x = deque();
        printf("%d\n",x);
    }
    else
    {
        show();
    }
    printf("Enter 1 to Push element\n");
    printf("Enter 2 to POP element\n");
    printf("Enter 3 to PRINT stack\n");
    printf("Enter -1 to end\n");

    scanf("%d",&n);
    }


}
                                                           
