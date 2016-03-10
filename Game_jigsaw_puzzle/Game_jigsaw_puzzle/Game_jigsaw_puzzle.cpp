// Game_jigsaw_puzzle.cpp : �������̨Ӧ�ó������ڵ㡣
//
/************************************************************************/
/* ƴͼ��Ϸ��飺
   1.http://baike.baidu.com/view/2879180.htm?fr=aladdin ƴͼ��飬�������ⱻ���ҵ�ƴͼ������ƴ��ԭͼ
   2.��������3��3ƴͼ����opencv�и���Ȥ����Ĳ���������¼��Ĳ�����С��Ŀ����ı�д��
   3.*/
/************************************************************************/
#include "stdafx.h"
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include "Pintu.h"
#include <string>


using namespace std;
using namespace cv;

int inWhichRoi(int x,int y)//�ж������������һ������
{
	int nc = x/(WIDTH/COLSNUM);
	int nr = y/(HEIGHT/ROWSNUM);
	int id = nr*3+nc+1;
	return id;
}

void swapRoi(int id1,int id2,int* p)//����id1��id2ָ��������
{
	int temp;
	temp = p[id1];
	p[id1] = p[id2];
	p[id2] = temp;
}

int compareMAX(int id1,int id2,int* p)//�Ƚ��������򣬷��ؽϴ�ֵ������
{
	if (p[id1]<p[id2])
	{
		return id2;
	}
	else
	{
		return id1;
	}
}
static void onMouse(int event,int x,int y,int flags,void* p)//��ѧvoid*ָ�룬������
{
	int* processID = (int*)p;
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		int n = inWhichRoi(x,y);
		switch (n)
		{
		case 1:
			if (processID[1]>processID[3])
			{
				if (processID[1] == 9)
				{
					swapRoi(n-1,1,processID);
				}
			}
			else
			{
				if (processID[3] == 9)
				{
					swapRoi(n-1,1,processID);
				}
			}
			break;
		case 2:
			{
				int temp = compareMAX(0,2,processID);
				int temp_1 = compareMAX(temp,4,processID);
				if (processID[temp_1] == 9)
				{
					swapRoi(n-1,temp_1,processID);
				}
			}
			
			break;
		case 3:
			{
				int temp = compareMAX(1,5,processID);
				if (processID[temp] == 9)
				{
					swapRoi(n-1,temp,processID);
				}
			}
			break;

		case 4:
			{
				int temp = compareMAX(0,4,processID);
				int temp_1 = compareMAX(temp,6,processID);
				if (processID[temp_1] == 9)
				{
					swapRoi(n-1,temp_1,processID);
				}
			}
			break;
		case 5:
			{
				int temp = compareMAX(1,3,processID);
				int temp_1 = compareMAX(temp,5,processID);
				int temp_2 = compareMAX(temp_1,7,processID);
				if (processID[temp_2] == 9)
				{
					swapRoi(n-1,temp_2,processID);
				}
			}
			break;
		case 6:
			{
				int temp = compareMAX(2,4,processID);
				int temp_1 = compareMAX(temp,8,processID);
				if (processID[temp_1] == 9)
				{
					swapRoi(n-1,temp_1,processID);
				}
			}
			break;
		case 7:
			{
				int temp = compareMAX(3,7,processID);
				if (processID[temp] == 9)
				{
					swapRoi(n-1,temp,processID);
				}
			}
			break;
		case 8:
			{
				int temp = compareMAX(6,4,processID);
				int temp_1 = compareMAX(temp,8,processID);
				if (processID[temp_1] == 9)
				{
					swapRoi(n-1,temp_1,processID);
				}
			}
			break;
		case 9:
			{
				int temp = compareMAX(5,7,processID);
				if (processID[temp] == 9)
				{
					swapRoi(n-1,temp,processID);
				}
			}
			break;
		default:
			break;
		}
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	string pictureName = "test.jpg";
	Mat img  = imread(pictureName);
    Pintu game(img);
	game.sortImg();
	game.showImg();
	setMouseCallback(game.winname,&onMouse,&game.processID);

	while (true)
	{
		int count = 0;
		for (int i=0;i<BLOCKNUM;i++)
		{
			if (game.processID[i] == i)
			{
				count++;
			}
		}
		if (count ==9)
		{
			game.completePinTu = true;
		}
		game.showImg();
	}
	return 0;
}

