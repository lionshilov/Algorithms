#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting_function(int n,int mass[], int *permutation,int *comparison){//Сортировка Шелла
        int i,j,step,tmp;
        for(step=n/2;step>0;step/=2){
                for(i=step;i<n;i++){
                        tmp=mass[i];
                        for(j=i;j>=step;j-=step){
                                (*comparison)++;
                                if(tmp<mass[j-step])mass[j]=mass[j-step];
                                else break;
                        }
                        mass[j]=tmp;
                        (*permutation)++;
                }
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
        for(int i=0;i<n;i++){ printf("%d ", arr[i]); }//отсортированный массив
        printf("\n");
        printf("Sravneniy: %d\n",comparison);
        printf("Perestanovok: %d\n",permutation);
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
