#include <bits/stdc++.h>

using namespace std;

#define MAX 2011

string s1, s2;

struct my_tuple
{
	int i1, i2;
	
	bool operator<(const my_tuple& other) const
	{
		if(i2 != other.i2)return i2 < other.i2;
		return i1 < other.i1;
	}
};

int dp[MAX][MAX];

int calc(int idx1, int idx2)
{
	if(idx1 >= s1.size() || idx2 >= s2.size())
	{
		return 0;
	}
	
	if(dp[idx1][idx2] != -1)return dp[idx1][idx2]; 
	
	int ind = idx2;
	
	int ans = 0;
	ans = calc(idx1, idx2 + 1);
	
	if(s1[idx1] == s2[idx2])
	{
		ans = max(ans, 1 + calc(idx1 + 1, idx2 + 1));
	}
	
	ans = max(ans, calc(idx1 + 1, ind));
	return dp[idx1][idx2] = ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s1 >> s2;
	
	for(int i = 0; i <= s1.size(); i++)
	{
		for(int j = 0; j <= s2.size(); j++)dp[i][j] = -1;
	}
	
	cout << calc(0, 0) << endl;
	
	
	return 0;
}
