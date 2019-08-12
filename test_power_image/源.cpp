#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<numeric>
#include<iostream>
#include<vector>
using namespace cv;
using namespace std;

String path = "F:/荧光图/红色背景70/机油/Image_20190808104350866.jpg";

int main()
{
	Mat src_img = imread(path);
	Mat gray_img;
	Mat bin_img;
	cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
	//灰度均值
	Scalar gray_mean = mean(gray_img);

	double minValue, maxValue;
	Point minLoc, maxLoc;
	minMaxLoc(gray_img, &minValue, &maxValue, &minLoc, &maxLoc);
	//cout << gray_mean(0);
	threshold(gray_img, bin_img, maxValue - 30, 255, THRESH_BINARY);
	//寻找全部轮廓
	namedWindow("bin_img", WINDOW_NORMAL);
	imshow("bin_img", bin_img);
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(bin_img, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

	/*for (int i = 0; i < hierarchy.size(); i++)
	{
		Scalar color = Scalar(rand() % 255, rand() % 255, rand() % 255);
		drawContours(src_img, contours, i, color,5, 8, hierarchy);
	}*/

	//寻找最大轮廓
	double maxarea = 0;
	int maxAreaIdx = 0;
	for (int index = contours.size() - 1; index >= 0; index--)
	{
		double tmparea = fabs(contourArea(contours[index]));
		if (tmparea > maxarea)
		{
			maxarea = tmparea;
			maxAreaIdx = index;//记录最大轮廓的索引号  
		}
	}
	/*Scalar color = Scalar(rand() % 255, rand() % 255, rand() % 255);
	drawContours(src_img, contours, maxAreaIdx, color, 5, 8, hierarchy);*/

	//外接矩形
	Rect r = boundingRect(contours[maxAreaIdx]);
	int nL = r.x, nR = r.br().x; //轮廓左右边界
	int nT = r.y, nB = r.br().y; //轮廓上下边界
	//最大轮廓的内切圆
	//int dist = 0;
	//int maxdist = 0;
	//Point center1;
	//for (int i = nL; i < nR; i++)  //列
	//{
	//	for (int j = nT; j < nB; j++)  //行
	//	{
	//		//计算轮廓内部各点到最近轮廓点的距离
	//		dist = pointPolygonTest(contours[maxAreaIdx], Point(i, j), true);
	//		if (dist > maxdist)
	//		{
	//			//求最大距离，只有轮廓最中心的点才距离最大
	//			maxdist = dist;
	//			center1 = Point(i, j);
	//		}
	//	}
	//}
	//int radius = maxdist;  //圆半径
	//Point center = center1;
	//circle(src_img, center1 , radius, Scalar(0, 0, 0), 3, 8);

	//计算轮廓内的B、G、R的平均值
	int point_idx_b_sum = 0;
	int point_idx_g_sum = 0;
	int point_idx_r_sum = 0;
	vector<int> b_vec;
	vector<int> g_vec;
	vector<int> r_vec;
	int point_idx_H_sum = 0;
	int point_idx_S_sum = 0;
	int point_idx_V_sum = 0;
	int point_idx_hui_sum = 0;
	vector<int> H_vec;
	vector<int> S_vec;
	vector<int> V_vec;
	vector<int> hui_vec;
	Mat hsv_img;
	Mat gray_img1;
	cvtColor(src_img, hsv_img, COLOR_BGR2HSV);
	cvtColor(src_img, gray_img1, COLOR_BGR2BGRA);
	int dist = 0;
	for (int i = nL; i < nR; i++)  //列
	{
		for (int j = nT; j < nB; j++)  //行
		{
			//计算轮廓内部各点到最近轮廓点的距离
			dist = pointPolygonTest(contours[maxAreaIdx], Point(i, j), true);
			b_vec.push_back(src_img.at<Vec3b>(Point(i, j))[0]);
			g_vec.push_back(src_img.at<Vec3b>(Point(i, j))[1]);
			r_vec.push_back(src_img.at<Vec3b>(Point(i, j))[2]);
			H_vec.push_back(hsv_img.at<Vec3b>(Point(i, j))[0]);
			S_vec.push_back(hsv_img.at<Vec3b>(Point(i, j))[1]);
			V_vec.push_back(hsv_img.at<Vec3b>(Point(i, j))[2]);
			hui_vec.push_back(gray_img.at<uchar>(Point(i, j)));
			//printf("b=%d\t", src_img.at<Vec3b>(Point(i, j))[0]);
		}
	}
	//cout << b_vec.size();
	//int b_max = max_element(b_vec.begin(), b_vec.end());
	int b_vec_sum = accumulate(b_vec.begin(), b_vec.end(), 0);
	int g_vec_sum = accumulate(g_vec.begin(), g_vec.end(), 0);
	int r_vec_sum = accumulate(r_vec.begin(), r_vec.end(), 0);
	int h_vec_sum = accumulate(H_vec.begin(), H_vec.end(), 0);
	int s_vec_sum = accumulate(S_vec.begin(), S_vec.end(), 0);
	int v_vec_sum = accumulate(V_vec.begin(), V_vec.end(), 0);
	int hui_vec_sum = accumulate(hui_vec.begin(), hui_vec.end(), 0);


	//输出HSV分量的最小与最大值范围
	vector<int>::iterator max1 = max_element(b_vec.begin(), b_vec.end());
	vector<int>::iterator min1 = min_element(b_vec.begin(), b_vec.end());
	cout << path << " " << "b范围" << *min1 << "-" << *max1 << endl;

	vector<int>::iterator max2 = max_element(g_vec.begin(), g_vec.end());
	vector<int>::iterator min2 = min_element(g_vec.begin(), g_vec.end());
	cout << path << " " << "g范围" << *min2 << "-" << *max2 << endl;

	vector<int>::iterator max3 = max_element(r_vec.begin(), r_vec.end());
	vector<int>::iterator min3 = min_element(r_vec.begin(), r_vec.end());
	cout << path << " " << "r范围" << *min3 << "-" << *max3 << endl;
	vector<int>::iterator max4 = max_element(H_vec.begin(), H_vec.end());
	vector<int>::iterator min4 = min_element(H_vec.begin(), H_vec.end());
	cout << path << " " << "H范围" << *min4 << "-" << *max4 << endl;

	vector<int>::iterator max5 = max_element(S_vec.begin(), S_vec.end());
	vector<int>::iterator min5 = min_element(S_vec.begin(), S_vec.end());
	cout << path << " " << "S范围" << *min5 << "-" << *max5 << endl;

	vector<int>::iterator max6 = max_element(V_vec.begin(), V_vec.end());
	vector<int>::iterator min6 = min_element(V_vec.begin(), V_vec.end());
	//输出BGR HSV平均值
	cout << path << " " << "V范围" << *min6 << "-" << *max6 << endl;
	cout << path << " " << "b=" << b_vec_sum / b_vec.size() << endl;
	cout << path << " " << "g=" << g_vec_sum / g_vec.size() << endl;
	cout << path << " " << "r=" << r_vec_sum / r_vec.size() << endl;

	cout << path << " " << "h=" << h_vec_sum / H_vec.size() << endl;
	cout << path << " " << "s=" << s_vec_sum / S_vec.size() << endl;
	cout << path << " " << "v=" << v_vec_sum / V_vec.size() << endl;

	cout << path << " " << "hui=" << hui_vec_sum / hui_vec.size();
	namedWindow("gray_img", WINDOW_NORMAL);
	namedWindow("src_img", WINDOW_NORMAL);
	while (1)
	{
		imshow("src_img", src_img);
		imshow("gray_img", gray_img);
		waitKey(40);
	}
}

