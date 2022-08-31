
#include <stdio.h>
#include <stdlib.h>
int size_file = 0;

void merge(int arr[], int l, int m, int r)
{

	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{

	if (l < r) {

		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main(int argc, char *argv[])
{
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
	int arr[size_file-1];
	fp_r = fopen(argv[1], "r");
	// arr = calloc(size_file,sizeof(int));
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	for(int i=0; i<size_file; i++)
	{
		fscanf(fp_r, "%d", &n);
		arr[i] = n;
	}


	mergeSort(arr, 0, arr_size );

	fp_w = fopen("mergesort.txt", "w");

	for(int i = 0;i<arr_size+1;i++)
	{
		fprintf(fp_w,"%d\n",arr[i]);
	}
	return 0;
}
