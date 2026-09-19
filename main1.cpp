#ifdef	__APPLE__	
#include	<GLUT/glut.h>	
#else	
#include	<GL/freeglut.h>	
#endif	
	
void	display()	{	
				glClear(GL_COLOR_BUFFER_BIT);	
				glFlush();	
}	
	
int	main(int	argc,	char**	argv)	{	
				glutInit(&argc,	argv);	
				glutInitDisplayMode(GLUT_SINGLE	|	GLUT_RGB);	
				glutInitWindowSize(640,	480);	
				glutInitWindowPosition(100,	100);	
				glutCreateWindow("CSE	4202	-	OpenGL	Setup	Test");	
	
				glClearColor(0.08f,	0.16f,	0.25f,	1.0f);	
				glutDisplayFunc(display);	
				glutMainLoop();	
				return	0;	
} 