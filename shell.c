#include <stdio.h>
/*
void shellsort(int array[], int n){
    int period = n / 2;
    int temp;
    int j;
    while(period > 0){
        for (int i = period; i < n; i++){
            temp = array[i];
            j = i;
            while(j >= period && array[j-period] > temp)
            {
                array[j] = temp;
                j -= period;
            }
            array[j] = temp;
        }
        period /= 2;
    }
};
*/
void shellsort(int* a, int n){
    for (int period = n / 2; period > 0; period /= 2) {
     for (int i = period; i < n; i++) {
       int j = i - period;
       while (j>=0 && a[j] > a[j + period]) {
         a[j] = a[j] ^ a[j + period]; 
         a[j + period] = a[j] ^ a[j + period];
         a[j] = a[j+period] ^ a[j];
         j -= period;
       }
     }
    }
}

int main()

{
    FILE *inputfile = fopen("input.txt", "r");
    int n;
    fscanf(inputfile, "%d", &n);
    int size = n;
    int data[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(inputfile, "%d", &data[i]);
    }
    fclose(inputfile);

    shellsort(data, size);

    FILE *outputfile = fopen("output.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(outputfile, "%d ", data[i]);
    }
    fclose(outputfile);
}