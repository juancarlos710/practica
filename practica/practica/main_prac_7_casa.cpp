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

GLfloat merDiffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };			// Mercurio
GLfloat merSpecular[] = { 0.8, 0.0, 0.2, 1.0 };
GLfloat merShininess[] = { 50.0 };

GLfloat venusDiffuse[] = { 1.0f, 1.0f, 204 / 255, 1.0f };			// Venus
GLfloat venusSpecular[] = { 1.0, 1.0, 153/255, 1.0 };
GLfloat venusShininess[] = { 50.0 };

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 199/255, 150/255, 110/255, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 199 / 255, 150 / 255, 110 / 255, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 236 / 255, 217 / 203, 110 / 255, 1.0f };			// Saturno
GLfloat SaturnoSpecular[] = { 236 / 255, 217 / 203, 110 / 255, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat AnilloDiffuse[] = { 159 / 255, 159 / 255, 159 / 255, 1.0f };			// Anillo
GLfloat AnilloSpecular[] = { 159 / 255, 159 / 255, 159 / 255, 1.0 };
GLfloat AnilloShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 138 / 255, 197 / 255, 253 / 255, 1.0f };			// Urano
GLfloat UranoSpecular[] = { 138 / 255, 197 / 255, 253 / 255, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NeptunoDiffuse[] = { 87 / 255, 232 / 255, 210 / 255, 1.0f };			// Neptuno
GLfloat NeptunoSpecular[] = { 87 / 255, 232 / 255, 210 / 255, 1.0 };
GLfloat NeptunoShininess[] = { 50.0 };

GLfloat PlutonDiffuse[] = { 168 / 255, 143 / 255, 136 / 255, 1.0f };			// Pluton
GLfloat PlutonSpecular[] = { 168 / 255, 143 / 255, 136 / 255, 1.0 };
GLfloat PlutonShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);

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
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(1.9, 15, 15);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);

	glPopMatrix();

	// mercurioo
	glPushMatrix();

	glColor3f(0.545, 0.251, 0.075);
	glRotatef(90, 1.0, 1.0, 1.0);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, merDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, merSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, merShininess);
	glutSolidSphere(0.3, 15, 15);

	glPopMatrix();

	// venus
	glPushMatrix();

	glColor3f(0.957, 0.643, 0.376);
	glRotatef(45, 1.0, 0.0, 1.0);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glTranslatef(3.5, 0.2, 0.2);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, venusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, venusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, venusShininess);
	glutSolidSphere(0.4, 15, 15);

	glPopMatrix();

	// Tierra
	glPushMatrix();

	glColor3f(0.5, 0.643, 0.376);
	glRotatef(100, 0.0, 1.0, 1.0);
	glRotatef(Tierra, 0.0, 1.0, 0.0);
	glTranslatef(5.2, 0.2, 0.2);
	glPushMatrix();
	glRotatef(Tierra, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(0.5, 15, 15);
	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 2, 0.0, 0.0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.2, 15, 15);

	glPopMatrix();

	glPopMatrix();

	// marte
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glRotatef(-50, 0.0, 0.0, 1.0);
	glRotatef(Marte, 0.0, 1.0, 0.0);
	glTranslatef(7, 0.2, 0.2);
	glRotatef(Marte, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutSolidSphere(0.45, 15, 15);

	glPopMatrix();

	// Jupiter
	glPushMatrix();

	glColor3f(1.0, 1.0, 0.5);
	glRotatef(60, 1.0, 1.0, 0.0);
	glRotatef(Jupiter, 0.0, 1.0, 0.0);
	glTranslatef(10, 0.2, 0.2);
	glPushMatrix();
	glRotatef(Jupiter, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
	glutSolidSphere(0.9, 15, 15);
	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna, 0.0, 0.0, 1.0);
	glTranslatef(0.9, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 2, 0.0, 0.0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.2, 15, 15);

	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna + 90, 1.0, 0.0, 0.0);
	glTranslatef(0.9, 0.8, 0.2);
	// rotacion
	glRotatef(Luna + 4, 0.0, 0.0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.2, 15, 15);

	glPopMatrix();

	glPopMatrix();

	// Saturno
	glPushMatrix();

	glColor3f(0.0, 0.5, 0.5);
	glRotatef(-90, 0.0, 1.0, 1.0);
	glRotatef(Saturno, 0.0, 1.0, 0.0);
	glTranslatef(13, 0.2, 0.2);
	glRotatef(Saturno, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
	glutSolidSphere(0.7, 15, 15);
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, AnilloDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, AnilloSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, AnilloShininess);
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
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.2, 15, 15);

	glPopMatrix();

	// Luna
	glPushMatrix();

	glColor3f(0.5, 0.5, 0.5);
	// traslacion
	glRotatef(Luna + 180, 1.0, 0.0, 0.0);
	glTranslatef(0.2, 0.8, 0.2);
	// rotacion
	glRotatef(Luna, 0.0, 0.0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.2, 15, 15);

	glPopMatrix();

	glPopMatrix();

	// Urano
	glPushMatrix();

	glColor3f(0.5, 0.7, 0.5);
	glRotatef(70, 1.0, 0.0, 1.0);
	glRotatef(Urano, 0.0, 1.0, 0.0);
	glTranslatef(16, 0.2, 0.2);
	glRotatef(Urano, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
	glutSolidSphere(0.6, 15, 15);

	glPopMatrix();

	// Neptuno
	glPushMatrix();

	glColor3f(0.5, 0.7, 0.3);
	glRotatef(-30, 1.0, 0.0, 0.0);
	glRotatef(Neptuno, 0.0, 1.0, 0.0);
	glTranslatef(18, 0.2, 0.2);
	glRotatef(Neptuno, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, NeptunoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, NeptunoShininess);
	glutSolidSphere(0.55, 15, 15);

	glPopMatrix();

	// Pluton
	glPushMatrix();

	glColor3f(0.1, 0.1, 0.1);
	glRotatef(-45, 0.0, 0.0, 1.0);
	glRotatef(Pluton, 0.0, 1.0, 0.0);
	glTranslatef(20, 0.2, 0.2);
	glRotatef(Pluton, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, NeptunoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, NeptunoShininess);
	glutSolidSphere(0.2, 15, 15);

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

		mercurio = (mercurio - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;

		venus = (venus - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Tierra = (Tierra - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Luna = (Luna - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Marte = (Marte - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Jupiter = (Jupiter - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Saturno = (Saturno - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Urano = (Urano - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Neptuno = (Neptuno - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

		Pluton = (Pluton - 2) % 360;

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