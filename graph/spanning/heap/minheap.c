#include<stdio.h>
#include<stdlib.h>


void heapify(int *arr, int i, int heapsize);
void make_heap(int *arr, int n);
void swap(int *a, int *b);
void rm_heap(int *arr, int n);


void rm_heap(int *arr, int n)
{
	printf("The removed element is: %d", *arr);
	arr[0]=arr[n-1];
	arr[n-1]=-1;

}



void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void make_heap(int *arr, int n)
{
	int i;
	for(i=(n-2)/2; i>=0; i--)
	{
		heapify(arr, i, n-1);
	}
}

void heapify(int *arr, int i, int heapsize)
{
	int left = 2*i+1; 
	int right = 2*i+2;
	int smallest;
	if(arr[left]<arr[i] && left <=heapsize)
	{
		smallest = left;
	}
	else
		smallest = i;
	
	if(arr[right] < arr[smallest] && right <= heapsize)
	{
		smallest = right;
	}



	if(i!=smallest)
	{
		swap(&arr[i], &arr[smallest]);
		heapify(arr, smallest, heapsize);
	}
}

int main()
{
	int n, i;
	printf("Enter the no of elements: ");
	scanf("%d", &n);
	int *arr=(int*)calloc(n, sizeof(int));
	printf("Enter the elements in the array: ");
	
	for(i=0; i< n; i++)
	{
		scanf("%d", (arr+i));
	}
	
	make_heap(arr, n);
	
	printf("The smallest element is: %d\n", *(arr));
	rm_heap(arr, n);
	printf("The array is: ");
	for(i=0;i<n; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
	
	
