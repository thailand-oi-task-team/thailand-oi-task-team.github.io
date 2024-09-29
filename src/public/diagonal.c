//gcc -Og diagonal.c -o diagonal
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma GCC optimize ("Og")
#define ITER 1000
#define SEED 2023
#define SIZE 4000

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
        int n = SIZE;
        int ans[8000];
        memset(ans, 0, sizeof(int) * 8000);
        for(int s = 0; s < (n * 2) - 1; s++){
            int i = s;
            if(s >= n) i = n - 1;
            int j = s - i;
            for(; i >= 0 && j < n; i--, j++){
                ans[s] += arr[i][j];
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