#include <stdio.h>
#include <stdlib.h>

int main() {
  int r1, c1, r2, c2, i, j, k;
  
  // Input matrix 1 rows and columns
  printf("Enter rows and columns for matrix 1: ");
  scanf("%d %d", &r1, &c1);

  // Input matrix 2 rows and columns 
  printf("Enter rows and columns for matrix 2: ");
  scanf("%d %d",&r2, &c2);

  // Check if matrices can be multiplied
  if(c1 != r2) {
    printf("Cannot multiply matrices.\n"); 
    exit(0);  
  }

  // Allocate memory 
  int *matrix1 = (int *)malloc(r1 * c1 * sizeof(int));
  int *matrix2 = (int *)malloc(r2 * c2 * sizeof(int));
  int *result = (int *)malloc(r1 * c2 * sizeof(int));

  // Read matrix 1  
  printf("\nEnter elements of matrix 1:\n");
  for(i=0; i<r1; i++) {
    for(j=0; j<c1; j++) {    
      scanf("%d", (matrix1 + i*c1 + j));
    }
  }
  
  // Read matrix 2
  printf("\nEnter elements of matrix 2:\n");
  for(i=0; i<r2; i++) {
    for(j=0; j<c2; j++) {  
      scanf("%d", (matrix2 + i*c2 + j));
    }
  }

  // Matrix multiplication
  for(i=0; i<r1; i++) {
    for(j=0; j<c2; j++) {
      *(result + i*c2 + j) = 0; 
      for(k=0; k<c1; k++) {
        *(result + i*c2 + j) += *(matrix1 + i*c1 + k) * *(matrix2 + k*c2 + j);
      }
    }
  }

  // Print result
  printf("\nResult Matrix:\n"); 
  for(i=0; i<r1; i++){
    for(j=0; j<c2; j++){
      printf("%d ", *(result + i*c2 + j)); 
    }
    printf("\n");
  }

  // Free memory  
  free(matrix1);
  free(matrix2);
  free(result);  

  return 0;
}