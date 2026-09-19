#ifdef	__APPLE__	
#include	<GLUT/glut.h>	
#else	
#include	<GL/freeglut.h>	
#endif	
	
void	display()	{	
				glClear(GL_COLOR_BUFFER_BIT);	
				glLoadIdentity();	
	
				//	Drawing	commands	go	here.	
	
				glFlush();	
}	
	
void	reshape(int	w,	int	h)	{	
				glViewport(0,	0,	w,	h);	
				glMatrixMode(GL_PROJECTION);	
				glLoadIdentity();	
				gluOrtho2D(-1.0,	1.0,	-1.0,	1.0);	
				glMatrixMode(GL_MODELVIEW);	
				glLoadIdentity();	
}	
	
int	main(int	argc,	char**	argv)	{	
				glutInit(&argc,	argv);	
				glutInitDisplayMode(GLUT_SINGLE	|	GLUT_RGB);	
				glutInitWindowSize(700,	700);	
				glutCreateWindow("CSE	4202	-	Lab	02");	
	
				glClearColor(0.97f,	0.98f,	1.0f,	1.0f);	
				glutDisplayFunc(display);	
				glutReshapeFunc(reshape);	
				glutMainLoop();	
				return	0;	
}