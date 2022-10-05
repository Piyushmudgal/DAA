/*
Number of ways to parenthesize

In matrix chain multiplication problem, given the number of matrices to be multiplied, 
write a C++ program to find the number of ways it may be parenthesized. 
For example, when there are three matrices A1, A2 and A3 there are two ways to parenthesize them. 
(A1(A2A3)) and ((A1A2)A3). 
If there are four matrices A1, A2, A3 and A4 then there are five ways to parenthesize as shown 
(A1(A2(A3A4))), (A1((A2A3)A4)), ((A1,A2)(A3A4)), ((A1(A2A3))A4), (((A1A2)A3)A4).

Input Format

First line contains the number of matrices in the chain, n

Output Format

Print the possible number of parenthesization
*/
// [(2N)!/(N+1)!N!]
#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k;
    cin>>n;
    int p[n];
    p[0] = 1;
    for(i = 1;i<n;++i)
      p[i] = 0;
    for(i = 0;i<n;i++)
    {
        for(j = 0,k=i-1;j<i;++j,k--)
        {
            p[i] = p[i] + p[j] * p[k];
        }
    }
    cout<<p[n-1];
}