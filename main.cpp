//暂时只能画直线
#include <windows.h>
#include <graphics.h>
#include <iostream>
#include <vector>
using namespace std;
vector <int> lx(200);
vector <int> ly(200);
vector <int> lx_(200);
vector <int> ly_(200);
class Paint
{
	bool sh = false;
	int ptr = 0;
	mouse_msg msg;
public:
	void drew()
	{
		kb();
		drewLine();
	}
	void line1()
	{
		delay_fps(120);
		cleardevice();
		if (sh)
		{
			int i, j;
			mousepos(&i, &j);
			line(lx[ptr], ly[ptr], i, j);
		}
		for (int i = 0; i < ptr; i++)
		{
			line(lx[i], ly[i],lx_[i], ly_[i]);
		}
	}
	void drewLine()
	{
		msg = getmouse();
		if (msg.flags == mouse_flag_left)
		{
			
			if (msg.msg == mouse_msg_down)
			{
				sh = true;
				mousepos(&lx[ptr], &ly[ptr]);
			}
			else if (msg.msg == mouse_msg_up)
			{
				sh = false;
				mousepos(&lx_[ptr], &ly_[ptr]);
				ptr++;
				
			}
		}
		line1();
	}
	void kb()
	{
		if (kbhit())
		{
			int c = getch();
			if (c == 8) {
				ptr--;
			}
		}
	}
};
int main()
{
	initgraph(920, 600);
	SetWindowTextA(getHWnd(), "paint-----------------------------by:lzp");
	setbkcolor(WHITE);
	Paint p;
	outtextxy(380, 0, "提示：这是一个简单的画图软件");
	while (is_run())
	{
		p.drew();
	}
	closegraph();
	return 0;
}

