//****************************************************************************
//  HEADER FILE USED IN PROJECT
//****************************************************************************
#include<bits/stdc++.h>
#include<iostream>
#include<process.h>
#include <conio.h>
#include<fstream>
#include<iomanip>
#include<string>
#include<windows.h>


using namespace std;

//****************************************************************************
// CLASS USED IN PROJECT
//****************************************************************************
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
class product
{
   char pno[5];
   char name[50],price[5],dis[5];
   float qty, tax;
   public:
   void create_product()
   {
      gotoxy(23,1);
      cout<<"******NEW ACCESSORIES DETAILS*****";
      cout << "\n\n\tPlease Enter The Product Code of Accessories: ";
      gets(pno);
      cout << "\tPlease Enter The Name of  Accessories       : ";
      gets(name);
      cout << "\tPlease Enter The Price of  Accessories      : ";
      gets(price);
      cout << "\tPlease Enter The Discount (%)               : ";
      cin >> dis;
   }

   void new_product()
   {
      char p[10],d[10];
      gotoxy(23,2);
      cout<<"******NEW ACCESSORIES DETAILS******";
      gotoxy(26,4);
      cout<<"Enter . to retain old one";
      cout << "\n\n\tPlease Enter The Product Code of Accessories : ";
      puts(pno);
      cout << "\tPlease Enter The Name of  Accessories        : ";
      puts(name);
      cout << "\tPlease Enter The Price of Accessories        : ";
      gets(p);
      cout << "\tPlease Enter The Discount (%)                : ";
      gets(d);
      if(strcmp(p,".")!=0)
      {
	 strcpy(price,p);
      }
      if(strcmp(d,".")!=0)
       {
	 strcpy(dis,d);
       }
       }
   void show_product()
   {
      cout << "\n\n\tThe Product Code of Accessories    : ";
      puts(pno);
      cout << "\tThe Name of The Accessories        : ";
      puts(name);
      cout << "\tThe Price of The Accessories       : ";
      puts(price);
      cout << "\tDiscount                           : " << dis<<"%";
   }

   char* retpno()
   {
      return pno;
   }

   char* retprice()
   {
      return price;
   }

   char* retname()
   {
      return name;
   }

   char* retdis()
   {
      return dis;
   }

};

//****************************************************************************
// GLOBAL DECLARATION FOR STREAM OBJECT, OBJECT
//****************************************************************************

fstream fp;
product pr;
//****************************************************************************
// FUNCTION TO WRITE IN FILE4
//****************************************************************************

void write_product()
{
   char ch;
   do
   {
    
   fp.open("Shop.dat", ios::out | ios::app);
   pr.create_product();
   fp.write((char * ) & pr, sizeof(product));
   gotoxy(24,8);
   cout << "...Accessories Record Created...";
   cout<<"\n\n\t\tDo You Want To Create More Record (y/n) : ";
   cin>>ch;
   fp.close();
   }while(ch=='y'||ch=='Y');
}


//****************************************************************************
// FUNCTION TO READ ALL RECORDS FROM FILE
//****************************************************************************
void display_all()
{
    
   gotoxy(25,1);
   cout << "******ACCESSORIES RECORDS******";
   fp.open("Shop.dat", ios:: in );
   while (fp.read((char * ) & pr, sizeof(product)))
   {
      pr.show_product();
      cout << "\n\t===================================================";
      getch();
   }
   fp.close();
}
//***************************************************************
// function to read specific record from file
//****************************************************************
void display_sp(char n[])
{
   int flag = 0;
   fp.open("Shop.dat", ios:: in );
   while (fp.read((char * ) & pr, sizeof(product)))
   {
      if(strcmpi(pr.retpno(),n)==0)
      {
	  
	 flag=1;
	 gotoxy(25,1);
	 cout<<"******ACCESSORIES DETAILS******";
	 pr.show_product();
      }
    }
    fp.close();
    if (flag == 0)
    {
        
       gotoxy(23,2);
       cout<<"...Accessories Record Not Found...";
    }
    getch();
}
//****************************************************************************
// FUNCTION TO MODIFY RECORD OF FILE
//****************************************************************************
void modify_product()
{
   int found = 0;
   char no[5];
    
   gotoxy(25,1);
   cout << "******MODIFY ACCESSORIES******";
   cout << "\n\n\tEnter The Accessories Code : ";
   gets(no);
   fp.open("Shop.dat", ios:: in | ios::out);
   while (fp.read((char * ) & pr, sizeof(product)) && found == 0)
   {
      if(strcmpi(pr.retpno(),no)==0)
      {
	  
	 pr.new_product();
	 int pos = -1 * sizeof(pr);
	 fp.seekp(pos, ios::cur);
	 fp.write((char * ) & pr, sizeof(product));
	 gotoxy(24,11);
	 cout << "...Accessories Record Updated...";
	 found = 1;
      }
    }
    fp.close();
    if (found == 0)
    {
        
       gotoxy(23,2);
       cout << "...Accessories Record Not Found...";
    }
    getch();
}
//****************************************************************************
// FUNCTION TO DELETE RECORD OF FILE
//****************************************************************************
void delete_product()
{
   int flag=0;
   char n[5],ch;
    
   gotoxy(25,1);
   cout << "******Delete Accessories******";
   cout << "\n\n\tPlease Enter The Accessories Code : ";
   gets(n);
   fp.open("Shop.dat", ios:: in | ios::out);
   fstream fp2;
   fp2.open("Temp.dat", ios::out);
   fp.seekg(0, ios::beg);
   while(fp.read((char*)&pr,sizeof(product)))
    {
	if(strcmpi(pr.retpno(),n)==0)
	{
	    gotoxy(25,5);
	    cout<<"******Accessories Details******";
	    pr.show_product();
	    flag=2;
	    cout<<"\n\n\t\t Sure To Delete This Accessories Record (Y/N) ? : ";
	    cin>>ch;
	}
    }
    fp.close();
    fp.open("shop.dat",ios::in);
    fp.seekg(0,ios::beg);
    if(ch=='y'||ch=='Y')
    {
	while(fp.read((char*)&pr,sizeof(product)))
	{
	    if(strcmpi(pr.retpno(),n)!=0)
	    {
		fp2.write((char*)&pr,sizeof(product));
	    }
	    else
	    {
		flag=1;
	    }
	}
    }
    fp2.close();
    fp.close();
    if(flag==1)
    {
	remove("shop.dat");
	rename("Temp.dat","shop.dat");
	gotoxy(31,15);
	cout<<"...Record Deleted...";
    }
    else if(flag==2)
    {
	gotoxy(29,15);
	cout<<"...Deletion Abounded...";
    }
    else
    {
	 
	gotoxy(29,2);
	cout<<"...Record Not Found...";
    }
    getch();
}//****************************************************************************
// FUNCTION TO DISPLAY ALL PRODUCTS PRICE LIST
//****************************************************************************

void menu()
{
   int a,b,c,x,y,z;
    
   fp.open("Shop.dat", ios:: in );
   if (!fp)
   {
      cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
      cout << "\n\n\n Program is closing ....";
      getch();
      exit(0);
   }
   gotoxy(26,1);
   cout << "******Accessories List******";
   cout << "\n\n============================================\n";
   cout << "  Code  |     Name     |  Price  | Discount\n";
   cout << "============================================\n";

   while (fp.read((char * ) & pr, sizeof(product)))
   {
      a=strlen(pr.retpno());
      b=strlen(pr.retname());
      c=strlen(pr.retprice());
      x=9-a;
      y=14-b;
      z=11-c;
      cout <<"  "<<pr.retpno()<<setw(x)<<"|  "<<pr.retname()<<setw(y)<<"| "<<pr.retprice()<<setw(z)<<"|  "<<pr.retdis()<<"%"<<endl;
   }
   fp.close();
}
//****************************************************************************
// INTRODUCTION FUNCTION
//****************************************************************************

void intro()
{
    
   gotoxy(29,8);
   cout<<"******PROJECT******";
   gotoxy(22,9);
   cout << " COMPUTER SHOP MANAGEMENT SYSTEM";
   gotoxy(22,11);
   cout << "MADE BY : Prashant Sharma";
   gotoxy(22,12);
   cout << "CLASS   : 12 th";
   gotoxy(22,13);
   cout << "SCHOOL  : Modern Era Public School";
   getch();

}
//****************************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************************

void disp_all()
{
    
   char ch;
   gotoxy(24,1);
   cout<<"******Display All Menu******";
   cout<<"\n\n\t1.ONE BY ONE";
   cout<<"\n\n\t2.ALL";
   cout<<"\n\n\t3.BACK";
   ch=getche();
   switch(ch)
   {
      case '1':
		  
		 display_all();
		 break;
      case '2':
		  
		 menu();
		 getch();
		 break;
      case '3':
		 return;
      default :
		 disp_all();
   }
}

void admin_menu()
{
    char ch2;
    do
    {
        
       gotoxy(27,1);
       cout << "******ADMIN MENU******";
       cout << "\n\n\t1.CREATE ACCESSORIES DETAIL";
       cout << "\n\n\t2.DISPLAY ALL ACCESSORIES DETAIL";
       cout << "\n\n\t3.DISPLAY SPECIFIC ACCESSORIES DETAIL";
       cout << "\n\n\t4.MODIFY ACCESSORIES DETAIL";
       cout << "\n\n\t5.DELETE ACCESSORIES DETAIL";
       cout << "\n\n\t6.BACK";
       cout << "\n\n\tPlease Enter Your Choice (1-7) ";
       ch2 = getche();
       switch (ch2)
       {
	  case '1':
		      
		     write_product();
		     break;
	  case '2':
		     disp_all();
		     break;
	  case '3':
		     char num[5];
		      
		     gotoxy(15,2);
		     cout<<"******Display Specific Accessories Detail******";
		     cout << "\n\n\tPlease Enter The Accessories Code :";
		     cin >> num;
		     display_sp(num);
		     break;
	  case '4':
		     modify_product();
		     break;
	  case '5':
		     delete_product();
		     break;
	  case '6':
		     return;
	  default :
		     cout << "\a";
       }
    }while(ch2 != '6');
}
//****************************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************************
int main()
{
    char ch;
    intro();
    do
    {
	 
	gotoxy(28,1);
	cout << "******MAIN MENU******";
	cout << "\n\n\t01. ADMINISTRATOR";
	cout << "\n\n\t02. EXIT";
	cout << "\n\n\tPlease Select Your Option (1-2) :";
	ch = getche();
	switch (ch)
	{
	   case '1':
		      admin_menu();
		      break;
	   case '2':
		      exit(0);
	   default :
		      cout << "\a";
	}
    } while (ch != '2');
}
//****************************************************************************
// END OF PROJECT
//****************************************************************************
