#include <stdio.h>
#include <stdlib.h>


void swap(int* ptr1, int* ptr2){
    int temp = *(ptr1);
    *ptr1 = *ptr2;
    *ptr2 = temp;
    return;
}

void show_heap(int* ptr_heap, int size){
    for(int i = 0; i < size; i ++){
        printf("%d ", *(ptr_heap+i));
    }
}

void copy_heap(int *heap1, int *heap2, int size){
    for(int i = 0; i<size; i++){
        *(heap2+i) = *(heap1+i);
    }

}

void insert(int* heap, int number, int size){

    int* new_heap = (int*) malloc((size + 1) * sizeof(int));

    copy_heap(heap, new_heap, size);

    free(heap);
    heap = new_heap;
    int child = size;
    int parent = child/2;
    *(heap+child) = number;

    while(parent && *(heap+child) > *(heap+parent)){
        swap(heap+child, heap+parent);
        child = parent;
        parent = child/2;
    }

    return;
}

int main() {
    int *heap = (int*) malloc((1) * sizeof(int));
    *heap = 5;
    int input=0;
    int size = 1;

    //        scanf("%d", &input);
//        if (input == -1) break;
//        printf("input: %d\n", input);
    insert(heap, 4, size);
    size++;
    show_heap(heap, size);

}