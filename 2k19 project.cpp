#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10], age[2], type[10],date[10];

public:

  void businstall();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::businstall()

{

  cout<<"Enter the bus service number : ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t";

  cin>>bus[p].to;
  
  cout << "\nChoose which type of luxuary seat you need to travel : ";
  
  cin >> bus[p].type;
  
  cout << "\nConform on which date you will travel : ";
  
  cin >> bus[p].date;
  
  bus[p].empty();

  p++;

}

void a::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"Enter any Installed Bus number: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat number is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus number \n";

      goto top;

    }
    cout << "\n Enter your age : " << endl;
    cin >> bus[p].age;

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"Enter bus number : ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus number : \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\tTo: \t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat number "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus number : ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "NOT INSTALLED")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  
  }

void a::avail()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Bus number : \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}

int main()

{

system("cls");

int w;

while(1)

{

    //system("cls");
    cout << "\n\n";
    cout << "\t\t\t WELCOME TO BUS RESERVATION ";

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.BusInstall\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.E-Tiicket\n\t\t\t"

  <<"4.Buses Available. \n\t\t\t"

  <<"5.Exit";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {

    case 1:  bus[p].businstall();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();
    		
             cout << "\n\nFor further Information please contact to emergency number : 7013915601 :";
    		
			cout << "\n\t\t H A P P Y J O U R N E Y \n\n " << "\t\t H A V E  A   N I C E  D A Y ...";
      break;

    case 4:  bus[0].avail();

      break;

    case 5:  exit(0);

  }

}
 cout << "\n For any official information you can login to our site ...... ";

return 0;

}
