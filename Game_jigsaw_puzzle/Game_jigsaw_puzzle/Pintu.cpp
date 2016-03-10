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
	winname = "PINTU";//��������
	completePinTu = false;//�Ƿ����ƴͼ
	image_original.create(HEIGHT,WIDTH,img.type());//����ָ����С��ͼ��
	resize(img,image_original,image_original.size(),0,0);//�����ص�ͼ�����ŵ�ָ����С

	Rect roi;              //����ʾ���ڷֳ�BLOCKNUM�飬��ÿ��ROI��������roi_sub[]��
	int x = WIDTH/COLSNUM;
	int y = HEIGHT/ROWSNUM;

	for (int i=0;i<BLOCKNUM;i++)
	{
		roi.x = (i%COLSNUM)*x;
		roi.y = (i/ROWSNUM)*y;
		roi.height = y;
		roi.width = x;
		image_sub[i] = image_original(roi).clone();//�ص�ѧϰclone������copyTo����������
		roi_sub[i] = roi;
	}
}

void Pintu::sortImg()//��BLOCKNUM=9�����ͱ��γ���
{
	vector<int> id;
	for (int i=1;i<=BLOCKNUM;i++)
	{
		id.push_back(i);
	}
	                                       //�˴������ִ��ҷ����кܶ��֣��Լ����Զ���
	random_shuffle(id.begin(),id.end()-1);//��1-8��˳����������ң�9��λ�ò��䣬��ƴͼ�����н�9��λ�����գ������ƶ�ͼƬ
	int num = 0;
	for (int j=1;j<BLOCKNUM;j++)//��������
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
		swap(id[0],id[1]);//���������Ϊ�����������е�ǰ��λ��������ʹ��������Ϊż������Ϊֻ��������Ϊż���Ĳ��ǿɸ�ԭ��ƴͼ
	}

	for (int i=0;i<BLOCKNUM;i++)
	{
		processID[i] = id[i];
	}
}

void Pintu::showImg()//��ʾ����
{
	Mat dst(HEIGHT,WIDTH,CV_8UC3);

	for (int i=0;i<BLOCKNUM;i++)
	{
		int id = processID[i];
		if (id == 9 && !completePinTu)//���ڵھŸ��еĻ��治����ʾ���������ƴͼʱ����ʾ
		{
			continue;
		}
		image_sub[id-1].copyTo(dst(roi_sub[i])); ////�ص�ѧϰclone������copyTo����������
	}
	imshow(winname,dst);
	waitKey(33);
}