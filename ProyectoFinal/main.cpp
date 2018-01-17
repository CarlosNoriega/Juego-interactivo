// primitives_opengl_main.cpp
// Quad centrado en el origen

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <list>
using namespace std;
// Tamaño de la ventana
GLint width = 800;
GLint height = 600;



GLfloat rr = 0;
list<int> pasos;
GLfloat x = 0.f;
bool rota = FALSE;
bool camina = FALSE;
bool fronte = TRUE;
//---------------------------------------------------------------------------------
int size = 10;
int upperFloor[10][10];
int lowerFloor[10][10];
int activeFloor[10][10];
int start = 101;
int obstacles = 200;
int fin = 1000;
int down = 300;
int up = 400;
int black = 500;

int posI;
int posJ;

int direction;
int front = 0;
int back = 2;
int left9 = 3;
int right3 = 1;

int currentLevel = 1;
//---------------------------------------------------------------------------------



// Parámetros de la cámara virtual


// Función que inicializa el Contexto OpenGL y la geometría de la escena
void init()
{
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glColor3f(1.f, 1.f, 1.f);
}


void rota90(){
	if (fronte){
		if (x < 180){
			x = (x + .05f);
		}
		else{
			fronte = !fronte;
			rota = FALSE;
			camina = TRUE;
		}
	}
	else{
		if (x < 360){
			x = (x + .05f);
		}
		else{
			fronte = !fronte;
			x = 0;
			rota = FALSE;
			camina = TRUE;
		}
	}
}
//-----------------------------------------------------------

void setActiveFloor(int matrix[10][10]){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			activeFloor[i][j] = matrix[i][j];
		}
	}
}


void initialize(){
	//fill matrices 1 - 100
	int fill = 1;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			upperFloor[i][j] = fill;
			lowerFloor[i][j] = fill++;
		}
	}

	//start position and direction
	posI = 9;
	posJ = 0;
	direction = front;
}

void level1(){
	rr = 0;
	initialize();
	int obstaclesUpper[] = { 8, 9, 11, 15, 19, 27, 29, 32, 34, 38, 49, 50, 51, 55, 70, 74, 88, 95 };
	int obstaclesLower[] = { 1, 7, 13, 18, 26, 29, 32, 38, 40, 47, 48, 55, 59, 62, 75, 92, 96 };

	//Obstáculos
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			int *pointerUpper = std::find(std::begin(obstaclesUpper), std::end(obstaclesUpper), upperFloor[i][j]);

			int *pointerLower = std::find(std::begin(obstaclesLower), std::end(obstaclesLower), upperFloor[i][j]);


			if (pointerUpper != std::end(obstaclesUpper)) {
				upperFloor[i][j] = obstacles;
			}

			if (pointerLower != std::end(obstaclesLower)) {
				lowerFloor[i][j] = obstacles;
			}
		}
	}

	//Inicio y fin
	upperFloor[9][0] = start;
	upperFloor[0][9] = fin;

	//jumps
	upperFloor[2][7] = down;
	lowerFloor[3][8] = up;

	//blacks
	upperFloor[3][8] = black;
	lowerFloor[2][7] = black;

	//ActiveFloor
	setActiveFloor(upperFloor);
	
}

void level2(){
	rr = 0;
	initialize();
	int obstaclesUpper[] = { 6, 13, 18, 22, 30, 31, 45, 48, 52, 63, 67, 71, 75, 76, 78, 85, 89, 96, 100 };
	int obstaclesLower[] = { 4, 10, 11, 12, 16, 18, 20, 23, 24, 27, 31, 37, 38, 39, 41, 43, 48, 52, 55, 58, 60, 62, 63, 66, 68, 73, 77, 79, 85, 88, 89, 98 };

	//Obstáculos
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			int *pointerUpper = std::find(std::begin(obstaclesUpper), std::end(obstaclesUpper), upperFloor[i][j]);

			int *pointerLower = std::find(std::begin(obstaclesLower), std::end(obstaclesLower), upperFloor[i][j]);


			if (pointerUpper != std::end(obstaclesUpper)) {
				upperFloor[i][j] = obstacles;
			}

			if (pointerLower != std::end(obstaclesLower)) {
				lowerFloor[i][j] = obstacles;
			}
		}
	}

	//Inicio y fin
	upperFloor[9][0] = start;
	upperFloor[8][5] = fin;

	//jumps
	upperFloor[2][0] = down;
	lowerFloor[9][8] = up;

	//blacks
	upperFloor[9][8] = black;
	lowerFloor[2][0] = black;

	//ActiveFloor
	setActiveFloor(upperFloor);

}

void level3(){
	rr = 0;
	initialize();
	int obstaclesUpper[] = { 1, 2, 14, 15, 16, 17, 18, 22, 27, 33, 34, 35, 37, 41, 45, 48, 49, 52, 53, 55, 57, 61, 67, 68, 70, 71, 73, 74, 75, 76, 83, 87, 88, 89, 92, 95 };
	int obstaclesLower[] = { 3, 7, 12, 15, 19, 22, 26, 27, 28, 33, 34, 38, 40, 41, 45, 46, 48, 54, 59, 62, 66, 67, 68, 69, 73, 74, 75, 79, 81, 82, 85, 87, 89, 97 };

	//Obstáculos
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			int *pointerUpper = std::find(std::begin(obstaclesUpper), std::end(obstaclesUpper), upperFloor[i][j]);

			int *pointerLower = std::find(std::begin(obstaclesLower), std::end(obstaclesLower), upperFloor[i][j]);


			if (pointerUpper != std::end(obstaclesUpper)) {
				upperFloor[i][j] = obstacles;
			}

			if (pointerLower != std::end(obstaclesLower)) {
				lowerFloor[i][j] = obstacles;
			}
		}
	}

	//Inicio y fin
	upperFloor[9][0] = start;
	upperFloor[5][0] = fin;

	//jumps
	upperFloor[9][2] = down;
	lowerFloor[5][0] = up;

	//blacks
	lowerFloor[9][2] = black;

	//ActiveFloor
	setActiveFloor(upperFloor);

}

void walk(){
	//Mover arriba
	if (direction == front){
		if (posI - 1 >= 0){
			if (activeFloor[posI - 1][posJ] != 200) {
				if (activeFloor[posI - 1][posJ] == 1000){
					posI = posI - 1;
					if (currentLevel == 1){
						currentLevel++;
						level2();
					}
					else if (currentLevel == 2){
						currentLevel++;
						level3();
					}
					else{
						//Gano!
					}

				}
				else if (activeFloor[posI - 1][posJ] == 300){
					posI = posI - 1;
					setActiveFloor(lowerFloor);
					rota = TRUE;
				}
				else if (activeFloor[posI - 1][posJ] == 400){
					posI = posI - 1;
					setActiveFloor(upperFloor);
					rota = TRUE;
				}
				else{
					posI = posI - 1;
				}
			}
		}
	}

	//Mover derecha
	else if (direction == right3){
		if (posJ + 1 <= 9){
			if (activeFloor[posI][posJ + 1] != 200) {
				if (activeFloor[posI][posJ + 1] == 1000){
					posJ = posJ + 1;
					if (currentLevel == 1){
						currentLevel++;
						level2();
					}
					else if (currentLevel == 2){
						currentLevel++;
						level3();
					}
					else{
						//Gano!
					}

				}
				else if (activeFloor[posI][posJ + 1] == 300){
					posJ = posJ + 1;
					setActiveFloor(lowerFloor);
					rota90();
				}
				else if (activeFloor[posI][posJ + 1] == 400){
					posJ = posJ + 1;
					setActiveFloor(upperFloor);
					rota90();
				}
				else{
					posJ = posJ + 1;
				}
			}
		}
	}

	//Mover abajo
	else if (direction == back){
		if (posI + 1 <= 9){
			if (activeFloor[posI + 1][posJ] != 200) {
				if (activeFloor[posI + 1][posJ] == 1000){
					posI = posI + 1;
					if (currentLevel == 1){
						currentLevel++;
						level2();
					}
					else if (currentLevel == 2){
						currentLevel++;
						level3();
					}
					else{
						//Gano!
					}
				}
				else if (activeFloor[posI + 1][posJ] == 300){
					posI = posI + 1;
					setActiveFloor(lowerFloor);
					rota = TRUE;
				}
				else if (activeFloor[posI + 1][posJ] == 400){
					posI = posI + 1;
					setActiveFloor(upperFloor);
					rota = TRUE;
				}
				else{
					posI = posI + 1;
				}
			}
		}
	}

	//Mover izquierda
	else if (direction == left9){
		if (posJ - 1 >= 0){
			if (activeFloor[posI][posJ - 1] != 200) {
				if (activeFloor[posI][posJ - 1] == 1000){
					posJ = posJ - 1;
					if (currentLevel == 1){
						currentLevel++;
						level2();
					}
					else if (currentLevel == 2){
						currentLevel++;
						level3();
					}
					else{
						//Gano!
					}
				}
				else if (activeFloor[posI][posJ - 1] == 300){
					posJ = posJ - 1;
					setActiveFloor(lowerFloor);
					rota = TRUE;
				}
				else if (activeFloor[posI][posJ - 1] == 400){
					posJ = posJ - 1;
					setActiveFloor(upperFloor);
					rota = TRUE;
				}
				else{
					posJ = posJ - 1;
				}
			}
		}
	}
}

void turn(){
	if (direction == front){
		direction = right3;
	}
	else if (direction == right3){
		direction = back;
	}
	else if (direction == back){
		direction = left9;
	}
	else{
		direction = front;
	}
}




//-----------------------------------------------------------

// Función que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
	if (h == 0)
	{
		h = 1;
	}
	width = w;
	height = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);		// Transf. de Proyección en Perspectiva
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height);								// Transf. de Viewport (mapeo al área de dibujo)
}


// Geometría Quad
void geomQuad(GLfloat size, GLenum face, GLenum mode)
{
	size = size / 2;
	glPolygonMode(face, mode);
	glBegin(GL_QUADS);
	glVertex2f(-size, size); // vertex 1
	glVertex2f(-size, -size); // vertex 2
	glVertex2f(size, -size); // vertex 3
	glVertex2f(size, size); // vertex 4
	glEnd();
}


void tablero(GLfloat size, GLenum face, GLenum mode){
	bool a = TRUE;
	if (x<90 || x>270)
	{
		a = TRUE;
	}
	else{
		a = FALSE;
	}
	if (a){
	glPushMatrix();
	glTranslatef((-size * 5) + (size / 2), (size * 5) - (size / 2) + size, 0.f);
	for (int i = 0; i < 10; i++)
	{
		glTranslatef(0.f, -size, 0.f);
		glPushMatrix();
		for (int j = 0; j < 10; j++)
		{
			if (upperFloor[i][j] == 101){ //inicio
				mode = GL_FILL;
				glColor3f(0.125f, 0.698f, 0.667f);
			}
			else if (upperFloor[i][j] == 200){ //obstacle
				mode = GL_FILL;
				glColor3f(0.863f, 0.078f, 0.235f);
			}

			else if (upperFloor[i][j] == 1000){ //fin
				mode = GL_FILL;
				glColor3f(0.f, 1.f, 0.f);
			}

			else if (upperFloor[i][j] == 300){ //down
				mode = GL_FILL;
				glColor3f(1.000, 1.000, 0.00);
			}

			else if (upperFloor[i][j] == 400){ //up
				mode = GL_FILL;
				glColor3f(1.000, 1.000, 0.00);
			}

			else if (upperFloor[i][j] == 500){ //black
				mode = GL_FILL;
				glColor3f(0.f, 0.f, 0.f);
			}
			else
			{
				mode = GL_FILL;
				glColor3f(0.878, 1.000, 1.000);
			}
			geomQuad(size, face, mode);
			glTranslatef(size, 0.f, 0.f);

		}
		glPopMatrix();

	}
	glPopMatrix();
	}
	else{
	glPushMatrix();
	glTranslatef((-size * 5) + (size / 2), (size * 5) - (size / 2) + size, -0.f);
	for (int i = 0; i < 10; i++)
	{
		glTranslatef(0.f, -size, 0.f);
		glPushMatrix();
		for (int j = 0; j < 10; j++)
		{
			if (lowerFloor[i][j] == 101){ //inicio
				mode = GL_FILL;
				glColor3f(0.125f, 0.698f, 0.667f);
			}
			else if (lowerFloor[i][j] == 200){ //obstacle
				mode = GL_FILL;
				glColor3f(0.863f, 0.078f, 0.235f);
			}

			else if (lowerFloor[i][j] == 1000){ //fin
				mode = GL_FILL;
				glColor3f(0.f, 1.f, 0.f);
			}

			else if (lowerFloor[i][j] == 300){ //down
				mode = GL_FILL;
				glColor3f(1.000, 1.000, 0.00);
			}

			else if (lowerFloor[i][j] == 400){ //up
				mode = GL_FILL;;
				glColor3f(1.000, 1.000, 0.00);
			}

			else if (lowerFloor[i][j] == 500){ //black
				mode = GL_FILL;
				glColor3f(0.f, 0.f, 0.f);
			}
			else
			{
				mode = GL_FILL;
				glColor3f(0.878, 1.000, 1.000);
			}
			geomQuad(size, face, mode);
			glTranslatef(size, 0.f, 0.f);

		}
		glPopMatrix();

	}
	glPopMatrix();
	}

}

void flecha(GLfloat size, GLenum face, GLenum mode){
	glPushMatrix();
	glScalef(size, size, size);
	glPolygonMode(face, mode);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0, -0.5, 0.0);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-1.0, 0.5, 0.0);
	glEnd();

	glPopMatrix();
}

void giro(GLfloat size, GLenum face, GLenum mode){
	glPushMatrix();
	glScalef(.7f*size,size,size);
	glTranslatef(.25,0,0);
	glPolygonMode(face, mode);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.5, -1, 0.0);
	glVertex3f(-.5, -1, 0.0);
	glVertex3f(-.5, -.5, 0.0);
	glVertex3f(0, -.5, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-1.5, .5, 0.0);
	glEnd();

	glPopMatrix();
}
int num = 0;
int cc = 0;
void caminando(){
	if (cc > 200){
		if (!pasos.empty())
		{
			num--;
			int p = pasos.front();
			pasos.pop_front();
			if (p == 1){
				walk();
			}
			else{
				turn();
				rr = rr - 90;
			}
			cc = 0;
		}
		
	}
	cc++;
}

void idle(){
	if (rota)
	{
		camina = FALSE;
		rota90();
	}
	if (camina){
		caminando();
	}
	glutPostRedisplay();
}


// Función que se invoca cada vez que se dibuja
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Se limpian los buffers con el color activo definido por glClearColor

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Transformación de vista
	glTranslatef(0, 0, -10);
	// Escena
	glColor3f(1.f, 1.f, 1.f);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glPushMatrix();
	glScalef(1.2f,1,1);
	geomQuad(4.7f, GL_FRONT_AND_BACK, GL_LINE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3f, -1.6f, 0);
	glScalef(1.05f, 1, 1);
	geomQuad(1.f, GL_FRONT_AND_BACK, GL_LINE);
	glScalef(.5f,.5f,.5f);
	flecha(1, GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, -1.6f, 0);
	glScalef(1.05f, 1, 1);
	geomQuad(1.f, GL_FRONT_AND_BACK, GL_LINE);
	glScalef(.5f, .5f, .5f);
	glRotatef(x, 0.f, 1.f, 0.f);
	giro(1, GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.14f, .65f, 0);
	glPushMatrix();
	glScalef(1.05f, 1, 1);
	geomQuad(3.2f, GL_FRONT_AND_BACK, GL_LINE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 1.2f, 0);
	int it=32;
	if (num<32)
	{
		it = num;
	}
	for (int i = 1; i <= it; i++)
	{
		auto l_front = pasos.begin();
		std::advance(l_front, (i-1));
		int sa = *l_front;
		if (sa==1)
		{
			flecha(.2, GL_FRONT_AND_BACK, GL_LINE);
		}
		else{
			giro(.2, GL_FRONT_AND_BACK, GL_LINE);
		}
		glTranslatef(0.f, -.5f, 0);
		if ((i%8) == 0 && i>0)
		{
			glTranslatef(0.5f, 4.f, 0);
		}
	}
	
	
	glPopMatrix();


	glPushMatrix();
	GLfloat s = x;
	glRotatef(s, 0.f, 1.f, 0.f);
	tablero(0.3f, GL_FRONT_AND_BACK, GL_FILL);
	glTranslatef((.3*posJ) - 1.35f, (-.3*posI) + 1.35f, .01);
	glScalef(1.5,.6,.6);
	glRotatef(90,0,0,1);
	glRotatef(rr, 0, 0, 1);
	glColor3f(0.580f, 0.000f, 0.827f);//  flechita
	flecha(.1, GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();




	glutSwapBuffers();			// Se intercambian buffers
}

void keyboard(unsigned char key, int x, int y){
	if (key == ' ')
	{
		camina = TRUE;
		glutPostRedisplay();
	}
	
}

void mouse(int button, int state, int x, int y)
{
	
	camina = FALSE;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if (510>x && x>369 && 584>y && y>450){

			pasos.push_back(1);
			num++;
		}
		if (741>x && x>600 && 584>y && y>450){
			pasos.push_back(2);
			num++;
			
		}
	}
	
}








int main(GLint argc, GLchar **argv)
{
	// 1. Se crea una ventana y un contexto OpenGL usando GLUT
	x = 0;
	level1();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Aplicacion educativa :)");

	// 1.2 Se definen las funciones callback para el manejo de eventos
	glutReshapeFunc(resize);
	glutDisplayFunc(render);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW Error");
		return false;
	}
	cout << "A darle atomos" << endl;
	init();
	glutMainLoop();
	return 0;
}