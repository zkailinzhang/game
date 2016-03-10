#include "stdafx.h"
#include "Pintu.h"



Pintu::Pintu()
{

}

Pintu::~Pintu()
{
}
Pintu::Pintu(Mat& img)
{
	winname = "PINTU";//窗口名称
	completePinTu = false;//是否完成拼图
	image_original.create(HEIGHT,WIDTH,img.type());//创建指定大小的图像
	resize(img,image_original,image_original.size(),0,0);//将加载的图像缩放到指定大小

	Rect roi;              //将显示窗口分成BLOCKNUM块，将每块ROI存入数组roi_sub[]中
	int x = WIDTH/COLSNUM;
	int y = HEIGHT/ROWSNUM;

	for (int i=0;i<BLOCKNUM;i++)
	{
		roi.x = (i%COLSNUM)*x;
		roi.y = (i/ROWSNUM)*y;
		roi.height = y;
		roi.width = x;
		image_sub[i] = image_original(roi).clone();//重点学习clone（）与copyTo（）的区别
		roi_sub[i] = roi;
	}
}

void Pintu::sortImg()//以BLOCKNUM=9来解释本段程序
{
	vector<int> id;
	for (int i=1;i<=BLOCKNUM;i++)
	{
		id.push_back(i);
	}
	                                       //此处的数字打乱方法有很多种，自己可以多查查
	random_shuffle(id.begin(),id.end()-1);//将1-8的顺序呢随机打乱，9的位置不变，在拼图过程中将9的位置留空，便于移动图片
	int num = 0;
	for (int j=1;j<BLOCKNUM;j++)//求逆序数
	{
		for (int k=0;k<j;k++)
		{
			if (id[k]>id[j])
			{
				num++;
			}
		}
	}
	if (num%2 !=0)
	{
		swap(id[0],id[1]);//如果逆序数为奇数，将序列的前两位互换，以使得逆序数为偶数，因为只有逆序数为偶数的才是可复原的拼图
	}

	for (int i=0;i<BLOCKNUM;i++)
	{
		processID[i] = id[i];
	}
}

void Pintu::showImg()//显示画面
{
	Mat dst(HEIGHT,WIDTH,CV_8UC3);

	for (int i=0;i<BLOCKNUM;i++)
	{
		int id = processID[i];
		if (id == 9 && !completePinTu)//对于第九格中的画面不予显示，但当完成拼图时再显示
		{
			continue;
		}
		image_sub[id-1].copyTo(dst(roi_sub[i])); ////重点学习clone（）与copyTo（）的区别
	}
	imshow(winname,dst);
	waitKey(33);
}