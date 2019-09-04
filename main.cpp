#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>

#define PI 3.1416

static float	tx1	=  0.0; //enemy1
static float	ty1	=  0.0;

static float	txE1	=  -320;
static float	tyE1	=  -100;


static float	tx2	=  200; //enemy2
static float	ty2	=  -200;

static float	txE2	=  -200;
static float	tyE2	=  200;

static float	tx3	=  200.0;
static float	ty3	=  200.0;

static float	tx4	=  -150.0;
static float	ty4	=  -150.0;


static float	dx	=  1.5;
static float	dy	=  2.5;

static float	dxE	=  0.5;
static float	dyE	=  2;

static float	dx2	=  3;
static float	dy2	=  1;

static float	dxE2	=  3;
static float	dyE2	=  2;

static float	dx3	=  3.5;
static float	dy3	=  4;

static float	dx4	=  4;
static float	dy4	=  3.5;

char str[20] = "Score: ";
char str1[10];
char duration[20] = "Time: ";
int tim = 60;
//char str2[10];
int score = 0;

static int mx=0, my=0;

void bomb()
{

    int i = 0;
	float angle = 0.0;
    //middle circle
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 3, sin(angle) * 3.5, 0);
		}

    glEnd();


    //head

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

        glVertex2d(2.5,2.5);
        glVertex2d(3.5,6);

        glVertex2d(2.5,2.5);
        glVertex2d(4.5,5);

        glVertex2d(2.5,2.55);
        glVertex2d(5,4);

    glEnd();


    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_QUADS);

        glVertex2d(1,2);
        glVertex2d(1.5,0.6);
        glVertex2d(3.5,2.5);
        glVertex2d(2.5,4);

    glEnd();
}

void bomb1()
{

    int i = 0;
	float angle = 0.0;
    //middle circle
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 3, sin(angle) * 3.5, 0);
		}

    glEnd();


    //head

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

        glVertex2d(2.5,2.5);
        glVertex2d(3.5,6);

        glVertex2d(2.5,2.5);
        glVertex2d(4.5,5);

        glVertex2d(2.5,2.55);
        glVertex2d(5,4);

    glEnd();


    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_QUADS);

        glVertex2d(1,2);
        glVertex2d(1.5,0.6);
        glVertex2d(3.5,2.5);
        glVertex2d(2.5,4);

    glEnd();
}



void enemy2()
{

    //body
	glBegin(GL_QUADS);

        glVertex2d(0,-0.5);
        glVertex2d(0,8);
        glVertex2d(1,8);
        glVertex2d(1,-0.5);

	glEnd();

	//Legs
	glColor3f(1.0, 0.8, 0.0);

	glBegin(GL_LINES);

        //RIGHT

        //right 1
        glVertex2d(1,7);
        glVertex2d(2,8);

        glVertex2d(2,8);
        glVertex2d(3,7);


        //right 2
        glVertex2d(1,6);
        glVertex2d(2,7);

        glVertex2d(2,7);
        glVertex2d(3,6);

        //right 3
        glVertex2d(1,5);
        glVertex2d(2,6);

        glVertex2d(2,6);
        glVertex2d(3,5);


        //right 4
        glVertex2d(1,4);
        glVertex2d(2,5);

        glVertex2d(2,5);
        glVertex2d(3,4);

        //right 5
        glVertex2d(1,3);
        glVertex2d(2,4);

        glVertex2d(2,4);
        glVertex2d(3,3);

        //right 6
        glVertex2d(1,2);
        glVertex2d(2,3);

        glVertex2d(2,3);
        glVertex2d(3,2);

        //right 7
        glVertex2d(1,1);
        glVertex2d(2,2);

        glVertex2d(2,2);
        glVertex2d(3,1);

        //right 8
        glVertex2d(1,0);
        glVertex2d(2,1);

        glVertex2d(2,1);
        glVertex2d(3,0);



        //LEFT

        //left 1
        glVertex2d(0,7);
        glVertex2d(-1,8);

        glVertex2d(-1,8);
        glVertex2d(-2,7);


        //left 2
        glVertex2d(0,6);
        glVertex2d(-1,7);

        glVertex2d(-1,7);
        glVertex2d(-2,6);

        //left 3
        glVertex2d(0,5);
        glVertex2d(-1,6);

        glVertex2d(-1,6);
        glVertex2d(-2,5);


        //left 4
        glVertex2d(0,4);
        glVertex2d(-1,5);

        glVertex2d(-1,5);
        glVertex2d(-2,4);

        //left 5
        glVertex2d(0,3);
        glVertex2d(-1,4);

        glVertex2d(-1,4);
        glVertex2d(-2,3);

        //left 6
        glVertex2d(0,2);
        glVertex2d(-1,3);

        glVertex2d(-1,3);
        glVertex2d(-2,2);

        //left 7
        glVertex2d(0,1);
        glVertex2d(-1,2);

        glVertex2d(-1,2);
        glVertex2d(-2,1);

        //left 8
        glVertex2d(0,0);
        glVertex2d(-1,1);

        glVertex2d(-1,1);
        glVertex2d(-2,0);

	glEnd();


	//Moustache

    glColor3f(0.7, 0.0, 0.0);
    glBegin(GL_LINES);

        //RIGHT

        glVertex2d(0.5,8);
        glVertex2d(2,10);

        //left
        glVertex2d(0.5,8);
        glVertex2d(-1,10);

    glEnd();




	//EYE

	int i = 0;
	float angle = 0.0;

	//glColor3f(0.5, 0.0, 0.0);
	glColor3f(0.7, 0.7, 0.4);
    glTranslatef(0.5,8,0);
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 0.3, sin(angle) * 0.3, 0);
		}

    glEnd();

    glTranslatef(0,-1,0);
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 0.3, sin(angle) * 0.3, 0);
		}

    glEnd();



}

void enemy1(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;


	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();


    //Leg
	glBegin(GL_LINES);

        glColor3f(1.0, 0.0, 0.0);

        //right up
        glVertex2d(2.7,0.5);
        glVertex2d(5.2,4);

        glVertex2d(5.2,4);
        glVertex2d(7.8,0.5);


        //right middle
        glVertex2d(2.9,-0.2);
        glVertex2d(5.2,2.5);

        glVertex2d(5.2,2.5);
        glVertex2d(7.8,-0.2);

        //right down
        glVertex2d(2.5,-1.5);
        glVertex2d(5.2,1.4);

        glVertex2d(5.2,1.4);
        glVertex2d(7.8,-1.5);

        //left up
        glVertex2d(-2.7,0.5);
        glVertex2d(-5.2,4);

        glVertex2d(-5.2,4);
        glVertex2d(-7.8,0.5);


        //left middle
        glVertex2d(-2.9,-0.2);
        glVertex2d(-5.2,2.5);

        glVertex2d(-5.2,2.5);
        glVertex2d(-7.8,-0.2);

        //left down
        glVertex2d(-2.5,-1.5);
        glVertex2d(-5.2,1.4);

        glVertex2d(-5.2,1.4);
        glVertex2d(-7.8,-1.5);

    glEnd();


    //middle design
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 1.5, sin(angle) * 1.5, 0);
		}

    glEnd();



    //Eye
    //right
    glColor3f(0.8, 0.3, 0.1);
    glTranslatef(1,2.5,0);
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 0.5, sin(angle) * 0.5, 0);
		}

    glEnd();


    //left
    glTranslatef(-1.5,0,0);
    glBegin(GL_POLYGON);
        for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * 0.5, sin(angle) * 0.5, 0);
		}

		glTranslatef(1,1,0);

    glEnd();


    //moustache
    glBegin(GL_LINES);

        //right
        glVertex2d(0.8,0);
        glVertex2d(3,3);

        //left
        glVertex2d(0.7,0);
        glVertex2d(-1.8,3);

    glEnd();







}

void output(int x, int y, float r, float g, float b, int font, char *string)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    //enemy 1
	glPushMatrix();

    glColor3f(0.0, 1.0, 0.0);
	glTranslatef(tx1,ty1,0);
	glScalef(8,9,1);

	enemy1(3,2.5);

	glPopMatrix();


	glPushMatrix();

	glColor3f(0.8, 0.3, 0.1);
	glTranslatef(tx2,ty2,0);
	glScalef(8,8,1);

	enemy2();

	glPopMatrix();

	glPushMatrix();

	glColor3f(0.2, 0.0, 0.1);
	glTranslatef(txE2,tyE2,0);
	glScalef(8,8,1);

	enemy2();

	glPopMatrix();


	glPushMatrix();

    glColor3f(0.6, 0.2, 0.0);
	glTranslatef(txE1,tyE1,0);
	glScalef(8,8,1);

	enemy1(3,2.5);

	glPopMatrix();


	glPushMatrix();

	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(tx3,ty3,0);
	glScalef(8,8,1);

	bomb();

	glPopMatrix();


	glPushMatrix();
	glColor3f(0.9, 0.3, 0.3);
	glTranslatef(tx4,ty4,0);
	glScalef(8,8,1);

	bomb1();

	glPopMatrix();


	strcpy(str,"Score: ");
	itoa(score,str1,10);
	output(-380,370,1,0,0,13, strcat(str,str1));

	strcpy(duration,"Time: ");
	sprintf(str1,"%d",tim);
	output(300,370,1,0,0,13, strcat(duration,str1));


	glFlush();
}

void generateEnemy(int value)
{
    tim--;
    //bomb
    if(tx3 > 450 && ty3 > 450)
    {
        tx3 = 20;
        ty3 = 25;
    }

    //enemy1
    if(tx1 > 450 && ty1 > 450)
    {
        tx1 = 200;
        ty1 = 25;
    }

    //copy-enemy1
    if(txE1 > 450 && tyE1 > 450)
    {
        txE1 = 50;
        tyE1 = 300;
    }

    //enemy2
    if(tx2 > 450 && ty2 > 450)
    {
        tx2 = 0;
        ty2 = 5;
    }

    //copy-enemy1
    if(txE2 > 450 && tyE2 > 450)
    {
        txE2 = -50;
        tyE2 = -300;
    }


    glutPostRedisplay();
    glutTimerFunc(1000, generateEnemy, 0);
}


void move_(int value)
{

    //bomb
    if((tx3>390 && ty3>390) || (tx3<-390 && ty3>390) || (tx3<-390 && ty3<-390) || (tx3>390 && ty3<-390))
    {
        dx3 = -dx3;
        dy3 = -dy3;
    }
    if(tx3>390 && ty3<390 && ty3>-390)
    {
        dx3 = -dx3;
    }
    if(tx3<390 && tx3>-390 && ty3>390)
    {
        dy3 = -dy3;
    }
    if(tx3<-390 && ty3<390 && ty3>-390)
    {
        dx3 = -dx3;
    }
    if(tx3<390 && tx3>-390 && ty3<-390)
    {
        dy3 = -dy3;
    }


    //bomb1
    if((tx4>390 && ty4>390) || (tx4<-390 && ty4>390) || (tx4<-390 && ty4<-390) || (tx4>390 && ty4<-390))
    {
        dx4 = -dx4;
        dy4 = -dy4;
    }

    if(tx4>390 && ty4<390 && ty4>-390)
    {
        dx4 = -dx4;
    }
    if(tx4<390 && tx4>-390 && ty4>390)
    {
        dy4 = -dy4;
    }
    if(tx4<-390 && ty4<390 && ty4>-390)
    {
        dx4 = -dx4;
    }
    if(tx4<390 && tx4>-390 && ty4<-390)
    {
        dy4 = -dy4;
    }


    //enemy 1
    if((tx1>390 && ty1>390) || (tx1<-390 && ty1>390) || (tx1<-390 && ty1<-390) || (tx1>390 && ty1<-390))
    {
        dx = -dx;
        dy = -dy;
    }
    if(tx1>390 && ty1<390 && ty1>-390)
    {
        dx = -dx;
    }
    if(tx1<390 && tx1>-390 && ty1>390)
    {
        dy = -dy;
    }
    if(tx1<-390 && ty1<390 && ty1>-390)
    {
        dx = -dx;
    }
    if(tx1<390 && tx1>-390 && ty1<-390)
    {
        dy = -dy;
    }


    //enemy 1 2nd
    if((txE1>390 && tyE1>390) || (txE1<-390 && tyE1>390) || (txE1<-390 && tyE1<-390) || (txE1>390 && tyE1<-390))
    {
        dxE = -dxE;
        dyE = -dyE;
    }
    if(txE1>390 && tyE1<390 && tyE1>-390)
    {
        dxE = -dxE;
    }
    if(txE1<390 && txE1>-390 && tyE1>390)
    {
        dyE = -dyE;
    }
    if(txE1<-390 && tyE1<390 && tyE1>-390)
    {
        dxE = -dxE;
    }
    if(txE1<390 && txE1>-390 && tyE1<-390)
    {
        dyE = -dyE;
    }



    //enemy 2
    if((tx2>390 && ty2>390) || (tx2<-390 && ty2>390) || (tx2<-390 && ty2<-390) || (tx2>390 && ty2<-390))
    {
        dx2 = -dx2;
        dy2 = -dy2;
    }
    if(tx2>390 && ty2<390 && ty2>-390)
    {
        dx2 = -dx2;
    }
    if(tx2<390 && tx2>-390 && ty2>390)
    {
        dy2 = -dy2;
    }
    if(tx2<-390 && ty2<390 && ty2>-390)
    {
        dx2 = -dx2;
    }
    if(tx2<390 && tx2>-390 && ty2<-390)
    {
        dy2 = -dy2;
    }

    //enemy 2 2nd
    if((txE2>390 && tyE2>390) || (txE2<-390 && tyE2>390) || (txE2<-390 && tyE2<-390) || (txE2>390 && tyE2<-390))
    {
        dxE2 = -dxE2;
        dyE2 = -dyE2;
    }
    if(txE2>390 && tyE2<390 && tyE2>-390)
    {
        dxE2 = -dxE2;
    }
    if(txE2<390 && txE2>-390 && tyE2>390)
    {
        dyE2 = -dyE2;
    }
    if(txE2<-390 && tyE2<390 && tyE2>-390)
    {
        dxE2 = -dxE2;
    }
    if(txE2<390 && txE2>-390 && tyE2<-390)
    {
        dyE2 = -dyE2;
    }





    tx1 = tx1+dx;
    ty1 = ty1+dy;

    txE1 = txE1+dxE;
    tyE1 = tyE1+dyE;

    tx2 = tx2+dx2;
    ty2 = ty2+dy2;

    txE2 = txE2+dxE2;
    tyE2 = tyE2+dyE2;

    tx3 = tx3+dx3;
    ty3 = ty3+dy3;

    tx4 = tx4+dx4;
    ty4 = ty4+dy4;
    glutPostRedisplay();

    glutTimerFunc(25, move_, 0);

}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-400.0, 400.0, -400.0, 400.0, -50.0, 50.0);
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

void finishGame(int value)
{
    exit(0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 's':
		    glutTimerFunc(1000, generateEnemy, 0);
	        glutTimerFunc(60000, finishGame, 0);
			glutTimerFunc(25, move_, 0);
			break;
		case 'e':
			 exit(0);

			 break;

	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
    mx = x -400;
    my = 400-y;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //bomb
        if(tx3-30 <= mx && mx <= tx3+30 && ty3-30 <= my && my <= ty3+30)
        {
            tx3 = 600;
            ty3 = 600;
            glutPostRedisplay();
            exit(0);
        }

        //bomb1
        if(tx4-30 <= mx && mx <= tx4+30 && ty4-30 <= my && my <= ty4+30)
        {
            tx4 = 600;
            ty4 = 600;
            glutPostRedisplay();
            exit(0);
        }

        //enemy1
        if(tx1-30 <= mx && mx <= tx1+30 && ty1-30 <= my && my <= ty1+30)
        {
            tx1 = 600;
            ty1 = 600;
            score+=1;
            glutPostRedisplay();
        }

        //copy- enemy1
        if(txE1-30 <= mx && mx <= txE1+30 && tyE1-30 <= my && my <= tyE1+30)
        {
            txE1 = 600;
            tyE1 = 600;
            score+=1;
            glutPostRedisplay();
        }

        //enemy2
        if(tx2-30 <= mx && mx <= tx2+30 && ty2-30 <= my && my <= ty2+30)
        {
            tx2 = 600;
            ty2 = 600;
            score+=1;
            glutPostRedisplay();
        }

        //copy-enemy2
        if(txE2-30 <= mx && mx <= txE2+30 && tyE2-30 <= my && my <= tyE2+30)
        {
            txE2 = 600;
            tyE2 = 600;
            score+=1;
            glutPostRedisplay();
        }
    }
    //printf("%d,%d  %lf,%lf\n",mx,my,tx3,ty3);
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("GAME");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

