//gcc -Og matsq.c -o matsq
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma GCC optimize ("Og")
#define ITER 10
#define SEED 2023
#define SIZE 1000

int arr[SIZE][SIZE];

int main(){
    srand(SEED);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = rand()%100;
        }
    }

    clock_t begin, end;

    begin = clock();
    for(int i=0; i<ITER; i++){
        /*put your code here*/
        int ans[SIZE][SIZE];
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                ans[i][j] = 0;
                for(int k = 0; k < SIZE; k++){
                    ans[i][j] += arr[i][k] * arr[k][j];
                }
            }
        }
    }
    end = clock();
    double base_line = ((double) (end - begin)) / CLOCKS_PER_SEC;
    printf("base_line runtime = %lf sec.\n",base_line);

    begin = clock();
    for(int i=0; i<ITER; i++){
        /*put your code here*/

    }
    end = clock();
    double cpu_time = ((double) (end - begin)) / CLOCKS_PER_SEC;
    printf("runtime = %lf sec.\n",cpu_time);
    printf("%lf percent faster\n",((base_line-cpu_time)/(cpu_time)*100));
}