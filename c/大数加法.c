#include<stdio.h>
#include<string.h>
 
#define MAX 1000     
 
int Addition(char num1[], char num2[], int sum[]); 
int main()
{
    int i, len;
    int sum[MAX] = {0};  
    char num1[] = "1234567891234567891234";  
    char num2[] = "2345678912345678913345"; 
    len = Addition(num1, num2, sum);     
    printf("%s\n  +\n%s\n  =\n", num1, num2);
    for (i = len-1; i >= 0; i--)
        printf("%d", sum[i]);
    printf("\n"); 
    
    return 0;
}

int Addition(char num1[], char num2[], int sum[])
{
    int i, j, len;
    int n2[MAX] = {0};
    int len1 = strlen (num1);  
    int len2 = strlen (num2);  
 
    len = len1>len2 ? len1 : len2; 
    for (i = len1-1, j = 0; i >= 0; i--, j++) 
        sum[j] = num1[i] - '0';
    for (i = len2-1, j = 0; i >= 0; i--, j++)
        n2[j] = num2[i] - '0';
    for (i = 0; i <= len; i++)
    {
        sum[i] += n2[i];  
        if (sum[i] > 9)  
        {   
            sum[i] -= 10;
            sum[i+1]++;
        }
    }
    if(sum[len] != 0)   
        len++;
    return len;    
} 
