#include <stdio.h>
#include <stdlib.h>

int cubeNum(int InputInt){
    int product = 1;
    for (int j = 1; j <= 3; j++){
        product *= InputInt;
    }
    return product;
}
int isArmStrong(int inputNum){
    int n = 0;
    char strInt[n];
    sprintf(strInt,"%d",inputNum);
    n = strlen(strInt);
    char digit;
    int limit = n - 1;
    int Sum = 0;
    int intDigitCube;
    for (int i = 0; i <= limit; i++){
        digit = strInt[i];
        intDigitCube = cubeNum(atoi(&digit));
        Sum += intDigitCube;
    }
    if (inputNum == Sum){
        printf("%d is an armstrong number.",inputNum);
    } else{
        printf("%d is not an armstrong number.",inputNum);
    }

}
int main()
{
    isArmStrong(1634);
    return 0;
}
