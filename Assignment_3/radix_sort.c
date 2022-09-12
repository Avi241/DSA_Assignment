// C++ implementation of Radix Sort

#include <stdio.h>

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by place.
void countSort(int arr[], int n, int place)
{
    int output[n]; // output array
    int i, count[10] = {0};

    printf("#######################################\n");
    print(arr,n);

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;
    
    print(count,n);

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    print(count,n);
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    print(output,n);

    printf("-----------------------\n");

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n,int digit)
{
    int place=1;
    // Find the maximum number to know number of digits
    // int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, place is passed. place is 10^i
    // where i is current digit number
    for (int i = 1; i<=digit ; i++)
    {
        countSort(arr,n,place);
        place*=10;
    }
        
}



// Driver Code
int main(int argc, char *argv[])
{
    // int arr[] = {170, 45, 75, 90, 802, 24, 2, 66,4875,564,78};
    int size_file;

    FILE *fp_r, *fp_w;
    fp_r = fopen(argv[1], "r");
	char c;
	int n;

	if (fp_r == NULL) // Check whether file exists
    {
        printf("FILE NOT FOUND");
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


    // int size_file = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixsort(arr, size_file,4);
    // print(arr, n);

    fp_w = fopen("radix.txt", "w");

	for(int i = 0;i<size_file;i++)
	{
		fprintf(fp_w,"%d\n",arr[i]);
	}
    printf("\n");
    return 0;
}