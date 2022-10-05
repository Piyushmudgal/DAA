/*Modify the bottom up  dynamic programming code written to solve rod cutting problem  to print 
the size of the pieces that we should cut the rod to get maximum revenue and the maximum revenue as well

Input Format

First line contains the length of the rod, n

Next line contains the length of each price from 1 to n separated by a space

Output Format

Print length of rods and maximum revenue separated by a space*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void printRodLengths(vector<int> s, int length)
{
    if(length==0)
        return;
    cout<<s[length]<<" ";
    printRodLengths(s, length-s[length]);
}
int bottomUpRodLength(vector<int> p, int length){
    vector<int> r(length+1);
    vector<int> s(length+1);
    r[0]=0;
    s[0]=0;
    int q;
    for(int j=1;j<=length;j++)
    {
        q=INT_MIN;
        for (int i = 1; i <=j; i++)
        {
            if(q<p[i-1]+r[j-i])
            {
                q=p[i-1]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    printRodLengths(s,length);
    return r[length];
}

int main()
{
    int n,d;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        arr.push_back(d);
    }
    cout<<bottomUpRodLength(arr, n);
}