#include <stdio.h>

int main(){
    int a[] = {6, 2, 1, 5, 3};

    int *p, *q;

    int b = 10;


    // p = a; // Pointer `p` points to the base address of array `a`
    // q = &b; // Pointer `q` points to the address of `b`

    // printf("Base address of array a: %p\n", p);
    // printf("Value at base address a: %d\n", *p);

    //q = a[2]; // warning: assignment makes pointer from integer without a cast [-Wint-conversion] 

    // a = &a; //error: assignment to expression with array type

    q = &a[2];

    // q = &q; //assignment from incompatible pointer type [-Wincompatible-pointer-types] 


    printf("Base address of array b: %p\n", q);
    printf("Value of b: %d\n", *q);

}