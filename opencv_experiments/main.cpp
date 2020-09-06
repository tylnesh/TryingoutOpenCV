#include <QCoreApplication>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);


    //cv::VideoCapture *video = new cv::VideoCapture("/dev/video0");
    cv::VideoCapture *video = new cv::VideoCapture();
    video->open(0);
    cv::Mat img;
    cv::Mat greyImg;
    cv::CascadeClassifier faceFrontCascade;
    faceFrontCascade = cv::CascadeClassifier("/home/tylnesh/opencv_build/opencv/data/haarcascades/haarcascade_frontalface_default.xml");
    std::vector<cv::Rect> faceObjects;

    bool captureCorrect;
    while(true){
    captureCorrect = video->read(img);
    if (!captureCorrect) {
        qDebug() << "can't receive frame";
        break;
    }
    //cv::Mat img = cv::imread("/home/tylnesh/Pictures/Birmingham-Xixon/IMG_20180501_015236.jpg",3);

    cv::resize(img,img,cv::Size(800,600),0.5,0.5);
    cv::cvtColor(img,greyImg,cv::COLOR_BGRA2GRAY);
    faceFrontCascade.detectMultiScale(greyImg, faceObjects);

    for (size_t i = 0; i<faceObjects.size(); i++){
        cv::Scalar colorScalar = cv::Scalar( 255, 0, 0 );
        cv::rectangle(img,faceObjects.at(i),colorScalar,5);
    }

    cv::imshow("Obrazok",img);
    if(cv::waitKey(1) == 'q') break;
    }
    return a.exec();
}
