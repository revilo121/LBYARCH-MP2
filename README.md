# Car Acceleration Calculation (C and x86-64 Assembly)

**Authors**:  
Karl Andrei L. Ordinario and Oliver Aldrin H. Arucan

## Project Overview

This project calculates the acceleration of cars based on user-provided initial velocity, final velocity, and the time taken for each car to travel a given distance. The program is implemented in C while using an external function written in x86-64 assembly to perform the calculations.

The user inputs the number of cars and their corresponding parameters. The C program then dynamically allocates memory for the input data, allowing the program to accommodate larger amounts of input data, and calls an assembly function to calculate the acceleration for each car.

## Performance Analysis

In order to accurately measure the execution time of our program, we made it run **30 times** for each test case with **10, 100, 1,000, 10,000, and 100,000** randomized inputs. The results for each test case are as follows:

- **10 Cars**: 0.0000000433 seconds
  ![image](https://github.com/user-attachments/assets/c893520d-d690-4714-93bf-47442c026bd2)
- **100 Cars**: 0.0000002067 seconds
  ![image](https://github.com/user-attachments/assets/e93f9d97-95e1-4898-ae3a-b391f777940f)
- **1,000 Cars**: 0.0000017700 seconds
  ![image](https://github.com/user-attachments/assets/a1d69827-7925-4deb-8139-fd56a03ccc69)
- **10,000 Cars**: 0.0000120200 seconds
  ![image](https://github.com/user-attachments/assets/518f5b05-9dbc-45bf-bb36-1c3c3c642f69)
- **100,000 Cars**: 0.0001672367 seconds
  ![image](https://github.com/user-attachments/assets/7dd5a186-5ee1-48c0-9e77-0f12f191967c)

### Short Performance Analysis

Given the performance of our code, the execution time is proportional to the number of inputs provided by the user. As the number of inputs increases by a factor of ten, the execution time similarly increases to the next significant digit to the left. Despite this, the program is capable of handling large inputs well beyond the given specifications for the project, which originally required only up to 10,000 cars. Our program successfully handled **100,000** cars, as demonstrated above.

## Correctness Check

### Test Case

- **Number of Cars**: 3
  - **Car 1**: Initial velocity = 0.0, Final velocity = 62.5, Time = 10.1
  - **Car 2**: Initial velocity = 60.0, Final velocity = 122.3, Time = 5.5
  - **Car 3**: Initial velocity = 30.0, Final velocity = 160.7, Time = 7.8

#### Expected Output

- **Acceleration for Car 1**: 2
- **Acceleration for Car 2**: 3
- **Acceleration for Car 3**: 5

#### Actual Output

![image](https://github.com/user-attachments/assets/04d639c5-ee95-48a0-8870-4aee290438ba)


As shown above, the program successfully calculated the expected accelerations for the given test case, showing that the program is correct.

## How to Use the Program

### Requirements

Ensure that Visual Studio Community 2022 is set up, and you have access to **gcc** and **nasm** for compiling the code.

### Usage

1. **Compile the Program**:
   - Compile the `main.c` file and the `asmfunc.asm` file using Visual Studio Community 2022.

2. **Run the Program**:
   - The program will first ask for the number of cars.
   - Provide the **initial velocity**, **final velocity**, and **time** for each car, separated by spaces.
   - The program will then calculate the acceleration for each car and display the results along with the average execution time (if multiple runs are performed).

## Files

- **main.c**: The main C file that contains the logic for receiving user input, calling the assembly function, and calculating the average execution time.
  
- **asmfunc.asm**: The assembly file that contains the function `compute_acceleration`, which uses SIMD registers and instructions to efficiently compute acceleration values.

- **10.c, 100.c, 1000.c, 10000.c, 100000.c**: C files similar to the main file but tailored for specific test cases involving **10**, **100**, **1,000**, **10,000**, and **100,000** cars. These programs use `srand()` for random inputs and run **30 times** to calculate the average execution time for each test case.
