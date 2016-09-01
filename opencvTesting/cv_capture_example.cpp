//
//    Copyright 2014 Christopher D. McMurrough
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

/*******************************************************************************************************************//**
 * @file cv_capture_example.cpp
 * @brief C++ example for acquiring and processing image frames with OpenCV
 * @author Christopher D. McMurrough
 **********************************************************************************************************************/

// include necessary dependencies
#include <iostream>
#include <cstdio>
#include <opencv/highgui.h>

// configuration parameters
#define NUM_COMNMAND_LINE_ARGUMENTS 2
#define DISPLAY_WINDOW_NAME "Camera Image"
#define DISPLAY_WINDOW_NAME_2 "Camera Image2"

/*******************************************************************************************************************//**
 * @brief Process a single image frame
 * @param[in] imageIn the input image frame
 * @return true if frame was processed successfully
 * @author Christopher D. McMurrough
 **********************************************************************************************************************/
bool processFrame(const cv::Mat &imageIn)
{
    // process the image frame
	
    return true;
}

void mysetup(cv::VideoCapture* capture){
	capture->set(CV_CAP_PROP_FRAME_WIDTH, 320.0);
	capture->set(CV_CAP_PROP_FRAME_HEIGHT, 240.0);
	int captureFPS = static_cast<int>(capture->get(CV_CAP_PROP_FPS));
	capture->set(CV_CAP_PROP_FPS, 100.0);
	std::printf("Old FPS: %d\n", captureFPS);
	cv::waitKey(15);
	int captureWidth = static_cast<int>(capture->get(CV_CAP_PROP_FRAME_WIDTH));
    int captureHeight = static_cast<int>(capture->get(CV_CAP_PROP_FRAME_HEIGHT));
	captureFPS = static_cast<int>(capture->get(CV_CAP_PROP_FPS));
	
	std::printf("New Width %d\n", captureWidth);
	std::printf("New Height %d\n", captureHeight);
	std::printf("New FPS %d\n", captureFPS);
}

/***********************************************************************************************************************
 * @brief program entry point
 * @param[in] argc number of command line arguments
 * @param[in] argv string array of command line arguments
 * @return return code (0 for normal termination)
 * @author Christopher D. McMurrough
 **********************************************************************************************************************/
int main(int argc, char **argv)
{
    // store video capture parameters
    int cameraIndex = 0;
    bool showFrames = false;

    // validate and parse the command line arguments
    if(argc != NUM_COMNMAND_LINE_ARGUMENTS + 1)
    {
        std::printf("USAGE: %s <camera_index> <display_mode> \n", argv[0]);
        std::printf("WARNING: Proceeding with default execution parameters... \n");
        cameraIndex = 0;
        showFrames = true;
    }
    else
    {
        cameraIndex = atoi(argv[1]);
        showFrames = atoi(argv[2]) > 0;
    }

    // initialize the camera capture
    cv::VideoCapture capture(cameraIndex);
	cv::VideoCapture capture2(cameraIndex + 1);
    if(!capture.isOpened())
    {
        std::printf("Unable to open video source, terminating program! \n");
        return 0;
    }
	if(!capture2.isOpened())
    {
        std::printf("Unable to open video source, terminating program! \n");
        return 0;
    }

    // get the video source paramters
    int captureWidth = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_WIDTH));
    int captureHeight = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	
    std::printf("%d\n", captureWidth);
	std::printf("%d\n", captureHeight);
	mysetup(&capture);
	mysetup(&capture2);
	
    // create the debug image windows
    if(showFrames)
    {
        cv::namedWindow(DISPLAY_WINDOW_NAME, CV_WINDOW_AUTOSIZE);
        cv::namedWindow(DISPLAY_WINDOW_NAME_2, CV_WINDOW_AUTOSIZE);
    }
    // process data until program termination
    bool doCapture = true;
    int frameCount = 0;
    while(doCapture)
    {
        // get the start time
        double startTicks = static_cast<double>(cv::getTickCount());

        // attempt to acquire an image frame
        cv::Mat captureFrame;
		cv::Mat captureFrame2;
        bool captureSuccess = capture.read(captureFrame);
        if(captureSuccess)
        {
            // process the image frame
            processFrame(captureFrame);
			std::printf("capture success: %d", frameCount);
            // increment the frame counter
            frameCount++;
        }
        else
        {
            std::printf("Unable to acquire image frame! \n");
        }
		bool captureSuccess2 = capture2.read(captureFrame2);
        if(captureSuccess2)
        {
            // process the image frame
            processFrame(captureFrame2);
			std::printf("capture success: %d", frameCount);
            // increment the frame counter
            frameCount++;
        }
        else
        {
            std::printf("Unable to acquire image frame! \n");
        }

        // update the GUI window if necessary
        if(showFrames && captureSuccess && captureSuccess2)
        {
            cv::imshow(DISPLAY_WINDOW_NAME, captureFrame);
			cv::imshow(DISPLAY_WINDOW_NAME_2, captureFrame2);

            // check for program termination
            if(((char) cv::waitKey(1)) == 'q')
            {
                doCapture = false;
            }
        }

        // compute the frame processing time
        double endTicks = static_cast<double>(cv::getTickCount());
        double elapsedTime = (endTicks - startTicks) / cv::getTickFrequency();
        std::printf("Frame processing time: %f \n", elapsedTime);
    }

    // release program resources before returning
    capture.release();
    cv::destroyAllWindows();
}
