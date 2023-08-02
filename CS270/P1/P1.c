// P1 Assignment
// Author: Ian Duncan
// Date:   1/15/2020
// Class:  CS270
// Email:  iandunc@rams.colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// example of a global array
//int exampleGlobalArray[2];
double  input[5];
double  output[4];

// this function can be used as a guide for the funtions you will implement
void computeCircle(double radius, double *addressOfArea)
{
    // Compute area
    double result = 3.141593 * radius * radius;

    // Dereference pointer to return result
    *addressOfArea = result;
}


void computeSphere(double radius, double *addressOfArea)
{
    // Compute area
    double result =  (4.0 / 3.0) * 3.141593 * radius * radius * radius;

    // Dereference pointer to return result
    *addressOfArea = result;
}


void computeCube(double side, double *addressOfArea)
{
    // Compute area
    double result = side * side * side;

    // Dereference pointer to return result
    *addressOfArea = result;
}


void computeTetrahedron(double side, double *addressOfArea)
{
    // Compute area
    double result = 0.117851 * side * side * side;

    // Dereference pointer to return result
    *addressOfArea = result;
}

void computeCylinder(double radius, double height, double *addressOfArea)
{
    // Compute area
    double result = 3.141593 * radius * radius * height;

    // Dereference pointer to return result
    *addressOfArea = result;
}

int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc != 6) {
        printf("usage: ./P1 <double> <double> <double> <double> <double> \n");
        return EXIT_FAILURE;
    }

    // Parse arguments
    input[0] = atof(argv[1]);
    input[1] = atof(argv[2]);
    input[2] = atof(argv[3]);
    input[3] = atof(argv[4]);
    input[4] = atof(argv[5]);

    // Local variable
    //double area;

    // Call function
    //computeCircle(radius, &area);
    computeSphere(input[0], &output[0]);
    computeCube(input[1], &output[1]);
    computeTetrahedron(input[2], &output[2]);
    computeCylinder(input[3], input[4], &output[3]);

    // Print area
    //printf("The area of a circle with radius %.5f equals %.5f.\n", radius, area);
    printf("SPHERE, radius = %.5f, volume = %.5f.\n", input[0], output[0]);
    printf("CUBE, side = %.5f, volume = %.5f.\n", input[1], output[1]);
    printf("TETRAHEDRON, side = %.5f, volume = %.5f.\n", input[2], output[2]);
    printf("CYLINDER, radius = %.5f, height = %.5f,  volume = %.5f.\n", input[3], input[4], output[3]);
    // Return success
    return EXIT_SUCCESS;
}
