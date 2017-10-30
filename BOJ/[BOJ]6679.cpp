#include <iostream>
#include <math.h>
using namespace std;
 
int Process(int data, int x)
{
	int moc =1;
	int p = 0;
	int mod;
	int result = 0;
 
 
	while (moc)
	{
		moc = data / x;
		mod = data - moc*x;
		data = moc;
		result += mod;
	}
	return result;
}
 
int main()
{
	
	for (int i = 1000; i <= 9999; i++)
	{
		if (Process(i, 10) == Process(i, 12))
		{
			if (Process(i, 10) == Process(i, 16))
			{
				cout << i << endl;
			}
		}
	}
	return 0;
}