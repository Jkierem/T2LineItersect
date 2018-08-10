#ifndef __G_ENGINE__
#define __G_ENGINE__

#include <GL/freeglut.h>
#include <GL/gl.h>

namespace GEngine {
  void drawPoint(float x , float y);
  void drawLine( float x1 , float y1, float x2 , float y2);
  void drawDirectedLine( float x1 , float y1, float x2 , float y2);
} /* GEngine */

#endif
