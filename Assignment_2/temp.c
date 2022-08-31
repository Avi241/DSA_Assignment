/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
int size_file = 0;
struct Array
{
	int* a;
};

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(struct Array *ar, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = ar->a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = ar->a[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			ar->a[k] = L[i];
			i++;
		}
		else {
			ar->a[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		ar->a[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		ar->a[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(struct Array *ar, int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(ar, l, m);
		mergeSort(ar, m + 1, r);

		merge(ar, l, m, r);
	}

    // for(int i = 0;i<=size_file;i++)
	// {
	// 	printf("%d\n ",ar->a[i]);
	// }
    // printf("\n");
    
}

int main(int argc, char *argv[])
{
    struct Array A;
    FILE *fp_r, *fp_w;
    fp_r = fopen(argv[1], "r");
    char c;
	int n;
    if (fp_r == NULL) // Check whether file exists
    {
        printf("FILE NOT FOUND");
        exit(0);
    }
    // Extract characters from file and store in character c
    for (c = getc(fp_r); c != EOF; c = getc(fp_r))
        if (c == '\n') // Increment count if this character is newline
            size_file = size_file + 1;

    fp_r = fopen(argv[1], "r");
	A.a = calloc(size_file,sizeof(int));
	int arr_size = sizeof(A.a) / sizeof(A.a[0]);

	for(int i=0; i<=size_file; i++)
	{
		fscanf(fp_r, "%d", &n);
        A.a[i] = n;	
	}

	// printf("Given array is \n");
    // for(int i = 0;i<=size_file;i++)
	// {
	// 	printf("%d\n ",A.a[i]);
	// }

	mergeSort(&A, 0, arr_size - 1);

	printf("Sorted array is \n");
    for(int i = 0;i<=size_file;i++)
	{
		printf("%d\n ",A.a[i]);
	}
    
    free(A.a);
	return 0;
}
