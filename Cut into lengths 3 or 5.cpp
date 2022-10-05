//A variation of rod cutting problem is one in which length of the rod will be of length greater 
//than or equal to 8 and you can make cuts of rods of length 3 or 5 only. For each unit of wastage 
//a penalty of Rs.1 should be given.
//Write an recursive algorithm and implement it to find the maximum revenue that may be generated.

/*Input Format

First line contains the length of the rod,n

Next line contains the price of rod of length 3 and 5 separated by a space

Output Format

Prin the maximum revenue that may be generated*/

#include<iostream>
#include<vector>

using namespace std;
int d3,d5;
int algo(int n) 
{
    // if(n<3)
    //     return -1 * n;
    // if(n==3)
    //     return d3;
    // if(n==5)
    //     return d5;
    // int d1=algo(n-3)+d3;
    // int d2=algo(n-5)+d5;
    // if(d1>d2)
    //     return d1;
    // else
    //     return d2;

    if (n < 0) {
        return INT32_MIN;
    } else if (n < 3) {
        return -1 * n;
    }

    return max(algo(n - 3) + d3, algo(n - 5) + d5);
}

int main()
{
    int n;
    cin>>n;
    cin>>d3>>d5;
    cout<<algo(n);                                    
}