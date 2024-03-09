#include <stdio.h>
#include <stdlib.h>

//Christian Estrada COP3502C Lab Assignment 7
typedef struct Tracker {
int value;
int SwapCounter;
int TotalSwaps;
}Tracker;

void BubbleSort(int Array[], int n, Tracker Tracker[]){
int i, j, temp;
for(int k = 0; k < n; k++){//setting the values of Tracker
    Tracker[k].value = Array[k];
    Tracker[k].SwapCounter = 0;
}
Tracker[0].TotalSwaps = 0;

for(i = 0; i < n-1; i++){
//basic Bubble Sort Algorithim
    for(j = 0; j < n-i-1; j++){
        if(Array[j] > Array[j+1]){
    
            (Tracker[0].TotalSwaps)++;//incrementing the total swaps counter when I start a swap

            temp = Array[j];

            Array[j] = Array[j+1];
            for(int k = 0; k < n; k++){
                if(Array[j] == Tracker[k].value){//going/iterating through the Tracker array until I find the value
                (Tracker[k].SwapCounter)++;//that matches with the value we just swapper, and incrementing the swap counter 
                }//for that specific numebr
            }
            Array[j+1] = temp;
            for(int k = 0; k < n; k++){//same logic as before
                if(Array[j+1] == Tracker[k].value){
                (Tracker[k].SwapCounter)++;
                }
            }

        }
    }
}

}

void SelectionSort(int Array[], int n, Tracker Tracker[]){
int i, j, min_index, temp;
for(int k = 0; k < n; k++){//setting the Tracker values
    Tracker[k].value = Array[k];
    Tracker[k].SwapCounter = 0;
}
Tracker[0].TotalSwaps = 0;

for(i = 0; i < n-1; i++){//basic Selection Sort algorithm
    min_index = i;
        for(j = i+1; j < n; j++){
            if(Array[j] < Array[min_index])
                min_index = j;
        }

    if(min_index != i){
    temp = Array[i];

    Tracker[0].TotalSwaps++;//same logic as before

    Array[i] = Array[min_index];
            for(int k = 0; k < n; k++){//same logic as before
                if(Array[i] == Tracker[k].value){
                (Tracker[k].SwapCounter)++;
                }
            }
    Array[min_index] = temp;
            for(int k = 0; k < n; k++){//same logic as before
                if(Array[min_index] == Tracker[k].value){
                (Tracker[k].SwapCounter)++;
                }
            }

    }
}
}

int main(){
int ArraySize = 9;
Tracker Tracker[ArraySize];

//Bubble Sort ==============================
int Array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
int Array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

//SORTING ARRAY 1 -------------
BubbleSort(Array1, ArraySize, Tracker);

printf("Array1 Bubble Sort:\n");
for(int i = 0; i < ArraySize; i++){//the number of times each thing is swapped
    for(int j = 0; j < ArraySize; j++)
        if(Array1[i] == Tracker[j].value)
            printf("%d: %d \n", Tracker[j].value, Tracker[j].SwapCounter);
}
printf("%d\n", Tracker[0].TotalSwaps);

//SORTING ARRAY 2 ----------------
BubbleSort(Array2, ArraySize, Tracker);

printf("Array2 Bubble Sort:\n");
for(int i = 0; i < ArraySize; i++){//the number of swaps per index
    for(int j = 0; j < ArraySize; j++)
        if(Array2[i] == Tracker[j].value)
            printf("%d: %d \n", Tracker[j].value, Tracker[j].SwapCounter);
}
printf("%d\n", Tracker[0].TotalSwaps);


//Selection Sort =====================================
int Array1Copy[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
int Array2Copy[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

//SORTING ARRAY 1 -------------
SelectionSort(Array1Copy, ArraySize, Tracker);

printf("Array1 Selection Sort:\n");
for(int i = 0; i < ArraySize; i++){//the number of times each thing is swapped
    for(int j = 0; j < ArraySize; j++)
        if(Array1Copy[i] == Tracker[j].value)
            printf("%d: %d \n", Tracker[j].value, Tracker[j].SwapCounter);
}
printf("%d\n", Tracker[0].TotalSwaps);

//SORTING ARRAY 2 --------------
SelectionSort(Array2Copy, ArraySize, Tracker);

printf("Array2 Selection Sort:\n");
for(int i = 0; i < ArraySize; i++){//the number of swaps per index
    for(int j = 0; j < ArraySize; j++)
        if(Array2Copy[i] == Tracker[j].value)
            printf("%d: %d \n", Tracker[j].value, Tracker[j].SwapCounter);
}
printf("%d\n", Tracker[0].TotalSwaps);

return 0;
}