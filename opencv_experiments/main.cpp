#include <QCoreApplication>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat img = cv::imread("/home/tylnesh/Pictures/Birmingham-Xixon/IMG_20180501_015236.jpg",3);
    cv::Mat greyImg;
    cv::resize(img,img,cv::Size(800,600),0.5,0.5);
    cv::cvtColor(img,greyImg,cv::COLOR_BGRA2GRAY);
    cv::CascadeClassifier faceFrontCascade;
    faceFrontCascade = cv::CascadeClassifier("/home/tylnesh/opencv/data/haarcascades/haarcascade_frontalface_default.xml");

    std::vector<cv::Rect> faceObjects;

    faceFrontCascade.detectMultiScale(greyImg, faceObjects);

    for (int i = 0; i<faceObjects.size(); i++)

    {
        //cv::Rect
        cv::Scalar colorScalar = cv::Scalar( 255, 0, 0 );
        cv::rectangle(img,faceObjects.at(i),colorScalar,5);
    }
    cv::imshow("Obrazok",img);

    return a.exec();
}
