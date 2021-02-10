//クリックで画像座標取得

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2/superres.hpp>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <stdexcept>
#include<algorithm>


#include "nr.h"

#define PI 3.1415926535



double val = 0;

using namespace std;
using namespace cv;

void mouse_callback(int event, int x, int y, int flags, void *userdata)
{
	if (event == EVENT_LBUTTONDOWN) {
		//cout << "Left mouse button is pressed." << endl;
		cout << x << "," << y << endl;
	}
}


void Caliblation() {
	vector<vector<Point3f>> objectPoints;
	vector<vector<Point2f>> imagePoints;

	vector<Point3f> objectpoint;
	objectpoint.push_back(Point3f(-3, 0, 0));
	objectpoint.push_back(Point3f(0, 0, 0));
	objectpoint.push_back(Point3f(3, 0, 0));
	objectpoint.push_back(Point3f(0, 4, 0));

	vector<Point2f> imagepoint;
	imagepoint.push_back(Point2f(225,242));
	imagepoint.push_back(Point2f(358, 256));
	imagepoint.push_back(Point2f(531, 261));
	imagepoint.push_back(Point2f(358, 403));
	imagePoints.push_back(imagepoint);
	imagepoint.clear();
	imagepoint.push_back(Point2f(235, 251));
	imagepoint.push_back(Point2f(367, 256));
	imagepoint.push_back(Point2f(511, 252));
	imagepoint.push_back(Point2f(358, 403));
	imagePoints.push_back(imagepoint);

	Size imageSize=Size(720,480);
	Mat cameraMatrix;
	Mat distCoeffs;
	vector<Mat> rvecs;
	vector<Mat> tvecs;



	objectPoints.push_back(objectpoint);
	objectPoints.push_back(objectpoint);

	
	

	calibrateCamera(objectPoints,imagePoints,imageSize,cameraMatrix,distCoeffs,rvecs,tvecs);


	cout << cameraMatrix << endl;
	cout << rvecs[0] << endl;
	cout << tvecs[0] << endl;

}


void GetCameraImg() {

}

int main()
{
	//Caliblation();
	//GetCameraImg();

	Mat img = imread("C:\\Users\\上井　康平\\Desktop\\斜視リカバリー\\myface\\0\\1.jpg");
	cout << "size:" << img.size() << endl;

	imshow("example", img);
	setMouseCallback("example", mouse_callback);
	
	waitKey();

	return 0;
}

//変更後