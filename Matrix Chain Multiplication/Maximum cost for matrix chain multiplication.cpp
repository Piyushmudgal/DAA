/*
Modify the algorithm developed in problem 4 (matrix chain multiplication problem) to find the way to parenthesize that will have maximum number of multiplications. Print the matrices with parenthesis that will have maximum number of multiplications as well. For example given three matrices and dimension as follows:

4
10 100 5 50

The code must print the m table as 
5000 75000 
25000 

S table as
1 1 
2 

Maximum cost is
75000

Paraenthesization of matrices is 
(A1(A2A3))

Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chain

Output Format

Print the mtable

Print the s table

Print the maximum cost

Print the parenthesization that will lead to maximum cost
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void print_matrix(vector<vector<int>> matrix){
    for(int i=1;i<matrix.size()-1;i++){
        for (int j = i+1; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
        
    }
}
void print_parenthesis(vector<vector<int>> matrix, int i, int j){
    if(i == j)  cout<<"A"<<i;
    else{
        cout<<"(";
        print_parenthesis(matrix, i, matrix[i][j]);
        print_parenthesis(matrix, matrix[i][j]+1, j);
        cout<<")";
    }
}
int matrix_chain_mul_helper(int a,int b,vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s){
    if(a == b)   return 0;
    if(m[a][b] != -1)   return m[a][b];
    m[a][b] = INT_MIN;
    for(int k = a; k < b; k++){
        int q = matrix_chain_mul_helper(a, k, p, m, s) 
                    + matrix_chain_mul_helper(k+1, b, p, m, s)
                    + p[a-1] * p[k]* p[b];
        if(q>m[a][b]){
            m[a][b] = q;
            s[a][b] = k;
        }
    }
    return m[a][b];
}
int matrix_chain_mul(vector<int>p){
    vector<vector<int>> m(p.size(), vector<int>(p.size()));
    vector<vector<int>> s(p.size(), vector<int>(p.size()));
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            if(i == j)  m[i][i] = 0;
            else m[i][j] = -1;
        }
    }
    int res = matrix_chain_mul_helper(1, p.size()-1, p, m, s);
    print_matrix(m);
    print_matrix(s);
    cout<<res<<endl;
    print_parenthesis(s, 1, s.size()-1);
    cout<<endl;
    return res;
}

int main()
{
    int n,ele,i;
    vector<int> p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p.push_back(ele);
    }   
    matrix_chain_mul(p);
}