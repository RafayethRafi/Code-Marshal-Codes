#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define endl '\n'
const int mx = 1e7+123;
int phi[mx];
long long presum[mx];

int main()
{
    optimize();
    int lim = 1e7,i,j;
    for(i=1;i<=lim;i++) phi[i] = i;

    for(i=2;i<=lim;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=lim;j+=i)
            {
                phi[j]/= i;
                phi[j]*= (i-1);
            }
        }
    }

    for(i=1;i<=lim;i++) presum[i] = presum[i-1] + phi[i];
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        long long n,p;
        cin>>n>>p;

        int x = -1, l=1,r =n;

        while(l<=r)
        {
            int m= (l+r)>>1;
            if(presum[m]>=p)
            {
                x = m;
                r= m-1;
            }
            else l = m+1;
        }
        long long ans =-1;
        if(x!=-1) ans = n/x;

        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
    return 0;
}
