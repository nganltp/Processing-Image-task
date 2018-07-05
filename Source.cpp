#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/ml.hpp>
#include <string>
using namespace cv;
using namespace std;

string Int2Str(int value)
{
	ostringstream os;
	os << value;
	return os.str();
}

int main(int argc, char **argv)
{
	/*Init*/
	float rateB, rateG, rateR;
	string strPath, strB, strG, strR;
	
	//string nameImg = argv[1];
	/*
	rateB = atof(argv[2]);
	rateG = atof(argv[3]);
	rateR = atof(argv[4]);*/
		//Mat foo = imread(nameImg);
	/*
		rateB = 0.3,
		rateG = 0.3,
		rateR = 0.3;*/

	Mat foo = imread("7.png");

	Mat newImg(foo.rows, foo.cols, CV_8UC1, Scalar(0));
	int inumImg = 0; 
	float oo=10;
	//cout << "nhap do lon buoc nhay: ";
	//cin >> oo;
	//oo = atof(argv[2]);
	for (rateB = 0; rateB <= 100 ; rateB+=oo) 
		for (rateG = 0; rateG <= 100-rateB; rateG += oo)
		{
			rateR = 100 - rateB - rateG;
			/*Get value 3 chanel of "foo" image and update value "newImg" image */
			for (int i = 0; i < foo.cols; i++) {
				for (int j = 0; j < foo.rows; j++) {
					Vec3b intensity = foo.at<Vec3b>(j, i);
					int valB = intensity.val[0]; //B
					int valG = intensity.val[1]; //G
					int valR = intensity.val[2]; //R
					//cout << "B " << valB << "   " << "G: " <<  valG << "   "<< "R: " << valR<<endl;
					newImg.at<uchar>(j, i) = valB * rateB + valG * rateG + valR * rateR;
				}
			}
			inumImg++;
			strPath = Int2Str(inumImg);
			strB = Int2Str(rateB);
			strG = Int2Str(rateG);
			strR = Int2Str(rateR);
			strPath = "E:/intern/Processing-Image-task/x64/Debug/Output/output" + strPath +"_B"+strB+"_G"+strG+"_R"+strR +".png";
			string nameOp = "output" + strPath + "_B" + strB + "_G" + strG + "_R" + strR + ".png";
			//cout << "B: " << strB << ", G: " << strG << ", R: " << strR << endl;
			cout << nameOp << endl;
			bool iSuccess = imwrite(strPath, newImg);
			/*if (!iSuccess)
				cout << " can't save Image!!!";
			else cout << " Success!";*/
			//cout << inumImg << endl;
		}
	imshow("origin", foo);
	imshow("Gray", newImg);
	waitKey(0);
	destroyAllWindows();
}