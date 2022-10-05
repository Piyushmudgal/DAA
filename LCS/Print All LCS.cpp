/*
Print all LCSs
Rewrite the print LCS routine to print all the LCSs of two sequences

 

Input Format

First line contains the first string, S1

Next line contains the second string, S2

Output Format

Print the length of the longest LCS in the first line

Print the Longest LCS that we get by traversing from the last cell (m,n) 
of the b table where m is the length of the first string and n is the 
length of the second string 
*/
// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// void printMultipleLCS(int m, int n, string s1, string s2, vector<vector<int>> &dp, string res){
//     if(m == 0 || n == 0){
//         cout<<res<<endl;
//         return;
//     }
//     if(dp[m-1][n] == dp[m][n])  printMultipleLCS(m-1, n, s1, s2, dp, res);
//     if(dp[m][n-1] == dp[m][n])  printMultipleLCS(m, n-1, s1, s2, dp, res);
//     else{
//         printMultipleLCS(m-1, n-1, s1, s2, dp, s1[m-1] + res);
//     }
// }
// void lcs(string s1, string s2){
//     int m = s1.size();
//     int n = s2.size();
//     vector<vector<int>> dp(m+1, vector<int>(n+1));
//     for(int i = 1; i < dp.size(); i++){
//         for(int j = 1; j < dp[0].size(); j++){
//             if(i==0 || j==0)    dp[i][j] = 0;
//             else dp[i][j] = -1;
//         }
//     }
//     for(int i = 1; i < dp.size(); i++){
//         for(int j = 1; j<dp[0].size(); j++){
//             if(s1[i-1] == s2[j-1]){
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
//     for (int i = 0; i < dp.size(); i++)
//     {
//         for (int j = 0; j < dp[0].size(); j++)
//         {
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     printMultipleLCS(m, n, s1, s2, dp, "");
// }
// int main(){
//     string s1, s2;
//     cin>>s1>>s2;
//     lcs(s1, s2);
// }
#include<iostream>
#include<string.h>
#include<set>
using namespace std;
int dp[1000][1000];
void lcs(string x, string y, int m, int n)
{
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (x[i-1]==y[j-1]) 
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else 
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}
set<string> lcsp(string x, string y, int m, int n) 
{ 
    set<string> s; 
    if (m==0 || n==0) 
    { 
        s.insert(""); 
        return s; 
    } 
    if (x[m-1]==y[n-1]) 
    { 
        set<string> t=lcsp(x, y, m-1, n-1); 
        for (string str : t) 
            s.insert(str+x[m-1]); 
    } 
    else
    { 
        if (dp[m-1][n]>=dp[m][n-1]) 
            s=lcsp(x, y, m-1, n); 
        if (dp[m][n-1]>=dp[m-1][n]) 
        { 
            set<string> t=lcsp(x, y, m, n-1); 
            s.insert(t.begin(), t.end()); 
        } 
    } 
    return s; 
} 

int main()
{
 
    string x,y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();
 
    
    memset(dp, -1, sizeof(dp));
    lcs(x, y, m, n);
    set<string> s=lcsp(x, y, m, n); 
  
    for (string str : s) 
        cout<<str<<"\n"; 
    return 0;
}