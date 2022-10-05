/*
Matrix Chain Multiplication Top Down

Develop a top down dynamic programming algorithm to find minimum cost for matrix chain multiplication. Print the tables maintained by the algorithm. For example, when there are six matrices and the input given is 

7
30 35 15 5 10 20 25

M table should be printed as 

15750 7875 9375 11875 15125 
2625 4375 7125 10500 
750 2500 5375 
1000 3500 
5000 
S table should be printed as 
1 1 3 3 3 
2 3 3 3 
3 3 3 
4 5 
5 
Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chaini need to know now can you love me again 

Output Format
Print the mtable

Print the s table

Print the minimum cost
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
    m[a][b] = INT_MAX;
    for(int k = a; k < b; k++){
        int q = matrix_chain_mul_helper(a, k, p, m, s) 
                    + matrix_chain_mul_helper(k+1, b, p, m, s)
                    + p[a-1] * p[k]* p[b];
        if(q<m[a][b]){
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
    // print_parenthesis(s, 1, s.size()-1);
    // cout<<endl;
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
    cout<<matrix_chain_mul(p);
}