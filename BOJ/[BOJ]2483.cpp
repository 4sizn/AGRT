#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using  namespace std;

bool MAP[102][102];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
vector<int> subsum;

class Point
{
public:
	int _x;
	int _y;

	Point()
	{};

	Point(int y, int x)
	{
		 _x = x;
		 _y = y;;
	};

};

int ROW;
int COL;
queue<Point> point_qu;
int area = 0;

bool check(int y, int x)
{
	if (y<=0 || y>ROW || x > COL || x <= 0) return false;
	if (MAP[y][x] == 1) return false;
	return true;
}

void goBfs(int y, int x)
{
	int sum = 0;
	MAP[y][x] = 1;
	point_qu.push(Point(y, x));

	while (point_qu.size() > 0)
	{
		Point temp = point_qu.front();
		point_qu.pop();
		sum++;
		for (int i = 0; i < 4; i++)
		{
			Point next_point(temp._y + dy[i], temp._x + dx[i]);
			if (!check(next_point._y, next_point._x)) continue;
			MAP[next_point._y][next_point._x] = 1;
			point_qu.push(next_point);
		}
	}
	// << "sum :" <<sum << endl;
	subsum.push_back(sum);
	area++;
}

int main()
{
	list<int> ls;
	int DATA_INDEX;

	cin >> ROW >> COL >> DATA_INDEX;
	for (int k = 0; k < DATA_INDEX; k++)
	{
		Point Data[2];

		for (int i = 0; i < 2; i++)
		{
			int t1; int t2;
			cin >> t1 >> t2;
			Data[i]._x = t1;
			Data[i]._y = t2;
		}

		for (int i = Data[0]._y + 1; i <= Data[1]._y; i++)
		{
			for (int j = Data[0]._x + 1; j <= Data[1]._x; j++)
			{
				MAP[i][j] = 1;
			}
		}
	}

	/*
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			MAP[i][j] == 1 ? cout << "@" : cout << "o";
		}
		cout << endl;
	}
	*/

	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (MAP[i][j] == 0)
			{
				int temp;
				goBfs(i, j);
			}
		}
	}
	
	cout << area << endl;
	sort(subsum.begin(), subsum.end());
	for(int i=0;i<subsum.size();i++)
{
		cout << subsum[i] << ' ';
	}


		return 0;
}