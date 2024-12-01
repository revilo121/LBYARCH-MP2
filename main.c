// Karl Andrei L. Ordinario and Oliver Aldrin H. Arucan
// S14

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern void compute_acceleration(double* input_matrix, int* output_accel, int num_cars);
int main() {
    int num_cars;
    printf("Enter the number of cars: ");
    scanf_s("%d", &num_cars);
    double* input_matrix = (double*)malloc(num_cars * 3 * sizeof(double));
    int* output_accel = (int*)malloc(num_cars * sizeof(int));
    for (int i = 0; i < num_cars; i++) {
        printf("Enter Initial Velocity, Final Velocity, and Time for car %d (space-separated): ", i + 1);
        scanf_s("%lf %lf %lf", &input_matrix[i * 3], &input_matrix[i * 3 + 1], &input_matrix[i * 3 + 2]);
    }
    clock_t start_time = clock();
    compute_acceleration(input_matrix, output_accel, num_cars);
    clock_t end_time = clock();
    printf("\nAcceleration values (in m/s^2):\n");
    for (int i = 0; i < num_cars; i++) {
        printf("%d\n", output_accel[i]);
    }
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %.10f seconds\n", time_taken);
    free(input_matrix);
    free(output_accel);
    return 0;
}