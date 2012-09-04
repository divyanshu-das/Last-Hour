#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

     int *p;
class LastHour
      {
              public:
                     
              int minOver;//minimum overs to be bowled
              int actOver;//actual overs to be bowled
              int TPO;//Time per Over
              float OB;//Overs Bowled
              int TL,TR;// Time lost
              int OTBT, OTBO;//Overs to be bowled time & over calculation
              int OL;// Overs Lost
              int ETOI;//End time of innings
              int SOSE;//Start of second innings
              int LHS, LHE;//Last hour times
              int hr,min;//To store hour and minute
              int h1,h2,m1,m2;//For time arithmetic
              int innings_calculation(int LHS, int LHE, int minOver, int TPO);
              int time_calculation(int LHS, int LHE, int minOver, int TPO);
              
      };

int LastHour::innings_calculation(int LHS, int LHE, int minOver, int TPO)
     {
         cout<<"Enter the no. of overs bowled after the last interruption: ";
         cin>>OB;
         cout<<"Enter the end time of innings: ";
         cin>>ETOI;
         cout<<"When do u want to start next innings? ";
         cin>>SOSE;        
         //Time calculation                
         h1=LHE/100;
         m1=LHE%100;
         h2=SOSE/100;
         m2=SOSE%100;
         if(m1>=m2)
         {
                   hr=h1-h2;
                   min=m1-m2;
         }
         else
         if(m1<m2)
         {
             hr=h1-h2-1;
             min=m1-m2+60;
         }
         
         TR = hr*100 + min;     
         //OL = int(TR / TPO);
         OTBT = int(TR/TPO);
         //Over calculation
         OB = floor(OB);
         OTBO = minOver - int (OB + int((SOSE-ETOI)/TPO));
         // Compare and print
          if(OTBO >= OTBT)
          {
                              cout<<"\nOvers left to be bowled: "<<OTBO<<"\n";
                              return OTBO;
          }
          else
          {
              cout<<"\nOvers left to be bowled: "<<OTBT;
              return OTBT;
          }

     }
int LastHour::time_calculation(int LHS, int LHE, int minOver, int TPO)
     {
         cout<<"Enter no of overs bowled after last interruption: ";
         cin>>OB; 
         cout<<"Enter the start time of interruption: ";
         cin>>ETOI;
         cout<<"When do u want to start the game? ";
         cin>>SOSE;        
         //Time calculation                
         
         h1=SOSE/100;
         m1=SOSE%100;
         h2=ETOI/100;
         m2=ETOI%100;
         if(m1>=m2)
         {
                   hr=h1-h2;
                   min=m1-m2;
         }
         else
         if(m1<m2)
         {
             hr=h1-h2-1;
             min=m1-m2+60;
         }
         TL = hr*100 + min;     
         cout<<TL<<endl;
         OL = int (TL / TPO);
         cout<<minOver<<endl;
         OTBT = minOver - int (OL+OB);
         cout<<"\nOver left to be bowled: "<<OTBT<<endl;
         return OTBT;
     }
     

int main()
{
    
    LastHour LH;
    int st,et,min,tpo,n,stm;
    char n1,ans;
    cout<<"\nEnter start time: ";
    cin>>st;
    cout<<"\nEnter End time: ";
    cin>>et;
    cout<<"\nEnter minimum overs to be bowled: ";
    cin>>min;
    p=&min;
    cout<<"\nEnter time required to bowl one over: ";
    cin>>tpo;
    cout<<"\n1.Match in play: ";
    cout<<"\n2.Match not in play: ";
    cout<<"\n3.No match in progree: \n";
    cout<<"\nEnter your choice: ";
    cin>>n;
    switch(n)
    {
label:             case 1:
                  cout<<"\nEnter the type of break: ";
                  cout<<"\na.Innings break: ";
                  cout<<"\nb.Interruption: ";
                  cout<<"\nc.No break:";
                  cin>>n1;
                  switch(n1)
                  {
                            case 'a':
                                 *p = LH.innings_calculation(st, et, min, tpo);
                                 cout<<"Is there another break in match?(y/n) :";
                                 cin>>ans;
                                 if(ans=='y' || ans=='Y')
                                 goto label;
                                 else if(ans=='n' || ans=='N')
                                 cout<<" Thank You ";
                                 system("PAUSE");
                                 exit(0);
                                 break;
                            case 'b':
                                 *p = LH.time_calculation(st, et, min, tpo);
                                 cout<<"Is there another break in match?(y/n) :";
                                 cin>>ans;
                                 if(ans=='y' || ans=='Y')
                                 goto label;
                                 else if(ans=='n' || ans=='N')
                                 cout<<" Thank You ";
                                 system("PAUSE");
                                 exit(0);
                                 break;
                            /*case 'c':
                                 exit(0);
                                 break;*/
                                 
                            }
                  case 2:
                       *p = LH.time_calculation(st, et, min, tpo);
                       cout<<"Is there another break in match?(y/n) :";
                       cin>>ans;
                       if(ans=='y' || ans=='Y')
                       goto label;
                       else if(ans=='n' || ans=='N')
                       cout<<" Thank You ";
                       system("PAUSE");
                       exit(0);
                       break;
                  /*case 3: 
                       exit(0);
                       break;*/
}                       
system("PAUSE");
return 0;
}
