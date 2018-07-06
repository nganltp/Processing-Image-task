#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/ml.hpp>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <io.h>
#include <direct.h> //mkdir
using namespace cv;
using namespace std;
namespace fs = std::experimental::filesystem;

string Int2Str(int value)
{
	ostringstream os;
	os << value;
	return os.str();
}

int main(int argc, char **argv)
{
	/*Init*/
	int type, num1, num2, num3,numImg=0;

	float rateB, rateG, rateR;
	string path,pathIn,pathOut, strB, strG, strR;

	/*Get value*/
	/*cout << "string path Input: ";
	cin >> pathIn;
	cout << "string path Output: ";
	cin >> pathOut;
	cout << "type: ";
	cin >> type;*/
	
	pathIn = "Input";
	pathOut = "Output";
	type = 1;

	path = "E:/intern/Processing-Image-task/x64/Debug/";
	pathIn = path + pathIn;
	pathOut = path + pathOut;

	/*type defaul*/
	if (type == 0)
	{
		//cout << pathIn;
		for (auto & p : fs::directory_iterator(pathIn)){
			ostringstream oss;
			oss << p;
			string pathI = oss.str();
			//cout << "path: " << pathI;
			//cout << p<< endl;
			//cout << typeid(pathI).name() << endl;
			Mat img = imread(pathI);
			cvtColor(img, img, CV_RGB2GRAY);
			numImg++;

			string strNumImg = Int2Str(numImg);
			string nameOp = pathOut + "/output" + strNumImg + ".png";
			cout << "nameOp: " << nameOp<<endl;
			bool iSuccess = imwrite(nameOp, img);
			if (!iSuccess)
				cout << " can't save Image!!!"<<endl;
			else cout << " Success!"<<endl;
			cout << "numImg: "<<numImg << endl;

			imshow("imgGray", img);
		}
		waitKey(0);
		destroyAllWindows();
		//system("pause");
	}
	if (type == 1)
	{
		//cout << pathIn;
		for (auto & p : fs::directory_iterator(pathIn)) {
			ostringstream oss;
			oss << p;
			string pathI = oss.str();
			//cout << "path: " << pathI;
			//cout << p<< endl;
			//cout << typeid(pathI).name() << endl;
			Mat img = imread(pathI);
			numImg++;
			string strNumImg = Int2Str(numImg);
			cout << "strNumImg: " << strNumImg<<endl;
			strNumImg = pathOut + "/" + strNumImg;
			cout << "pathOut+ strNumImg : " << strNumImg<<endl;
			const char *cstr = strNumImg.c_str();
			int itest = _mkdir(cstr);
			cout << itest;
			Mat newImg(img.rows, img.cols, CV_8UC1, Scalar(0));
			float oo = 0.1;
			//cout << "nhap do lon buoc nhay: ";
			//cin >> oo;
			//oo = atof(argv[2]);
			int numRate = 0;
			for (rateB = 0; rateB <= 1; rateB += oo)
				for (rateG = 0; rateG <= 1 - rateB; rateG += oo)
				{
					rateR = 1 - rateB - rateG;
					/*Get value 3 chanel of "foo" image and update value "newImg" image */
					for (int i = 0; i < img.cols; i++)
						for (int j = 0; j < img.rows; j++) {
							Vec3b intensity = img.at<Vec3b>(j, i);
							int valB = intensity.val[0]; //B
							int valG = intensity.val[1]; //G
							int valR = intensity.val[2]; //R
							//cout << "B " << valB << "   " << "G: " <<  valG << "   "<< "R: " << valR<<endl;
							newImg.at<uchar>(j, i) = valB * rateB + valG * rateG + valR * rateR;
						}
					numRate++;
					string strNumRate = Int2Str(numRate);
					strB = Int2Str(rateB*100);
					strG = Int2Str(rateG*100);
					strR = Int2Str(rateR*100);
				
					cout << "numImg: " << numImg << endl;
					imshow("imgGray", img);
					//strPath = "E:/intern/Processing-Image-task/x64/Debug/Output/" +strNumImg+ strPath + "_B" + strB + "_G" + strG + "_R" + strR + ".png";
					string nameOp = strNumImg + "/output" + strNumRate + "__B" + strB + "_G" + strG + "_R" + strR + ".png";
					//cout << "B: " << strB << ", G: " << strG << ", R: " << strR << endl;
					//cout << nameOp << endl;
					bool iSuccess = imwrite(nameOp, newImg);
					/*if (!iSuccess)
						cout << " can't save Image!!!";
					else cout << " Success!";*/
					cout << "numImg: " << numImg << endl;
					imshow("imgGray", img);
				}
		}
		waitKey(0);
		destroyAllWindows();	
	}
	//system("pause");
	/*Read from Input folder*/
	/*string path = "E:/intern/Processing-Image-task/x64/Debug/";
	path = path + num1;
	//cout << path;
	system("pause");
	for (auto & p : fs::directory_iterator(path))
	{
		//cout << p << endl;
	}*/
		
	
	

//	
//	cout << "num1: ";
//	cin >> num1;
//	if (num3 == 0)
//	{
//
//	}
//	if (num3 == 1)
//	{
//		Mat newImg(foo.rows, foo.cols, CV_8UC1, Scalar(0));
//		int inumImg = 0;
//		float oo = 10;
//		//cout << "nhap do lon buoc nhay: ";
//		//cin >> oo;
//		//oo = atof(argv[2]);
//		for (rateB = 0; rateB <= 100; rateB += oo)
//			for (rateG = 0; rateG <= 100 - rateB; rateG += oo)
//			{
//				rateR = 100 - rateB - rateG;
//				/*Get value 3 chanel of "foo" image and update value "newImg" image */
//				for (int i = 0; i < foo.cols; i++) {
//					for (int j = 0; j < foo.rows; j++) {
//						Vec3b intensity = foo.at<Vec3b>(j, i);
//						int valB = intensity.val[0]; //B
//						int valG = intensity.val[1]; //G
//						int valR = intensity.val[2]; //R
//													 //cout << "B " << valB << "   " << "G: " <<  valG << "   "<< "R: " << valR<<endl;
//						newImg.at<uchar>(j, i) = valB * rateB + valG * rateG + valR * rateR;
//					}
//				}
//				inumImg++;
//				strPath = Int2Str(inumImg);
//				strB = Int2Str(rateB);
//				strG = Int2Str(rateG);
//				strR = Int2Str(rateR);
//				strPath = "E:/intern/Processing-Image-task/x64/Debug/Output/output" + strPath + "_B" + strB + "_G" + strG + "_R" + strR + ".png";
//				string nameOp = "output" + strPath + "_B" + strB + "_G" + strG + "_R" + strR + ".png";
//				//cout << "B: " << strB << ", G: " << strG << ", R: " << strR << endl;
//				cout << nameOp << endl;
//				bool iSuccess = imwrite(strPath, newImg);
//				/*if (!iSuccess)
//				cout << " can't save Image!!!";
//				else cout << " Success!";*/
//				//cout << inumImg << endl;
//			}
//
//	}
//	if (num3 == 2)
//	{
//
//	}
//	//string nameImg = argv[1];
//	/*
//	rateB = atof(argv[2]);
//	rateG = atof(argv[3]);
//	rateR = atof(argv[4]);*/
//		//Mat foo = imread(nameImg);
//	/*
//		rateB = 0.3,
//		rateG = 0.3,
//		rateR = 0.3;*/
//
//	Mat foo = imread("7.png");
//
//	//Mat newImg(foo.rows, foo.cols, CV_8UC1, Scalar(0));
//	//int inumImg = 0; 
//	//float oo=10;
//	////cout << "nhap do lon buoc nhay: ";
//	////cin >> oo;
//	////oo = atof(argv[2]);
//	//for (rateB = 0; rateB <= 100 ; rateB+=oo) 
//	//	for (rateG = 0; rateG <= 100-rateB; rateG += oo)
//	//	{
//	//		rateR = 100 - rateB - rateG;
//	//		/*Get value 3 chanel of "foo" image and update value "newImg" image */
//	//		for (int i = 0; i < foo.cols; i++) {
//	//			for (int j = 0; j < foo.rows; j++) {
//	//				Vec3b intensity = foo.at<Vec3b>(j, i);
//	//				int valB = intensity.val[0]; //B
//	//				int valG = intensity.val[1]; //G
//	//				int valR = intensity.val[2]; //R
//	//				//cout << "B " << valB << "   " << "G: " <<  valG << "   "<< "R: " << valR<<endl;
//	//				newImg.at<uchar>(j, i) = valB * rateB + valG * rateG + valR * rateR;
//	//			}
//	//		}
//	//		inumImg++;
//	//		strPath = Int2Str(inumImg);
//	//		strB = Int2Str(rateB);
//	//		strG = Int2Str(rateG);
//	//		strR = Int2Str(rateR);
//	//		strPath = "E:/intern/Processing-Image-task/x64/Debug/Output/output" + strPath +"_B"+strB+"_G"+strG+"_R"+strR +".png";
//	//		string nameOp = "output" + strPath + "_B" + strB + "_G" + strG + "_R" + strR + ".png";
//	//		//cout << "B: " << strB << ", G: " << strG << ", R: " << strR << endl;
//	//		cout << nameOp << endl;
//	//		bool iSuccess = imwrite(strPath, newImg);
//	//		/*if (!iSuccess)
//	//			cout << " can't save Image!!!";
//	//		else cout << " Success!";*/
//	//		//cout << inumImg << endl;
//	//	}
//	imshow("origin", foo);
//	imshow("Gray", newImg);
//	waitKey(0);
//	destroyAllWindows();
}
/*
#define FRAME_WIDTH 320
#define FRAME_HEIGHT 240

int low_h = 30, low_s = 30, low_v = 30;
int high_h = 100, high_s = 100, high_v = 100;
/*
void hist_equalize(Mat &img)
{
	Mat ycrcb;
	cvtColor(img, ycrcb, CV_BGR2YCrCb);

	vector<Mat> chanels(3);
	split(ycrcb, chanels);

	Ptr<CLAHE> clahe = createCLAHE(2.0, Size(4, 4));
	clahe->apply(chanels[0], chanels[0]);

	merge(chanels, ycrcb);
	cvtColor(ycrcb, img, CV_YCrCb2BGR);
}
*/
/*void on_low_h_thresh_trackbar(int, void *)
{
	low_h = min(high_h - 1, low_h);
	setTrackbarPos("Low H", "Threshold Selection", low_h);
}

void on_high_h_thresh_trackbar(int, void *)
{
	high_h = max(high_h, low_h + 1);
	setTrackbarPos("High H", "Threshold Selection", high_h);
}

void on_low_s_thresh_trackbar(int, void *)
{
	low_s = min(high_s - 1, low_s);
	setTrackbarPos("Low S", "Threshold Selection", low_s);
}

void on_high_s_thresh_trackbar(int, void *)
{
	high_s = max(high_s, low_s + 1);
	setTrackbarPos("High S", "Threshold Selection", high_s);
}

void on_low_v_thresh_trackbar(int, void *)
{
	low_v = min(high_v - 1, low_v);
	setTrackbarPos("Low V", "Threshold Selection", low_v);
}

void on_high_v_thresh_trackbar(int, void *)
{
	high_v = max(high_v, low_v + 1);
	setTrackbarPos("High V", "Threshold Selection", high_v);
}
/*
void analyzeFrame(const VideoFrameRef &frame_color, Mat &color_img)
{
	int w = frame_color.getWidth();
	int h = frame_color.getHeight();

	color_img = Mat(h, w, CV_8UC3);
	RGB888Pixel *color_img_data = (RGB888Pixel *)frame_color.getData();
	memcpy(color_img.data, color_img_data, h * w * sizeof(RGB888Pixel));
	cvtColor(color_img, color_img, COLOR_RGB2BGR);

	return;
}
*/
//int main()
//{
//	// Init
//	/*Status rc;
//	Device device;
//	VideoStream color;
//
//	rc = OpenNI::initialize();
//	if (rc != STATUS_OK)
//		return 0;
//	rc = device.open(ANY_DEVICE);
//	if (rc != STATUS_OK)
//		return 0;
//	if (!device.getSensorInfo(SENSOR_COLOR))
//		return 0;
//	rc = color.create(device, SENSOR_COLOR);
//	if (rc != STATUS_OK)
//		return 0;
//
//	VideoMode color_mode = color.getVideoMode();
//	color_mode.setFps(30);
//	color_mode.setResolution(FRAME_WIDTH, FRAME_HEIGHT);
//	color_mode.setPixelFormat(PIXEL_FORMAT_RGB888);
//	color.setVideoMode(color_mode);
//
//	rc = color.start();
//	if (rc != STATUS_OK)
//		return 0;*/
//
//	/*VideoFrameRef frame_color;
//	VideoStream *streams[] = { &color };*/
//
//	Mat frame, hsv, mask;
//	/*
//	namedWindow("Threshold Selection", WINDOW_NORMAL);
//
//	createTrackbar("Low H", "Threshold Selection", &low_h, 255, on_low_h_thresh_trackbar);
//	createTrackbar("High H", "Threshold Selection", &high_h, 255, on_high_h_thresh_trackbar);
//	createTrackbar("Low S", "Threshold Selection", &low_s, 255, on_low_s_thresh_trackbar);
//	createTrackbar("High S", "Threshold Selection", &high_s, 255, on_high_s_thresh_trackbar);
//	createTrackbar("Low V", "Threshold Selection", &low_v, 255, on_low_v_thresh_trackbar);
//	createTrackbar("High V", "Threshold Selection", &high_v, 255, on_high_v_thresh_trackbar);*/
//
//	/*while ((char)waitKey(1) != 'q')
//	{*/
//		//color.readFrame(&frame_color);
//		//analyzeFrame(frame_color, frame);
//		//flip(frame, frame, 1);
//
//		//resize(frame, frame, Size(FRAME_WIDTH, FRAME_HEIGHT));
//		//hist_equalize(frame);
//
//		//medianBlur(frame, frame, 3);
//	frame = imread("6.png");
//		cvtColor(frame, hsv, COLOR_BGR2HSV);
//		int low_h=23,
//			low_s=41,
//			low_v=133,
//			high_h=40,
//			high_s=150,
//			high_v=255;
//		//cvInRangeS(hsvframe,cvScalar(23,41,133),cvScalar(40,150,255),threshy);
//		inRange(hsv, Scalar(low_h, low_s, low_v), Scalar(high_h, high_s, high_v), mask);
//		Mat openImg;
//
//		int morph_size =13;
//		Mat element = getStructuringElemebnt(MORPH_ELLIPSE, Size(4 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));
//		morphologyEx(mask, openImg, MORPH_CLOSE, element);
//
//		for(int x = 0 ; x < openImg.cols;x++)
//			for (int y = 0; y < openImg.rows; y++)
//			{
//
//			}
//
//		imshow("frame", frame);
//		imshow("mask", mask);
//		imshow("openImg", openImg);
//		waitKey(0);
//		destroyAllWindows();
//	//}
//
//	return 0;
//}