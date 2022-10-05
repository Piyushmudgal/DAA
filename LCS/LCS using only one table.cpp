/*
LCS using only one table
Modify the bottom up dynamic programming algorithm for LCS to maintain only length table (c table) 
and print the LCS by examining the neighboring entries of the cell and print 'No common subsequence' 
if no such sequence exist.

Input Format

First line contains the first string, S1

Next line contains the second string, S2

Output Format

Print the length of the longest LCS in the first line

Print the Longest LCS that we get by traversing from the last cell (m,n) of the b table 
where m is the length of the first string and n is the length of the second string 
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
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
void lcs(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            if(i==0 || j==0)    dp[i][j] = 0;
            else dp[i][j] = -1;
        }
    }
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j<dp[0].size(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    if(dp[m][n] == 0)
    cout<<"No common subsequence"<<endl;
    else{
        cout<<dp[m][n]<<endl;
        printLCS(m, n, s1, s2, dp);
    }
    
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    lcs(s1, s2);
}