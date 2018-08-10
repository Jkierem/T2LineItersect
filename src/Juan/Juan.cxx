#include "Juan.h"
#include <random>
#include <algorithm>
#include <iostream>

Transformation Juan::getRotationMatrix(float d){
  Transformation t(cos(d),-1*sin(d),sin(d),cos(d),1);
  return t;
}

Transformation Juan::getScaleMatrix(float sx , float sy){
  Transformation t(sx,0,0,sy,1);
  return t;
}

Transformation Juan::getTranslationMatrix( float tx , float ty){
  Transformation t(1,0,tx,0,1,ty,1);
  return t;
}

std::vector<Point_2> Juan::generateRandomPoints( int n , Ellipse e){
  std::random_device device;
  std::mt19937 mt(device());
  std::uniform_real_distribution<double> rDist(0.0, 1.0);
  std::uniform_real_distribution<double> thetaDist(0.0, 2.0);
  std::vector<Point_2> dots;
  for (size_t i = 0; i < n; i++) {
    float r = rDist(mt);
    Point_2 p(r,0);
    float theta = thetaDist(mt)*M_PI;
    Transformation randomRotation = getRotationMatrix(theta);
    p = randomRotation(p);
    dots.push_back(p);
  }
  Transformation scale = getScaleMatrix(e.r1 , e.r2);
  Transformation rotate = getRotationMatrix(e.angle*M_PI);
  Transformation translate = getTranslationMatrix(e.center.x() , e.center.y());
  for( auto& dot : dots ){
    dot = translate(rotate(scale(dot)));
  }
  return dots;
}

Hull Juan::generateRandomLines( Cloud dots ){
  Hull lines;
  for (size_t i = 0; i < dots.size(); i+=2) {
    lines.push_back( Segment_2( dots[i], dots[i+1] ) );
  }
  return lines;
}

Cloud Juan::shuffleCloud( Cloud dots ){
  std::random_shuffle ( dots.begin(), dots.end() );
  return dots;
}
