#include <iostream>
#include <cstdlib>
#include<windows.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#define MAX 40
class user
{
    public:
    int id;
    float balance;

    user(){}
    void display()
    {
        cout<<id<<" has "<<balance<<" balance "<<endl;
    }
    void input(int i,float b)
    {
        id=i;
        balance=b;
    }
    int getid()
    {
        return id;
    }
    int getbal()
    {
        return balance;
    }
    void change(float bal)
    {
        balance=balance-bal;
    }
    void change1(float bal)
    {
        balance=balance+bal;
    }

};

enum Color { DBLUE=1,GREEN,GREY,DRED,DPURP,BROWN,LGREY,DGREY,BLUE,LIMEG,TEAL,
    RED,PURPLE,YELLOW,WHITE,B_B };

bool quit;

void col(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

istream &operator>> ( istream &in, Color &c )
{
    int tint;
    cin >> tint;
    if (tint==-1) quit=true;
    c=(Color)tint;
}


struct node {
string p;
int color;};

class AdjacencyMatrix
{
    private:
        int n;
        int **adj;
        bool **visited;
        int dis;
    public:
        AdjacencyMatrix(int n)
        {
            dis=0;
            this->n = n;
            visited = new bool* [n];
            for(int i=0;i<n;i++)
                visited[i]= new bool[n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }

        void add_edge(int origin, int destin,int w)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin][destin]=w;
                adj[destin][origin]=w;
                 }
        }

        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
        int rr(int so,int des){
        return adj[so][des];}
        int isReachable(int s, int d, node sa[]);
        int price( );
        int print(int *,int s ,int d,node []);
        int d(){return dis;};
};
int AdjacencyMatrix::price(){

return dis*2;
}

int  AdjacencyMatrix::isReachable(int s, int d, node sa[])
{
int *parent;
parent = new int [n];
            for (int i = 0; i < n; i++)
            {
                    parent[i] = -1;
            }


     for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
          visited[i][j] = false;
          }}
queue<int> q;
visited[s][0]=true;
visited[0][s]=true;
q.push(s);
int i;
while(!q.empty())
{
    s=q.front();
    if(s==d){
         return print(parent,s,d,sa);

    }
    q.pop();
    for(i=0;i<n;++i)
{

if (!visited[s][i])
            {
                visited[s][i] = true;
                visited[i][s] = true;
                if(adj[s][i]!=0){
                    q.push(i);
                    parent[i]=s;
                }
            }}}
            return 0;
}
int AdjacencyMatrix::print(int* parent,int s,int d,node sa[]){
    system("color 34");
   static int level = 0;
    int i=0;
    Color x;
    if (parent[s] == -1)
    {
cout << "Shortest route between " << sa[s].p << " and "
             << sa[d].p << " is "  ;
        x=(Color)sa[s].color;
        col(x);
        cout<< sa[s].p << " ";
        return level;
    }

    print(parent, parent[s], d,sa);
    level++;
    dis=dis+adj[parent[s]][s];
    if (s < n)
    {
        x=(Color)sa[s].color;
        col(x);
        cout << "-> " << sa[s].p ;
    }
    return level ;
}

void add(node s[],string place,int color, int a)
{
    s[a].p=place;
    s[a].color=color;
}


int  search(node s[],string sa,int n){
for(int i=0;i<n;i++){
    if(s[i].p==sa)
        return i;
}
                    }

void dispsta(node s[],int a){
for(int i=0;i<a;i++)
    {
        Color x;

    if(i>=0 && i<=10)
    x=(Color)27;
else if (i>=11 && i<=21)
    x=(Color)95;
else if (i>=22 && i<=26)
    x=(Color)160;
    else if (i>=27 && i<=36)
    x=(Color)224;
     col(x);
    cout<<s[i].p<<"\n";
}
}

bool checks(string d,node s[]){
for(int i=0;i<37;i++){
    if(s[i].p==d)
        return true;
}
return false;
}

void intro()
{
    cout<<"A project on Metro Management System By: \n"<<endl;
    cout<<"Ishita Kalsi"<<endl;
}

int main()
{
    intro();
    cout<<"\n\n\n\n\n\n Press enter to continue with our services.";
    getch();
    system("cls");

    A:
    system("color 11");
    int nodes, max_edges, origin, destin ,i,id;
    user u[10];
    fstream file;

    /*Commented because data written in the file one time. Now it will append only.
    u[0].input(1,100);
    u[1].input(2,256);
    u[2].input(3,564);
    u[3].input(4,320);
    u[4].input(5,232.2);
    u[5].input(6,23.5);
    u[6].input(7,349);
    u[7].input(8,136.8);
    u[8].input(9,57);
    u[9].input(10,389);

    file.open("file.txt", ios :: out);
    for (i = 0; i < 10; i++)
    {
        file.write((char *)&u[i], sizeof(u[i]));
    }
    file.close();

    */

    cout<<"Enter your Card Id : ";
    cin>>id;

    file.open("file.txt", ios :: in);
    i=0;
    bool flag=false;
    while (i!=10) {
       file.read((char *)&u[i], sizeof(u[i]));
       if(id==u[i].getid())
       {
           flag=true;
           cout<<"Ur balance is : Rs. "<<u[i].getbal()<<endl;
           break;
       }
      i++;
    }
    file.close();

    if(!flag)
    {
        cout<<"Id not found";
        exit(0);
    }
    else
    {
        getch();
        system("cls");
    //output current balance of card
    int nodes, max_edges, origin, destin;
    string source,destination;
    nodes=37;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    node s[nodes];

add(s,"noida",9,0);
add(s,"mayur vihar",9,1);
add(s,"akshardham",9,2);
add(s,"yamuna bank",9,3);
add(s,"pragati maidan",9,4);
add(s,"mandi house",9,5);
add(s,"bharakhamba",9,6);
add(s,"rajiv chowk",9,7);
add(s,"karol bagh",9,8);
add(s,"rajouri garden",9,9);
add(s,"dwarka",9,10);
add(s,"kashmere gate",13,11);
add(s,"lal quila",13,12);
add(s,"jama masjid",13,13);
add(s,"delhi gate",13,14);
add(s,"ito",13,15);
add(s,"janpath",13,16);
add(s,"lajpat",13,17);
add(s,"moolchand",13,18);
add(s,"kailash colony",13,19);
add(s,"nehru place",13,20);
add(s,"escorts mujesar",13,21);
add(s,"inderlok",10,22);
add(s,"punjabi bagh",10,23);
add(s,"madipur",10,24);
add(s,"udhyog nagar",10,25);
add(s,"mundka",10,26);
add(s,"samaypur badli",14,27);
add(s,"rohini",14,28);
add(s,"model town",14,29);
add(s,"new delhi",14,30);
add(s,"civil lines",14,31);
add(s,"chandni chowk",14,32);
add(s,"ina",14,33);
add(s,"aiims",14,34);
add(s,"hauz khas",14,35);
add(s,"huda city center",14,36);
am.add_edge(0,1,2);
am.add_edge(1,2,4);
am.add_edge(2,3,2);
am.add_edge(3,4,3);
am.add_edge(4,5,3);
am.add_edge(5,6,2);
am.add_edge(6,7,5);
am.add_edge(7,8,5);
am.add_edge(8,9,2);
am.add_edge(9,10,2);
am.add_edge(11,12,2);
am.add_edge(12,13,2);
am.add_edge(13,14,2);
am.add_edge(14,15,2);
am.add_edge(15,5,2);
am.add_edge(5,16,2);
am.add_edge(16,17,2);
am.add_edge(17,18,2);
am.add_edge(18,19,2);
am.add_edge(19,20,2);
am.add_edge(20,21,2);
am.add_edge(22,8,3);
am.add_edge(22,23,2);
am.add_edge(23,24,2);
am.add_edge(24,25,2);
am.add_edge(25,26,2);
am.add_edge(27,28,2);
am.add_edge(28,29,2);
am.add_edge(29,9,2);
am.add_edge(9,30,2);
am.add_edge(30,31,2);
am.add_edge(31,32,2);
am.add_edge(32,33,2);
am.add_edge(33,34,2);
am.add_edge(34,35,2);
am.add_edge(35,36,2);

int money;
    cout<<"CHOOSE 1 IF YOU WANT TO TRAVEL \n  CHOOSE 0 IF YOU WANT TO RECHARGE \n ";
    cin>>max_edges;
    system("cls");
    if(max_edges==1)
        {
            system("color 7");
            dispsta(s,nodes);
            col(7);

    getline(cin,source);

    while(1)
    {
        bool b=checks(source,s);
        if(b)
            break;
        else{
            cout<<endl<<"ENTER NEW SOURCE:\n";
            getline(cin,source);
        }
    }
    cout<<"\n"<<"ENTER DESTINATION:\n";
    getline(cin,destination);
    while(1)
    {
        bool b=checks(destination,s);
        if(b)
            break;
        else{
            cout<<"ENTER NEW DESTINATION:";
            getline(cin,destination);
        }
    }
    system("cls");

    origin=search(s,source,nodes);
    destin=search(s,destination,nodes);
    int x=am.isReachable(origin,destin,s);
    col(7);

    cout << "\n\n\n\n\n\nShortest Distance between " << source
         << " and " << destination << " is " <<am.d()<<" km.";


cout<<"\n\n\n\nprice is : rs "<<am.price()<<"\n";

        }

    else if(max_edges==0)
        {
            system("color 47");
            cout<<"ENTER AMOUNT YOU WANT TO ADD \n";
            cin>>money;

        file.open("file.txt", ios :: app);
        i=0;
        while (i!=10)
        {
            file.read((char *)&u[i], sizeof(u[i]));
            if(id==u[i].getid())
        {
           u[i].change1(money);
           file.write((char *)&u[i], sizeof(u[i]));
           cout<<"Ur balance now is : Rs. "<<u[i].getbal()<<endl;
           break;
       }
      i++;
        }

    file.close();


        cout<<"DO YOU WANT TO TRAVEL NOW ENTER 1 TO TRAVEL \n";
        cin>>max_edges;
        system("cls");
        if(max_edges==1)
       {
           system("color 7");
           dispsta(s,nodes);
       col(7);
    getline(cin,source);

    while(1)
    {
        bool b=checks(source,s);
        if(b)
            break;
        else{
            cout<<endl<<"ENTER NEW SOURCE:\n";
            getline(cin,source);
        }
    }
    cout<<"\n"<<"ENTER DESTINATION:\n";
    getline(cin,destination);
    while(1)
    {
        bool b=checks(destination,s);
        if(b)
            break;
        else{
            cout<<"ENTER NEW DESTINATION:";
            getline(cin,destination);
        }
    }
    system("cls");

    origin=search(s,source,nodes);
    destin=search(s,destination,nodes);
    int x=am.isReachable(origin,destin,s);
    col(7);

    cout << "\n\n\n\n\n\n\n\n\n\n Shortest Distance between " << source
         << " and " << destination << " is " <<am.d()<<" km.";


cout<<"\n\n\n\nprice is : rs "<<am.price()<<"\n";
       }
}
cout<<endl;

    file.open("file.txt", ios :: app);
    i=0;
    while (i!=10) {
       file.read((char *)&u[i], sizeof(u[i]));
       if(id==u[i].getid())
       {
           u[i].change(am.price());
           file.write((char *)&u[i], sizeof(u[i]));
           cout<<"Ur balance now is : Rs. "<<u[i].getbal()<<endl;
           break;

       }
      i++;
    }

    file.close();
}

int c;
cout<<"\n"<<"enter 1 to continue and 0 to stop"<<"\n";
cin>>c;
if(c==1)
goto A;

return 0;
}
