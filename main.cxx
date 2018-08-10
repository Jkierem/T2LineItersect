#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>

#include "./src/Juan/Juan.h"
#include "./src/GEngine/GEngine.h"
#include "./src/Core/Core.h"

Juan::Ellipse ellipse;
int numberOfPoints;

void getConfigFromArgs(int argc , char* argv[]){
  numberOfPoints = atoi(argv[1]);
  if( numberOfPoints <= 0 ){
    numberOfPoints = 2;
  }
  numberOfPoints += numberOfPoints % 2;
  Juan::Ellipse e;
  e.r1 = atof(argv[2]);
  e.r2 = atof(argv[3]);
  e.angle = atof(argv[4]);
  if (argc == 7) {
    float x = atof(argv[5]);
    float y = atof(argv[6]);
    e.center = Point_2(x,y);
  }else{
    e.center = Point_2(300,300);
  }
  ellipse = e;
}

void getDefaultConfig(){
  numberOfPoints = 50;
  Juan::Ellipse e;
  e.r1 = 250;
  e.r2 = 130;
  e.center = Point_2(300,300);
  e.angle = 1;
  ellipse = e;
}

void init (void) {
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 600);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  std::vector<Point_2> dots = Juan::generateRandomPoints(numberOfPoints,ellipse);
  for( auto dot : dots ){
    GEngine::drawPoint( dot.x() , dot.y() );
  }
  Hull lines = Juan::generateRandomLines( dots );
  for( auto line : lines ){
    Point_2 src = line.source();
    Point_2 tar = line.target();
    GEngine::drawDirectedLine( src.x() , src.y() , tar.x() , tar.y() );
  }
  glFlush();
}

void resize (int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
}

int main(int argc , char* argv[]){
  if( argc == 1){
    getDefaultConfig();
  }else if( argc == 5 || argc == 7 ){
    getConfigFromArgs(argc,argv);
  }else{
    std::cout << "Invalid arguments. Usage:" << std::endl;
    std::cout << "\t lineintersect [numberOfPoints] [r1] [r2] [angle] [centerX] [centerY]" << "\n\n";
    std::cout << "All arguments are optional. If any of the arguments is supplied then all must be supplied excluding center arguments." << '\n';
    return 1;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Line Intersect");
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  init();
  glutMainLoop();
	return 0;
}
