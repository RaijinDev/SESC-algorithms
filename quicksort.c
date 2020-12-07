#include <stdio.h>
int part(int array[], int l, int h) {
  int pivot = array[h];
  int i = l-1;
  for (int j = l; j < h; j++) {
    if (array[j] <= pivot) {
      i++;
      array[i] = array[i] ^ array[j];
      array[j] = array[i] ^ array[j];
      array[i] = array[j] ^ array[i];
    }
  }

array[i+1] = array[i+1] ^ array[h];
array[h] = array[i+1] ^ array[h];
array[i+1] = array[h] ^ array[i+1];
return i+1;
}

void quicksort(int array[], int l, int h) {
  if (l < h) {
    int postp = part(array, l, h);
    quicksort(array, l, postp-1);
    quicksort(array, postp+1, h);
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

    quicksort(fin, 0, n--);

    FILE *outputfile = fopen("output.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(outputfile, "%d ", fin[i]);
    }
    fclose(outputfile);
    
}