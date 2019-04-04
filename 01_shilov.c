#include <stdio.h>
#include <stdlib.h> // fast sorting_function

void sorting_function(int arr[],int left,int right){
        int i=left,j=right,d,m = arr[(left+right)/2];
        while(i<=j){
            for(;arr[i]<m;i++);
            for(;arr[j]>m;j--);
            if(i<=j){
                d=arr[i];
                arr[i++]=arr[j];
                arr[j--]=d;
            }
        }
        if(left<j) sorting_function(arr,left,j);
        if(i<right) sorting_function(arr,i,right);
}

int main()
{
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
            }
        sorting_function(arr,0,n);

        for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
        printf("\n");
        return 0;
}
