#include<iostream>
using namespace std;


int main()
{
    int i,temp,SIZE=4;
    int array[SIZE]={4,20,1,8};
    for(i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE-i-1;j++)
        {
            if(array[j]>=array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;

            }
        }
    }
    for (int a = 0; a < SIZE; a++)
    {
        cout<<array[a];
    }
    
    
    return 0;

}