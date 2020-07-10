#include <gl/glut.h>
#include <stdlib.h>

void init(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0); // set the background to white

glMatrixMode(GL_PROJECTION);		// set projection parameters
glLoadIdentity();
gluOrtho2D(0.0,500.0,0.0,400.0);
}
void myLine(void)
{
	
glClear( GL_COLOR_BUFFER_BIT );	
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_LINES);				
glVertex2i(0, 0);			
glVertex2i( 200, 200);
				
glEnd();
glFlush();						
}

void myDisplay(void)
{
glClear( GL_COLOR_BUFFER_BIT );	
}
//-------------------------------------------------------------------
void menu(int ms)
{
	switch(ms)
	{
	case 1:myLine();
		break;
	case 2:exit(0);
		break;
	}
}
void set_up_menu(void)
{
	glutCreateMenu(menu);
glutAddMenuEntry("Line",1);
	glutAddMenuEntry("Exit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void main( int argc, char **argv)
{
glutInit(&argc, argv);						// Initialize GLUT
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); // Set display mode
glutInitWindowPosition(100,200);		// Set top-left display window position
glutInitWindowSize(320,320);		// Set display window width and height
glutCreateWindow("An Example");// Create display window
init(); 						// Execute initialization procedure
glutDisplayFunc(myDisplay);
set_up_menu();// Send graphics to display window
glutMainLoop();					// Display everything and wait
}
