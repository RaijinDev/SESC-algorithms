#include <stdio.h>

  void transf(int array[], int n, int i) {
    int biggest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
  
    if (left < n && array[left] > array[biggest])
      biggest = left;
  
    if (right < n && array[right] > array[biggest])
      biggest = right;
  
    if (biggest != i) {
      array[i] = array[i] ^ array[biggest];
      array[biggest] = array[i] ^ array[biggest];
      array[i] = array[biggest] ^ array[i];
      transf(array, n, biggest);
    }
  }

  void heapsort(int array[], int n) {
    for (int i = n/2-1; i >= 0; i--)
      transf(array, n, i);
  
      for (int i = n-1; i >= 0; i--) {
      array[0] = array[0] ^ array[i];
      array[i] = array[0] ^ array[i];
      array[0] = array[i] ^ array[0];
      transf(array, i, 0);
    }
  }

int main()

{
  /*
  int data[5] = { -100, 3, 5, 4, 5 };
    int size = 5;
    quicksort(data, 0, size-1);
    for (int i = 0; i < size; i++)
    {

        printf("%d ", data[i]);

    }
    */
  
    FILE *inputfile = fopen("input.txt", "r");
    int n;
    fscanf(inputfile, "%d", &n);
    int size = n;
    int fin[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(inputfile, "%d", &fin[i]);
    }
    fclose(inputfile);

    heapsort(fin, n);

    FILE *outputfile = fopen("output.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(outputfile, "%d ", fin[i]);
    }
    fclose(outputfile);
    
}