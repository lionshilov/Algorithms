#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main()
{
     signed long long int vvod, max, min, n;
     printf("Сколько чисел вы хотите ввести? = "); 
     scanf("%lld %lld",&n,&vvod);
     max = min = vvod;
     for (int i = 1; i < n; ++ i)
     {
          scanf("%lld",&vvod);
          if (vvod > max) max = vvod;
          if (vvod < min) min = vvod;
     }
    printf("Максимум = %lld",max);
 getchar();
}
