#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF (ll)1e12
#define MOD (1000000000 + 7)

int findPages(int a[], int n, int m) 
    {
        long int mx=1000010;
        long int l=0;
        long r=mx;
        long int ans=r;
        while(l<=r)
        {
            long int mid=(l+r)/2;
            cout<<mid<<"-";
            int i=0;
            int j=0;
            int res=0;
            while(i<m && j<n)
            {
                long int sum=0;
                while(j<n && (sum+a[j]<=mid))
                {
                    sum+=a[j];
                    res=max((long int)res,(long int)sum);
                    ++j;
                }
                ++i;
            }
            cout<<i<<' '<<j<<' '<<res<<endl;
            if(i<m)
            {
                r=mid-1;
            }
            else
            {
                if(j<n)
                    l=mid+1;
                else
                {
					cout<<res<<endl;
                    r=mid-1;
                    ans=min((long int)ans,(long int)res);
                }
            }
        }
        return ans;
    }
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll t=1;
	//cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		int a[10010];
		for(int i=0;i<n;++i)
			cin>> a[i];
		int m;
		cin>>m;
		cout<<"\n"<<findPages(a,n,m);
	}
		
}
