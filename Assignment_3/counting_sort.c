#include <stdio.h>
#include <stdlib.h>

void print_arr(int arr[],int arr_size)
{
    
    for(int i=0;i<arr_size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
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
        printf("%d\n",place);
        count_sort(arr,size_arr,place);
        place*=10;
    }
}

void main()
{
    int arr[] = {1,300,1,800,5,8,80,4568};
    int size_arr = sizeof(arr)/ sizeof(arr[0]);
    print_arr(arr,size_arr);
    radix_sort(arr,size_arr,4);
    print_arr(arr,size_arr);

}
