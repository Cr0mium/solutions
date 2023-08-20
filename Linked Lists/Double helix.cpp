#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF (ll)1e12
#define MOD (1000000000 + 7)
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll t=1;
	//cin>> t;
	while(t)
	{
		ll n;
		cin>> n;
		if(n==0) break;
		
		vector<ll> v1(n);
		for(auto &it: v1) cin>> it;
		
		ll m;
		cin>> m;
		
		vector<ll> v2(m);
		for(auto &it: v2) cin>> it;
		
		vector<vector<ll>> s(2,vector<ll>(max(n,m)+1));
		for(ll i=0;i<n;++i)
			s[0][i+1]=v1[i]+s[0][i];
		
		for(ll i=0;i<m;++i)
			s[1][i+1]=v2[i]+s[1][i];
		
		ll p1=0;
		ll p2=0;
		ll sum=0;
		for(ll i=0;i<n;++i)
		{
			ll j=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
			if(v2[j]!=v1[i]) continue;
			ll s1,s2;
			s1=s[0][i+1]-s[0][p1];
			s2=s[1][j+1]-s[1][p2];
			p1=i+1;
			p2=j+1;
			//cout<<s1<<' '<<s2<<endl;
			sum+= max(s1,s2);
		}
	cout<<sum+max(s[0][n]-s[0][p1],s[1][m]-s[1][p2])<<endl;
	}
		
}
