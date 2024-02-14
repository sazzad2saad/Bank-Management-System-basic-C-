#include<bits/stdc++.h>
#include<conio.h>
#define clr (system("CLS"))
#include<windows.h>
using namespace std;
class sys
{
    int ac_no;
    string name;
    string dob;
    string f_name;
    string phone_num;
    string email;
    float amount;

    fstream file, file1;

public:
    int check_ac_no;
    //declaration
    void create_ac();
    void ac_info();
    void dep();
    void withdraw();
};
int main()
{
    sys obj;
    char choice;
    string str="Welcome to Our Banking system";
    int i=0;
    cout<<"\t\t::   ";
    while(str[i]!='\0')
    {
        Sleep(100);
        cout<<str[i];
        i++;
    }
    cout<<"  ::\n";
    Sleep(500);
main_menu:               //main menu start
    cout<<"\n\n\n\t\t.......:::     Our Bank     :::.......";
    cout<<"\n\t\t::     press 1 to Login  Account    :: ";
    cout<<"\n\t\t::     press 2 to Create Account    ::";
    cout<<"\n\t\t::                                  ::";
    cout<<"\n\t\t::         press 0 to Exit          ::";
    cout<<"\n\t\t:: ................................ ::\n\t\t\t\t";


    choice= getch();
    switch(choice)
    {

    case 49:
        clr;
        cout<<"\n\n\n\n\t\t.......:::     Our Bank     :::.......";
        cout<<"\n\t\t::     press 1 for Account Info     :: ";
        cout<<"\n\t\t::     press 2 to  Deposit  Money   ::";
        cout<<"\n\t\t::     press 3 to  Withdraw Money   :: ";
        cout<<"\n\t\t::                                  ::";
        cout<<"\n\t\t::          press 0 to Exit         ::";
        cout<<"\n\t\t:: ................................ ::\n\t\t\t\t";
        char choice3;
        choice3=getch();
        switch(choice3)
        {
        case 49:
            obj.ac_info();
            break;
        case 50:
            obj.dep();
            break;
        case 51:
            obj.withdraw();
            break;
        case 48:
            exit(0);
            break;
        default:
            clr;
            cout<<"\n\n\t\t......................................";
            cout<<"\n\t\t::          Invalid Input           :: ";
            cout<<"\n\t\t::                                  :: ";
            cout<<"\n\t\t::   press 1 to Back to main menu   :: ";
            cout<<"\n\t\t::   press 0 to Exit                ::";
            cout<<"\n\t\t......................................\n\t\t\t\t";
            int choice4;
            choice4=getch();
            switch(choice4)
            {
            case 49:
                clr;
                goto main_menu;
                break;
            case 48:
                exit(0);
                break;
            default:

                cout<<"\n\n\t\tInvalid choice. Please try again.";

            }
        }

        break;
    case 50:
        clr;
        obj.create_ac();
        break;
    case 48:
        exit(0);
        break;
    default:
        clr;
        cout<<"\n\n\t\t......................................";
        cout<<"\n\t\t::          Invalid Input           :: ";
        cout<<"\n\t\t::                                  :: ";
        cout<<"\n\t\t::   press 1 to Back to main menu   :: ";
        cout<<"\n\t\t::   press 0 to Exit                ::";
        cout<<"\n\t\t......................................\n\t\t\t\t";
        int choice2;
        choice2=getch();
        switch(choice2)
        {
        case 49:
            clr;
            goto main_menu;
            break;
        case 48:
            exit(0);
            break;
        default:

            cout<<"\n\n\t\tInvalid choice. Please try again.";

        }

    }

    return 0;
}
void sys :: create_ac()
{
    srand(time(0));
    ac_no= pow(rand(),2);
    ac_no+=ac_no;
    cout<<   "\n\n\t\tEnter your name          :: ";
    cin>>name;
    cout<< "\n\t\tEnter your Father's name :: ";
    cin>>f_name;
    cout<< "\n\t\tEnter your Date of Birth :: ";
    cin>>dob;
    cout<< "\n\t\tEnter your Phone Number  :: ";
    cin>>phone_num;
    cout<< "\n\t\tEnter your Email Account :: ";
    cin>>email;
    cout<<"\n\t\tEnter Your amount         :: ";
    cin>>amount;

    cout<<"\n\t\tYour account is being created";
    Sleep(1000);
    int count=0;
    for(int i=1; i<=5; i++)
    {
        cout<<".";
        Sleep(300);
    }

    //fstream file; //ac_no,name,dob,f_name,phone_num,email,pass...
    file.open("data.txt",ios::out|ios::app);
    file<<ac_no<<"\t"<<name<<"\t"<<dob<<"\t"<<f_name<<"\t"<<phone_num<<"\t"<<email<<"\t"<<"\t"<<amount<<"\n";
    file.close();
    clr;
    cout<< "\n\n\t\tYour account has been created. \n\n\t\tYour Account No :: "<<ac_no<<"\n\n\t\tThank you for having us.\n\n\n\n";

}

void sys :: ac_info()
{

    //fstream file;
    file.open("data.txt",ios::in);
    if(!file)
    {
        cout<<"File Error!";
    }
    else
    {
        clr;
        cout<< "\n\n\t\tEnter Account   :: ";
        //cout<< "\t\t                  :: ";
        int check_ac_no;
        cin>>check_ac_no;

        while(!file.eof())
        {
            if(check_ac_no==ac_no)
            {
                cout<< "\n\n\t\tName            :: "<<name;
                cout<< "\n\t\tFather's name   :: "<<f_name;
                cout<< "\n\t\tDate of Birth   :: "<<dob;
                cout<< "\n\t\tPhone Number    :: "<<phone_num;
                cout<< "\n\t\tEmail Account   :: "<<email;
                cout<< "\n\t\tAccount Balance :: "<<amount;
                cout<<"\n\n\n\n";
                exit(0);
            }
            file>>ac_no>>name>>dob>>f_name>>phone_num>>email>>amount;
        }
        cout<<"Account Not found!"<<endl;
    }
    file.close();
}
void sys :: dep()
{
    clr;
    cout<< "\n\n\t\tEnter Account      :: ";
    int check_ac_no;
    cin>>check_ac_no;
    cout<< "\t\tEnter Amount       :: ";
    float dep_amount;
    cin>> dep_amount;
    cout<<"\n\n\t\tProcesseing";
    for(int i=1; i<=5; i++)
    {
        cout<<".";
        Sleep(300);
    }

    clr;
    //fstream file, file1;
    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    if(!file)
    {
        cout<<"File Error!";
    }
    else
    {

        //cin>>dep_amount;
        file>>ac_no>>name>>dob>>f_name>>phone_num>>email>>amount;
        while(!file.eof())
        {

            if(check_ac_no==ac_no)
            {
                amount+=dep_amount;
                file1<<ac_no<<"\t"<<name<<"\t"<<dob<<"\t"<<f_name<<"\t"<<phone_num<<"\t"<<email<<"\t"<<"\t"<<amount<<"\n";
                cout<<"\n\n\t\tYour amount was    :: "<<amount-dep_amount<<"\n";

                cout<<"\n\t\tYour new amount is :: "<<amount<<"\n\n\n\n";

            }
            else
            {
                file1<<ac_no<<"\t"<<name<<"\t"<<dob<<"\t"<<f_name<<"\t"<<phone_num<<"\t"<<email<<"\t"<<"\t"<<amount<<"\n";
            }

            file>>ac_no>>name>>dob>>f_name>>phone_num>>email>>amount;

        }
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
}
void sys :: withdraw()
{
    clr;
    cout<< "\n\n\t\tEnter Account      :: ";
    int check_ac_no;
    cin>>check_ac_no;
    cout<< "\t\tEnter Amount       :: ";
    float withdraw;
    cin>>withdraw;
    cout<<"\n\n\t\tProcesseing";
    for(int i=1; i<=5; i++)
    {
        cout<<".";
        Sleep(300);
    }

    clr;
    //fstream file, file1;
    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    if(!file)
    {
        cout<<"File Error!";
    }
    else
    {

        file>>ac_no>>name>>dob>>f_name>>phone_num>>email>>amount;
        while(!file.eof())
        {

            if(check_ac_no==ac_no)
            {
                amount-=withdraw;
                file1<<ac_no<<"\t"<<name<<"\t"<<dob<<"\t"<<f_name<<"\t"<<phone_num<<"\t"<<email<<"\t"<<"\t"<<amount<<"\n";
                cout<<"\n\n\t\tYour amount was    :: "<<amount+withdraw<<"\n";

                cout<<"\n\t\tYour new amount is :: "<<amount<<"\n\n\n\n";

            }
            else
            {
                file1<<ac_no<<"\t"<<name<<"\t"<<dob<<"\t"<<f_name<<"\t"<<phone_num<<"\t"<<email<<"\t"<<"\t"<<amount<<"\n";
            }

            file>>ac_no>>name>>dob>>f_name>>phone_num>>email>>amount;

        }
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
}

