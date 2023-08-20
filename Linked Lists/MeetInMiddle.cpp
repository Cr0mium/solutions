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
	while(t--)
	{
		ll n,a,b;
		cin>> n >> a >> b;
		vector<ll> v(n);
		for(ll i=0;i<n;++i)
			cin>> v[i];
		vector<ll> s[2];
		ll ans=0;
		int x=n/2;
		for(int k=0;k<2;++k)
		{	
			for(ll i=0;i< (1ll<<x); ++i)
			{
				ll sum=0;
				for(ll j=0;j<x;++j)
				{
					if((i>>j)&1)
					{
						sum+=(v[k*n/2+j]);
					}
				}
				
				s[k].push_back(sum);
			}
			x=n-x;
		}
		sort(s[1].begin(),s[1].end());
		//for(auto it:s[1]) cout<<it<<' ';
	
		for(int i=0;i<(int)s[0].size();++i)
		{
			ans+=(upper_bound(s[1].begin(),s[1].end(),b-s[0][i])-lower_bound(s[1].begin(),s[1].end(),a-s[0][i]));
		}
		cout<<ans<<endl;
	}
		
}
