#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat image = imread("D:/images/Shinchan.jpg");
	Mat dst;
	if (image.empty())
	{
		cout << "ERROR!!";
		cin.get();
		return -1;
	}
	string windowName = "My Favorite cartoon";
	double angle;
	cout << "Enter the angle : ";
	cin >> angle;
	Point2f pc(image.cols / 2, image.rows / 2);
	Mat r=getRotationMatrix2D(pc, angle, 1.0);
	warpAffine(image, dst, r, image.size());
	namedWindow("My Favorite cartoon", WINDOW_NORMAL);
	imshow("My Favorite cartoon", image);
	namedWindow("Rotated image", WINDOW_NORMAL);
	imshow("Rotated image", dst);
	waitKey(0);
	destroyWindow(windowName);
}