/****************
* Author : Mrinmoy Sarkar
* Email  : sarkar.mrinmoy.bd@ieee.org
* Date   : 17 Mar 2017
*****************/



#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

#define M 10000

char A[M][M];
int  used[M][M];
int X,Y;
int m = -1;
int x_c[M],y_c[M];
int x_f[M],y_f[M];
string output[M];

int find_longest_path(int i, int j, int count);
void copy_xy();
void print_xy(int count);


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    m = -1;
    int i = 0,j = 0;

    while(scanf("%s",&A[i][0]) != EOF)i++;
    X=i-1;
    i=0;
    while(A[i][j])j++;
    Y=j-1;

    i = j = 0;
    while(A[i][j])
    {
        if(A[i][j] == '.')
        {
            x_c[0] = i;
            y_c[0] = j;
            used[i][j] = 1;
            find_longest_path(i, j, 1);
            used[i][j] = 0;
        }
        j++;
    }
 
    j--;
    i++;
    while(A[i][j])
    {
        if(A[i][j] == '.')
        {
            x_c[0] = i;
            y_c[0] = j;
            used[i][j] = 1; 
            find_longest_path(i, j, 1);
            used[i][j] = 0;
        }
        i++;
    }
  
    i--;
    j--;
    while(A[i][j] && j>=0)
    {
        if(A[i][j] == '.')
        {
            x_c[0] = i;
            y_c[0] = j;
            used[i][j] = 1;
            find_longest_path(i, j, 1);
            used[i][j] = 0;        
        }
        j--;
    }

    j++;
    i--;
    while(A[i][j] && i>0)
    {
        if(A[i][j] == '.')
        {
            x_c[0] = i;
            y_c[0] = j;
            used[i][j] = 1;
            find_longest_path(i, j, 1);
            used[i][j] = 0;            
        }
        i--;
    }
    cout << m << endl;
    for(i=0;i<=X;i++)
    {
        for(j=0;j<=Y;j++)
        {
            output[i] += A[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        char s[M] ;
        sprintf(s,"%d",i);
        output[x_f[i]].replace(y_f[i],1,s);
    }    
    for(i=0;i<=X;i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}


int find_longest_path(int i, int j, int count)
{
    if(i < X && used[i+1][j] == 0 && A[i+1][j] == '.')
    {
        x_c[count] = i+1;
        y_c[count] = j;
        used[i+1][j] = 1;
        find_longest_path(i+1,j,count+1);
        used[i+1][j] = 0;
    }
    if(i>0 && used[i-1][j] == 0 && A[i-1][j] == '.')
    {
        x_c[count] = i-1;
        y_c[count] = j;
        used[i-1][j] = 1;
        find_longest_path(i-1,j,count+1);
        used[i-1][j] = 0;
    }
    if(j<Y && used[i][j+1] == 0 && A[i][j+1] == '.')
    {
        x_c[count] = i;
        y_c[count] = j+1;
        used[i][j+1] = 1;
        find_longest_path(i,j+1,count+1);
        used[i][j+1] = 0;
    }
    if(j>0 && used[i][j-1] == 0 && A[i][j-1] == '.')
    {
        x_c[count] = i;
        y_c[count] = j-1;
        used[i][j-1] = 1;
        find_longest_path(i,j-1,count+1);
        used[i][j-1] = 0;
    }
    //print_xy(count);
    if(m < count)
    {
        m = count;
        copy_xy();
    }
    return m;
}


void copy_xy()
{
    for(int i=0;i<m;i++)
    {
        x_f[i] = x_c[i];
        y_f[i] = y_c[i];    
    }
}

void print_xy(int count)
{
    for(int i=0;i<count;i++)
    {
        cout << "(" << x_c[i] << ", " << y_c[i] << ") ";
    }
    cout << endl;
}























