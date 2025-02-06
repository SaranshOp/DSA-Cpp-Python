#include <stdio.h>
int main()
{
    int n1 = 10, n2 = 30, n3 = 70;
    int max = (n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3));
    printf("%d", max);
}