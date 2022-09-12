
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

void count_sort(int arr[],int size_arr,int place)
{
    int count_array[10]={0};
    // print_arr(count_array,10);
    for(int i=0;i<size_arr;i++)
    {
        count_array[arr[i]/place % 10]++;
    }

    // print_arr(count_array,10);

    for(int i=1;i<10;i++)
    {
        count_array[i]+=count_array[i-1];
    }
    // print_arr(count_array,10);

    int output_arr[size_arr];

    for(int i=0;i<size_arr;i++)
    {
        output_arr[--count_array[arr[i]/place % 10]]=arr[i];
    }

    // print_arr(output_arr,size_arr);

    for(int i=0;i<size_arr;i++)
    {
        arr[i]=output_arr[i];
    }

}

void radix_sort(int arr[],int size_arr,int digit)
{
    int place=1;
    for (int i = 1; i<=digit ; i++)
    {
        count_sort(arr,size_arr,place);
        place*=10;
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

	radix_sort(arr, size_file ,digit_count);
	
    fp_w = fopen("radix.txt", "w");

	for(int i = 0;i<size_file;i++)
	{
		fprintf(fp_w,"%d\n",arr[i]);
	}
	return 0;
}
