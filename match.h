#ifndef MATCH
#define MATCH

#include "utils.h"
#include "ncc.h"
#include "feature.h"
#include "delaunay.h"

extern double image_scale;
//typedef std::pair<int, int> ipair;

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     std::vector<Match>& matches,
                     const int window_radius=8, const int search_radius=10, const double mcc_threshold=0.8);

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     const std::vector<Match>& seeds, std::vector<Match>& matches,
                     const int window_radius=8, const int search_radius=10, const double mcc_threshold=0.8);

void performMatching(const cv::Mat& img1, const cv::Mat& img2, const std::vector<cv::Point2f>& gridpoints,
                     const std::vector<Match>& seeds, std::vector<Match>& matches,
                     const int window_radius=8, const int search_radius=10, const double mcc_threshold=0.8);

void ftfMatchImpl(const cv::Mat &img1, const cv::Mat &img2,
                  const std::vector<cv::Point2f> &lpts, const std::vector<cv::Point2f> &rpts,
                  std::vector<std::vector<int> > t2f, std::vector<std::vector<double> > affinePars,
                  std::vector<Correspondence> &matches,  const int window_radius=8, const int search_radius=10, const double mcc_threshold=0.8,
                  const cv::Mat &img1_del=cv::Mat(), const cv::Mat &img2_del=cv::Mat());

void writeCorrespondences(const std::vector<Match>& matches,char* path);

void genFeature2TriangleTable(const std::vector<cv::Point2f>& features,
                              const Delaunay& tris,
                              std::vector<int>& f2t, std::vector<std::vector<int> >& t2f);

void showFeatureInsideTriangles(const cv::Mat& img, const std::vector<cv::Point2f>& features,
                                const Delaunay& tris, const std::vector<std::vector<int> >& t2f);

void constructContour(const cv::Point2f& center, const int searchRadius, std::vector<cv::Point2f>& contour);

void constructContour(const cv::Point2f& center, const int searchRadius, cv::Rect& contour);

void one2oneCheck(const std::vector<Correspondence> &src, std::vector<Correspondence> &dst);

void inverseCheck(const std::vector<Correspondence> &matches12, const std::vector<Correspondence> &matches21, std::vector<Correspondence> &matches);

#endif // MATCH

