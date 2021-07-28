// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

//Function to merge the arrays.
void merge(int arr1[], int arr2[], int n, int m)
{ 
    int p1 = 0, p2 = 0, index = 0;
    int arr3[n + m];
    
    while (p1 < n && p2 < m) {
        if (arr1[p1] < arr2[p2]) {
            arr3[index++] = arr1[p1++];
        } else {
            arr3[index++] = arr2[p2++];
        }
    }
    while (p1 < n) {
        arr3[index++] = arr1[p1++];
    }
    while (p2 < m) {
        arr3[index++] = arr2[p2++];
    }
    
    for (int i = 0; i < n; ++i) {
        arr1[i] = arr3[i];
    }
    for (int i = 0; i < m; ++i) {
        arr2[i] = arr3[i+n];
    }
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}  // } Driver Code Ends