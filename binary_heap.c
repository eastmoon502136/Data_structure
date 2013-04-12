#include <stdio.h>
#include <string.h>

int heap[100];	 
int hs = 0;	

void sink(int p)
{
	int q = p << 1, a = heap[p];	 
	while(q <= hs) {		 
		if(q < hs && heap[q+1] < heap[q]) q++;
		if(heap[q] >= a) break;   
		heap[p] = heap[q];     
		p = q;
		q = p<<1;
	}
	heap[p] = a;
}

int deleteMin()
{
	int r = heap[1];	
	heap[1] = heap[hs--];
	sink(1);
	
	return r;
}

void swim(int p)
{
	int q = p >> 1, a = heap[p];
	while(q && a < heap[q]) {	 
		heap[p] = heap[q];
		p = q;
		q = p >> 1;
	}
	heap[p] = a;
}

void insert(int a)	 
{
	heap[++hs] = a;
	swim(hs);
}

void build()
{
	for(int i = hs / 2; i > 0; i--)
	sink(i);
}

int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF) {
		hs = 0;
		memset(heap, 0, sizeof(heap));
		while(n--) {
			int a;
			scanf("%d", &a);
			insert(a);
		}
		for(int i = 0; i <= hs; i++)
			printf("%d ", heap[i]);
		printf("\n");
		printf("The Minnum is %d\n", deleteMin());
	}
	
	return 0;
}
