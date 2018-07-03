#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/ml.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	/*Init*/
	float rateB = 0.3,
		rateG = 0.3,
		rateR = 0.3;

	Mat foo = imread("6.png");
	Mat newImg(foo.rows, foo.cols, CV_8UC1, Scalar(0));

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
	imshow("origin", foo);
	imshow("Gray", newImg);
	waitKey(0);
	destroyAllWindows();
}