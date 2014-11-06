/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<iostream>
using namespace std;

/* Global variables */
char title[] = "3D Shapes";

/*Define some colors*/
float  brown[]  = {.5429 ,.2695 ,.074};
float white[] = {1,1,1};
float black[] = {0,0,0};




/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(.75f, .5f, .5f, 0.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void DrawCube(float * color ){

    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
   glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    glColor3f(color[0],color[1],color[2]);
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)

}
void DrawTiles(int colorflag,float x,float y,float z) {
   float cubefacecolor[] = {0,0,0};
    glScalef(1,1,1);
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(x, y, z);  // Move right and into the screen


   //colorflag = 1 => white cube
   //colorflag =  0 => black cube
    if(colorflag == 1){
            //cout<<"here";
        cubefacecolor[0] = 1;
        cubefacecolor[1] = 1;
        cubefacecolor[2] = 1;
    }


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
       DrawCube(cubefacecolor);
   glEnd();  // End of drawing color-cube
}



void DrawFloor(int width, int length,float baseX,float baseY) {
    int i,j;


    for(i=0;i<length;i++)
        for(j=0;j<width;j++)

            DrawTiles((i+j)%2, baseX + i  ,baseY + j ,-6);


}

void DrawTableTop(float x,float y,float z) {
    float color[] = {.4,.2,.2};
   glLoadIdentity();                 // Reset the model-view matrix

   glTranslatef(x, y, z);  // Move right and into the screen
    glScalef(2,.25,2);


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
    DrawCube(color);
   glEnd();  // End of drawing color-cube
}

void DrawTableLeg(float x,float y,float z) {
   float color[] = {.4,.2,.2};
   glLoadIdentity();         // Reset the model-view matrix

   glTranslatef(x,y,z);  // Move left and into the screen
   glScalef(.1,2,.1);


   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      DrawCube(color);

   glEnd();  // End of drawing color-cube
}


/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors

    DrawTableTop(0,4,-6);//co-ordinates
     //DrawTableTop(0,4,-10);//co-ordinates
       DrawTableTop(0,4,-14);//co-ordinates

    DrawTableLeg(1.8,0,-5.8);//co-ordinates
    DrawTableLeg(1.8,0,-7.8);//co-ordinates
     DrawTableLeg(-1.8,0,-5.8);//co-ordinates
    DrawTableLeg(-1.8,0,-7.8);//co-ordinates
   // DrawFloor(7,7,-5,-5); //width,height,xy position


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}




/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
 //  gluLookAt(0.0, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, -1.0); // Default Camera Position
   gluPerspective(90.0f, aspect, 0.1f, 100.0f);

}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {

   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}