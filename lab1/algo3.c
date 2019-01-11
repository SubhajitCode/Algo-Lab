#include <stdio.h>

void main()
{
    int n, n1;
    printf("Please enter your string size:");
    scanf("%d", &n);
    char string[n + 1];
    getchar();
        printf("Please enter your string:");
    gets(string);
    printf("Please enter your Roll size(Less than String size):");
    scanf("%d", &n1);
    int roll[n1];
    printf("Please enter your Roll :");
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &roll[i]);
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j <roll[i];j++)
        {
            string[j]=(string[j]-96)%26+97;
        }

    }
    printf("after Rolling --------------------------------------------------------------\n");
    puts(string);
}