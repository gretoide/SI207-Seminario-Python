#include <stdio.h>

int main()
{
    int n=5,x,y;

    x=++n;

    y=n++;

    printf("n = %d | x = %d | y = %d\n", n,x,y  );

    return 0;
}
