/*Bubble sort algorithm for practice by rishi yadav*/

#include<stdio.h>
#include<malloc.h>

void swap(int *var1,int *var2){

    int temp;
    temp=*var1;
    *var1=*var2;
    *var2=temp;
    printf("In swap\n");
    printf("%d %d\n",*var1,*var2);

}

void Bubble_sort(int lower,int upper,int *a){

    int flag,n,j,i;
    if(lower>=upper) return;
    n=upper-lower+1;

    for(j=0;j<n-1;j++){

        flag=0;
        for(i=0;i<n-2-j;i++){

            if(a[i]>a[i+1]){
                swap(&a[i],&a[i+1]);
                flag=1;
                printf("yes\n");
            }
        }
        if(flag==0) return;
    }

/*
    for(int i=lower;i<upper;i++)
        printf("%d",(*(a+i)));*/

}


int main(int argc, char const *argv[])
{
    int n;
    /* code */
    printf("Enter number of values : ");
    scanf("%d",&n);

    int *a=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&(*(a+i)));

    /*Bubble sort call*/
    Bubble_sort(0,n,a);


    for(int i=0;i<n;i++)
        printf("%d ",(*(a+i)));
        printf("\n");
    return 0;
}

