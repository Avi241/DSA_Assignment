
#include <stdio.h>
#include <stdlib.h>
int size_file;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n, int digit_count)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
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
    for (c = getc(fp_r); c != EOF; c = getc(fp_r))
        if (c == '\n') // Increment count if this character is newline
            size_file = size_file + 1;

	int arr[size_file-1];

	// printf("%d",size_file);

	fp_r = fopen(argv[1], "r");

	for(int i=0; i<size_file; i++)
	{
		fscanf(fp_r, "%d", &n);
		arr[i] = n;
	}
	int digit_count = atoi(argv[2]);

	radixsort(arr, size_file ,digit_count);
	
    fp_w = fopen("radix.txt", "w");

	for(int i = 0;i<size_file;i++)
	{
		fprintf(fp_w,"%d\n",arr[i]);
	}
	return 0;
}
