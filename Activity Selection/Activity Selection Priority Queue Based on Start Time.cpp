/*
Activity Selection Priority Queue Based on Start Time
Given a set ‘S’ of ‘n’ activities, implement the recursive greedy algorithm to select a subset of activities from S by selecting the task that starts last. Build a priority queue (max heap) based on start time and then select the activities

Input Format

First line contains the number of activities, n

Next 'n' line contains the details of the activities such as name of activity, start time and finish time

Output Format

Print the name of the activities that are selected separated by a space
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class activity{
    public:
        string name;
        int start_time;
        int end_time;
        friend istream& operator>>(istream&, activity&);
        friend ostream& operator<<(ostream&, const activity&);
        bool operator<(const activity&) const;
};
istream& operator>>(istream& in, activity& a){
    in>>a.name>>a.start_time>>a.end_time;
    return in;
}
ostream& operator<<(ostream& out, activity& a){
    out<<a.name<<" ";
    return out;
}
bool activity::operator<(const activity& a) const{
    return a.start_time > start_time;
}
void activitySelectionRecursive(priority_queue<activity>& pq, vector<activity>& res){
    activity a;
    a = pq.top();
    res.push_back(a);
    pq.pop();
    while(!pq.empty() && a.start_time < pq.top().end_time){
        pq.pop();
    }
    if(!pq.empty()){
        activitySelectionRecursive(pq, res);
    }
    else
        return;
}

int main(){
    priority_queue<activity> pq;
    vector<activity> res;
    int n;
    cin>>n;
    activity a;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        pq.push(a);
    }
    // while(!pq.empty()){
    //     a = pq.top();
    //     cout<<a;
    //     pq.pop();
    // }
    activitySelectionRecursive(pq, res);
    reverse(res.begin(), res.end());
    for(auto i: res){
        cout<< i;
    }
}
