#include<stdio.h>
#include<windows.h>
 struct date {
  int day;
  int month;
  int year;
 };
struct account {
  char name[20];
  char number[10];
  char street[50];
  char mobileno[11];
  char city[20];
  float paid_amount;
  float due_amount;
  float total_amount;
  struct date dt;
};

void gotoxy(int ,int);
void menu();
void input();
void searchcustomeraccount();
void search_by_name();
void search_by_number();
void viewallaccounts();
int main()
{
    gotoxy(15,8);
    printf("<----------:CUSTOMER BILLING SYSTEM:---------->");
    gotoxy(19,15);
    printf("press any key to continue");
    getch();
    menu();
    return 0;
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,5);
    printf("<----:MENU:---->");
    gotoxy(10,7);
    printf("==============================================");
    gotoxy(10,9);
    printf("1.Add New Customer Account");
    gotoxy(10,11);
    printf("2.Search Customer Account");
    gotoxy(10,13);
    printf("3.All Customers Account details");
    gotoxy(10,15);
    printf("4.Exit");
    gotoxy(10,17);
    printf("==============================================");
    gotoxy(10,19);
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:input();
                break;
        case 2:searchcustomeraccount();
                break;
        case 3:viewallaccounts();
                break;
        case 4:exit(0);
    }
}
void input()
{
    system("cls");
    char another ='y';
    struct account acc;
    FILE *fp=fopen("C:\\Users\\keert\\OneDrive\\Desktop\\PTA\\CSB\\data.txt","ab+");
    while(another=='y')
    {
    gotoxy(10,3);
    printf("<----:ADD A NEW CUSTOMER ACCOUNT:---->");
    gotoxy(10,5);
    printf("Enter customer name: ");
    scanf("%s", acc.name);
    gotoxy(10,7);
    printf("Enter customer account number: ");
    scanf("%s", acc.number);
    gotoxy(10,9);
    printf("Enter customer Mobile number: ");
    scanf("%s", acc.mobileno);
    gotoxy(10,11);
    printf("Enter customer street: ");
    scanf("%s", acc.street);
    gotoxy(10,13);
    printf("Enter customer city: ");
    scanf("%s", acc.city);
    gotoxy(10,15);
    printf("Enter customer total amount: ");
   scanf("%f", &acc.total_amount);
   gotoxy(10,17);
   printf("Enter customer paid amount: ");
   scanf("%f", &acc.paid_amount);
   gotoxy(10,19);
   printf("Enter date of billed: ");
   scanf("%d",&acc.dt.day);
   scanf("%d",&acc.dt.month);
   scanf("%d",&acc.dt.year);
   gotoxy(10,21);
   printf("**Customer Account Added Successfully**\n");
   acc.due_amount = acc.total_amount - acc.paid_amount;
   fwrite(&acc,sizeof(acc),1,fp);
   gotoxy(10,23);
   printf("Want to add of another record? Then press 'y' else 'n'.");
   another=getch();
   system("cls");
   }
   fclose(fp);
   gotoxy(10,25);
   printf("press any key to continue.");
   getch();
   menu();
}
void searchcustomeraccount()
{    system("cls");
    gotoxy(13,8);
    printf("<----:SEARCH A CUSTOMER ACCOUNT:--->");
    gotoxy(15,10);
    printf("1.Search by customer name");
    gotoxy(15,12);
    printf("2.Search by customer number");
    gotoxy(13,15);
    printf("Enter your choice : ");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:search_by_name();
               break;
        case 2:search_by_number();
               break;

    }
}
void search_by_name()
{
    system("cls");
    struct account acc;
    char name[20];
    gotoxy(10,3);
    printf("<----:SEARCH BY NAME:---->");
    gotoxy(10,5);
    printf("Enter Customer Name:");
    scanf("%s",name);
    FILE *fp=fopen("C:\\Users\\keert\\OneDrive\\Desktop\\PTA\\CSB\\data.txt","rb");
    if(fp == NULL){
        gotoxy(10,7);
        printf("Error opening file.");
        exit(1);
    }
    while(fread(&acc,sizeof(acc),1,fp)==1)
    {
        if(strcmp(acc.name,name)==0)
        {
            gotoxy(10,9);
            printf("Name:%s",acc.name);
            gotoxy(10,11);
            printf("Number:%s",acc.number);
            gotoxy(10,13);
            printf("Mobile Number:%s",acc.mobileno);
            gotoxy(10,15);
            printf("Street:%s",acc.street);
            gotoxy(10,17);
            printf("city:%s",acc.city);
            gotoxy(10,19);
            printf("paid Amount:%.2f",acc.paid_amount);
            gotoxy(10,21);
            printf("Due Amount:-%.2f",acc.due_amount);
            gotoxy(10,13);
            printf("Date of Billed:%d%d%d",acc.dt.day,acc.dt.month,acc.dt.year);

        }
    }
   fclose(fp);
   gotoxy(10,25);
   printf("press any key to continue.");
   getch();
   menu();
}
void search_by_number()
{
    system("cls");
    struct account acc;
    char number[20];
    gotoxy(10,3);
    printf("<----:SEARCH BY NUMBER:---->");
    gotoxy(10,5);
    printf("Enter Customer Number:");
    scanf("%s",number);
    FILE *fp=fopen("C:\\Users\\keert\\OneDrive\\Desktop\\PTA\\CSB\\data.txt","rb");
    if(fp == NULL){
        gotoxy(10,7);
        printf("Error opening file.");
        exit(1);
    }
    while(fread(&acc,sizeof(acc),1,fp)==1)
    {
        if(strcmp(acc.number,number)==0)
        {
            gotoxy(10,9);
            printf("Name:%s",acc.name);
            gotoxy(10,11);
            printf("Number:%s",acc.number);
            gotoxy(10,13);
            printf("Mobile Number:%s",acc.mobileno);
            gotoxy(10,15);
            printf("Street:%s",acc.street);
            gotoxy(10,17);
            printf("City:%s",acc.city);
            gotoxy(10,19);
            printf("paid Amount:%.2f",acc.paid_amount);
            gotoxy(10,21);
            printf("Due Amount:-%.2f",acc.due_amount);
            gotoxy(10,23);
            printf("Date of Billed:%d-%d-%d",acc.dt.day,acc.dt.month,acc.dt.year);
        }

    }
   fclose(fp);
   gotoxy(10,25);
   printf("Press any key to continue.");
   getch();
   menu();
}
void viewallaccounts()
{
    int i=1,j;
    struct account acc;
    system("cls");
    gotoxy(2,3);
    printf("<----:VIEW ALL CUSTOMERS DETAILS:---->");
    gotoxy(2,5);
    printf("S.No Name of Customer  AccountNo  MobileNo  Street         City           Total Amount   Paid Amount      Due Amount");
    gotoxy(2,6);
    printf("--------------------------------------------------------------------------------------------------------------------");
    FILE *fp = fopen("data.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&acc,sizeof(acc),1,fp) == 1){
        gotoxy(2,j);
        printf("%-7d%-18s%-7s%-12s%-15s%-15s%-15.2f%-18.2f%-14.2f",i,acc.name,acc.number,acc.mobileno,acc.street,acc.city,acc.total_amount,acc.paid_amount,-acc.due_amount);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(2,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
