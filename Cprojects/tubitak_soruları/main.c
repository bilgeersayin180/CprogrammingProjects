#include <stdio.h>
#include <stdlib.h>

int main()
{
     int x = 1, y = 1, z = 2, i = 0;
     for (i = 2; i < 5; i++)
         printf("%d ", y++);
     while (x < y){
         for (i = 4; i > z; --i){

            printf("%d %d ",i, z);
         }
          x+=1;
}
return 0;
}

