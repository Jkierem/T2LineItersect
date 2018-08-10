#ifndef __JUAN__H__
#define __JUAN__H__

#include <vector>
#include <random>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Aff_transformation_2.h>

typedef CGAL::Simple_cartesian<float> Kernel;
typedef CGAL::Aff_transformation_2<Kernel> Transformation;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Vector_2 Vector_2;
typedef Kernel::Segment_2 Segment_2;

typedef std::vector<Point_2> Cloud;
typedef std::vector<Segment_2> Hull;

namespace Juan {
  struct Ellipse {
    Point_2 center;
    float r1;
    float r2;
    float angle;
  };
  Transformation getRotationMatrix(float d);
  Transformation getScaleMatrix(float sx , float sy);
  Transformation getTranslationMatrix( float tx , float ty);
  Cloud generateRandomPoints(int n , Juan::Ellipse e);
  Hull generateRandomLines( Cloud dots );
  Cloud shuffleCloud( Cloud dots );
} /* Juan */

#endif
