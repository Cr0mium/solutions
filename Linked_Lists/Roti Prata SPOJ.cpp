using namespace std;
#define INF (ll)1e12
#define MOD (1000000000 + 7)

ll calculate(ll a,ll t)
{
	ll tt=0;
	ll i=0;
	while(tt+i*a<=t)
	{
		tt+=(i*a);
		++i;
	}
	return i-1;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll t=1;
	cin>> t;
	while(t--)
	{
		ll n;
		cin>> n;
		ll m;
		cin>> m;
		vector<ll> v(m);
		for(auto &it: v) cin>> it;
		
		ll l=0,r=10000000;
		ll ans=r;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			ll sum=0;
			for(ll i=0;i<m;++i)
			{
				sum+=calculate(v[i],mid);
			}
			//cout<<sum<<' '<<mid<<endl;
			if(sum>=n)
			{
				r=mid-1;
				ans=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
	}
		
}
