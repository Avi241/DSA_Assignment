
/* Program demo for Command line Arguments, Reading and Writing a file*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp_r, *fp_w; // File Pointers for reading and writing
    int n, counter,min,max; // define the variables for diff outputs
    long sum; // sum can go beyond the size of int so long is used 
    float average; // need upto 2 decimal place for average so float is used
    printf("Value at argv[0]= %s\n", argv[0]); // To verify your 1st Command Line Argument
    printf("Value at argv[1]= %s\n", argv[1]); // To verify your 2nd Command Line Argumnent
    printf("Value of argc =%d\n", argc);       // # of arugments passed through Command Line
    fp_r = fopen(argv[1], "r");                // To read the provided input file
    if (fp_r == NULL) // Check whether file exists
    {
        printf("FILE NOT FOUND");
        exit(0);
    }
    fp_w = fopen("output.txt", "w"); // Write to file ,. 'a'-->append mode
    fscanf(fp_r, "%d", &n); // read the first line of file for initialization
    sum=n,average=n,min=n,max=n,counter=1; // Initialize the variables
    while (fscanf(fp_r, "%d", &n) != EOF) // read the next lines of input file until the End of File(EOF)
    {
        counter++; // increment counter
        sum=sum+n; // Sum the numbers
        if(min>n) // finding min max algo
            min=n;   
            if(max<n)
                max=n;
    }
    average=(float)sum/counter; // take the average need typecasting here
    printf("%d\n%d\n%d\n%ld\n%0.2f\n",counter,min,max,sum,average); // print on console for your ref
    fprintf(fp_w,"%d\n%d\n%d\n%ld\n%0.2f\n",counter,min,max,sum,average); // print in the output files
    fclose(fp_r); // close files
    fclose(fp_w);
    return 0;
}