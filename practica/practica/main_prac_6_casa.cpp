// Semestre 2018 - 1
//****************************************************************************//
//****************************************************************************//
//************** Alumno (s): *************************************************//
//*************	González Vicente Juan Carlos			Grupo:1	******//
//*************		Visual Studio Community 2017		**************//
//*************			Version	15.3.2			**************//
//****************************************************************************//
//****************************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int Tierra = 0;
int Luna = 0;
int Marte = 0;
int Jupiter = 0;
int Saturno = 0;
int Urano = 0;
int Neptuno = 0;
int Pluton = 0;

float camaraZ = -15.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix();

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
								//glutSolidSphere(1.9,12,12);  //Draw Sun (radio,horizontal,vertical);
	glutWireSphere(1.9, 15, 15);  //Draw Sun (radio,H,V);

	glPopMatrix();

	// mercurioo
	glPushMatrix();

	glColor3f(0.545, 0.251, 0.075);
	glRotatef(90, 1.0, 1.0, 1.0);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glutWireSphere(0.3, 15, 15);

	glPopMatrix();

	// venus
	glPushMatrix();

	glColor3f(0.957, 0.643, 0.376);
	glRotatef(45, 1.0, 0.0, 1.0);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glTranslatef(3.5, 0.2, 0.2);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glutWireSphere(0.4, 15, 15);

	glPopMatrix();

	// Tierra
	glPushMatrix();

	glColor3f(0.5, 0.643, 0.376);
	glRotatef(100, 0.0, 1.0, 1.0);
	glRotatef(Tierra, 0.0, 1.0, 0.0);
	glTranslatef(5.2, 0.2, 0.2);
	glPushMatrix();
	glRotatef(Tierra, 0.0, 1.0, 0.0);
	glutWireSphere(0.5, 15, 15);
	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 2, 0.0, 0.0, 1);
	glutWireSphere(0.2, 15, 15);

	glPopMatrix();

	glPopMatrix();

	// marte
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glRotatef(-50, 0.0, 0.0, 1.0);
	glRotatef(Marte, 0.0, 1.0, 0.0);
	glTranslatef(7, 0.2, 0.2);
	glRotatef(Marte, 0.0, 1.0, 0.0);
	glutWireSphere(0.45, 15, 15);

	glPopMatrix();

	// Jupiter
	glPushMatrix();

	glColor3f(1.0, 1.0, 0.5);
	glRotatef(60, 1.0, 1.0, 0.0);
	glRotatef(Jupiter, 0.0, 1.0, 0.0);
	glTranslatef(10, 0.2, 0.2);
	glPushMatrix();
	glRotatef(Jupiter, 0.0, 1.0, 0.0);
	glutWireSphere(0.9, 15, 15);
	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 2, 0.0, 0.0, 1);
	glutWireSphere(0.2, 15, 15);

	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna + 90, 1.0, 0.0, 0.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 4, 0.0, 0.0, 1);
	glutWireSphere(0.2, 15, 15);

	glPopMatrix();

	glPopMatrix();

	// Saturno
	glPushMatrix();

	glColor3f(0.0, 0.5, 0.5);
	glRotatef(-90, 0.0, 1.0, 1.0);
	glRotatef(Saturno, 0.0, 1.0, 0.0);
	glTranslatef(13, 0.2, 0.2);
	glRotatef(Saturno, 0.0, 1.0, 0.0);
	glutWireSphere(0.7, 15, 15);
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.5);
	glutSolidTorus(0.2, 1.2, 20, 20);
	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 2, 0.0, 0.0, 1);
	glutWireSphere(0.2, 15, 15);

	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna + 180, 1.0, 0.0, 0.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna, 0.0, 0.0, 1);
	glutWireSphere(0.2, 15, 15);

	glPopMatrix();

	glPopMatrix();

	// Urano
	glPushMatrix();

	glColor3f(0.5, 0.7, 0.5);
	glRotatef(70, 1.0, 0.0, 1.0);
	glRotatef(Urano, 0.0, 1.0, 0.0);
	glTranslatef(16, 0.2, 0.2);
	glRotatef(Urano, 0.0, 1.0, 0.0);
	glutWireSphere(0.6, 15, 15);

	glPopMatrix();

	// Neptuno
	glPushMatrix();

	glColor3f(0.5, 0.7, 0.3);
	glRotatef(-30, 1.0, 0.0, 0.0);
	glRotatef(Neptuno, 0.0, 1.0, 0.0);
	glTranslatef(18, 0.2, 0.2);
	glRotatef(Neptuno, 0.0, 1.0, 0.0);
	glutWireSphere(0.55, 15, 15);

	glPopMatrix();

	// Pluton
	glPushMatrix();

	glColor3f(0.1, 0.1, 0.1);
	glRotatef(-45, 0.0, 0.0, 1.0);
	glRotatef(Pluton, 0.0, 1.0, 0.0);
	glTranslatef(20, 0.2, 0.2);
	glRotatef(Pluton, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 15, 15);

	glPopMatrix();

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{

		sol = (sol - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;

		mercurio = (mercurio - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;

		venus = (venus - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Tierra = (Tierra - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Luna = (Luna - 10) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Marte = (Marte - 12) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Jupiter = (Jupiter - 14) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Saturno = (Saturno - 16) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Urano = (Urano - 18) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Neptuno = (Neptuno - 20) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Pluton = (Pluton - 22) % 360;

		dwLastUpdateTime = dwCurrentTime;

	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
