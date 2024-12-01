// Karl Andrei L. Ordinario and Oliver Aldrin H. Arucan
// S14

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


extern void compute_acceleration(double *input_matrix, int *output_accel, int num_cars);

int main() {
    int num_cars = 100000;  // number of cars/input
    int num_runs = 30;     // Number of times to run

    double *input_matrix = (double *)malloc(num_cars * 3 * sizeof(double));
    int *output_accel = (int *)malloc(num_cars * sizeof(int));

    if (input_matrix == NULL || output_accel == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    srand(time(NULL));
    for (int i = 0; i < num_cars; i++) {
        input_matrix[i * 3] = (double)(rand() % 201);       
        input_matrix[i * 3 + 1] = (double)(rand() % 301);    
        input_matrix[i * 3 + 2] = (double)(rand() % 20 + 1); 
    }

    LARGE_INTEGER frequency;
    LARGE_INTEGER start_time, end_time;
    double total_time = 0.0;

    QueryPerformanceFrequency(&frequency);

    for (int run = 0; run < num_runs; run++) {
        
        QueryPerformanceCounter(&start_time);
        compute_acceleration(input_matrix, output_accel, num_cars);
        QueryPerformanceCounter(&end_time);

        double time_taken = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
        total_time += time_taken;
    }

    double avg_time = total_time / num_runs;

    printf("All 10,000 acceleration values:\n");
    for (int i = 0; i < num_cars; i++) {
        printf("%d\n", output_accel[i]);
    }

    printf("\nAverage execution time for 10,000 cars over 30 runs: %.6f seconds\n", avg_time);

    free(input_matrix);
    free(output_accel);

    return 0;
}
