#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    #pragma omp parallel for
    for(int i=0;i<4;i++)
    {
        int thread_num = omp_get_thread_num();
        int cpu_num = sched_getcpu();
        printf("Thread %3d is running on CPU %3d\n", thread_num, cpu_num);
    }
}