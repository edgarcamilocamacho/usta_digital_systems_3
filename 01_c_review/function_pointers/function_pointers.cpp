#include <stdio.h>
#include <stdlib.h> //for qsort()

int compare1(const void* left, const void* right)
{
    return (*(int*)left - *(int*)right);
}

int compare2(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
}

main()
{
    int (*cmp) (const void* , const void*);

    cmp = &compare1;
    int iarray[] = {2,5,6,4,3,8,9,7,1,0};
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);
    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }
    printf("\n");

    cmp = &compare2;
    int iarray2[] = {2,5,6,4,3,8,9,7,1,0};
    qsort(iarray2, sizeof(iarray2)/sizeof(*iarray2), sizeof(*iarray2), cmp);
    c = 0;
    while (c < sizeof(iarray2)/sizeof(*iarray2))
    {
        printf("%d \t", iarray2[c]);
        c++;
    }
    printf("\n");


}