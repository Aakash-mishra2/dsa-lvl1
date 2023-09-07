#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    file_io();
    priority_queue< int, vector<int>, greater<int>> rightHeap;
    priority_queue<int> leftHeap;

    int d;
    cin>>d;
    leftHeap.push(d);

    float med = d;
    cout<<med <<" ";

    cin>>d;
    while( d!= -1){
        if(leftHeap.size() == rightHeap.size()){
          if( d < med){
            leftHeap.push(d);
            med = leftHeap.top();
          }
          else{
            rightHeap.push(d);
            med = rightHeap.top();
          }
        }
        else if(leftHeap.size() > rightHeap.size()){
            if(d<med){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
            leftHeap.push(d);
            }
            else{ 
                rightHeap.push(d);
            }
            med = static_cast<float>(leftHeap.top() + rightHeap.top())/2;
        }
        else{
            if( d<med){ 
                leftHeap.push(d);
            }
            else{
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            med = static_cast<float>(leftHeap.top() + rightHeap.top())/2;
        }
        cout<<med<<" ";
        cin>>d;
    }
}
