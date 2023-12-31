#include<bits/stdc++.h>
using namespace std;

int count_subsequences(string s1, string s2){
	int m = s1.length(), n = s2.length();
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for(int i = 0; i<=m; i++){ dp[i][0]++; }
	for( int i  = 1; i<=m; i++){
		for( int j = 1; j<=n; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[m][n];
}

int main(){
	string s1 = "ABCDCE", s2 = "ABC";
	cout<<count_subsequences(s1, s2)<<endl;
	return 0;
}