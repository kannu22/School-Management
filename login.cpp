#include<iostream>
#include<conio.h>
using namespace std;
#include <fstream>
#include<string.h>
struct A1
{
    char id[20],password[20];
   
};
struct B1
{
    char code[20],name[20],salry[20],lab[20];
    
};
struct S1
{
    char name[20],phone[20];
    int roll,marks;
};
struct T1
{
    char code[20],lab[20];
    double salary;
};
//*****************************************
void login(int);
void createID(int);
void loginID(int);
void mainmenu();
void activity(int);
void find(int);
void edit(int);
void insert(int);
void del(int);
void show();
void display();
//****************************************
void mainmenu()
{
int a;
cout<<"1. Admin \n";
cout<<"2. Teacher \n";
cout<<"3. Students \n";
cout<<"4. Exit \n";
cout<<"Enter Choice(1-4) :";
cin>>a;
if(a==1)
 login(a);   
else if(a==2)
 login(a);   
else if(a==3)
 login(a);   
}

//******************************************
void login(int x)
{
int a;
cout<<"1. Login \n";
cout<<"2. Create \n";
cout<<"3. Exit \n";
cout<<"Enter Choice(1-3) :";
cin>>a;
if (a==2)
{
    createID(x);
}
else if (a==1)
{
    loginID(x);
}
}
//************************************************************
void createID(int y)
{
    fstream fin;
    if(y==1)
    fin.open("adminpass.dat", ios::in|ios::out);
    else if(y==2)
    fin.open("tecpass.dat", ios::in|ios::out);
    else if(y==3)
    fin.open("stupass.dat", ios::in|ios::out);

    if(!fin)
    {
        cout<<"error";
        exit(0);
    }
    A1 x;
    fin.seekg(0,ios::beg);
    cin.ignore();
    cout<<"Id:";
    cin.getline(x.id,50);
    cout<<"Password:";
    cin.ignore();
    cin.getline(x.password,50);
    fin.write((char*)&x,sizeof(A1));
    cout<<"ID Successfully Created : Please Login\n";
    fin.close();
    login(y);
} 

void loginID(int y)
{
int x;
ifstream fin;
    if(y==1)
    fin.open("adminpass.dat", ios::in);
    else if(y==2)
    fin.open("tecpass.dat", ios::in);
    else if(y==3)
    fin.open("stupass.dat", ios::in);

if(!fin)
{
    cout<<"error";
    exit(0);
}
char a[50],b[50];
cin.ignore();
cout<<"id: ";cin.getline(a,50);
cout<<"Pass : ";
cin.ignore();cin.getline(b,50);
A1 t;
fin.seekg(0,ios::beg);
int found=0;
while(fin.read((char*)&t,sizeof(A1)))
{
    if(strcmp(a,t.id)==0&&strcmp(b,t.password)==0)
    {
        found=1;
        break;
    }
}
if(found==0)
{
    cout<<"ID or Password Not Match............Login Again\n";
    getch();
    login(y);
}
else
{
    cout<<"found \n";
    cout<<"1. Teacher \n";
    cout<<"2. Students \n";
    int k;
    cin>>k;
    activity(k);
}
fin.close();
}

void activity(int t)
{
    int y;
    cout<<"1. Find \n";
    cout<<"2. Edit \n";
    cout<<"3. Insert \n";
    cout<<"4. Delete \n";
    cout<<"Enter Choice: ";
    cin>>y;
    if(y==1)
    {
        find(t);
    }
    else if(y==2)
    {
        edit(t);
    }
    else if(y==3)
    {
        insert(t);
    }
    else if(y==4)
    {
        del(t);
    }
}   

void find(int a)
{
    fstream fin;
    int x=0,r;
    char c[50];
    S1 C;
    T1 D;
    if(a==2)
    {
        cout<<"enter roll:";
        cin>>r;
        fin.open("student.dat",ios::in);
        while(fin.read((char*)&C,sizeof(S1)))
        {
            if(C.roll==r)
            {
                x=1;
                cout<<"roll:"<<C.roll;
                cout<<" name:"<<C.name;
                cout<<" marks:"<<C.marks;
                cout<<" phone:"<<C.phone;
                break;
            }
        }
        if(x==0)
        {
            cout<<"Not Found";
        }
    }
    else if(a==1)
    {
        cin.ignore();
        cout<<"enter code:";
        cin.getline(c,50);
        fin.open("teacher.dat",ios::in);
        while(fin.read((char*)&D,sizeof(T1)))
        {
            if(strcmp(D.code,c)==0)
            {
                x=1;
                cout<<"code:"<<D.code;
                cout<<"lab:"<<D.lab;
                cout<<"salary:"<<D.salary;
                break;
            }
        }
        if(x==0)
        {
            cout<<"Not found";
        }
    }
    fin.close();
}

void edit(int a)
{
    fstream fin;
    int x=0,r;
    char c[20];
    S1 C;
    T1 D;
    if(a==2)
    {
        cout<<"enter roll:";
        cin>>r;
        cin.ignore();
        fin.open("student.dat",ios::in|ios::out);
        while(fin.read((char*)&C,sizeof(S1)))
        {
            if(C.roll==r)
            {
                x=1;
                fin.seekp(-1*sizeof(S1),ios::cur);
                cin.getline(C.name,20);
                cin.ignore();
                cin>>C.marks;
                cin>>C.phone;
                fin.write((char*)&C,sizeof(S1));
                cout<<"roll:"<<C.roll;
                cout<<"name:"<<C.name;
                cout<<"marks:"<<C.marks;
                cout<<"phone:"<<C.phone;
                break;
            }
        }
        if(x==0)
        {
            cout<<"Not Found";
        }
    }
    else if(a==1)
    {
        cin.ignore();
        cout<<"enter code:";
        cin.getline(c,20);
        //cin.ignore();
        fin.open("teacher.dat",ios::in|ios::out);
        while(fin.read((char*)&D,sizeof(T1)))
        {
                
            if(strcmp(D.code,c)==0)
            {
                x=1;
                fin.seekp(-1*sizeof(T1),ios::cur);
                cin.getline(D.lab,50);
                //cin.ignore();
                cin>>D.salary;
                cout<<"code:"<<D.code;
                cout<<"lab:"<<D.lab;
                cout<<"salary:"<<D.salary<<endl;
                fin.write((char*)&D,sizeof(T1));

            }
        }
        if(x==0)
        {
            cout<<"Not found";
        }
    }
    fin.close();
}

void insert(int a)
{
    fstream fin;
    S1 C;
    T1 D;
    if(a==2)
    {
        fin.open("student.dat",ios::in|ios::out);
        fin.seekp(0,ios::end);
        cout<<"name ";
        cin.ignore();
        cin.getline(C.name,20);
        cout<<"roll ";cin>>C.roll;
        cin.ignore();
        cout<<"phone ";
        cin.getline(C.phone,20);
        cout<<"marks ";cin>>C.marks;
        fin.write((char*) &C,sizeof(S1));
        fin.close();
        show();
    }
    else if(a==1)
    {
        fin.open("teacher.dat",ios::in|ios::out);
        fin.seekp(0,ios::end);
        cin.ignore();
        cout<<"code ";
        cin.getline(D.code,20);
        //cin.ignore();
        cout<<"salary ";cin>>D.salary;
        cin.ignore();
        cout<<"lab ";
        cin.getline(D.lab,20);
        fin.write((char*)&D,sizeof(T1));
        fin.close();
        display();
    }
}
void del(int a)
{
    ifstream fin;
    ofstream fout;
    int x=0,r;
    char c[50];
    S1 C;
    T1 D;
    if(a==2)
    {
        cout<<"enter roll:";
        cin>>r;
        fin.open("student.dat",ios::in);
        fout.open("xyz.dat",ios::out);
        while(fin.read((char*)&C,sizeof(S1)))
        {
            if(C.roll!=r)
            {
                x=1;
                fout.write((char*)&C,sizeof(S1));
            }
        }
        if(x==0)
        {
            cout<<"Not Found";
        }
        fin.close();
        fout.close();

        remove("student.dat");
        rename("xyz.dat","student.dat");

        fin.open("student.dat",ios::in);
        while(fin.read((char*)&C,sizeof(S1)))
        {
            cout<<C.roll;
            cout<<C.name;
            cout<<C.marks;
            cout<<C.phone;
        }
        fin.close();
    }
    else if(a==1)
    {
        cin.ignore();
        cout<<"enter code:";
        cin.getline(c,50);
        //cin.ignore();
        fin.open("teacher.dat",ios::in);
        fout.open("xyz.dat",ios::out);
        while(fin.read((char*)&D,sizeof(T1)))
        {
            if(strcmp(D.code,c)!=0)
            {
                x=1;
                fout.write((char*)&D,sizeof(T1));
            }
        }
        if(x==0)
        {
            cout<<"Not found";
        }
        fin.close();
        fout.close();

        remove("teacher.dat");
        rename("xyz.dat","teacher.dat");
        
        fin.open("teacher.dat",ios::in);
        while(fin.read((char*)&D,sizeof(T1)))
        {
            cout<<D.code;
            cout<<D.lab;
            cout<<D.salary;
        }
        fin.close();
    }
}

void show()
{
    S1 C;
    ifstream fin;
    fin.open("student.dat",ios::in);
    while(fin.read((char*)&C,sizeof(S1)))
    {   
        cout<<C.roll<<"  "<<C.name<<"   "<<C.phone<<"   "<<C.marks<<endl;
    }
    fin.close();
}
void display()
{
    T1 D;
    ifstream fin;
    fin.open("teacher.dat",ios::in);
    while(fin.read((char*)&D,sizeof(T1)))
    {
        cout<<D.code<<" "<<D.lab<<" "<<D.salary<<endl;
    }
    fin.close();
}

main()
{
   mainmenu();
    return 0;
}