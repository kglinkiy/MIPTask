#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <iostream>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

using namespace dlib;
using namespace std;
using namespace cv;
int main()
{
	try // try/catch protecting  sanity 
	{
		VideoCapture cap(0);
		if (!cap.isOpened())
		{
			cerr << "Unable to connect to camera" << endl;
			return 1;
		}

		image_window win;

		// Load face detection and pose estimation models.
		frontal_face_detector detector = get_frontal_face_detector();
		shape_predictor pose_model;
		deserialize("shape_predictor_5_face_landmarks.dat") >> pose_model;

		// Grab and process frames until the main window is closed by the user.
		while (!win.is_closed())
		{
			
			Mat temp;
			if (!cap.read(temp))
			{
				break;
			}
			
			cv_image<bgr_pixel> cimg(temp);

			// Detect faces 
			vector<rectangle> faces = detector(cimg);
			// Find the pose of each face.
			vector<full_object_detection> shapes;
			for (unsigned long i = 0; i < faces.size(); ++i)
				shapes.push_back(pose_model(cimg, faces[i]));

			// Display it all on the screen
			win.clear_overlay();
			win.set_image(cimg);
			win.add_overlay(render_face_detections(shapes));
		}
	}
	catch (serialization_error& e)
	{
		cout << "Oh no" <<"\n";
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}
