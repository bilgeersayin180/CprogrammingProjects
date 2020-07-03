#include <stdio.h>
#include <stdlib.h>

int SumOfDigits(int number){
    int limit = 0;
    char strNum[limit];

    sprintf(strNum, "%d", number);

    limit = strlen(strNum);

    int DigitSum = 0;
    char digit;
    for (int i = 0; i <= limit - 1;i++){
        digit = strNum[i];
        DigitSum += atoi(&digit);
    }
    printf("Sum of digits of the number that you entered: %d", DigitSum);
    return 0;

}

int main(){
    SumOfDigits(22222);
    return 0;
}

