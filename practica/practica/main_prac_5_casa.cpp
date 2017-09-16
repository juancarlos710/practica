// Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	González Vicente Juan Carlos			Grupo:1							******//
//*************		Visual Studio Community 2017		******//
//*************				Version	15.3.2				******//
//************************************************************//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float	anghombro = 90.0f;
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
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
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
	//Poner Código Aquí.

	glPushMatrix();

	// Cabesa
	glPushMatrix();

	glColor3f(1, 0, 0);
	//(0,0,0)		
	prisma();

	glPopMatrix();

	// cuello
	glPushMatrix();

	glTranslatef(0, -0.75, 0);
	glScalef(0.5, 0.5, 1);
	glColor3f(0, 1, 0);
	prisma();

	glPopMatrix();

	// torso
	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(0, -2.5, 0);
	glScalef(3, 3, 1);
	glColor3f(0, 0, 1);
	prisma();

	glPopMatrix();

	//brazo derecho
	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(-3, -1.5, 0);
	glScalef(3, 1, 1);
	glColor3f(1, 1, 0);
	prisma();

	glPopMatrix();

	// mano derecha
	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(-4.5, -1.5, 0);
	glScalef(2, 2, 1);
	glColor3f(1, 1, 0);
	prisma();

	glPopMatrix();

	// pierna derecha

	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(-0.75, -7.5, 0);
	glScalef(1, 7, 1);
	glColor3f(1, 1, 0);
	prisma();

	glPopMatrix();

	// pie derecho
	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(-1.75, -12.5, 0);
	glScalef(3, 3, 1);
	glColor3f(1, 1, 0);
	prisma();

	glPopMatrix();

	// pierna derecha

	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(0.75, -7.5, 0);
	glScalef(1, 7, 1);
	glColor3f(1, 1, 0);
	prisma();

	glPopMatrix();
	////////
	// pie derecho
	glPushMatrix();
	//(0,-2.5,0)
	glTranslatef(1.75, -12.5, 0);
	glScalef(3, 3, 1);
	glColor3f(1, 1, 0);
	prisma();

	glPopMatrix();


	glPopMatrix();


	// brazo detallada
	glPushMatrix();

		// controla hombro
		glTranslatef(1.75, -1.5, 0);
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
		if (anghombro <= 180.0) {

			anghombro += 0.5f;
		
		}
		else {

			anghombro = 180;

		}

		break;
	case 'w':
	case 'W':

		if (anghombro >= 0.0) {

			anghombro -= 0.5f;
		
		}
		else {

			anghombro = 0.0f;

		}

		break;


	case 'e':
	case 'E':

		if (angcodo <= 135.0) {

			angcodo += 0.5f;
		
		}
		else {

			angcodo = 135.0f;

		}

		break;
	case 'r':
	case 'R':

		if (angcodo >= 0.0) {

			angcodo -= 0.5f;

		}
		else {

			angcodo = 0.0f;

		}
		
		break;


	case 't':
	case 'T':

		if (angmano <= 30.0) {

			angmano += 0.5f;

		}
		else {

			angmano = 30.0f;

		}

		break;
	case 'y':
	case 'Y':
		
		if (angmano >= -45.0) {

			angmano -= 0.5f;

		}
		else {

			angmano = -45.0f;

		}

		break;


	case 'u':
	case 'U':

		if (angpulgar1 <= 0.0) {
		
			angpulgar1 += 0.5f;
		
		}

		
		break;
	case 'i':
	case 'I':

		if (angpulgar1 >= -90.0)
		angpulgar1 -= 0.5f;
		
		
		break;


	case 'o':
	case 'O':

		if (angpulgar2 <= 0.0)
		angpulgar2 += 0.5f;
		break;
	case 'p':
	case 'P':
		if (angpulgar2 >= -90.0)
		angpulgar2 -= 0.5f;
		break;


	case 'a':
	case 'A':
		if (angIndice1 <= 0.0)
		angIndice1 += 0.5f;
		break;

	case 's':
	case 'S':
		if (angIndice1 >= -90.0)
		angIndice1 -= 0.5f;
		break;

	case 'd':
	case 'D':
		if (angIndice2 <= 0.0)
		angIndice2 += 0.5f;
		break;

	case 'f':
	case 'F':
		if (angIndice2 >= -90.0)
		angIndice2 -= 0.5f;
		break;

	case 'g':
	case 'G':
		if (angIndice3 <= 0.0)
		angIndice3 += 0.5f;
		break;

	case 'h':
	case 'H':
		if (angIndice3 >= -90.0)
		angIndice3 -= 0.5f;
		break;

	case 'j':
	case 'J':
		if (angMedio1 <= 0.0)
		angMedio1 += 0.5f;
		break;

	case 'k':
	case 'K':
		if (angMedio1 >= -90.0)
		angMedio1 -= 0.5f;
		break;

	case 'z':
	case 'Z':
		if (angMedio2 <= 0.0)
		angMedio2 += 0.5f;
		break;

	case 'x':
	case 'X':
		if (angMedio2 >= -90.0)
		angMedio2 -= 0.5f;
		break;

	case 'c':
	case 'C':
		if (angMedio3 <= 0.0)
		angMedio3 += 0.5f;
		break;

	case 'v':
	case 'V':
		if (angMedio3 >= -90.0)
		angMedio3 -= 0.5f;
		break;

	case 'b':
	case 'B':
		if (angAnular1 <= 0.0)
		angAnular1 += 0.2f;
		break;

	case 'n':
	case 'N':
		if (angAnular1 >= -90.0)
		angAnular1 -= 0.2f;
		break;

	case 'm':
	case 'M':
		if (angAnular2 <= 0.0)
		angAnular2 += 0.2f;
		break;

	case 44:
		if (angAnular2 >= -90.0)
		angAnular2 -= 0.2f;
		break;

	case '9':
		if (angAnular3 <= 0.0)
		angAnular3 += 0.2f;
		break;

	case '0':
		if (angAnular3 >= -90.0)
		angAnular3 -= 0.2f;
		break;

	case '1':
		if (angMenique1 <= 0.0)
		angMenique1 += 0.2f;
		break;

	case '2':
		if (angMenique1 >= -90.0)
		angMenique1 -= 0.2f;
		break;

	case '3':
		if (angMenique2 <= 0.0)
		angMenique2 += 0.2f;
		break;

	case '4':
		if (angMenique2 >= -90.0)
		angMenique2 -= 0.2f;
		break;

	case '5':
		if (angMenique3 <= 0.0)
		angMenique3 += 0.2f;
		break;

	case '6':
		if (angMenique3 >= -90.0)
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
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}
