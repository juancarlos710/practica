// Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float	anghombro = 0.0f;
float	angcodo = 0.0f;
float	angmano = 0.0f;

float	angpulgar1 = 0.0f;
float	angpulgar2 = 0.0f;
float	angpulgar3 = 0.0f;

float	angIndice1 = 0.0f;
float	angIndice2 = 0.0f;
float	angIndice3 = 0.0f;

float	angMedio1 = 0.0f;
float	angMedio2 = 0.0f;
float	angMedio3 = 0.0f;

float	angAnular1 = 0.0f;
float	angAnular2 = 0.0f;
float	angAnular3 = 0.0f;

float	angMenique1 = 0.0f;
float	angMenique2 = 0.0f;
float	angMenique3 = 0.0f;


GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

														//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner C�digo Aqu�.


	// brazo detallada
	glPushMatrix();

		// controla hombro
		glRotatef(anghombro, 0,0,1);
		// hombro
		glPushMatrix();
			glColor3f(0,1,0);
			glScalef(0.5, 0.5, 1);
			prisma();
		glPopMatrix();

		// bicep
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1,0,0);
			
			glScalef(0.5, 1, 1);
			prisma();
		glPopMatrix();

		// codo
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angcodo, 0,0,1);
		glPushMatrix();
			glColor3f(0, 0, 1);
			glScalef(0.5, 0.5, 1);
			prisma();
		glPopMatrix();

		// antebrazo
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1, 1, 0);
			glScalef(0.5, 1, 1);
			prisma();
		glPopMatrix();

		// mano
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angmano, 0,0,1);
		glPushMatrix();
			glColor3f(0, 1, 1);
			glScalef(0.5, 0.5, 1);
			prisma();
		glPopMatrix();

		// pulgar
		// dedo 1
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.0);
			glRotatef(angpulgar1, 0, 0, 1);
			glTranslatef(0.1,0, 0);
			

			glColor3f(0.3, 0.5, 0);
			// parte 1
			glPushMatrix();
				glScalef(0.2, 0.1, 1);
				prisma();
			glPopMatrix();

			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angpulgar2,0,0,1);
			glTranslatef(0.1,0,0);
			glColor3f(0.3, 0.7, 0);
			// parte 2
			glPushMatrix();
				glScalef(0.2, 0.1, 1);
				prisma();
			glPopMatrix();
			
		glPopMatrix();

		// Indice
		// dedo 2
		glPushMatrix();
				glTranslatef(0.1, -0.25, 0.0);
				glRotatef(angIndice1, 1, 0, 0);
				glTranslatef(0.1, -0.1, 0);
				glColor3f(0.3, 0.5, 0);
			// parte 1
			glPushMatrix();
				glScalef(0.1, 0.2, 1);
				prisma();
			glPopMatrix();

				glTranslatef(0, -0.1, 0.0);
				glRotatef(angIndice2, 1, 0, 0);
				glTranslatef(0, -0.1, 0);
				glColor3f(0.7, 0.7, 0);
			// parte 2
			glPushMatrix();
				glScalef(0.1, 0.2, 1);
				prisma();
			glPopMatrix();

				glTranslatef(0, -0.1, 0.0);
				glRotatef(angIndice3, 1, 0, 0);
				glTranslatef(0, -0.1, 0);
				glColor3f(0.1, 0.7, 0);
			// parte 3
			glPushMatrix();
				glScalef(0.1, 0.2, 1);
				prisma();
			glPopMatrix();
			glPopMatrix();

			// Medio
			// dedo 3
			glPushMatrix();
					glTranslatef(0.03333333333333333, -0.25, 0.0);
					glRotatef(angMedio1, 1, 0, 0);
					glTranslatef(0.03333333333333333, -0.15, 0);
					glColor3f(0.1, 0.1, 0.1);
				// parte 1
				glPushMatrix();
					glScalef(0.1, 0.3, 1);
					prisma();
				glPopMatrix();

					glTranslatef(0, -0.15, 0.0);
					glRotatef(angMedio2, 1, 0, 0);
					glTranslatef(0, -0.15, 0);
					glColor3f(0.2, 0.2, 0.2);
				// parte 2
				glPushMatrix();
					glScalef(0.1, 0.3, 1);
					prisma();
				glPopMatrix();

					glTranslatef(0, -0.15, 0.0);
					glRotatef(angMedio3, 1, 0, 0);
					glTranslatef(0, -0.15, 0);
					glColor3f(0.3, 0.3, 0.3);
				// parte 3
				glPushMatrix();
					glScalef(0.1, 0.3, 1);
					prisma();
				glPopMatrix();


		glPopMatrix();

		// Anular
		// dedo 4
		glPushMatrix();
				glTranslatef(-0.03333333333333333, -0.25, 0.0);
				glRotatef(angAnular1, 1, 0, 0);
				glTranslatef(-0.03333333333333333, -0.1, 0);
				glColor3f(0.1, 0.5, 0.5);
			// parte 1
			glPushMatrix();
				glScalef(0.1, 0.2, 1);
				prisma();
			glPopMatrix();

				glTranslatef(0, -0.1, 0.0);
				glRotatef(angAnular2, 1, 0, 0);
				glTranslatef(0, -0.1, 0);
				glColor3f(0.1, 0.6, 0.6);
			// parte 2
			glPushMatrix();
				glScalef(0.1, 0.2, 1);
				prisma();
			glPopMatrix();

				glTranslatef(0, -0.1, 0.0);
				glRotatef(angAnular3, 1, 0, 0);
				glTranslatef(0, -0.1, 0);
				glColor3f(0.1, 0.7, 0.7);
			// parte 3
			glPushMatrix();
				glScalef(0.1, 0.2, 1);
				prisma();
			glPopMatrix();

		glPopMatrix();

		// Menique
		// dedo 2
				glPushMatrix();
				glTranslatef(-0.1, -0.25, 0.0);
				glRotatef(angMenique1, 1, 0, 0);
				glTranslatef(-0.1, -0.05, 0);
				glColor3f(0.7, 0.5, 0.6);
			// parte 1
			glPushMatrix();
				glScalef(0.1, 0.1, 1);
				prisma();
			glPopMatrix();

				glTranslatef(0, -0.05, 0.0);
				glRotatef(angMenique2, 1, 0, 0);
				glTranslatef(0, -0.05, 0);
				glColor3f(0.6, 0.4, 0.5);
			// parte 2
			glPushMatrix();
				glScalef(0.1, 0.1, 1);
				prisma();
			glPopMatrix();

				glTranslatef(0, -0.05, 0.0);
				glRotatef(angMenique3, 1, 0, 0);
				glTranslatef(0, -0.05, 0);
				glColor3f(0.6, 0.3, 0.4);
			// parte 3
			glPushMatrix();
				glScalef(0.1, 0.1, 1);
				prisma();
			glPopMatrix();
			glPopMatrix();


		glPopMatrix();

	
	glPopMatrix();

	//prisma();


	glutSwapBuffers();
	// Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
		// manipulacion de brazo

	case 'q':
	case 'Q':
		anghombro += 0.5f;
		break;
	case 'w':
	case 'W':
		anghombro -= 0.5f;
		break;


	case 'e':
	case 'E':
		angcodo += 0.5f;
		break;
	case 'r':
	case 'R':
		angcodo -= 0.5f;
		break;


	case 't':
	case 'T':
		angmano += 0.5f;
		break;
	case 'y':
	case 'Y':
		angmano -= 0.5f;
		break;


	case 'u':
	case 'U':
		angpulgar1 += 0.5f;
		break;
	case 'i':
	case 'I':
		angpulgar1 -= 0.5f;
		break;


	case 'o':
	case 'O':
		angpulgar2 += 0.5f;
		break;
	case 'p':
	case 'P':
		angpulgar2 -= 0.5f;
		break;


	case 'a':
	case 'A':
		angIndice1 += 0.5f;
		break;

	case 's':
	case 'S':
		angIndice1 -= 0.5f;
		break;

	case 'd':
	case 'D':
		angIndice2 += 0.5f;
		break;

	case 'f':
	case 'F':
		angIndice2 -= 0.5f;
		break;

	case 'g':
	case 'G':
		angIndice3 += 0.5f;
		break;

	case 'h':
	case 'H':
		angIndice3 -= 0.5f;
		break;

	case 'j':
	case 'J':
		angMedio1 += 0.5f;
		break;

	case 'k':
	case 'K':
		angMedio1 -= 0.5f;
		break;

	case 'z':
	case 'Z':
		angMedio2 += 0.5f;
		break;

	case 'x':
	case 'X':
		angMedio2 -= 0.5f;
		break;

	case 'c':
	case 'C':
		angMedio3 += 0.5f;
		break;

	case 'v':
	case 'V':
		angMedio3 -= 0.5f;
		break;

	case 'b':
	case 'B':
		angAnular1 += 0.2f;
		break;

	case 'n':
	case 'N':
		angAnular1 -= 0.2f;
		break;

	case 'm':
	case 'M':
		angAnular2 += 0.2f;
		break;

	case 44:
		angAnular2 -= 0.2f;
		break;

	case '9':
		angAnular3 += 0.2f;
		break;

	case '0':
		angAnular3 -= 0.2f;
		break;

	case '1':
		angMenique1 += 0.2f;
		break;

	case '2':
		angMenique1 -= 0.2f;
		break;

	case '3':
		angMenique2 += 0.2f;
		break;

	case '4':
		angMenique2 -= 0.2f;
		break;

	case '5':
		angMenique3 += 0.2f;
		break;

	case '6':
		angMenique3 -= 0.2f;
		break;

	case '7':
	
		transX += 0.2f;
		break;

	case '8':

		transX -= 0.2f;
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
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
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}
