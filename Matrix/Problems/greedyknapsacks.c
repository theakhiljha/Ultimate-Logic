#include <stdio.h>

int  main()
{
	int m,n,v[20],w[20],i,j,k[20],V,W;
	float y[20],temp,x[20];

	setbuf(stdout, NULL);

	printf("Enter capacity: ");
	scanf("%d",&m);
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	printf("Enter item values and weights respectively: ");
	for(i=0;i<n;i++)
	{
		printf("\nItem %d: ",i+1);
		k[i]=i+1;
		scanf("%d",&v[i]);
		scanf("%d",&w[i]);
		x[i]=0;
	}
	printf("Item\tvalue\tweight\tv/w\n");
	for(i=0;i<=n-1;i++)
	{
		y[i]=(float)v[i]/w[i];
		printf("%d\t%d\t%d\t%f\n",k[i],v[i],w[i],y[i]);
	}
	for(j=0;j<=n-2;j++)
	{
		for(i=0;i<=n-2;i++)
		{
			if(y[i]<y[i+1])
			{
				temp=y[i+1];
				y[i+1]=y[i];
				y[i]=temp;

				temp=v[i+1];
				v[i+1]=v[i];
				v[i]=temp;

				temp=w[i+1];
				w[i+1]=w[i];
				w[i]=temp;

				temp=k[i+1];
				k[i+1]=k[i];
				k[i]=temp;
			}
		}
	}
	printf("Item\tvalue\tweight\tv/w\n");
	for(i=0;i<n;i++)
	{
		y[i]=(float)v[i]/w[i];
		printf("%d\t%d\t%d\t%f\n",k[i],v[i],w[i],y[i]);
	}
	printf("Item\tvalue\t\tweight\t\tfractional amount\n");
	V=0;W=m;
	for(i=0;i<=n-1;i++)
	{
		if(w[i]>W)
			break;
		else
		{
			x[i]=1;
			W=W-w[i];
			V=V+x[i]*v[i];
			printf("%d\t%f\t%f\t%f\n",k[i],x[i]*v[i],x[i]*w[i],x[i]);
		}
	}
	if(i<n)
	{
		x[i]=(float)W/w[i];
		V=V+x[i]*v[i];
		W=W-x[i]*w[i];
		printf("%d\t%f\t%f\t%f\n",k[i],x[i]*v[i],x[i]*w[i],x[i]);
	}
	W=m;
	printf("\nOptimal solution:\n");
	printf("VALUE=%d\nWEIGHT=%d",V,W);

	return 0;
}
