# include <ros/ros.h>
# include <m3api/xiApi.h>
# include <xiApiPlusOcv.hpp>
# include "stdafx.h"
# include <iostream>
# include "opencv2/opencv.hpp"
# include "opencv2/imgcodecs.hpp"
# include <image_transport/image_transport.h>
# include <cv_bridge/cv_bridge.h>
# include <sensor_msgs/image_encodings.h>
# include <vector>
# include <string>
# include <unistd.h>
# include <memory.h> 
# include <sstream>
# include "std_msgs/String.h"

using namespace cv;
using namespace std;
using namespace ros;
using namespace cv_bridge;


int main(int argc, char* argv[])
{
			

	// Sample for XIMEA OpenCV
		xiAPIplusCameraOcv cam;
		//xiAPIplusCameraOcv cam2;
		//xiAPIplusCameraOcv cam3;
		//xiAPIplusCameraOcv cam4;

	// Retrieving a handle to the camera device
		//cout << "Opening first camera..." << endl;
		//cam.OpenByUserID("cam1");
		//cam2.OpenByUserID("cam2");
		//cam3.OpenByUserID("cam3");
		//cam4.OpenByUserID("cam4");
}


	