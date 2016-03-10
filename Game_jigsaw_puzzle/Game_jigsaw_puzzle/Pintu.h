#ifndef _GAME_PINTU_
#define _GAME_PINTU_

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using namespace cv;

#define WIDTH 640
#define HEIGHT 480
#define RESOLUTION (WIDTH*HEIGHT)


#define LEFT_DIRECTION 1
#define RIGHT_DIRECTION 2
#define UP_DIRECTION 3
#define DOWN_DIRECTION 4



const int BLOCKNUM = 9; //3��3��
const int COLSNUM = 3;
const int ROWSNUM = 3;



const int resolution = RESOLUTION;


//��ͼƬ�ֳ�BLOCKNUM�飬�ֱ����image_sub[BLOCKNUM]�����У�����ͬ���ֳ�BLOCKNUM�飬ÿһ����������roi_sub[BLOCKNUM]
//����processID[BLOCKNUM]�д����ͼƬ�ı�ź�������λ�ã�����processID[1]==2����roi_sub[1]���д�ŵ���ͼƬimage_sub[2];


class Pintu
{
	Mat image_original;//����ĳ�ʼͼƬ
	Mat image_sub[BLOCKNUM];

public:
	Pintu();
	~Pintu();
	Pintu(Mat& img);
	void sortImg();
	void showImg();
	//void upMove();
	//void downMove();
	//void leftMove();
	//void rightMove();
	//void move();

	string winname;
	bool completePinTu;
    int processID[BLOCKNUM];
	Rect roi_sub[BLOCKNUM];

private:

};



#endif