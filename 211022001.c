/* Program demo for Command line Arguments, Reading and Writing a file*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp_r, *fp_w; // File Pointers for reading and writing
    int n, counter,min,max;
    long sum;
    float average;
    printf("Value at argv[0]= %s\n", argv[0]); // To verify your 1st Command Line Argument
    printf("Value at argv[1]= %s\n", argv[1]); // To verify your 2nd Command Line Argumnent
    printf("Value of argc =%d\n", argc);       // # of arugments passed through Command Line
    fp_r = fopen(argv[1], "r");                // To read the provided input file
    if (fp_r == NULL)
    {
        printf("FILE NOT FOUND");
        exit(0);
    }
    fp_w = fopen("output.txt", "w"); // Write to file ,. 'a'-->append mode
    sum=0,average=0,min=0,max=0,counter=0;
    while (fscanf(fp_r, "%d", &n) != EOF)
    {
        counter++;
        sum=sum+n;
        // min=max=n;
        if(min>n)
            min=n;   
            if(max<n)
                max=n;
    }
    average=(float)sum/counter;
    printf("%d %ld %0.2f %d %d \n",counter,sum,average,min,max);
    fprintf(fp_w, "%d\n", n);
    fclose(fp_r);
    fclose(fp_w);
    return 0;
}