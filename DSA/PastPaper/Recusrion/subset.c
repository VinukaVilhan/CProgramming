#include <stdio.h>

void generateSubsets(int arr[], int n, int index, int currentSubset[], int currentSize) 
{
    // Base case: when should we stop?
    if (index == n) {
        // Print the current subset
        printf("[");
        for (int i = 0; i < currentSize; i++) {
            printf("%d", currentSubset[i]);
            if (i < currentSize - 1) printf(",");
        }
        printf("]\n");
        return;
    }
    else{
        
    }
    
    // YOUR CODE HERE:
    // At each element, you have 2 choices:
    // 1. Include the current element in the subset
    // 2. Don't include the current element in the subset
    
    // Hint: Make two recursive calls


}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;
    int currentSubset[10]; // Assuming max 10 elements
    
    printf("All subsets:\n");
    generateSubsets(arr, n, 0, currentSubset, 0);
    return 0;
}