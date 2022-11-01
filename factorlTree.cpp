#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "BmpLoader.h"

/// this is for sound
#include<iostream>
#include<Windows.h>
#include<MMSystem.h>


#define PI 3.1416

using namespace std;

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1000, windowWidth=1000;
//GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, lpan = 0.0, rpan = 0.0, fdist=0.0,yaw = 0.0, dx = 0.0,dy = 0.0,dz = 0.0,roll=0.0,pitch = 0.0,cdist = 0.0,xaxis = 0.0, yaxis=1.0,zaxis=0.0;
GLfloat alpha = 0.0, theta = 0.0,bita = 0.0, axis_x=0.0, axis_y=0.0;

GLfloat up_x = 0,up_y = 1,up_z = 0;

GLboolean bRotate = false, uRotate = false;

GLfloat theta_pakha =0;
//
double wall_length = 20.0,wall_width = 0.5, wall_height = 10.0;
double Loop, LoopAll = 0;
GLfloat eyeX =wall_length/2;// 2;
GLfloat eyeY =wall_height/2;// 3;
GLfloat eyeZ = 1.5 * wall_length;

GLfloat nearP = 4, farP = 250;

GLfloat lookX = wall_length / 2;
GLfloat lookY = wall_height/2;
GLfloat lookZ = wall_length/2;

GLfloat x_look = lookX;
GLfloat y_look = lookY;
GLfloat z_look = lookZ;
bool l_on1 = true;
bool l_on2 = true;
bool l_on3 = true;
bool ambflag=true;
bool difflag=true;
bool specflag=true;

bool ambient0 = true, diffuse0 = true, specular0 = true;
bool ambient1 = true, diffuse1 = true, specular1 = true;

float cubeSideLength = 1.0;

float redish[] = {0.5020, 0.0000, 0.0000};
float deep_ash[] = {0.4392, 0.5020, 0.5647};
float blue[] = {0.0,0.0,1.0};
float white[] = {1.0,1.0,1.0};
float ash[] = {0.6627, 0.6627, 0.6627};
float green[] = {0.0,1.0,0.0};
float red[] = {1.0,0.0000, 0.0000};
float brown[] = {0.5451, 0.2706, 0.0745};
float black[] = {0.0, 0.0, 0.0};
vector<int> v;
unsigned int ID;
//GLfloat alpha = 0.0, theta = 0.0, beta= 0.0, axis_x=0.0, axis_y=0.0, axis_z = 0.0, eyeX = 2.0, eyeY = 3.0, eyeZ = 10.0, roll = 0.0, pitch = 0.0, yaw = 0.0;

static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, cubeSideLength}, //1
    {cubeSideLength, 0.0, 1.0}, //2
    {cubeSideLength, 0.0, 0.0}, //3
    {0.0, cubeSideLength, 0.0}, //4
    {0.0, cubeSideLength, cubeSideLength}, //5
    {cubeSideLength, cubeSideLength, cubeSideLength}, //6
    {cubeSideLength, cubeSideLength, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};



void LoadTexture(const char*filename)
{
    /*glBindTexture(GL_TEXTURE_2D, TextureColorbufferName);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000);
 glBindTexture(GL_TEXTURE_2D, 0);*/
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


void texture_image()
{
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\treeside.bmp"); //0
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\grass.bmp"); //0
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\soil_grass3.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\road.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\backglas.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\tire.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\car_body.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\redlight.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\number_plate.bmp");
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\head_light.bmp");
    v.push_back(ID);
}


void light0()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 100.0, 0.0, 1.0 };
    glEnable( GL_LIGHT0);
    if (ambient0) glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    else glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
    if (diffuse0) glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    else glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);

    if(specular0) glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    else glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    /*  GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
      glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
      glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0); */
}

void light1()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 200, 9.5, -15 };  //0.7, 1.5, 9.0

    glEnable( GL_LIGHT1);

    if(ambient1) glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    else glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
    if(diffuse1) glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    else glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);

    if(specular1) glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    else glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
//    GLfloat spot_direction[] = { 0.3, -1, -0.8 };
    GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

    glPopMatrix();

    /*GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);*/
}

static void getNormal3p (GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void drawcube(float am_r, float am_g, float am_b, float df_r,float df_g,float df_b,float sp_r=1.0,float sp_g=1.0,float sp_b=1.0,float shininess = 60)
{
//    glColor3f(1,0,0);
    //glBegin(GL_TRIANGLES);

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { am_r, am_g, am_b, 1.0 };

//    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { df_r, df_g, df_b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { sp_r, sp_g, sp_b, 1.0 };
//    GLfloat mat_shininess[] = {60};
    GLfloat mat_shininess[] = {shininess};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
//        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][3]][0]);

        glVertex3fv(&v_cube[quadIndices[i][0]][0]);glTexCoord2f(0,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);glTexCoord2f(1,1);
    }
    glEnd();


}

void Cylinder3D(double baseRadius, double topRadius, double height)
{
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    GLUquadricObj *quadratic;

    quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic, GL_TRUE);
    glRotatef(-90.0f, 1.0f,0.0f, 0.0f);
//    gluCylinder(quadratic, baseRadius+0.5, topRadius, height, 45, 45);
    gluCylinder(quadratic, baseRadius, topRadius, height, 45, 45);
    //gluQuadricTexture(quadratic, TRUE);
    gluDeleteQuadric(quadratic);
}


void circle_3D(GLdouble radius)
{
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, radius, 20, 20);
    gluDeleteQuadric(qobj);
}

void FrustumChange(bool positive = true)
{
    if(positive)nearP++;
    else nearP--;
}

void Pitch(bool clock = true)
{
    // Translate to origin
    if(clock)bita++;
    else bita--;
    GLfloat dx = 0 ;
    GLfloat dy = 0;
    GLfloat dz = -eyeZ;

    GLfloat new_x = dx;
    GLfloat new_y = dy*cos(bita*PI/180.0)-dz*sin(bita*PI/180.0);
    GLfloat new_z = dy*sin(bita*PI/180.0) +dz*cos(bita*PI/180.0);

    lookX = new_x;
    lookY = new_y;
    lookZ = new_z-dz;
}



void Roll(bool clock = true)
{
    if(clock)alpha++;
    else alpha--;
    up_x = -sin(PI*alpha/180.0);
    up_y = cos(PI*alpha/180);
}

void Yaw(bool clock = true)
{
    if(clock) theta++;
    else theta--;
    GLfloat dx =0;
    GLfloat dy = 0;
    GLfloat dz = -eyeZ;

    GLfloat new_x = dx*cos(theta*PI/180.0)+dz*sin(theta*PI/180.0);
    GLfloat new_y = dy;
    GLfloat new_z = -dx*sin(theta*PI/180.0) +dz*cos(theta*PI/180.0);

    lookX = new_x;
    lookY = new_y;
    lookZ = -dz+new_z;
}


void zoom(bool positive = true)
{
    float dx = lookX - eyeX;
    float dy = lookY - eyeY;
    float dz = lookZ - eyeZ;
    float unit_dist = sqrt(dx*dx+dy*dy+dz*dz);
    if(unit_dist<=.1 && positive)return;
    if(!positive)unit_dist*=-1;
    eyeX+=dx/unit_dist;
    eyeY+=dy/unit_dist;
    eyeZ+=dz/unit_dist;
    lookX+=dx/unit_dist;
    lookY+=dy/unit_dist;
    lookZ+=dz/unit_dist;

}

void drawaxes()
{
    glPushMatrix();// axis drawing
//        c = 9;

//        glColor3f(colors[c][0],colors[c][1],colors[c][2]);
        glColor3f(redish[0],redish[1],redish[2]);
        glBegin(GL_LINES);
        glVertex3f(-wall_length,0,0);
        glVertex3f(wall_length, 0, 0);//x axis
        glEnd();

//        c = 8;
//        glColor3f(colors[c][0],colors[c][1],colors[c][2]);
        glColor3f(redish[0],redish[1],redish[2]);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0, wall_length, 0);//y axis
        glEnd();

//        c = 1;
//        glColor3f(colors[c][0],colors[c][1],colors[c][2]);

        glColor3f(redish[0],redish[1],redish[2]);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0, 0, wall_length);//z axis
        glEnd();


    glPopMatrix();

}



void drawTable()
{

    //table
    glPushMatrix();
    glTranslatef(170,0,3);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(195,0,3);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(170,0,-50);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(195,0,-50);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(170,4,5);
    glScalef(6,.1,-11.5);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

}

void drawLaptop()
{

//laptop

    glPushMatrix();
//    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(170, 4.9, -25);
    glScalef(2.5, 0.0, 3);

    drawcube(black[0],black[1],black[2],1,1,1);
    glPopMatrix();


    glPushMatrix();
//    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(183, 4.9, -25);
    glScalef(0, 0.2, 3);
    float pink[] = {1.0, 0.1, 1.0};
    drawcube(pink[0],pink[1],pink[2],1,1,1);
    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(166.5, 5.05, -13);
//    glScalef(0, 0.155, 2.4);
//    color = {1.0, 1.0, 1.0};

    glPushMatrix();
//    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(182.5, 5.05, -23);
    glScalef(0, 0.155, 2.4);
//    color = {1.0, 1.0, 1.0};
    drawcube(white[0], white[1],white[2],1,1,1);
    glPopMatrix();

}

void drawChair()
{

    //Chair
    glPushMatrix();
    glTranslatef(155, 0, -10);
    glScalef(0.6, 1, .4);
//    vector<float> color = {1.0, 1.0, 1.0};
    float yellow[] = {0.5451, 0.2706, 0.0745};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(155, 0, -30);
    glScalef(0.6, 1, .4);
//    color = {1.0, 1.0, 1.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(175, 0, -10);
    glScalef(0.6, 0.4, .4);
//    color = {1.0, 1.0, 1.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(175, 0, -30);
    glScalef(0.6, 0.4, .4);
//    color = {1.0, 1.0, 1.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

//     upper portion of the chair
    glPushMatrix();
    glTranslatef(157, 1.9, -7.8);
    glScalef(4.5, 0.1, -4.5);
//    color = {1.0, 0.0, 0.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();


    //
    glPushMatrix();
    glTranslatef(155, 3.3, -27.5);
    glScalef(0.6, 0.3, 3.5);
//    color = {1.0, 1.0, 0.0};
    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();
}


void cylinder(float alas, float atas, float tinggi ,int textureID = 4)
{
//    textureID = 5;
    glBindTexture(GL_TEXTURE_2D,v[textureID]);
    glEnable(GL_TEXTURE_2D);

	float i;
	glPushMatrix();
        glTranslatef(1.0, 0.0, -alas / 8);
        // ...
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D, v[textureID]);
            glutSolidCone(alas, 0, 32, 4);
        glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        glDisable(GL_TEXTURE_GEN_T);
        // ...
        for (i = 0; i <= tinggi; i += alas / 24) {
            glTranslatef(0.0, 0.0, alas / 24);
            glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[textureID]);
                glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        }

        glTranslatef(0.0, 0.0, alas / 4);
        // ...
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D, v[textureID]);
            glutSolidCone(atas, 0, 20, 1);
        glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void blok(float tebal, int ratiol, int ratiop, int textureID=0)
{
    glBindTexture(GL_TEXTURE_2D,v[textureID]);
    glEnable(GL_TEXTURE_2D);

    // ...
	float i, j;
	glPushMatrix();
	for (i = 0; i < ratiop; i++) {
		glTranslatef(-(ratiol + 1) * tebal / 2, 0.0, 0.0);
		for (j = 0; j < ratiol; j++) {
			glTranslatef(tebal, 0.0, 0.0);
            // this is to texture the glutSolidCube
            glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[textureID]);
                glutSolidCube(tebal);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
		}

		glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
	}
	glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void spotlight(float x,float y, float z,float spt_cutoff)
{
    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat l_dif[] = {1,1,1,1};
    GLfloat l_spec[] = {0.2,0.2,0.2,1};
    GLfloat l_pos3[] = {x,y+10,z+10,1.0};
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2,GL_AMBIENT,l_amb);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,l_dif);
    glLightfv(GL_LIGHT2,GL_SPECULAR,l_spec);
    glLightfv(GL_LIGHT2,GL_POSITION,l_pos3);
//    GLfloat l_spt[] = {0,0,-1,1};
//    GLfloat spt_ct[] = {spt_cutoff};
//    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
//    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);

    if(l_on3)
    {

        if(ambflag)
        {
            glLightfv(GL_LIGHT2,GL_AMBIENT,l_amb);
        }
        else
        {
            glLightfv(GL_LIGHT2,GL_AMBIENT,l_no);
        }
        if(difflag)
        {
            glLightfv(GL_LIGHT2,GL_DIFFUSE,l_dif);
        }
        else
        {
            glLightfv(GL_LIGHT2,GL_DIFFUSE,l_no);
        }
        if(specflag)
        {
            glLightfv(GL_LIGHT2,GL_SPECULAR,l_spec);
        }
        else
        {
            glLightfv(GL_LIGHT2,GL_SPECULAR,l_no);
        }
    }
    else
    {
        glLightfv(GL_LIGHT2,GL_AMBIENT,l_no);
        glLightfv(GL_LIGHT2,GL_DIFFUSE,l_no);
        glLightfv(GL_LIGHT2,GL_SPECULAR,l_no);
    }

    GLfloat l_spt[] = {0,0,-1,1};
    GLfloat spt_ct[] = {spt_cutoff};
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);


}

void jhop(double pos_x=6.0,double pos_y=0.0,double pos_z =0.0)
{
    glPushMatrix();
    glTranslatef(pos_x,pos_y+4,pos_z+0);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(pos_x-0.8,pos_y+4.3,pos_z+0);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pos_x+0.8,pos_y+4.3,pos_z-0.2);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Tree(double baseRadius=0.4, double topRadius=0.3, double height =10)
//void Tree()
{
//    int randm = 10;
//    srand(5);
//    randm = (rand() % 9) + 8;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[0]);
    glPushMatrix();
        // baseRadius, topRadius,
        Cylinder3D(baseRadius, topRadius, height);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glTranslatef(0, height+1, 0);
        glBindTexture(GL_TEXTURE_2D,2);
        glEnable(GL_TEXTURE_2D);
            circle_3D(2.3);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.8, height-0.3, 0);
        glBindTexture(GL_TEXTURE_2D,2);
        glEnable(GL_TEXTURE_2D);
            circle_3D(2.3);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.8, height-0.3, -0.2);
        glBindTexture(GL_TEXTURE_2D,2);
        glEnable(GL_TEXTURE_2D);
            circle_3D(2.3);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


void drawRoad()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[3]);

        glPushMatrix();
            glTranslatef(-100,0.01,10);
            glScalef(200,0,10);
                drawcube(black[0],black[1],black[2],1,1,1);
        glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
void drawRoom()
{
    //floor
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[2]);
    glPushMatrix();
    glTranslatef(-100,0,0);
    glScalef(200,0,30);

    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawBed()
{

    //front bed side
    glPushMatrix();
    glTranslatef(5,2,0);
    glScalef(20,0.2,1);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);
    glPopMatrix();



    glPushMatrix();
    //front-bottom bed leg
    glTranslatef(100,0,0);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    //bottom bed side
    glTranslatef(0,2,0);
    glScalef(1,0.4,-10);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);
    glPopMatrix();



    glPushMatrix();
    //back-bottom bed leg
    glTranslatef(100,0,-50);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    //back bed side
    glTranslatef(5,2,0);
    glScalef(-20,0.2,1);

//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    glPopMatrix();

    glPushMatrix();
    //back upper leg
    glTranslatef(0,0,-50);

//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    //upper bed side
    glTranslatef(0,2,0);
    glScalef(1,0.5,10.5);

//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    glPopMatrix();

    //bedsheet
    glPushMatrix();
    glTranslatef(5,3,5.3);
    glScaled(19,.1,-11);

    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();

    //pillow
    glPushMatrix();
    glTranslatef(3,3.5,-1.5);
    glScaled(5,.1,-8);


    drawcube(ash[0],ash[1],ash[2],1,1,1);
    glPopMatrix();

    //katha
    glPushMatrix();
    glTranslatef(50,3,7.0);
    glScaled(10,.15,-11.5);


    drawcube(green[0],green[1],green[2],1,1,1);
    glPopMatrix();

//      glPushMatrix();
//      glTranslatef(0,0,0);
//      glScalef


}


void drawSphere(float am_r, float am_g, float am_b, float df_r, float df_g, float df_b )
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.0, 0.5, 0.0, 1.0 };
    GLfloat mat_ambient[] = { am_r, am_g, am_b, 1.0 };

//    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { df_r, df_g, df_b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);



//    glPushMatrix();
//    glTranslatef(155, 0, -15);
//    glScalef(0.6, 1, .4);
    glutSolidSphere (2.0, 20, 16);
//    glPopMatrix();

}































































































void Tire()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[5]);

    glPushMatrix();
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 0.1,0.1,0.1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glutSolidTorus(0.2, 0.8, 5, 50);
    glPopMatrix();




    glPushMatrix();
    glTranslated(0,-0.8,0);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();




    glPushMatrix();
    glTranslated(0.8,0.0,0);
    glRotatef(90,0,0,1);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.1,0.0,0);
    glRotatef(45,0,0,1);
    glPushMatrix();
    glTranslated(0.8,0.0,0);
    glRotatef(90,0,0,1);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glTranslated(0.0,0.0,0);
    glRotatef(-45,0,0,1);
    glPushMatrix();
    glTranslated(0.8,0.0,0);
    glRotatef(90,0,0,1);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


}


void car_body(void)
{
    //glRotatef(rot,0,1,0);
    ///CAR nicher body
    glBindTexture(GL_TEXTURE_2D,v[6]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-0.1-1+x_look,-2,-2+z_look);

    //glRotatef(rot,0,1,0);

    glScaled(2.2,1,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    //glRotatef(rot,0,1,0);
    glPopMatrix();


    spotlight(-1+x_look,-1.25,-1.9+z_look,30);
    ///Red light1
    glBindTexture(GL_TEXTURE_2D,v[7]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-1+x_look,-1.25,-1.9+z_look);
    //reff();
    glScaled(.4,.2,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///red light 2
    glBindTexture(GL_TEXTURE_2D,v[7]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0.6+x_look,-1.25,-1.9+z_look);
    glScaled(.4,.2,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///head light3
    glBindTexture(GL_TEXTURE_2D,v[9]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-1+x_look,-1.25,1.9+z_look);
    //reff();
    glScaled(.4,.2,-4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///head light 4
    glBindTexture(GL_TEXTURE_2D,v[9]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0.6+x_look,-1.25,1.9+z_look);
    glScaled(.4,.2,-4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




    ///numberplate
    glBindTexture(GL_TEXTURE_2D,v[8]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-.3+x_look,-1.6,-1.9+z_look);
    glScaled(.6,.4,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    /*///BUMPER
    glPushMatrix();
    glTranslatef(-1+x_look,-1.8,-1.9+z_look);
    glScaled(2,.1,4);
    drawcube(255.1/255,255.1/255,255.1/255,1,1,1);
    glPopMatrix();*/

    ///CAR TOP
    glBindTexture(GL_TEXTURE_2D,v[6]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-1+.05+x_look,-1,-1.1+z_look);
    glScaled(1.9,.7,2);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    ///back glass
    glBindTexture(GL_TEXTURE_2D,v[4]);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(-1+.15+.05+x_look,-1+.07,-1.1+z_look);
    glScaled(1.6,.6,2.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    ///Tyre
    glPushMatrix();
    glTranslatef(0.3-1.5+x_look,-1.9,-1.4+z_look);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();
    ///Tyre
    glPushMatrix();
    glTranslatef(-0.25+1.5+x_look,-1.9,-1.4+z_look);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();


    float dist=2.2;
    ///Tyre
    glPushMatrix();
    glTranslatef(0.3-1.5+x_look,-1.9,-1.4+z_look+dist);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();
    ///Tyre
    glPushMatrix();
    glTranslatef(-0.25+1.5+x_look,-1.9,-1.4+z_look+dist);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();
}

float moving = 0.0f;
void car()
{
    glPushMatrix();
        glTranslatef(moving, 2.5, 5.5);
        glRotatef(90, 0, -1, 0);
        glScalef(1.0,1.0,1.0);

        moving += 0.3f;
        if(moving>300){
            moving=0.0f;
        }
        car_body();
    glPopMatrix();
}


void carBody()
{
    glBindTexture(GL_TEXTURE_2D,v[6]);
    glEnable(GL_TEXTURE_2D);

    // lower part of the body
    glPushMatrix();
        glTranslatef(-0.1-1+x_look,-2,-2+z_look);
        glScaled(2.2,1,4);
        drawcube(1,1,1,1,1,1);
    glPopMatrix();

    //
    ///Red light1
    glBindTexture(GL_TEXTURE_2D,v[7]);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
        glTranslatef(-1+x_look, -1.25, -1.9+z_look);
        //reff();
        glScaled(.4,.2,4);
        drawcube(1,1,1,1,1,1);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

float moveTheCarAlongXaxis = 0;

void drawCar()
{
    glPushMatrix();
        glTranslatef(moveTheCarAlongXaxis, 0, 0);
        glRotatef(90, 0, -1, 0);
        glScalef(1.0,1.0,1.0);
        // this is to move the car along x-axis
        moveTheCarAlongXaxis += 0.01f;
        if(moveTheCarAlongXaxis > 100){
            moveTheCarAlongXaxis = 0.0f;
        }
        // car body parts
        carBody();
    glPopMatrix();
}







class Sound{
    public:
        void bombBlustSound()
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("C://Users//shakil//Desktop//lab//project//bombBlustSound.wav"), NULL, SND_ASYNC | SND_FILENAME);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            PlaySound(NULL, 0, 0);
        }
        void carSound(bool makeSound)
        {
            PlaySound(NULL, 0, 0);
            if(makeSound) PlaySound(TEXT("C://Users//shakil//Desktop//lab//project//highway.wav"), NULL, SND_ASYNC | SND_FILENAME);
            else PlaySound(NULL,0,0);
        }
};
Sound makeSomeNoise;



//float moving = -199.0f;
// car current position
float xCar = -500, yCar = 12.5, zCar = 180, carStartingPoint = -500, carEndingPoing = 800;
bool isCarDestoryed = false;
bool isCarMakingSound = false;

void car1()
{

    if(isCarMakingSound==false){
        makeSomeNoise.carSound(1);
        isCarMakingSound = true;
    }

    glPushMatrix();
        // to move the car
        glTranslatef(xCar, yCar, zCar);
        if(isCarDestoryed == false) xCar += 1.5;
        if(xCar > carEndingPoing){
            xCar = carStartingPoint;
        }

        Loop++;

        glPushMatrix();
            blok(10, 3, 2, v[6]);

            glTranslatef(0, 9, 0);
            blok(10, 3, 2, v[6]);

            glTranslatef(10, -10, 0);
            blok(10, 5.5, 2, v[6]);

            glRotatef(-35, 0, 0, 15);
            glTranslatef(0, 7, 0);
            blok(10, 2, 2, v[6]);

            glTranslatef(2, 4.9, -2.5);
            blok(0.5, 20, 31, v[6]);
            glRotatef(180, 45, -45, 0);

        glPopMatrix();

        // tire
        glPushMatrix();
            // 1
            glTranslatef(20, -8, -7);
//            cylinder(5, 5, 3);
            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3,v[4]);
            glDisable(GL_TEXTURE_2D);

            // 2
            glTranslatef(-20, 8, 7);
            glTranslatef(-5, -8, -7);
//            cylinder(5, 5, 3);
            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3, v[4]);
            glDisable(GL_TEXTURE_2D);



            // 3
//            glColor3f(0.4, 0.4, 0.4);
            glTranslatef(5, 8, 7);
            glRotatef(180, 0, 180, 0);
            glTranslatef(3, -8, -17);
//            cylinder(5, 5, 3);

            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3,v[4]);
            glDisable(GL_TEXTURE_2D);




            // 4
//            glColor3f(0.4, 0.4, 0.4);
            glTranslatef(-3, 8, 17);
            glTranslatef(-22, -8, -17);
//            cylinder(5, 5, 3);
            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3,v[4]);
            glDisable(GL_TEXTURE_2D);

            // window
//            glColor3f(1.0, 1.0, 1.0);
            glRotatef(90, 1, 0, 0);
            glTranslatef(8, 2.5, -15);
//            blok(2, 4, 5);

            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 5,v[9]);
            glDisable(GL_TEXTURE_2D);

            //
            glRotatef(90, 0, 1, 0);
            glTranslatef(0, -0.2, 7);
//            blok(2, 4, 8);
            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 8,v[9]);
            glDisable(GL_TEXTURE_2D);


            //
            glRotatef(0, 0, 0, 0);
            glTranslatef(0, 19.2, 0);
//            blok(2, 4, 8);
            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 8,v[9]);
            glDisable(GL_TEXTURE_2D);



            //
            glRotatef(90, 0, 1, 0);
            glTranslatef(7, 0, -8);
//            blok(2, 4, 5);

            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 5),v[9];
            glDisable(GL_TEXTURE_2D);




            // light front
//            glColor3f(9.9, 9.9, 0.0);
            glRotatef(90, 0, 1, 0);
            glTranslatef(0, -3, 20);
//            cylinder(2, 2, 3);
            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                cylinder(2, 2, 3,v[9]);
            glDisable(GL_TEXTURE_2D);


//            glColor3f(9.9, 9.9, 0.0);
            glRotatef(0, 0, 0, 0);
            glTranslatef(0, -12, 0);
//            cylinder(2, 2, 3);
            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                cylinder(2, 2, 3,v[9]);
            glDisable(GL_TEXTURE_2D);

            // light back
            glRotatef(0, 0, 0, 0);
            glTranslatef(0, 0, -52);
            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                cylinder(1, 1, 3,v[9]);
            glDisable(GL_TEXTURE_2D);


//            glColor3f(1.0, 1.0, 1.0);
            glRotatef(90, 1, 0, 0);
            glTranslatef(-8, 3.5, -12);
//            blok(2, 4, 8);
            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 8,v[9]);
            glDisable(GL_TEXTURE_2D);

//            glColor3f(9.0, 0.0, 0.0);
            glRotatef(0, 0, 0, 0);
            glTranslatef(-8, 28, 0);
//            cylinder(1, 1, 12);

            glBindTexture(GL_TEXTURE_2D,v[9]);
            glEnable(GL_TEXTURE_2D);
                cylinder(1, 1, 12,v[9]);
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    glPopMatrix();
}










// bomb
float currentX = 0, currentY = 0, currentZ = 0;
float destionationX = 25, destionationY = 0, destionationZ = 0;
float getPt( float n1 , float n2 , float perc ) {
    float diff = n2 - n1;
    return n1 + ( diff * perc );
}
struct Point{
    float x,y,z;
};
GLfloat xTarget = 0, yTarget = 0, zTarget = 0;
bool canChangeTheTarget = true;


void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = {1,1,1,1.0};
    GLfloat mat_diffuse[] = {1,1,1,1.0};
    GLfloat mat_specular[] = {1,1,1,1.0};
    GLfloat mat_shininess[] = {100};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * PI;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);
    glBegin(GL_LINES);
        for(i=0; i <= triangleAmount; i++)
        {
            glVertex2f( x, y);
            glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
}

void target()
{
    glPushMatrix();
        glScalef(1, 1, 1);
        glTranslatef(xTarget, yTarget, zTarget);
        glColor3f(green[0], green[1], green[2]);
        drawcube(green[0], green[1], green[2], 1, 1, 1);
//        glRotatef(90, 1, 0, 0);
//        drawCircle(0,0,1);

    glPopMatrix();
}

vector<Point>missilePathPoint;
int pos;
bool shouldThrow;
float xMissile, yMissile, zMissile;
float bombBlastArea = 17;




void bomb()
{
    glPushMatrix();
        missilePathPoint.clear();
//        cout<<"eyeX "<<eyeX<<' '<<eyeY<<' '<<eyeZ<<endl;
        float x1 = 0, y1 = 0, z1 = 0, x3 = xTarget, y3 = yTarget, z3 = zTarget;
//        float x1=eyeX+5, y1=eyeY, z1=eyeZ, x3=xTarget, y3=yTarget, z3=zTarget;
        float x2=(x1+x3)/2, y2=max(y1,y3) + 12, z2=(z1+z3)/2;
        for( float i = 0 ; i < 1 ; i += 0.01 ) {
            float xa = getPt(x1, x2, i);
            float ya = getPt(y1, y2, i);
            float za = getPt(z1, z2, i);
            float xb = getPt(x2, x3, i);
            float yb = getPt(y2, y3, i);
            float zb = getPt(z2, z3 ,i);

            float x = getPt(xa, xb, i);
            float y = getPt(ya, yb, i);
            float z = getPt(za, zb, i);

            Point point3d;
            point3d.x = x;
            point3d.y = y;
            point3d.z = z;
            missilePathPoint.push_back(point3d);
        }

        glPushMatrix();
            glBegin(GL_POINTS);
            for(auto it:missilePathPoint){
                glColor3f(1, 1, 1);
                glVertex3f(it.x,it.y,it.z);
            }
            glEnd();
        glPopMatrix();

        if(shouldThrow==true){
            glPushMatrix();
                if(pos>=(int)missilePathPoint.size()){
                    pos = missilePathPoint.size() - 1;
                    glScalef(1,1,1);
                    glTranslatef(missilePathPoint[pos].x, missilePathPoint[pos].y, missilePathPoint[pos].z);
                    glColor3f(1,1,1);
                    drawcube(white[0],white[1],white[2],1,1,1);

                    // is the car within the blast area
                    if( abs(missilePathPoint[missilePathPoint.size()-1].x - xCar) <= bombBlastArea or
                        abs(missilePathPoint[missilePathPoint.size()-1].y - yCar) <= bombBlastArea or
                        abs(missilePathPoint[missilePathPoint.size()-1].z - zCar) <= bombBlastArea ){
                            // stop the car
                            isCarDestoryed = true;
                            makeSomeNoise.bombBlustSound();
                       }
                    pos = 0;
                    shouldThrow=false;
                    canChangeTheTarget = true;
                }
                else{
                    glScalef(1,1,1);
                    glTranslatef(missilePathPoint[pos].x, missilePathPoint[pos].y, missilePathPoint[pos].z);
                    glColor3f(1,1,1);
                    drawcube(white[0],white[1],white[2],1,1,1);
    //                std::this_thread::sleep_for(std::chrono::milliseconds(5));
    //                pos++;
                    // to speed up the missile, don't use every point on the path
                    pos+=5;
                }


            glPopMatrix();
        }
    glPopMatrix();
}
void throwTheMissile()
{
    shouldThrow = true;
    canChangeTheTarget = false;
}
void missileLauncher()
{
//    glPushMatrix();
//        glEnable(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D,v[0]);
//        glPushMatrix();
//            glTranslatef(10,0,0);
//            glRotatef(90,1,0,0);
//            glRotatef(45,0,1,0);
//            // baseRadius, topRadius,
//            Cylinder3D(0.5, 0.5, 3);
//            glDisable(GL_TEXTURE_2D);
//        glPopMatrix();
//        glDisable(GL_TEXTURE_2D);
//    glPopMatrix();
//
//    glPushMatrix();
//        glEnable(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D,v[0]);
//        glPushMatrix();
//            glTranslatef(12,3,0);
//            // baseRadius, topRadius,
//            Cylinder3D(0.5, 0.5, 3);
//            glDisable(GL_TEXTURE_2D);
//        glPopMatrix();
//        glDisable(GL_TEXTURE_2D);
//    glPopMatrix();
}


// car
void resizedCar()
{
//    cout<<"resized car "<<endl;
    glPushMatrix();
//        glScalef(0.08, 0.08, 0.08);
        glScalef(0.08, 0.08, 0.08);
        car1();
    glPopMatrix();
}















// factorlTree

#define PI 3.1416

int flag = 1;
GLfloat angle = 0.0f;
GLfloat angle2 = 0.0f;
//int moving;
int startx, starty;
float r = 0.0f;//0.47f;
float g = 1.0f;//0.0f;
float b = 0.0f;//0.74f;

void makecylinder(float height,float Base)
{
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,v[0]);
//    glPushMatrix();
//        // baseRadius, topRadius,
//        Cylinder3D(Base, Base - (0.2 * Base), height);
//        glDisable(GL_TEXTURE_2D);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    GLUquadricObj *qobj;

    qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    glRotatef(-90.0f, 1.0f,0.0f, 0.0f);
    gluCylinder(qobj, Base, Base - (0.2 * Base), height, 45, 45);
    gluDeleteQuadric(qobj);
}

void maketree(float height,float Base)
{
	glPushMatrix();
        float angle;
    //	makecylinder(height, Base);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,v[0]);
        glPushMatrix();
            makecylinder(height, Base);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glTranslatef(0.0f, height,0.0f);
        height -= height * 0.1f;
        Base -= Base * 0.1f;

        if (height > 1)
        {
            angle = 22.5f;
            glPushMatrix();
                glRotatef(angle, -1.0f, 0.0f, 0.0f);
                maketree(height, Base);
            glPopMatrix();

            glPushMatrix();
                glRotatef(angle, 0.5f, 0.0f, 0.866f);
                maketree(height, Base);
            glPopMatrix();
            glPushMatrix();
                glRotatef(angle, 0.5f, 0.0f, -0.866f);
                maketree(height, Base);
            glPopMatrix();
        }
	glPopMatrix();
}

// factorlTree
void factorlTree()
{
    glPushMatrix();
        glTranslatef(10,3,0);
        glScalef(0.5, 0.5, 0.5);
        maketree(3.0f, 0.2f);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(20,3,0);
        glScalef(0.5, 0.5, 0.5);
        maketree(4.0f, 0.2f);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(30,3,0);
        glScalef(0.5, 0.5, 0.5);
        maketree(3.5f, 0.2f);
    glPopMatrix();
}









// plant tree
void singleTree(float xTree, float yTree, float zTree)
{
    glPushMatrix();
        glPushMatrix();
            glTranslatef(xTree, yTree, zTree);
            glScaled(1,1,1);
                Tree(0.4,0.3,10);
        glPopMatrix();

        GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
        GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
        GLfloat mat_specular[] = { 0.1,0.1,0.1, 1.0 };
        GLfloat mat_shininess[] = {90};

        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glPopMatrix();
}

struct TreePosition{
    float xTree,yTree,zTree;
};
vector<TreePosition>treePosition;
bool treePositionGenerated = false;

void TreePlant()
{
//    cout<<treePosition.size()<<endl;
    for(auto it:treePosition){
        singleTree(it.xTree, it.yTree, it.zTree);
//        cout<<it.xTree<<' '<<it.yTree<<' '<<it.zTree<<endl;
    }
    if(treePositionGenerated) return;
    TreePosition treePos;
    // we will generate 100 trees
    int rangeFromOrigin = 50;
    int originToRoad = 10;
    int soilOnZaxis = 30;
    int totalTree = 25;
    // total number of tree will be (totalTree * 4)
    for(int i = 0; i < totalTree; i++){
        // + +
        float xPos = rand()%rangeFromOrigin;
        float yPos = 0;
        float zPos = rand() % originToRoad;
        treePos.xTree = xPos; treePos.yTree = yPos; treePos.zTree = zPos;
        treePosition.push_back(treePos);
        // - +
        xPos = - rand()%rangeFromOrigin;
        yPos = 0;
        zPos = rand() % originToRoad;
        treePos.xTree = xPos; treePos.yTree = yPos; treePos.zTree = zPos;
        treePosition.push_back(treePos);
        // - -
        xPos = - rand()%rangeFromOrigin;
        yPos = 0;
        zPos = soilOnZaxis - rand() % originToRoad;
        treePos.xTree = xPos; treePos.yTree = yPos; treePos.zTree = zPos;
        treePosition.push_back(treePos);
        // + -
        xPos = rand()%rangeFromOrigin;
        yPos = 0;
        zPos = soilOnZaxis - rand() % originToRoad;
        treePos.xTree = xPos; treePos.yTree = yPos; treePos.zTree = zPos;
        treePosition.push_back(treePos);
    }
    treePositionGenerated = true;

    vector<TreePosition> temp;
    bool vis[treePosition.size()] = {};
    float radius = 25;
    int maxNumberOfAllowedTree = 80;

    for(int i = 0; i < (int)treePosition.size(); i++){
        if(vis[i]==false){
            temp.push_back(treePosition[i]);
            vis[i]=true;

            if((int)temp.size() > maxNumberOfAllowedTree) break;

//            cout<<"pos "<<i<<' '<<endl;
            for(int j = i+1; j < (int)treePosition.size(); j++){
                // we will discard all the tree which are with the radius of current tree

                if(vis[j]) continue; // if for some tree this one is already discarded

                float xDiff = abs(treePosition[i].xTree - treePosition[j].xTree) * abs(treePosition[i].xTree - treePosition[j].xTree);
                float yDiff = abs(treePosition[i].yTree - treePosition[j].yTree) * abs(treePosition[i].yTree - treePosition[j].yTree);
                float zDiff = abs(treePosition[i].zTree - treePosition[j].zTree) * abs(treePosition[i].zTree - treePosition[j].zTree);
//                cout<<xDiff<<' '<<yDiff<<' '<<zDiff<<endl;

//                cout<<"radius "<<xDiff+yDiff+zDiff<<endl;
                if(xDiff+yDiff+zDiff <= radius){
                    vis[j] = true;

//                    cout<<"change "<<i<<' '<<j<<endl;
                }
            }
        }
//        cout<<i<<' '<<temp.size()<<endl;
    }
    treePosition = temp;
//    cout<<"\n\n\n\n\n";
}






void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-5,5,-5,5,nearP,farP);
    //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,up_x,up_y,up_z);
    glViewport(0, 0, windowHeight, windowWidth);

    drawaxes();
    //drawcube(redish[0],redish[1],redish[2],1,1,1);
//    glutSolidCube(1.0);
//    drawRoom();
//    drawRoad();
////    piler();
////    car();
//
////    drawCar();
////    car1();
//    resizedCar();
//
//    // bomb
//    missileLauncher();
//    bomb();
//    target();
////
//    TreePlant();
    factorlTree();

//    fire();

    glFlush();
    glutSwapBuffers();
}

int makeNoise = 1;

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
        // sound
        case ',':
            if(makeNoise) {
                PlaySound(TEXT("C://Users//shakil//Desktop//lab//highway.wav"), NULL, SND_ASYNC | SND_FILENAME);
//                mciSendString("C://Users//shakil//Desktop//lab//highway.wav", NULL, 0, NULL);
            }
            else{
                PlaySound(NULL, 0, 0);
            }
            makeNoise ^= 1;
            break;

        // to restart the game
        case ']':
            xCar = carStartingPoint;
            isCarDestoryed = false;
            isCarMakingSound = false;
            break;

        // throw the missile
        case 'p':
            throwTheMissile();
            break;

        // to move the target
        case 'w': // up
            if(canChangeTheTarget==false) break;
            zTarget--;
            break;
        case 's': // down
            if(canChangeTheTarget==false) break;
            zTarget++;
            break;
        case 'a': // left
            if(canChangeTheTarget==false) break;
            xTarget--;
            break;
        case 'd': // right
            if(canChangeTheTarget==false) break;
            xTarget++;
            break;
        case 'W': // up
            if(canChangeTheTarget==false) break;
            yTarget++;
            break;
        case 'D': // down
            if(canChangeTheTarget==false) break;
            yTarget--;
            break;






        //case '1':
        case '1':
            bRotate = !bRotate;
            uRotate = false;
            axis_x=0.0;
            axis_y=1.0;
            break;

        //case '2':
        case '2':
            uRotate = !uRotate;
            bRotate = false;
            axis_x=1.0;
            axis_y=0.0;
            break;


        case '+': //zoom in
            zoom();
            break;
        case '-': //zoom out
            zoom(false);
            break;
        case '*': //zoom up
            eyeY++;
            lookY++;
            break;
        case '/': //zoom down
            eyeY--;
            lookY--;
            break;

        case 'x':
            eyeX++;
            lookX++;
            break;
        case 'z':
            eyeX--;
            lookX--;
            break;
        case 'y':
            Yaw();
            break;
        case 'Y':
            Yaw(false);
            break;

        case 'r':
            Roll();
            break;
        case 'R':
            Roll(false);
            break;
//
//        case 'p':
//            Pitch();
//            break;

        case 'P':
            Pitch(false);
            break;


        case 'f':
            FrustumChange();
            break;

        case 'F':
            FrustumChange(false);
            break;
//        //ambient light handle
//        case 'A':
//            ambient0 = true;
//            light0();
//            break;
//        case 'a':
//            ambient0 = false;
//            light0();
//            break;
//        //diffuse light handle
//        case 'D':
//            diffuse0 = true;
//            light0();
//            break;
//        case 'd':
//            diffuse0 = false;
//            light0();
//            break;
//
//        //specular light handle
//        case 'S':
//            specular0 = true;
//            light0();
//            break;
//        case 's':
//            specular0 = false;
//            light0();
//            break;


//        //ambient light handle
//        case 'Q':
//            ambient1 = true;
//            light1();
//            break;
//        case 'q':
//            ambient1 = false;
//            light1();
//            break;
//        //diffuse light handle
//        case 'W':
//            diffuse1 = true;
//            light1();
//            break;
//        case 'w':
//            diffuse1 = false;
//            light1();
//            break;
//
//        //specular light handle
//        case 'E':
//            specular1 = true;
//            light1();
//            break;
//        case 'e':
//            specular1 = false;
//            light1();
//            break;
//
//        case 'h':
//        case 'H':
//            l_on3=1-l_on3;
//            break;
//
//        case 'i':
//        case 'I':
//            ambflag=1-ambflag;
//            break;
//
//        case 't':
//        case 'T':
//            difflag=1-difflag;
//            break;
//        case 'u':
//        case 'U':
//            specflag=1-specflag;
//            break;

        case 27:	// Escape key
            exit(1);
    }
}




void animate()
{
    if (bRotate == true)
    {
        theta += 0.5;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.5;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("project");

    texture_image();

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    light0();
    light1();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
