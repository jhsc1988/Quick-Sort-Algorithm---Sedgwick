/* 
 * File:   main_qsrt.c
 * Author: vignesh
 * Comments: Simple quick ssort demo program
 * Created on 16 December 2009, 10:51
 */

#include <stdio.h>
#include <stdlib.h>

void quickSort(int entry[], int left, int right){
    
    int pivot, i, j, swap;
    if(right>left){
        pivot = entry[right];
        i = left - 1;
        j = right;
        for(;;){
            while(entry[++i] < pivot);
            while(entry[--j] > pivot);
            //check if i doesn't go past or equal j
            if(i >=j) break;
            swap = entry[i];
            entry[i] = entry[j];
            entry[j] = swap;
        }
        swap = entry[i];
        entry[i] = entry[right];
        entry[right] = swap; 
        
        quickSort(entry, left, i-1);
        quickSort(entry, i+1, right);
    }
    return;
}

int main () {
    int i;
    int a[] = {1, 4, 13, 40, 121, 364, 1093, 3280};
    int n = sizeof (a) / sizeof (a[0]);
    
    quickSort(a, 0, n-1);
    for(i=0; i<n; i++){
        printf("\t%d", a[i]);
    }
    return 0;
}
 