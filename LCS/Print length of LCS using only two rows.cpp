/*
Print length of LCS using only two rows
Modify the bottom up dynamic programming algorithm for LCS to print the length of the LCS by 
maintaining only recent two rows of ‘b’ table

Input Format

First line contains the first string, S1

Next line contains the second string, S2

Output Format

Print the length of the longest LCS in the first line
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int lcs(string s1, string s2){
    vector<vector<int>> dp(2, vector<int>(s2.length()+1));  
    for(int i = 1;i<=s1.length(); i++){
        for(int j = 1; j<=s2.length(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i % 2][j] = dp[(i-1) % 2][j-1] + 1;
            }
            else{
                dp[i % 2][j] = max(dp[(i-1) %2][j], dp[i % 2][j-1]);
            }
        }
    }
    return dp[s1.length() % 2][s2.length()];
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<lcs(s1, s2)<<endl;
}