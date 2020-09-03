// find intersection of two sorted arrays
#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Function prints Intersection of arr1[] and arr2[] 
data1_len is the number of elements in arr1[] 
data1_len is the number of elements in arr2[] */
int intersection(int arr1[], int arr2[], int arrResult[], int data1_len, int data2_len) 
{ 
    int i = 0, j = 0, k = 0; 
    while (i < data1_len && j < data2_len) { 
        if (arr1[i] < arr2[j]) 
            i++; 
        else if (arr2[j] < arr1[i]) 
            j++; 
        else /* if arr1[i] == arr2[j] */
        { 
//            cout << arr2[j] << " ";
            arrResult[k] = arr2[j];
//            cout << arrResult[k] << " "; 
            i++; 
            j++; 
            k++;
        } 
    }
    return k; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int arr1[] = { 1, 2, 4, 5, 6, 7, 8, 9, 10 }; 
    int arr2[] = { 2, 3, 5, 7, 8, 9, 10}; 
    int arrResult[] = {};
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
    int result_len = 0;
    // Function calling 
    result_len = intersection(arr1, arr2, arrResult, m, n);
    printf ("arrResult len is %d\n", result_len);
    for (int i = 0; i < result_len; i++)
    {
        printf ("arrResult is: arrResult[%d], value is %d\n", i, arrResult[i]);       
    }
    return 0; 
} 
