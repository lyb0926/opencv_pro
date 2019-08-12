//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//
//#include<iostream>
//#include<vector>
//using namespace cv;
//using namespace std;
//
//String path = "F:/康明斯荧光图/黑色背景 机油/IMG_20190730_134701.jpg";
//
//int main()
//{
//	Mat src_img = imread(path);
//	Mat gray_img;
//	Mat bin_img;
//	cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
//	//灰度均值
//	Scalar gray_mean = mean(gray_img);
//	//cout << gray_mean(0);
//	threshold(gray_img, bin_img, 90, 255, THRESH_BINARY);
//	//寻找全部轮廓
//	vector<vector<Point>>contours;
//	vector<Vec4i>hierarchy;
//	findContours(bin_img, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
//
//	for (int i = 0; i < hierarchy.size(); i++)
//	{
//		Scalar color = Scalar(rand() % 255, rand() % 255, rand() % 255);
//		drawContours(src_img, contours, i, color,5, 8, hierarchy);
//	}
//	//寻找最大轮廓
//	double maxarea = 0;
//	int maxAreaIdx = 0;
//	for (int index = contours.size() - 1; index >= 0; index--)
//	{
//		double tmparea = fabs(contourArea(contours[index]));
//		if (tmparea > maxarea)
//		{
//			maxarea = tmparea;
//			maxAreaIdx = index;//记录最大轮廓的索引号  
//		}
//	}
//	//Scalar color = Scalar(rand() % 255, rand() % 255, rand() % 255);
//	//drawContours(src_img, contours, maxAreaIdx, color, 5, 8, hierarchy);
//
//	//最大轮廓的内切圆
//	Rect r = boundingRect(contours[maxAreaIdx]);
//	int nL = r.x, nR = r.br().x; //轮廓左右边界
//	int nT = r.y, nB = r.br().y; //轮廓上下边界
//
//	int dist = 0;
//	int maxdist = 0;
//	Point center1;
//	for (int i = nL; i < nR; i++)  //列
//	{
//		for (int j = nT; j < nB; j++)  //行
//		{
//			//计算轮廓内部各点到最近轮廓点的距离
//			dist = pointPolygonTest(contours[maxAreaIdx], Point(i, j), true);
//			if (dist > maxdist)
//			{
//				//求最大距离，只有轮廓最中心的点才距离最大
//				maxdist = dist;
//				center1 = Point(i, j);
//			}
//		}
//	}
//	int radius = maxdist;  //圆半径
//	Point center = center1;
//	circle(src_img, center1 , radius, Scalar(0, 0, 0), 3, 8);
//	//
//	int point_idx_b_sum = 0;
//	int point_idx_g_sum = 0;
//	int point_idx_r_sum = 0;
//	vector<int> b_vec;
//	vector<int> g_vec;
//	vector<int> r_vec;
//	for (int i = nL; i < nR; i++)  //列
//	{
//		for (int j = nT; j < nB; j++)  //行
//		{
//			//计算轮廓内部各点到最近轮廓点的距离
//			dist = pointPolygonTest(contours[maxAreaIdx], Point(i, j), true);
//			b_vec.push_back(src_img.at<Vec3b>(Point(i, j))[0]);
//			g_vec.push_back(src_img.at<Vec3b>(Point(i, j))[1]);
//			r_vec.push_back(src_img.at<Vec3b>(Point(i, j))[2]);
//			//printf("b=%d\t", src_img.at<Vec3b>(Point(i, j))[0]);
//		}
//	}
//	//cout << b_vec.size();
//	for (vector<int>::iterator iter = b_vec.begin(); iter != b_vec.end(); iter++)
//	{
//		point_idx_b_sum = point_idx_b_sum + *iter;
//	}
//	for (vector<int>::iterator iter = g_vec.begin(); iter != g_vec.end(); iter++)
//	{
//		point_idx_g_sum = point_idx_g_sum + *iter;
//	}
//	for (vector<int>::iterator iter = r_vec.begin(); iter != r_vec.end(); iter++)
//	{
//		point_idx_r_sum = point_idx_r_sum + *iter;
//	}
//
//	cout << path << " " << "b=" << point_idx_b_sum / b_vec.size() << endl;
//	cout << path << " " << "g=" << point_idx_g_sum / b_vec.size() << endl;
//	cout << path << " " << "r=" << point_idx_r_sum / b_vec.size();
//	namedWindow("gray_img", WINDOW_NORMAL);
//	namedWindow("src_img", WINDOW_NORMAL);
//	while (1)
//	{
//		imshow("src_img", src_img);
//		imshow("gray_img", gray_img);
//		waitKey(40);
//	}
//}
//
