#include<iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../arrays-lvl1/revn-1/input.txt", "r", stdin);
    freopen("../arrays-lvl1/revn-1/output.txt", "w", stdout);
#endif
}

int main(){
    file_io();
    int t; cin>>t;
    
    while(t--){
        int x; cin>>x;
        if(x&1)cout<<x<<" is odd"<<endl;
        else cout<<x<<" is even"<<endl;
    }
    return 0;
}