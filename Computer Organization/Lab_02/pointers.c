#include <stdio.h> 
 
int main() { 
    //1 (Starts off as int x,y,*px,*py)
    int x = 0;
    int y = 0;
    int *px, *py; 
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};  

    //3 (Declared x,y, and arr)
    printf("x: %d\ny: %d\n", x, y);
    printf("arr[]:");
    for(int i = 0; i < 10; i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    //4
    printf("&x: %p\n&y: %p\n", &x, &y);

    //5
    px = &x;
    py = &y;
    printf("px: %p\npy: %p\n", px, py);
    printf("*px: %d\n*py: %d\n", *px, *py);

    //6
    for(int i = 0; i < 10; i++){
        printf("*(arr+%d):%d ", i, *(arr+i));
    }
    printf("\n");

    //7
    printf("Adress of arr: %p\n", arr);
    printf("Adress of &arr[0]: %p\n", &arr[0]);

    //8
    printf("Adress of &arr: %p\n", &arr);


    return 0; 
}