#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void multiplyLargeNumbers(char *num1,int len1,char* num2,int len2){
    int resultLen=len1 + len2;
    int* result=(int *)calloc(resultLen,sizeof(int));
    for(int i=len1-1;i>=0;i--){
        for (int j= len2-1;j>=0;j--){
            int mul=(num1[i]-'0')* (num2[j]-'0');
            int sum=mul+result[i+j+1];
            result[i+j+1]=sum%10;
            result[i+j]+=sum/10;

        }
    }
// Print numbers and the result
    printf("%s x %s = ", num1, num2);

    // Skip leading zeros in the result
    int i = 0;
    while (i < resultLen && result[i] == 0)
        i++;

    // If all digits are zero (e.g., 0 x 0)
    if (i == resultLen)
        printf("0");
    else
        for (; i < resultLen; i++)
            printf("%d", result[i]);

    printf("\n");

    free(result);
}




int main() {
    int len1, len2;

    // Input length and number 1
    printf("Enter length of first number: ");
    scanf("%d", &len1);
    char *num1 = (char *)malloc((len1 + 1) * sizeof(char)); // +1 for null terminator
    printf("Enter first number of length %d: ", len1);
    scanf("%s", num1);

    // Input length and number 2
    printf("Enter length of second number: ");
    scanf("%d", &len2);
    char *num2 = (char *)malloc((len2 + 1) * sizeof(char));
    printf("Enter second number of length %d: ", len2);
    scanf("%s", num2);

    // Call multiplication function
    multiplyLargeNumbers(num1, len1, num2, len2);

    // Free allocated memory
    free(num1);
    free(num2);

    return 0;
}