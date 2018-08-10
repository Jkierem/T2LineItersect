#include "GEngine.h"

void GEngine::drawPoint(float x , float y){
  glColor3f(1,0,0);
  glPointSize(2);
  glBegin(GL_POINTS);
    glVertex2i( x , y );
  glEnd();
}

void GEngine::drawLine( float x1 , float y1, float x2 , float y2){
  glColor3f(0,1,0);
  glBegin(GL_LINES);
    glVertex2i( x1 , y1 );
    glVertex2i( x2 , y2 );
  glEnd();
}

void GEngine::drawDirectedLine( float x1 , float y1, float x2 , float y2){
  //glLineWidth(5);
  glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2i( x1 , y1 );
    glColor3f(0,0,1);
    glVertex2i( x2 , y2 );
  glEnd();
}
