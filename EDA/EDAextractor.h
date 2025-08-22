// EDAextractor.h (MODIFIED VERSION)

#ifndef ORBEXTRACTOR_H
#define ORBEXTRACTOR_H

#include <vector>
#include <list>
#include <opencv2/opencv.hpp>


namespace ORB
{


    struct KeyPointWithEntropy {
        cv::KeyPoint kp;
        double entropy;

        KeyPointWithEntropy() : entropy(0.0) {}
        KeyPointWithEntropy(const cv::KeyPoint& _kp, double _entropy) : kp(_kp), entropy(_entropy) {}
    };


    class ExtractorNode
    {
    public:
        ExtractorNode() :bNoMore(false) {}

        void DivideNode(ExtractorNode& n1, ExtractorNode& n2, ExtractorNode& n3, ExtractorNode& n4);


        std::vector<KeyPointWithEntropy> vKeys;

        cv::Point2i UL, UR, BL, BR;
        std::list<ExtractorNode>::iterator lit;
        bool bNoMore;
    };

    class EDAextractor
    {
    public:

        enum { HARRIS_SCORE = 0, FAST_SCORE = 1 };

        EDAextractor(int nfeatures, float scaleFactor, int nlevels,
            int iniThFAST, int minThFAST);

        ~EDAextractor() {}


        int operator()(cv::InputArray _image, cv::InputArray _mask,
            std::vector<cv::KeyPoint>& _keypoints,
            cv::OutputArray _descriptors, std::vector<int>& vLappingArea);

        int inline GetLevels() {
            return nlevels;
        }

        float inline GetScaleFactor() {
            return scaleFactor;
        }

        std::vector<float> inline GetScaleFactors() {
            return mvScaleFactor;
        }

        std::vector<float> inline GetInverseScaleFactors() {
            return mvInvScaleFactor;
        }

        std::vector<float> inline GetScaleSigmaSquares() {
            return mvLevelSigma2;
        }

        std::vector<float> inline GetInverseScaleSigmaSquares() {
            return mvInvLevelSigma2;
        }

        std::vector<cv::Mat> mvImagePyramid;

    protected:

        void ComputePyramid(cv::Mat image);
        void ComputeKeyPointsOctTree(std::vector<std::vector<cv::KeyPoint> >& allKeypoints);


        std::vector<KeyPointWithEntropy> DistributeOctTree(const std::vector<KeyPointWithEntropy>& vToDistributeKeys, const int& minX,
            const int& maxX, const int& minY, const int& maxY, const int& nFeatures, const int& level);

        void ComputeKeyPointsOld(std::vector<std::vector<cv::KeyPoint> >& allKeypoints);
        std::vector<cv::Point> pattern;

        int nfeatures;
        double scaleFactor;
        int nlevels;
        int iniThFAST;
        int minThFAST;

        std::vector<int> mnFeaturesPerLevel;

        std::vector<int> umax;

        std::vector<float> mvScaleFactor;
        std::vector<float> mvInvScaleFactor;
        std::vector<float> mvLevelSigma2;
        std::vector<float> mvInvLevelSigma2;

        std::vector<std::vector<double>> mvEntropiesPyramid;
    };

} //namespace ORB

#endif
