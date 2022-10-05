/*A rod cutting company streling corporation will cut rods of specific lengths only. 
Given a list of lengths by which this company will make rods, a rod of length ‘n’ and 
list of prices of each piece of rod that shall be cut by the company, 
write an algorithm and implement it using top down dynamic programming to find maximum revenue that shall be generated. 
In that case, give a penalty of Rs 1 for each meter of the residue.

Input Format

First line contains the length of the rod, n

Next line contains price of various lengths of rods from 1 to n

Next line cotains the number of preferred lengths

Next line contains the preferred lengths separated by a space

Output Format

Print the maximum revenue that may be generated */
#include<iostream>
#include<vector>
using namespace std;

int max_cost(/* TODO: Add args */) {
    // TODO: Complete function
    // HINT: Access cost of rod by prices[rod_length - 1];
    
}

int main() {
    vector<int> prices, preferred;
    int n, p;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        prices.push_back(cost);
    }

    cin >> p;

    for(int i = 0; i < p; i++) {
        int length;
        cin >> length;
        preferred.push_back(length);
    }

    cout << max_cost(/* TODO: Pass args */);
    return 0;
}