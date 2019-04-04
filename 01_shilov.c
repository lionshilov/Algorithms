#include <stdio.h>
#include <stdlib.h> // сортировка расческой

void sorting_function(int n, int arr[]){
        int step = n-1, tmp;
        while(step>=1){
                for(int i=0;i<n-step;i++){
                        if(arr[i]>arr[i+step]){
                                tmp=arr[i];
                                arr[i]=arr[i+step];
                                arr[i+step]=tmp;
                        }
                }
                step--;
        }
}

int main(){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
        sorting_function(n,arr);
        for(int i=0;i<n;i++){
                printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
}
