#include<stdio.h>
#define maxn 105

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int a[maxn][maxn];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int q;
	scanf("%d",&q);
	
    for(int t=0;t<q;t++) {
		int u,d,l,r;
		scanf("%d %d %d %d",&u,&d,&l,&r);
		int ans = 0;
        for(int j = u; j <= d; j++)
        {
            for(int b = l; b <= r; b++)
            {
                if(a[j][b] > ans)
                    ans = a[j][b];
            }
        }

		printf("%d\n",ans);	// output the answer immedialety
	}
	return 0;
}