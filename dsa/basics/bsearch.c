#include <stdio.h>

int main()
{
	int a[20] = {0}; 
	int n, i, j, temp;
	int *beg, *end, *mid, target;

	printf(" enter the total integers you want to enter (make it less then 20):\n");
	scanf("%d", &n);
	if (n >= 20) return 0;   // ouch!
	printf(" enter the integer array elements:\n" );
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	// sort the loaded array, a must for binary search! 
	// you can apply qsort or other algorithms here
	for(i = 0; i < n-1; i++)
	{  
		for(j = 0; j < n-i-1; j++)
		{
			if (a[j+1] < a[j])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf(" the sorted numbers are:");
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	// point to beginning and end of the array
	beg = &a[0];
	end = &a[n];  // use n = one element past the loaded array!
	printf("\n beg points to address %d and end to %d",beg, end);  // test

	// mid should point somewhere in the middle of these addresses
	mid = beg + n/2;
	//mid = beg += n/2;
	printf("\n mid points to address %d", mid);  // test

	printf("\n enter the number to be searched:");
	scanf("%d",&target);

	// binary search, there is an AND in the middle of while()!!!
	while((beg <= end) && (*mid != target))
	{
		// is the target in lower or upper half?
		if (target < *mid)
		{
			end = mid - 1;     // new end
			n = n/2;
			mid = beg + n/2;  // new middle
		}
		else
		{
			beg = mid + 1;     // new beginning
			n = n/2;
			mid = beg + n/2;  // new middle      
		}
	}

	// did you find the target?
	if (*mid == target)
	{
		printf("\n %d found!", target);
	}
	else
	{
		printf("\n %d not found!", target);
	}
	printf("\n");
	//getchar();  // trap enter
	//getchar();  // wait
	return 0;
}


