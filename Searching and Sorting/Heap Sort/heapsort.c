#include<stdio.h>
#include<stdlib.h>
#define size 100

void insbheap(int a[],int n);
void delbheap(int a[],int n);
void heapsort(int a[],int n);
void print(int a[], int n);
int main()
{
	int x, item;
	int a[size], i, n;
	printf("Enter number of Elements in array\n");
	scanf("%d", &n);
	printf("Enter the Elements in array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",  &a[i]);
	}
	heapsort(a,n);
	printf("\nThe array sorted (HEAP) in ascending order\n");
	print(a,n);
}

void print(int a[], int n)
{
	int i;
	printf("The sorted array is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
	}
}


void insbheap(int a[],int n)
{
	int k,i,j,item;
	for (k=1;k<n;k++) {
		item = a[k];
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j]))
		{
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}
		a[i] = item;
	}
}

void delbheap(int a[],int n)
{
	int i,j,item;
	j = 0;
	item = a[j];
	i = 2*j+1;
	while(i<=n-1) {
		if(i+1 <= n-1)
		   if(a[i] <a[i+1])
		    i++;
		if(item<a[i]) {
			a[j] = a[i];
			j = i;
			i = 2*j+1;
		} else
		   break;
	}
	a[j] = item;
}


void heapsort(int a[],int n)
{
	int i,temp;
	insbheap(a,n);
	for (i=n-1;i>0;i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		delbheap(a,i);
	}
}
