#include <stdio.h>
#include <stdlib.h>


void InitializeDisks(int* arr, int disks){
    int loop;
    for(loop = 0; loop < disks; loop++){
        arr[loop] = 1;
    }
}

int GetUntarget(int from, int to){
    if(from != 1 && to != 1)
        return 1;
    else if(from != 2 && to != 2)
        return 2;
    else if(from != 3 && to != 3)
        return 3;
    else{
        printf("Error!");
        return -1;
    }
}

int FindTopDisks(int * arr, int disks, int pillar){
    
    int idx;
    for(idx = 0; idx < disks ; idx++){
        if(arr[idx] == pillar){
            return idx;
        }
    }
    return -1;
}

void PrintCurState(int* arr, int disks){
    int idx;
    
    printf("Pillar 1 : ");
    for(idx = disks - 1; idx >= 0; idx--){
        if(arr[idx] == 1){
            printf("%d  ", idx+1);
        }
    }
    printf("\n");
    printf("Pillar 2 : ");
    for(idx = disks - 1; idx >= 0; idx--){
        if(arr[idx] == 2){
            printf("%d  ", idx+1);
        }
    }
    printf("\n");
    
    printf("Pillar 3 : ");
    for(idx = disks - 1; idx >= 0; idx--){
        if(arr[idx] == 3){
            printf("%d  ", idx+1);
        }
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    
}

void PrintHanoiMov(int* arr, int numOfDisks, int from, int to, int disks){
    int untarget;
    
    untarget = GetUntarget(from, to);
    
    if(numOfDisks == 1){
        arr[FindTopDisks(arr, disks, from)] = to;
        PrintCurState(arr, disks);
    }
    
    else{
        PrintHanoiMov(arr, numOfDisks - 1, from, untarget, disks);
        PrintHanoiMov(arr, 1, from, to, disks);
        PrintHanoiMov(arr, numOfDisks - 1, untarget, to, disks);
    }
}


int main(){
    int * arr;
    int disks;
    
    printf("How many disks? : ");
    scanf("%d", &disks);
    arr = (int*)calloc(disks, sizeof(int));
    InitializeDisks(arr, disks);
    PrintCurState(arr, disks);
    PrintHanoiMov(arr, disks, 1, 3, disks);
}
