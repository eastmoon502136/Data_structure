#include <stdio.h>
#include <string.h>

int rank[100];
int p[100];		  


void makeset(int x)
{
	rank[x] = 0; 
	p[x] = x;
}


int findset(int x)
{
	int px = x, i;
	while(px != p[px])	px = p[px];
	while(x != px) {
		i = p[x];
		p[x] = px;
		x = i;
	}
return px;
}


void unionset(int x, int y)
{
	x = findset(x);
	y = findset(y);
	if(rank[x] > rank[y]) p[y] = x;
	else {
		p[x] = y;
		if(rank[x] == rank[y])	rank[y]++;
	}
}

int main(int argc, char *argv)
{
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= 100; i++)
			makeset(i);
		for(int i = 0; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			//a = findset(a);	
			//b = findset(b);
			unionset(a, b);
		}
		for(int i = 1; i <= 2 * n; i++)
			printf("%d ", rank[i]);
		printf("\n");
		for(int i = 1; i <= 2 * n; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
return 0;
}
