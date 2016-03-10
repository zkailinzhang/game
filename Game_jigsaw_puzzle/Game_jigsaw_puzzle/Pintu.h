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



const int BLOCKNUM = 9; //3×3块
const int COLSNUM = 3;
const int ROWSNUM = 3;



const int resolution = RESOLUTION;


//将图片分成BLOCKNUM块，分别存入image_sub[BLOCKNUM]数组中，窗口同样分成BLOCKNUM块，每一块的区域存入roi_sub[BLOCKNUM]
//数组processID[BLOCKNUM]中存放着图片的编号和所处的位置，比如processID[1]==2代表，roi_sub[1]块中存放的是图片image_sub[2];


class Pintu
{
	Mat image_original;//载入的初始图片
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