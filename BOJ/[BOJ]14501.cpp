/*
date : 17.10.26
url : https://www.acmicpc.net/problem/14501
context : i는 당일, j는 이전일을 고려하여 DP문제 출력
		
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N = 0;
	int T[17] = { 0, };
	int P[17] = { 0, };
	int D[17] = { 0, };

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int t1; int t2;
		cin >> t1 >> t2;
		T[i] = t1;
		P[i] = t2;
		D[i] = P[i];
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if(i-j>= T[j]) //당일 일자 - 이전 일자 >= 이전 일자의 유효기간 
			D[i] = max(D[j] + P[i], D[i]);
		}
	}


	//DP
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i + T[i] <= N+1)
		{
			result = max(D[i], result);
		}
	}

	cout << result;

	return 0;
}