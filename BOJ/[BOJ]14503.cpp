#include <iostream>
using namespace std;
 
int N, M;
int START_X, START_Y, START_ARROW;
int MAP[51][51];
const int CLEAN = 2;
 
class Robot
{
public:
	int _x;
	int _y;
	int _arrow; // 0 북, 1 동, 2 남, 3 서
	int _rotation_index = 0;
	int _cleanNum = 0;
	bool _power = false;
 
	Robot(int y, int x, int arrow)
	{
		_y = y;
		_x = x;
		_arrow = arrow;
	}
 
	void Rotate()
	{
		int goleft[4] = { 3, 0, 1, 2 };
		_arrow = goleft[_arrow];
 
		Increase_Rotation_Index();
	}
 
	bool Gostright()
	{
		bool result = true;
 
		int dx = 0; int dy = 0;
		
		switch (_arrow)
		{
		case 0:
			dy--;
			break;
		case 1:
			dx++;
			break;
		case 2:
			dy++;
			break;
		case 3:
			dx--;
			break;
		}
		
		//CHECK AVAILABLE
		if (MAP[dy + _y][dx + _x] != 0)
			result = false;
 
		if (dx + _x > M || dy + _y > N || dy + _y < 1 || dx + _x <1)
			result = false;
 
		if (result == true)
		{
			_x += dx;
			_y += dy;
		}
 
		return result;
	}
 
	bool GoBack()
	{
		bool result = true;
 
		int dx = 0; int dy = 0;
 
		switch (_arrow)
		{
		case 0:
			dy++;
			break;
		case 1:
			dx--;
			break;
		case 2:
			dy--;
			break;
		case 3:
			dx++;
			break;
		}
 
		//CHECK AVAILABLE
		if (MAP[dy + _y][dx + _x] == 1) //벽이면 큰일
			result = false;
 
		if (dx + _x > M || dy + _y > N || dy + _y < 1 || dx + _x <1)
			result = false;
 
		if (result == true)
		{
			_x += dx;
			_y += dy;
		}
 
		return result;
	}
	
	void Increase_Rotation_Index()
	{
		_rotation_index++;
	}
 
	void CleanArea()
	{
		MAP[_y][_x] = CLEAN;
		_cleanNum++;
/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << MAP[i][j];
			}
			cout << endl;
		}
		*/
			
	}
 
	void Process()
	{
		while (_power)
		{
			if (MAP[_y][_x] == 0)
				CleanArea();
 
			if (_rotation_index >= 4)
			{
				bool backcheck = GoBack();
				if (!backcheck)
					_power = false;
				_rotation_index = 0;
			}
 
			Rotate();
			bool gocheck = Gostright();
 
			if (gocheck)
				_rotation_index = 0;
			
		}
	}
 
};
 
int main()
{
	cin >> N >> M;
	cin>> START_Y >> START_X >> START_ARROW;
 
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> MAP[i][j];
 
	Robot robot(START_Y+1, START_X+1, START_ARROW);
	robot._power = true;
 
	robot.Process();
 
	cout << robot._cleanNum;
	return 0;
}
