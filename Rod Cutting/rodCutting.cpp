#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int rodCutting(vector<int> arr, int cutLength)
{
    vector<int> A(11);
    int q;
    A[0]=0;
    for(int j=1;j<=cutLength;j++)
    {
        // cout<<"j:"<<j<<" ";
        int q=INT_MIN;
        for(int i=1;i<=j;i++)
        {
            if(q<(arr[i-1])+A[j-i])
                q=(arr[i-1]+A[j-i]);
            // cout<<"i:"<<i<<endl;
        }
        A[j]=q;
        // print(A);
    }
    return A[cutLength];
}
int main()
{
    int n,cutLength,d;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin>>d;
        arr.push_back(d);
    }
    cin>>cutLength;
    cout<<rodCutting(arr, cutLength);
}