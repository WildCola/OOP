#ifndef MENU_H
#define MENU_H

#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<iostream>

char gotoXY(int x, int y);
void startmenu();
void login(char name[]);
void badlogin();
void goodlogin(char name[]);
void userlog();

char gotoXY(int x, int y) //functie adaptata dupa cea gasita la: http://www.cplusplus.com/forum/general/56892/
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

void startmenu()
{
    system("cls");
    char btl = 201, btr = 187, bbl = 200, bbr = 188, bhl = 205, bvl = 186, li = 204, ri = 185, sep = 178;
    cout<<"  ";
    for(int i=0; i<strlen("Welcome to our movie rental service")+2; ++i)
        cout<<sep;
    cout<<"\n"<<sep<<sep<<btl;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<btr<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"Welcome to our movie rental service"<<bvl<<sep<<sep<<"\n"<<sep<<sep<<li;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<ri<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"1. User Log In                     "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<li;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<ri<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"2. Create New Account              "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<li;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<ri<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"3. Admin Log In                    "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<li;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<ri<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"4. Exit Program                    "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<bbl;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<bbr<<sep<<sep<<"\n  ";
    for(int i=0; i<strlen("Welcome to our movie rental service")+2; ++i)
        cout<<sep;
    cout<<" \n"<<sep<<sep<<btl;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<btr<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"Choose any option to continue:     "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<bbl;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<bbr<<sep<<sep<<"\n  ";
    for(int i=0; i<strlen("Welcome to our movie rental service")+2; ++i)
        cout<<sep;
}

void login(char name[])
{
    system("cls");
    char btl = 201, btr = 187, bbl = 200, bbr = 188, bhl = 205, bvl = 186, li = 204, ri = 185, sep = 178;
     cout<<"  ";
    for(int i=0; i<strlen("Welcome to our movie rental service")+2; ++i)
        cout<<sep;
    cout<<"\n"<<sep<<sep<<btl;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<btr<<sep<<sep<<"\n"<<sep<<sep<<bvl<<name<<" Log In";
    for(int i=0; i<strlen("Welcome to our movie rental service")-strlen(name)-strlen(" Log In"); ++i)
        cout<<" ";
    cout<<bvl<<sep<<sep<<"\n"<<sep<<sep<<li;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<ri<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"UserName:                          "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<li;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<ri<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"Password:                          "<<bvl<<sep<<sep<<"\n"<<sep<<sep<<bbl;
    for(int i=0; i<strlen("Welcome to our movie rental service"); ++i)
        cout<<bhl;
    cout<<bbr<<sep<<sep<<"\n  ";
    for(int i=0; i<strlen("Welcome to our movie rental service")+2; ++i)
        cout<<sep;
}

void badlogin()
{
    system("cls");
    char btl = 201, btr = 187, bbl = 200, bbr = 188, bhl = 205, bvl = 186, li = 204, ri = 185, sep = 178;
     cout<<"  ";
    for(int i=0; i<strlen("Wrong username or password. Press any key to go back to the log in screen")+2; ++i)
        cout<<sep;
    cout<<"\n"<<sep<<sep<<btl;
    for(int i=0; i<strlen("Wrong username or password. Press any key to go back to the log in screen"); ++i)
        cout<<bhl;
    cout<<btr<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"Wrong username or password. Press any key to go back to the log in screen"<<bvl<<sep<<sep<<"\n"<<sep<<sep<<bbl;
    for(int i=0; i<strlen("Wrong username or password. Press any key to go back to the log in screen"); ++i)
        cout<<bhl;
    cout<<bbr<<sep<<sep<<"\n  ";
    for(int i=0; i<strlen("Wrong username or password. Press any key to go back to the log in screen")+2; ++i)
        cout<<sep;
    cout<<"\n";
}

void goodlogin(char name[])
{
    system("cls");
    char btl = 201, btr = 187, bbl = 200, bbr = 188, bhl = 205, bvl = 186, li = 204, ri = 185, sep = 178;
     cout<<"  ";
    for(int i=0; i<strlen("Welcome ") + strlen(name) +2; ++i)
        cout<<sep;
    cout<<"\n"<<sep<<sep<<btl;
    for(int i=0; i<strlen("Welcome ") + strlen(name); ++i)
        cout<<bhl;
    cout<<btr<<sep<<sep<<"\n"<<sep<<sep<<bvl<<"Welcome "<<name<<bvl<<sep<<sep<<"\n"<<sep<<sep<<bbl;
    for(int i=0; i<strlen("Welcome ") + strlen(name); ++i)
        cout<<bhl;
    cout<<bbr<<sep<<sep<<"\n  ";
    for(int i=0; i<strlen("Welcome ") + strlen(name)+2; ++i)
        cout<<sep;
    cout<<"\n";
}


#endif // MENU



