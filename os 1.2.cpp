#include<bits/stdc++.h>
using namespace std;
class fcfs_alg
{
    int ar[10],exe[10],id[10];
    char d[10];
    int n,x,y;
    void sort(int *,int *,int *);
public:
    void getdata();
    void display();
    void chart(int,int);
    void int_to_ch(int);
    void cal_wt_tt();
};
void fcfs_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
 cout<<"Enter execution time and arrival time of process "<<i+1<<" : ";
 cin>>exe[i]>>ar[i];
 id[i]=i+1;
    }
}
void fcfs_alg::int_to_ch(int temp)
{
   int i;
   if(temp==0)
   {
      d[0]=48;
      d[1]=0;
      return;
   }
   for(i=0;temp!=0;i++)
    {
 d[i]=temp%10+48;
 temp/=10;
    }
    d[i]=0;
    strrev(d);
}
void fcfs_alg::chart(int id,int t)
{
    rectangle(x,y,x+30,y+30);
    if(id!=-1)
    {
       int_to_ch(id);
       outtextxy(x+12,y+12,d);
    }
    int_to_ch(t);
    if(t>10)
       outtextxy(x+24,y+33,d);
    else
       outtextxy(x+30,y+33,d);
    x+=30;
    if(x+60>getmaxx())
    {
       y+=50;
       x=5;
       outtextxy(x,y+33,d);
    }
}
void fcfs_alg::display()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    outtextxy(5,56,"Process ID    Execution time   Arrival Time ");
    x=5,y=66;
    for(int i=0;i<n;i++,y+=16)
    {
 int_to_ch(i+1);
 outtextxy(35,y,d);
 int_to_ch(exe[i]);
 outtextxy(150,y,d);
 int_to_ch(ar[i]);
 outtextxy(270,y,d);
    }
}
void fcfs_alg::sort(int *f,int *m,int *l)
{
    int temp;
    for(int y=0;y<n-1;y++)
    {
 for(int z=0;z<n-1;z++)
     if(f[z]>f[z+1])
     {
  temp=f[z];
  f[z]=f[z+1];
  f[z+1]=temp;
  temp=l[z];
  l[z]=l[z+1];
  l[z+1]=temp;
  temp=m[z];
  m[z]=m[z+1];
  m[z+1]=temp;
     }
    }
}
void fcfs_alg::cal_wt_tt()
{
    int wt,tnt,temp,z=y+10;
    float avg=0,avtnt=0;
    sort(ar,exe,id);
    temp=ar[0];
    y+=(n+2)*16;
    outtextxy(x,y+10,"GANTT CHART");
    y=y+26;
    int_to_ch(temp);
    outtextxy(x,y+33,d);
    outtextxy(x,z,"Process id    Waiting time    Turn around time ");
    z=z+16;
    for(int i=0;i<n;i++,z+=16)
    {
 if(ar[i]>temp)
 {
     wt=0;
     temp=ar[i];
     chart(-1,temp);
 }
 else
     wt=temp-ar[i];
 avg+=wt;
 temp+=exe[i];
 tnt=temp-ar[i];
 avtnt+=tnt;
 int_to_ch(id[i]);
 outtextxy(35,z,d);
 int_to_ch(wt);
 outtextxy(150,z,d);
 int_to_ch(tnt);
 outtextxy(270,z,d);
 chart(id[i],temp);
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
    fcfs_alg fcfs;
    fcfs.getdata();
    fcfs.display();
    fcfs.cal_wt_tt();
    getch();
    return 0;
}
