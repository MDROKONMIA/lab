#include<stdio.h>
#include<stdlib.h>

#define max 1000

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int l, int r, int array[]){
    int i = l - 1;
    int pivot = array[r];
    for (int j = l; j < r; j++){
        if(array[i]<pivot){
            i++;
            swap(&array[i], &array[j]);
        }
        
    }
    swap(&array[i+1], &array[r]);
    return i + 1;
}

void quickshort(int l, int r, int array[]){

    if(l>=r)
        return;
    int quick= partition(l, r, array);
    quickshort(l, quick - 1, array);
    quickshort(quick + 1, r, array);
}

int main(int argc, char *argv[]){
    FILE *fp;
    int array[max];

    if(argc!=2) {
        printf("Usage: %s <filename>\n", argv[2]);
        return -1;
    }
    fp = fopen(argv[1], "r");
    if(fp==NULL){
        printf("Could not open file <%s> \n", argv[1]);
        return -1;
    }

    int n = 0;
    while(fscanf(fp,"%d", &array[n])==1)
    {
        n++;
    }
    fclose(fp);
    for (int i = 0; i<n; i++){
        printf("%d ", array[i]);
    }

    quickshort(0, n - 1, array);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}