#include <opencv2/opencv.hpp>
#include<iomanip>
#include<iostream>

 

using namespace cv;

using namespace std;

 

int main()

{

    //initialize and allocate memory to load the video stream from camera

	 // 先插的是1 之后的是2  以后先来左边，再来右边
	
	
    VideoCapture camera1(1); 

    camera1.set(CV_CAP_PROP_FRAME_WIDTH,1920);

    camera1.set(CV_CAP_PROP_FRAME_HEIGHT,1080);

    VideoCapture camera2(2);

   camera2.set(CV_CAP_PROP_FRAME_WIDTH,1920);

   camera2.set(CV_CAP_PROP_FRAME_HEIGHT,1080);

 

    if( !camera1.isOpened() ) 
		cout << "cam1 fail you"<<endl;

    if( !camera2.isOpened() ) 
		cout <<" cam2 fail zuo"<<endl;

	double t, fps, t1, t2, error;

    while(true) {

		t = (double)cv::getTickCount();
        //grab and retrieve each frames of the video sequentially

        Mat3b frame0, frame1;
		
		camera1 >> frame0;
		t1 = (double)cv::getTickCount();
        
        camera2 >> frame1;
		t2 = (double)cv::getTickCount();
 

        imshow("Video1 we hope it's left", frame0);

        imshow("Video2 we hope it's right", frame1);


        //wait for 40 milliseconds
		
		
        int c = waitKey(10);
		
		
		//计算帧率和两相机间的同步误差
		t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
		error=(t2-t1)/cv::getTickFrequency();
        fps = 1.0 / t;
		
		
		cout<<setprecision(4);
		cout << "the fps is "<<"\t"<<fps<<endl;
		cout<<"the different time  between two cam is"<<"\t"<<error*1000<<" ms"<<endl;


        //exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)

        if(27 == char(c)) break;

    }

    return 0;

}