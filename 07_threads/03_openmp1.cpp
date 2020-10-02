#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv)
{
    #pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        printf("hello parallel world from thread # %d\n", threadID);
    }
    return 0;
}