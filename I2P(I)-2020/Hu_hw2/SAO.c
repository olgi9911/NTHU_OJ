#include<stdio.h>
#define maxn 501

int main() {
	int n;
	scanf("%d",&n);
	int a[maxn];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
    int q;
	scanf("%d",&q);
    for(int t=0;t<q;t++) 
    {
		int l,r;
		scanf("%d %d", &l, &r);
		int ans = 0;
        int max[maxn]={0};
        int temp = 0;

        for(int j = l, t = l; j <= r; j++)
        {
            max[a[t]]++;
            t++;
        }

        for(int k = 1; k < maxn; k++)
        {
            if(max[k] > temp)
                temp = max[k];
        }

        for(int m = 1; m < maxn; m++)
        {
            if(max[m] == temp)
            {
                ans = m;
                break;
            }
        }

		printf("%d\n",ans);	// output the answer immedialety
	}
	return 0;
}