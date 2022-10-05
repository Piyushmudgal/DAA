/*
Top Down LCS
Develop a top down dynamic programming algorithm for Longest Common Subsequence 
problem and implement using C++. Print the length of the LCS and the 
LCS as well.

Input Format

First line contains the first string, S1

Next line contains the second string, S2

Output Format

Print the length of the longest LCS in the first line

Print the Longest LCS that we get by traversing from the last cell (m,n) 
of the b table where m is the length of the first string 
and n is the length of the second string  
*/
/*
ACCGGTCGAGTGCGCGGAAGCCGGCCGAA
GTCGTTCGGAATGCCGTTGCTCTGTAAA
20
GTCGTCGGAAGCCGGCCGAA
ABCBDAB
BDCABA
4
BCBA
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int lcsUTIL(int m, int n, string s1, string s2, vector<vector<int>>& dp){
    if(n == 0 || m == 0)    return 0;
    if(dp[m][n] != -1)  return dp[m][n];
    if(s1[m - 1] == s2[n - 1]){
        return dp[m][n] = 1 + lcsUTIL(m-1, n-1, s1, s2, dp);
    }
    else{
        return dp[m][n] = max(lcsUTIL(m-1, n, s1, s2, dp), lcsUTIL(m, n-1, s1, s2, dp));
    }
}
void printLCS(int m, int n, string s1, string s2, vector<vector<int>> &dp){
    string s = "";
    int i = m, j = n;
    while(i>0 && j>0){
        if(dp[i-1][j] == dp[i][j]){
            i--;
        }
        else if(dp[i][j-1] == dp[i][j]){
            j--;
        }
        else{
            s= s1[i-1] + s;
            i--;
            j--;
        }
    }
    cout<<s<<endl;
}
void lcs(int m, int n, string s1, string s2){
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i = 1; i <=m; i++){
        for (int j = 1; j <= n; j++)
            dp[i][j] = - 1;
    }
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<lcsUTIL(m, n, s1, s2, dp)<<endl;
    printLCS(m, n,s1, s2, dp);
}
   
int main(){
    string s1, s2;
    cin>>s1>>s2;
    lcs(s1.size(), s2.size(), s1, s2);
}