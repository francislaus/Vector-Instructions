#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define LENGTH 134217728

float a[LENGTH];
float b[LENGTH];
float c[LENGTH];

void vector_add(int length, float a[], float b[], float c[])
{
    for(int i = 0; i < length; i++)
    {
        c[i] = a[i] + b[i];
    }
}


void fill_memory(float array[], float value, int length)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = value;
    }
}


int main()
{
    struct timeval start, end;
    fill_memory(a, 1.0, LENGTH);
    fill_memory(b, 2.0, LENGTH);
    gettimeofday(&start, NULL);
    vector_add(LENGTH, a, b, c);
    gettimeofday(&end, NULL);
    for(int i = 0; i < LENGTH; i++)
    {
        if(c[i] != (float) (3.0))
        {
            printf("ERROR\n");
            break;
        }
    }
    double time_taken; 
  
    time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6; 
    printf("time: %f\n", time_taken);
    return 0;
}