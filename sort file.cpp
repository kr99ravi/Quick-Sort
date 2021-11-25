#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void Quick_Sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		Quick_Sort(arr, low, pi - 1);
		Quick_Sort(arr, pi + 1, high);
	}
}

int main()
{
    int n;
    cout<<"Enter Array size";
    cin>>n;
    int arr[n];
    cout<<"Enter array element ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Quick_Sort(arr, 0, n - 1);

   cout<<"Sorted Array:"<<endl;
   for(int i=0;i<n;i++) 
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
