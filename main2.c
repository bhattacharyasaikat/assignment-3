#include <stdio.h>
#include <malloc.h>


int search(int * arr, int len, int ele){
    for (int i = 0; i < len; i++){
        if (arr[i] == ele){
            return i;
        }
    }

    return -1;
}

int * rem(int * array, int len, int index){
    int mover = index;
    while (mover < len - 1){
        int temp = array[mover];
        array[mover] = array[mover + 1];
        array[mover + 1] = temp;
        mover++; 
    }

    array = realloc(array, sizeof(int)*(len - 1));
    return array;
}

void print(int * array, int len){
    for (int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int len;
    printf("enter the length of the array: ");
    scanf("%d", &len);

    int * array = (int *)malloc(sizeof(int) * len);

    printf("enter the elements: ");
    for (int i = 0; i < len; i++){
        int x;
        scanf("%d", &x);
        array[i] = x;
    }

    int del;
    printf("enter the element you want to delete: ");
    scanf("%d", &del);

    int decider = search(array, len, del);
    if (decider == -1){
        printf("element doesn't exist\n");
    }else{
        int * removed = rem(array, len, decider);
        print(removed, len - 1);
    }   

    return 0;
}