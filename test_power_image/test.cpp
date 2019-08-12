//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//
//#include<iostream>
//#include<vector>
//using namespace cv;
//using namespace std;
//
//String path = "F:/荧光图/红色背景40/P80/IMG_20190808_134619.jpg";
////鼠标点击 返回HSV分量
//void mouse_callback(int event, int x, int y, int flags, void*param)
//{
//	Mat src_img = imread(path);
//	Mat hsv_img;
//	Point p(x, y);
//	cvtColor(src_img, hsv_img, COLOR_BGR2HSV);
//	switch (event)
//	{
//	case EVENT_LBUTTONDOWN:
//	{
//		printf("h=%d\t", hsv_img.at<Vec3b>(p)[0]);
//		printf("s=%d\t", hsv_img.at<Vec3b>(p)[1]);
//		printf("v=%d\n", hsv_img.at<Vec3b>(p)[2]);
//		circle(hsv_img, p, 10, Scalar(0, 0, 255), 3);
//	}
//	break;
//	}
//}
////获取各点灰度值
//void mouse_callback1(int event, int x, int y, int flags, void* param)
//{
//	Mat src_img = imread(path);
//	Mat gray_img;
//	Point p(x, y);
//	cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
//	//cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
//	switch (event)
//	{
//	case EVENT_LBUTTONDOWN:
//	{
//
//		printf("hui=%d\n", gray_img.at<uchar>(y, x));
//
//		circle(gray_img, p, 10, Scalar(0, 0, 255), 3);
//	}
//	break;
//	}
//}
//void mouse_callback2(int event, int x, int y, int flags, void* param)
//{
//	Mat src_img = imread(path);
//	Point p(x, y);
//	switch (event)
//	{
//	case EVENT_LBUTTONDOWN:
//	{
//		printf("b=%d\t", src_img.at<Vec3b>(p)[0]);
//		printf("g=%d\t", src_img.at<Vec3b>(p)[1]);
//		printf("r=%d\n", src_img.at<Vec3b>(p)[2]);
//		circle(src_img, p, 10, Scalar(0, 0, 255), 3);
//	}
//	break;
//	}
//}
//
//int main()
//{
//	//hsv分量
//	Mat src_img = imread(path);
//	Mat hsv_img;
//	Mat gray_img;
//	cvtColor(src_img, hsv_img, COLOR_BGR2HSV);
//	cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
//	namedWindow("bgr_img", WINDOW_NORMAL);
//	namedWindow("hsv_img", WINDOW_NORMAL);
//	namedWindow("gray_img", WINDOW_NORMAL);
//	setMouseCallback("bgr_img", mouse_callback2, &src_img);
//	setMouseCallback("gray_img", mouse_callback1, &gray_img);
//	setMouseCallback("hsv_img", mouse_callback, &src_img);
//	while (1)
//	{
//		imshow("bgr_img", src_img);
//		imshow("hsv_img", hsv_img);
//		imshow("gray_img", gray_img);
//		waitKey(40);
//	}
//	//各点灰度值
//	/*Mat src_img = imread("C:/Users/test1/Desktop/Street.jpg");
//	Mat gray_img;
//	cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
//	namedWindow("gray_img", WINDOW_NORMAL);
//	setMouseCallback("gray_img", mouse_callback, &gray_img);
//	while (1)
//	{
//		imshow("gray_img", gray_img);
//		waitKey(40);
//	}*/
//}
//
//
