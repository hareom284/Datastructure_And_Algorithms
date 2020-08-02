#include<iostream>
using namespace std;
int main()
{
    int i,SIZE=7;
    int list[SIZE]={9,3,2,1,4,7,40};
    bool check;
    while (check)
    {
        check=false;
        for(i=0;i<SIZE;i++)
        {
            if(list[i]>list[i+1])
            {
                int temp=list[i];
                list[i]=list[i+1];
                list[i+1]=temp;
                check=true;
            }
        }
    }
    for ( i = 0; i < SIZE; i++)
    {
        cout<<list[i]<<" ";
    }
    
    
}