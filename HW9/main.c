/*Furkan Taşkın 200104004072 HW9*/
#include <stdio.h>
#include <stdlib.h>

/*global declarations for use in different functions*/
int Id; /*connects loans to customers*/
int id_cus;
float amount;
float interestRate;
int period;
int Id_arr[50];
float amount_arr[50];
float interestRate_arr[50];
int period_arr[50];
int i=0;
float total;
float total1=0, total2=0, total3=0;

union Person
{
   char name[50];
   char address[50];
   int phone;
} ;

union Loan
{
  float amount;
  float interestRate;
  int period;
};

struct BankAccount
{
  union Person Customer;
  union Loan Loans[3];
};


double calculateLoan(float amount, int period, float interestRate);/*takes two float and one integer and calculates the loan according to formula recursivelty*/
void listCustomers(struct BankAccount *Account); /*prints all customer names in the struct*/
void addCustomer(struct BankAccount *Account);/*adds customers details to Customer union and also customer.txt file*/
void newLoan(struct BankAccount *Account);/*assigns loans to customers*/
void getReport(int cus_or_loan,int id_num);/*prints customer details from customer.txt file or loan details from global array*/
void my_fflush(); /*helper function for clearing the buffer after scanf*/


int main()
{
  int flag=0;
  int select,cus_or_loan,id_num;
  struct BankAccount Account[50];/*array of struct */


    while(flag!=1)/*flag contolled loop*/
    {
          printf("\n=====================================\n");
          printf("Welcome to the bank management system\n");
          printf("=====================================\n");
          printf("1.List all customers\n");
          printf("2.Add new customer\n");
          printf("3.New loan application\n");
          printf("4.Report Menu\n");
          printf("5.Exit system\n");
          scanf("%d", &select);
          my_fflush(); /*clearing the buffer*/

          switch (select)
          {
            case 1:
              listCustomers(Account);
            break;
            case 2:
              addCustomer(Account);
            break;
            case 3:
              newLoan(Account);
            break;
            case 4:
              printf("1.Customer Detail\n");
              printf("2.Loan Detail\n");
              scanf("%d",&cus_or_loan);
              my_fflush();
                if (cus_or_loan==2)
                {
                   printf("\nPlease enter the id number:");
                   scanf("%d",&id_num);
                }
              getReport(cus_or_loan,id_num);
            break;
            case 5:
              flag=1;
            break;

            default:
              printf("\nPlease enter a valid input!\n\n");
          }

    }

  return 0;
}

/*𝑳𝒐𝒂𝒏 𝑭𝒐𝒓𝒎𝒖𝒍𝒂 = 𝑨𝒎𝒐𝒖𝒏𝒕 ∗ (𝟏 + 𝒊𝒏𝒕𝒆𝒓𝒆𝒔𝒕𝑹𝒂𝒕𝒆)^𝒑𝒆𝒓𝒊𝒐𝒅*/
double calculateLoan(float amount, int period, float interestRate)
{
   if (period==0)  /*means there is no interest,just first main credit value*/
     return amount;
   else
     return (1+interestRate)*calculateLoan(amount,period-1,interestRate);/*decrease the period by 1 and multiply according to formula*/
}


void listCustomers(struct BankAccount *Account)
{
    printf("%s\n",Account->Customer.name);

}


void newLoan(struct BankAccount *Account)
{
   int id_loan;
   int counter=0;

   printf("Please enter your ID number: ");
   scanf("%d",&id_loan);/*getting number from user */
   Id=id_loan;         /*assigning id_loan to global Id variable for later comparison*/
   Id_arr[i]=id_loan; /*also the array */

   if (id_cus==id_loan)
   {
       counter++;
       if (counter<=3)
       {
           /*doing the things again for different parameters*/
           printf("Please enter how much credit you want to take out: ");
           scanf("%f",&(Account->Loans->amount));
           amount = Account->Loans->amount;
           amount_arr[i] = amount;

           printf("Please enter your period: ");
           scanf("%d",&(Account->Loans->period));
           period = Account->Loans->period;
           period_arr[i] = period;

           printf("Please enter your interest rate: ");
           scanf("%f",&(Account->Loans->interestRate));
           interestRate = Account->Loans->interestRate;
           interestRate_arr[i] = interestRate;

           total=calculateLoan(amount,period,interestRate);/*calculating the loan and printing*/
           printf("Total loan: %.2f\n",total);
           i++;/*increment by one for store in next cells in arrays*/

           if (counter==1)
           {
              total1=calculateLoan(amount,period,interestRate);
           }
           if (counter==2)
           {
              total2=calculateLoan(amount,period,interestRate);
           }
           if (counter==3)
           {
              total3=calculateLoan(amount,period,interestRate);
           }
       }
       else
         printf("\nOne customer can not have more than 3 loans!\n" );
    }
}


void getReport(int cus_or_loan,int id_num)
{
    FILE *fp;
    fp=fopen("customer.txt","a+");/*opening customer.txt*/
    char ch;
    float monthly;
    int a,j;

     if(cus_or_loan==1)/*user wants to see customers details*/
     {
         while (!feof(fp))/*not end of the file*/
         {
            ch = fgetc(fp);/*get every character in that file*/
            printf("%c", ch);/*and print them*/
         }
     }
     else if (cus_or_loan==2)/*user wants to see loan details*/
     {
          for (a = 0; a < 50; a++)/*traversing the array*/
          {
             if (Id_arr[a]==id_num)/*given id is found in global array*/
             {
                /*print them */
                printf("Amount: %.2f\n",amount_arr[a]);
                printf("Period: %d\n",period_arr[a]);
                printf("Interest rate: %.2f\n",interestRate_arr[a]);

                total = calculateLoan(amount,period,interestRate);
                printf("\nTotal credit value: %.2f\n", total);
                monthly = total / period_arr[a]; /*monthly payments will be equal to total credit divide by period*/
                printf("\n\n");

                for (j = 1; j <= period_arr[a]; j++)
                   printf("%d. Month Installment = %.2f\n",j,monthly); /*printing monthly payments*/
             }
          }
     }
    fclose(fp);
}

void addCustomer(struct BankAccount *Account)
{
    FILE *fp;
    fp=fopen("customer.txt","a+");

    /*taking details to union and write to customer.txt*/
    printf("Customer ID:");
    scanf("%d",&id_cus);
    fprintf(fp, "ID:%d\n",id_cus);

    printf("Customer phone:");
    scanf("%d",&(Account->Customer.phone));
    fprintf(fp, "Phone:%d\n", Account->Customer.phone);

    printf("Customer address:");
    scanf("%s",Account->Customer.address);
    fprintf(fp, "Adress:%s\n",Account->Customer.address);

    printf("Customer name:");
    scanf("%s",Account->Customer.name);
    fprintf(fp, "Name:%s\n", Account->Customer.name);



    fprintf(fp, "Loan:[%.2f + %.2f + %.2f]\n",total1,total2,total3);


    fprintf(fp, "\n");

fclose(fp);
}


void my_fflush()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
