#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting_function(int n, int arr[], int *permutation,int *comparison){     //"расческа"
        int step=n-1,tmp;
        while(step>=1){
                for(int i=0;i<n-step;i++){
                        if(arr[i]>arr[i+step]){
                                tmp=arr[i];
                                arr[i]=arr[i+step];
                                arr[i+step]=tmp;
                                (*permutation)++;//перестановки
                        }
                        (*comparison)++;//сравнение
                }
                step--;
        }
}

int main(){
    clock_t start,stop;
    double rez,sr_rez = 0;
    double comp_avg=0,perm_avg=0;
    int comparison,permutation;
    start = clock();
    for(int ch=0;ch<1;ch++){
        int n=200;
        comparison=0,permutation=0;
        int arr[n];
        for(int i=0;i<n;i++){arr[i]=rand()%(2*n)+1;} // наилучший {arr[i]=n + i - 199;} // наихудший {arr[i]=n-i}; 
        sorting_function(n,arr,&permutation,&comparison);
        for(int i=0;i<n;i++){ printf("%d ", arr[i]); } //отсортированный массив
        printf("\n");
        printf("comparison: %d\n",comparison);
        printf("permutation: %d\n",permutation);
        comp_avg+=comparison;
        perm_avg+=permutation;
    }
    stop = clock();
    long double clock_rez = (stop - start)/(long double)CLOCKS_PER_SEC;
    printf("%Lf \n",clock_rez/1000);
    start ,stop = 0;
    clock_rez = 0;
    comp_avg=comp_avg/100;
    perm_avg=perm_avg/100;
    printf("average comparison: %.0f\n",comp_avg);
    printf("average permutation: %.2f\n",perm_avg);
    return 0;
}
