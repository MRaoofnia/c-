#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int** C(int ,int ,int ,int ,int ,int);
int** merge(int** ,int** ,int** ,int** ,int);
int** add(int** ,int** ,int);
int** d(int ,int ,int ,int ,int);

using namespace std;

int main()
{
    int n=1024;

    int* a[4096];
    int* b[4096];
    int* c[4096];
    for(int i=0;i<4096;i++){
        a[i]=new int[4096];
        b[i]=new int[4096];
        c[i]=new int[4096];
    }

    srand (time(NULL));

    for(int i=0;i<4096;i++)
        for(int j=0;j<4096;j++)
        {
            a[i][j]=rand()%10;
            b[i][j]=rand()%10;
        }

    int** cc[4];
    #pragma omp parallel for
    for(int i=0;i<4;i++)
    {
        cc[i]=C(i,n,c);
    }
    c=merge(cc[0],cc[1],cc[2],cc[3],n/2);

    /*
    //#pragma omp parallel for
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            c[i][j] += a[i][k] * b[k][j];
        }
    }*/

}


int** C(int n/*shows which c. e.g.C1*/,int length/*length of unsplitted matrix. the big C.*/,int ai,int aj,int bi,int bj)
{

    switch(n)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }

}

int** d(int ai,int aj,int bi,int bj,int length)
{
    //breaking one d into many Cs
    return merge(   C(1,length/2,ai,aj,bi,bj)
                    C(2,length/2,ai,aj,bi,bj)
                    C(3,length/2,ai,aj,bi,bj)
                    C(4,length/2,ai,aj,bi,bj));
}

int** merge(int** c1,int** c2,int** c3,int** c4/*parts of the result array*/,int length/*length of any part*/)
{
    //initiating the array
    int* res[length*2];
    for(int i=0;i<length;i++)
        res[i]=new int[length*2];
    //adding c1
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
            res[i][j]=c1[i][j];
    //adding c2
    for(int i=length;i<length*2;i++)
        for(int j=0;j<length;j++)
            res[i][j]=c1[i-length][j];
    //adding c3
    for(int i=0;i<length;i++)
        for(int j=length;j<length*2;j++)
            res[i][j]=c1[i][j-length];
    //adding c4
    for(int i=length;i<length*2;i++)
        for(int j=length;j<length*2;j++)
            res[i][j]=c1[i-length][j-length];
    return res;
}

int** add(int** d1,int** d2/*the Ds to be added*/,int length/*length of all*/)
{
    //initiating the array
    int* res[length];
    for(int i=0;i<length;i++)
        res[i]=new int[length];
    //adding to arrays into the third one
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
            res[i][j]=d1[i][j]+d2[i][j];
    return res;
}