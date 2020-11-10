/* 
C Program to Check is The Credit Card Number Valid Or Not
Dont know what its not working for live cc and ccn
but wroking for indian physical cards
Amex is not perfectly supported
*/
#include <stdio.h>
void merchant(int cc[])
{
    /// Merchant Used International
    int merchant = 0;
    for (int i = 0; i < 6; i++)
            merchant = merchant*10 + cc[i];
    if(merchant>=360001 && merchant<=369999)
    printf("Merchant = DINNER\n");
    else if(merchant>=370000 && merchant<=379999)
    printf("Merchant = AMEX\n");
    else if((merchant>=380000 && merchant<=399999) ||(merchant>=644000 && merchant<=652149))
    printf("Merchant = DISCOVER\n");
    else if(merchant>=400000 && merchant<=499999)
    printf("Merchant = VISA\n");
    else if(merchant>=510000 && merchant<=559999)
    printf("Merchant = MASTERCARD\n");
    else if((merchant>=652150 && merchant<=653149) || (merchant>=508500 && merchant<=50808999))
    printf("Merchant = RUPAY\n");
    else 
    printf("Merchant = Unknown\n");

}
int main()
{
    int cc[16],sum = 0, sum_10 = 0, sum2 = 0,large_10, sumt;
    printf("For Amex Please Enter First Number of CVV At The Place Of 16 Digit\nProvide Space After Each Digit At Last Press Enter\nEnter Credit Card Number\n\n");
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &cc[i]);
    }
    if(cc[0]>=3 && cc[0]<=6)
    {
        merchant(cc);       
        for (int i = 0; i < 16; i+=2)
        {
            large_10 = 2*cc[i];
            if(large_10>=10)
            sum_10 = sum_10 + (large_10 - 9);
            else if(large_10<10)
            sum = sum+cc[i];
        } 
        for (int i = 1; i < 16; i+=2)
            sum2 = sum2 + cc[i];
        sumt = sum + sum2 + sum_10;
        if(sumt%10 == 0)
        {
            for (int i = 0; i < 16; i++)
            {
                printf("%d", cc[i]);
                if((i+1)%4 == 0)
                printf(" ");
            }
            printf("\nIs A Valid Credit Card Number\n");
        }
        else
        {
            for (int i = 0; i < 16; i++)
            {
                printf("%d", cc[i]);
                if((i+1)%4 == 0)
                printf(" ");
            } 
            printf("\nIs Not A Valid Credit Card Number\n");
            printf("Sumt = %d\n", sumt);
        }
    }
    else
    printf("Enter Valid Merchant Credit Card Number\n");
        
}