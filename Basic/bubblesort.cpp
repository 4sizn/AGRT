#include <iostream>
using namespace std;
 
int main()
{
	int arr[10] = { 10, 8, 6, 5, 4, 3, 3, 2, 1, 0 };
 
	for(int i=0;i<9;i++)
		for (int j = i+1; j < 10; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
 
	for each (int t in arr)
	{
		cout << t<<"  ";
	}
	return 0;
}