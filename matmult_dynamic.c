#include <stdio.h>
#include <stdlib.h>

int main() {
  int r1, c1, r2, c2, i, j, k;

  // Input rows and columns of first matrix
  printf("Enter rows and columns of first matrix: ");
  scanf("%d %d", &r1, &c1);

  // Input rows and columns of second matrix 
  printf("Enter rows and columns of second matrix: ");
  scanf("%d %d",&r2, &c2);

  // Check if matrices can be multiplied
  if(c1 != r2) {
    printf("Matrices cannot be multiplied\n");
    exit(0);
  }

  // Dynamically allocate memory for matrices
  int** matrix1 = (int**)malloc(r1 * sizeof(int*));
  for(i=0; i<r1; i++)
    matrix1[i] = (int*)malloc(c1 * sizeof(int)); 

  int** matrix2 = (int**)malloc(r2 * sizeof(int*));
  for(i=0; i<r2; i++)
     matrix2[i] = (int*)malloc(c2 * sizeof(int));

  // Input elements of first matrix 
  printf("\nEnter elements of first matrix:\n");
  for(i=0; i<r1; i++) {
    for(j=0; j<c1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  // Input elements of second matrix
  printf("\nEnter elements of second matrix:\n");
  for(i=0; i<r2; i++) {
    for(j=0; j<c2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  // Initialize result matrix
  int** result = (int**)malloc(r1 * sizeof(int*)); 
  for(i=0; i<r1; i++)
    result[i] = (int*)malloc(c2 * sizeof(int));

  // Perform matrix multiplication
  for(i=0; i<r1; i++) {
    for(j=0; j<c2; j++) {
      result[i][j] = 0;
      for(k=0; k<c1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Print result matrix
  printf("\nResult matrix: \n");
  for(i=0; i<r1; i++) {
    for(j=0; j<c2; j++){
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for(i=0; i<r1; i++) {
    free(matrix1[i]);
  }
  free(matrix1);

  for(i=0; i<r2; i++) {
    free(matrix2[i]);
  }
  free(matrix2);

  for(i=0; i<r1; i++) {
    free(result[i]);
  }
  free(result);

  return 0;
}