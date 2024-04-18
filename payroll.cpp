#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class emplo 
{
    public : 
    string ename,pn,email;int eid;float exp,basic_salary,hra,da,gross_salary,sla,mia,dap,hrap,inc,winc,salary;
    void get()
    {
       cout<<"\n------------Employee Details-------------";
       cout<<"\nEnter Employee ID : ";cin>>eid;
       cout<<"\nEnter Employee Name : ";cin>>ename;
       cout<<"\nEnter Contact Number : ";cin>>pn;
       cout<<"\nEnter Email ID : ";cin>>email;
       cout<<"\nEnter Experience in years : ";cin>>exp;
       cout<<"\nEnter Basic Salary : ";cin>>basic_salary;
        cout<<"\nEnter Student Loan Amount(if Applicable) : ";cin>>sla;
        cout<<"\nEnter Medical Insurance Amount : ";cin>>mia;
                  if(basic_salary<=20000)
                 {
                    dap = 0.6;hrap = 0.8;
                 }
                 else if(basic_salary >20000 && basic_salary <50000)
                 {
                    dap=0.5;hrap=0.7;
                 }
                 else 
                 {
                    dap =0.5;hrap=0.65;
                 }
                 cout<<"\nEnter DA : ";cin>>da;
                 cout<<"\nEnter HRA : ";cin>>hra;
                 gross_salary = basic_salary+(hra*hrap)+(da*dap);
                 salary = (gross_salary)-(0.02*sla)-(0.02*mia);   
                 if(exp==3||exp==4||exp==5)
                 {
                  inc = 7000;
                 }
                 else if(exp==1||exp==2)
                 {
                  inc = 4000;
                 }
                 else 
                 {
                   inc = 12000;
                 }
    }
    void display()
    {
          cout<<"\n----------Employee Details-----------";
          cout<<"\nEmployee ID : "<<eid;
          cout<<"\nName : "<<ename;
          cout<<"\nContact Number : "<<pn;
          cout<<"\nEmail ID : "<<email;
          cout<<"\nExperience : "<<exp<<" years";
          cout<<"\nBasic Salary : "<<basic_salary;
          cout<<"\nStudent Loan Amount : "<<sla;
          cout<<"\nMediacal Insurance Amount : "<<mia;
          cout<<"\nDA : "<<da;
          cout<<"\nHRA : "<<hra;
          cout<<"\nGross Salary : "<<gross_salary;
          cout<<"\nTake Home Salary : "<<salary;
          cout<<"\nIncrement Amount Per Year : "<<inc;
          cout<<"\n--------------------------------------";

    }
};
emplo a;
void write()
{
    ofstream fout;
    fout.open("Employee.dat",ios::app|ios::binary);
    a.get();
    fout.write((char*)&a,sizeof(a));
    fout.close();
    cout<<"\nData Added Successfully...";
}
void read()
{
    ifstream fin;
    fin.open("Employee.dat",ios::in|ios::binary);
    while(fin.read((char*)&a,sizeof(a)))
    {
        a.display();
    }
    fin.close();
}
void search()
{
    fstream fin;
    int acc,flag=0;
    fin.open("Employee.dat",ios::in|ios::binary);
    cout<<"\nEnter the Employee ID  : ";
    cin>>acc;
    while(fin.read((char*)&a,sizeof(a)))
    {
        if(a.eid==acc)
        {
            flag=1;
            cout<<"\nRecord Found";
            a.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    fin.close();
}
void update()
{
    int ac,amt,fl=0,incre;float bs,DA,HRA,experience,dap,hrap,gs,sal,sla,mia;char ans;
    fstream f;
    f.open("Employee.dat",ios::out|ios::in|ios::binary);
    cout<<"\nEnter the Employee Number : ";
    cin>>ac;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.eid==ac)
        {
            fl=1;
            cout<<"\nRecord Found";
            cout<<"\nEnter Updated Basic Salary : ";cin>>bs;
            cout<<"\nEnter Updated DA : ";cin>>DA;
            cout<<"\nEnter Updated HRA : ";cin>>HRA;
            cout<<"\nEnter Updated Experience : ";cin>>experience;
            float t=f.tellp();
            a.basic_salary=bs;
            a.da=DA;
            a.hra=HRA;
            a.exp=experience;
             if(bs<=20000)
                 {
                    dap = 0.6;hrap = 0.8;
                 }
                 else if(bs >20000 && bs <50000)
                 {
                    dap=0.5;hrap=0.7;
                 }
                 else 
                 {
                    dap =0.5;hrap=0.65;
                 }
                 gs = bs+(HRA*hrap)+(DA*dap);
                 sal = (gs)-(0.02*sla)-(0.02*mia);   
                 if(experience==3||experience==4||experience==5)
                 {
                  incre = 7000;
                 }
                 else if(experience==1||experience==2)
                 {
                  incre = 4000;
                 }
                 else 
                 {
                   incre = 12000;
                 }
                 a.gross_salary=gs;
                 a.salary=sal;
                 a.inc=incre;
            f.seekp(t-sizeof(a));
            f.write((char*)&a,sizeof(a));
            cout<<"\nData Updated Successfully.....";
            break;
        }
    }
    if(fl==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
void delete_specific()
{
    int ac,fl=0;
    fstream f;
    f.open("Employee.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("new.dat",ios::app|ios::binary);
    cout<<"\nEnter Employee ID : ";
    cin>>ac;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.eid!=ac)
        {

            fout.write((char*)&a,sizeof(a));
        }
        else{
            fl=1;
        }
    }
    f.close();
    fout.close();
    remove("Employee.dat");
    rename("new.dat","employee.dat");
    cout<<"\nSuccessful";

}
int main()
{
    int pass;string user,k="admin_here";
    cout<<"\n\t-----Payroll System-----";
     while(1)
     {
     cout<<"\nEnter User Name : ";cin>>user;
     cout<<"\nEnter Password : ";cin>>pass;
     if( user==k && pass==152209)
     {
     cout<<"\nWelcome admin_here";break;
     }
     else
     {
     cout<<"\nPlease Enter VALID User Name or Password";
     }
     }
    int ch;
    remove("Employee.dat");
    while(1)
    {
        cout<<"\n\nEnter\n1.Add Employee Details\n2.Display All Details\n3.Search specific Employee Details\n4.Update Specific Employee Details\n5.Delete Specific Employee Details\n6.EXIT";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:write();break;
            case 2:read();break;
            case 3:search();break;
            case 4:update();break;
            case 5:delete_specific();break;     
            case 6:exit(0);
            default:cout<<"\nInvalid Choice";
        }
    }
}
