#include <stdio.h>
#include <stdlib.h>

int main()
{   int d = 1;
    for (int i = 1; i <= 4; i++){
        printf("\n");
        for(int j = 1; j <= i; j++){
            printf("%5d", d);
            d += 3;
        }
    }
    return 0;
}
