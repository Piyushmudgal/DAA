/*
Activity Selection Sort Iterative
Given a set ‘S’ of ‘n’ activities, implement the iterative greedy algorithm to select a subset of activities from S by selecting the task that finishes first. Sort the activities in ascending order based on finsih time and then select the activities

Input Format

First line contains the number of activities, n

Next 'n' line contains the details of the activities such as name of activity, start time and finish time

Output Format

Print the name of the activities that are selected separated by a space
*/
#include<iostream>
#include<string>
#include<vector>
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
    return a.end_time > end_time;
}
void merge(vector<activity> &arr,int left, int mid, int right)
{
    int leftLength=mid-left+1;
    int rightLength=right-mid;
    activity leftArray[leftLength],rightArray[rightLength];
    for(int i=0;i<leftLength;i++)
        leftArray[i]=arr[left+i];

    for (int j = 0; j < rightLength; j++)
        rightArray[j]=arr[mid+1+j];
    
    int i=0,j=0,k=left;
    while(i<leftLength && j<rightLength)
    {
        if(leftArray[i]<rightArray[j])
            arr[k++]=leftArray[i++];
        
        else 
            arr[k++]=rightArray[j++];
    }
    while(i<leftLength || j<rightLength)
    {
        if(i<leftLength)
            while(i<leftLength)
                arr[k++]=leftArray[i++];
        if(j<rightLength)
            while(j<rightLength)
                arr[k++]=rightArray[j++];
    }
}
void mergeSort(vector<activity> &arr,int left, int right)
{
    if(left>=right)
        return;
    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left, mid, right);

}
void activitySelectionIterative(vector<activity>& v, vector<activity>& res, int i){
    activity a;
    a = v[i++];
    res.push_back(a);
    while(i < v.size()){
        if(v[i].start_time > a.end_time){
            a = v[i];
            res.push_back(a);
        }
        i++;
    }
    return;
}
int main(){
    vector<activity> v;
    activity a;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
    }
    mergeSort(v, 0, v.size() - 1);
    vector<activity> res;
    activitySelectionIterative(v, res, 0);
    for(auto i:res){
        cout<<i;
    }
}