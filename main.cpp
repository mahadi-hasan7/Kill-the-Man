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
//GLfloat eyeX =wall_length/2;// 2;
//GLfloat eyeY =wall_height/2;// 3;
//GLfloat eyeZ = 1.5 * wall_length;


GLfloat eyeX =13;// 2;
GLfloat eyeY =5;// 3;
GLfloat eyeZ = 40;


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
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\treeside.bmp"); // 0
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\grass.bmp"); // 1
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\soil_grass3.bmp"); // 2
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\road.bmp"); // 3
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\backglas.bmp"); // 4
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\tire.bmp"); // 5
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\car_body.bmp"); // 6
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\redlight.bmp"); // 7
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\number_plate.bmp"); // 8
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\head_light.bmp"); // 9
    v.push_back(ID);

    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\targetposition.bmp"); // 10
    v.push_back(ID);

    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\treeleaf.bmp"); // 11
    v.push_back(ID);

    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\burningcar.bmp"); // 12
    v.push_back(ID);


    /// building
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\building1.bmp"); // 13
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\building2.bmp"); // 14
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\building3.bmp"); // 15
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\building4.bmp"); // 16
    v.push_back(ID);

    /// fire
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\fire.bmp"); // 17
    v.push_back(ID);

    /// landscape
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\landscape.bmp"); // 18
    v.push_back(ID);
    LoadTexture("C:\\Users\\shakil\\Desktop\\lab\\project\\texture_image\\landscape1.bmp"); // 19
    v.push_back(ID);

}


void light0()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_position[] = { 0.0, 100.0, 0.0, 1.0 };
    GLfloat light_position[] = { 0.0, 100.0, 10.0, 1.0 };
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
//    GLfloat light_position[] = { 200, 9.5, -15 };  //0.7, 1.5, 9.0
    GLfloat light_position[] = { 0, 15, 0 };  //0.7, 1.5, 9.
    glEnable( GL_LIGHT1);

    if(ambient1) glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    else glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
    if(diffuse1) glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    else glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);

    if(specular1) glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    else glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
//    GLfloat spot_direction[] = { 0.3, -1, -0.8 };
//    GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
    GLfloat spot_direction[] = {1.0, 0, 0.0};
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
























double const pi = acos(-1), d=0.05;
double const sn = sin(pi/180), cs=cos(pi/180);
GLfloat sx, cx;
int theta_x=0, theta_y=0, theta_z=0;
GLfloat dx,dy,dz;

void tric(double deg)
{
    deg = deg * pi / 180;
    sx=sin(deg);
    cx=cos(deg);
}

void wcsAlign()
{
    lookX=lookX-eyeX;
    lookY=lookY-eyeY;
    lookZ=lookZ-eyeZ;

    tric(-theta_x);//X axix
    dy = lookY*cx-lookZ*sx;
    dz = lookY*sx+lookZ*cx;

    lookY=dy;
    lookZ=dz;

    tric(-theta_y);//Y axix
    dx = lookX*cx+lookZ*sx;
    dz = -lookX*sx+lookZ*cx;

    lookX = dx;
    lookZ = dz;

    tric(-theta_z);//Z axix

    dx = lookX*cx-lookY*sx;
    dy = lookX*sx+lookY*cx;

    lookX = dx;
    lookY = dy;

//    cout << "WCS:" << endl;
//    cout << lookX << " " << lookY << " " << lookZ << endl;
}

void retransform()
{
    tric(theta_z);//Z axix

    dx = lookX*cx-lookY*sx;
    dy = lookX*sx+lookY*cx;

    lookX = dx;
    lookY = dy;

    tric(theta_y);//Y axix
    dx = lookX*cx+lookZ*sx;
    dz = -lookX*sx+lookZ*cx;

    lookX = dx;
    lookZ = dz;

    tric(theta_x);//X axix
    dy = lookY*cx-lookZ*sx;
    dz = lookY*sx+lookZ*cx;

    lookY=dy;
    lookZ=dz;


//    cout << "VCS:" << endl;
//    cout << lookX << " " << lookY << " " << lookZ << endl;

    lookX=lookX+eyeX;
    lookY=lookY+eyeY;
    lookZ=lookZ+eyeZ;

}

void Pitch(bool clock = true)
{
    // Translate to origin
//    if(clock)bita++;
//    else bita--;
//    GLfloat dx = 0 ;
//    GLfloat dy = 0;
//    GLfloat dz = -eyeZ;
//
//    GLfloat new_x = dx;
//    GLfloat new_y = dy*cos(bita*PI/180.0)-dz*sin(bita*PI/180.0);
//    GLfloat new_z = dy*sin(bita*PI/180.0) +dz*cos(bita*PI/180.0);
//
//    lookX = new_x;
//    lookY = new_y;
//    lookZ = new_z-dz;


    if(clock){
        wcsAlign();
        theta_x += 1;
        retransform();
    }
    else{
        wcsAlign();
        theta_x -= 1;
        retransform();
    }

}



void Roll(bool clock = true)
{
//    if(clock)alpha++;
//    else alpha--;
//    up_x = -sin(PI*alpha/180.0);
//    up_y = cos(PI*alpha/180);


    if(clock){
        dx = up_x*cs+up_y*sn;
            dy = -up_x*sn+up_y*cs;

            up_x=dx;
            up_y=dy;

            theta_z -= 1;
    }
    else{
        dx = up_x*cs-up_y*sn;
            dy = up_x*sn+up_y*cs;

            up_x=dx;
            up_y=dy;

            theta_z += 1;
    }
}

void Yaw(bool clock = true)
{
//    if(clock) theta++;
//    else theta--;
//    GLfloat dx =0;
//    GLfloat dy = 0;
//    GLfloat dz = -eyeZ;
//
//    GLfloat new_x = dx*cos(theta*PI/180.0)+dz*sin(theta*PI/180.0);
//    GLfloat new_y = dy;
//    GLfloat new_z = -dx*sin(theta*PI/180.0) +dz*cos(theta*PI/180.0);
//
//    lookX = new_x;
//    lookY = new_y;
//    lookZ = -dz+new_z;

    if(clock){
        wcsAlign();
        theta_y += 1;
        retransform();
    }
    else{

        wcsAlign();
            theta_y -= 1;
            retransform();
    }
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
    glBindTexture(GL_TEXTURE_2D, textureID);
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
            glBindTexture(GL_TEXTURE_2D, textureID);
                glutSolidCube(tebal);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
		}

		glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
	}
	glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void spotlight(float x,float y, float z,float spt_cutoff, bool on = true)
{
    GLfloat l_no[] = {0, 0, 0, 1.0};
//    GLfloat l_amb[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat l_amb[] = {1, 1, 1, 1.0};
    GLfloat l_dif[] = {1,1,1,1};
//    GLfloat l_spec[] = {0.2,0.2,0.2,1};
    GLfloat l_spec[] = {1,1,1,1};
//    GLfloat l_pos3[] = {x,y+10,z+10,1.0};

    GLfloat l_pos3[] = {0,0,0,1.0};

    if(on==false){
        glDisable(GL_LIGHT2);
        return;
    }

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

    GLfloat l_spt[] = {1,0,0,0};
    GLfloat spt_ct[] = {30};
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
        glBindTexture(GL_TEXTURE_2D,v[11]);
        glEnable(GL_TEXTURE_2D);
            circle_3D(2.3);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.8, height-0.3, 0);
        glBindTexture(GL_TEXTURE_2D,v[11]);
        glEnable(GL_TEXTURE_2D);
            circle_3D(2.3);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.8, height-0.3, -0.2);
        glBindTexture(GL_TEXTURE_2D,v[11]);
        glEnable(GL_TEXTURE_2D);
            circle_3D(2.3);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


void road()
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
void soil()
{
    // soil
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[2]);
        glPushMatrix();
            glTranslatef(-100,0,0);
            glScalef(200,0,30);
        drawcube(brown[0],brown[1],brown[2],1,1,1);
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[2]);
        glPushMatrix();
            glTranslatef(-100,0,0);
            glScalef(200,0,-30);
        drawcube(brown[0],brown[1],brown[2],1,1,1);
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
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







class Sound {
    public:
        void bombBlustSound()
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("C://Users//shakil//Desktop//lab//project//bombBlustSound.wav"), NULL, SND_ASYNC | SND_FILENAME);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
void destoryedCar()
{
    int buryingCarTexture = 8;

    glPushMatrix();
        glTranslatef(xCar, yCar, zCar);
        glPushMatrix();
            // front light of the car
            glPushMatrix();
                glTranslatef(0,6,0);
                spotlight(0,-3,0,30,0);
            glPopMatrix();

            blok(10, 3, 2, buryingCarTexture);

            glTranslatef(0, 6, 0);
            blok(10, 3, 2, buryingCarTexture);

            glTranslatef(10, -10, 0);
            blok(10, 5.5, 2, buryingCarTexture);

            glRotatef(-35, 0, 0, 15);
            glTranslatef(0, 7, 0);
            blok(10, 2, 2, buryingCarTexture);

            glTranslatef(2, 4.9, -2.5);
            blok(0.5, 20, 31, buryingCarTexture);
            glRotatef(180, 45, -45, 0);

        glPopMatrix();

        // tire
        glPushMatrix();
            // 1
            glTranslatef(20, -8, -9);
//            cylinder(5, 5, 3);
            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3,v[4]);
            glDisable(GL_TEXTURE_2D);

            // 2
            glTranslatef(-20, 8, 9);
            glTranslatef(-5, -8, -9);
//            cylinder(5, 5, 3);
            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3, v[4]);
            glDisable(GL_TEXTURE_2D);



            // 3
//            glColor3f(0.4, 0.4, 0.4);
            glTranslatef(5, 8, 9);
            glRotatef(180, 0, 180, 0);

            glRotatef(90,1,0,0);
            glTranslatef(3, -7, -17);
//            cylinder(5, 5, 3);

            glBindTexture(GL_TEXTURE_2D,v[4]);
            glEnable(GL_TEXTURE_2D);
                cylinder(5, 5, 3,v[4]);
            glDisable(GL_TEXTURE_2D);




            // 4
//            glColor3f(0.4, 0.4, 0.4);
            glTranslatef(-3, 1, 21);
            glTranslatef(-22, -1, -21);
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
//            spotlight(0+xCar,-3+yCar,0+zCar,30);
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


float carMovingSpeed = 5;
void car1()
{
    if(isCarDestoryed==true){
        destoryedCar();
        return;
    }

    if(isCarMakingSound==false){
        makeSomeNoise.carSound(1);
        isCarMakingSound = true;
    }

    glPushMatrix();
        // to move the car
        glTranslatef(xCar, yCar, zCar);
        if(isCarDestoryed == false) xCar += carMovingSpeed;
        if(xCar > carEndingPoing){
            xCar = carStartingPoint;
        }

        Loop++;

        glPushMatrix();

            // front light of the car
            glPushMatrix();
                glTranslatef(0,9,0);
                spotlight(0,-3,0,30);
            glPopMatrix();

            blok(10, 3, 2, v[7]);

            glTranslatef(0, 9, 0);
            blok(10, 3, 2, v[7]);

            glTranslatef(10, -10, 0);
            blok(10, 5.5, 2, v[7]);

            glRotatef(-35, 0, 0, 15);
            glTranslatef(0, 7, 0);
            blok(10, 2, 2, v[7]);

            glTranslatef(2, 4.9, -2.5);
            blok(0.5, 20, 31, v[7]);
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

            glBindTexture(GL_TEXTURE_2D,v[10]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 5,v[10]);
            glDisable(GL_TEXTURE_2D);

            //
            glRotatef(90, 0, 1, 0);
            glTranslatef(0, -0.2, 7);
//            blok(2, 4, 8);
            glBindTexture(GL_TEXTURE_2D,v[10]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 8,v[10]);
            glDisable(GL_TEXTURE_2D);


            //
            glRotatef(0, 0, 0, 0);
            glTranslatef(0, 19.2, 0);
//            blok(2, 4, 8);
            glBindTexture(GL_TEXTURE_2D,v[10]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 8,v[10]);
            glDisable(GL_TEXTURE_2D);



            //
            glRotatef(90, 0, 1, 0);
            glTranslatef(7, 0, -8);
//            blok(2, 4, 5);

            glBindTexture(GL_TEXTURE_2D,v[10]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 5),v[10];
            glDisable(GL_TEXTURE_2D);




            // light front
//            spotlight(0+xCar,-3+yCar,0+zCar,30);
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
            glBindTexture(GL_TEXTURE_2D,v[10]);
            glEnable(GL_TEXTURE_2D);
                blok(2, 4, 8,v[10]);
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
        glScalef(1,0.01,1);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,v[10]);
        glPushMatrix();
            drawcube(white[0], white[1], white[2], 1, 1, 1);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

vector<Point>missilePathPoint;
int pos;
bool shouldThrow;
float xMissile, yMissile, zMissile;
float bombBlastArea = 25;


float bombMovingSpeed = 10;
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
//                    drawcube(white[0],white[1],white[2],1,1,1);

                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,v[0]);
                    glPushMatrix();
                        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                        glEnable(GL_TEXTURE_GEN_T);
                        glBindTexture(GL_TEXTURE_2D, v[17]);
                            glutSolidSphere(0.5,20,20);
                        glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                        glDisable(GL_TEXTURE_GEN_T);
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

                    // is the car within the blast area
//                    if( abs(missilePathPoint[missilePathPoint.size()-1].x - xCar) <= bombBlastArea or
//                        abs(missilePathPoint[missilePathPoint.size()-1].y - yCar) <= bombBlastArea or
//                        abs(missilePathPoint[missilePathPoint.size()-1].z - zCar) <= bombBlastArea ){
//                            // stop the car
//                            isCarDestoryed = true;
//                            makeSomeNoise.bombBlustSound();
//                       }

                    float tempXcar = xCar;
                    float tempYcar = 0;
                    float tempZcar = 16;

                    float xDiff = abs(xTarget - tempXcar);
                    float yDiff = abs(yTarget - tempYcar);
                    float zDiff = abs(zTarget - tempZcar);
//                    cout<<xTarget<<' '<<yTarget<<' '<<zTarget<<endl;
//                    cout<<xCar<<' '<<yCar<<' '<<zCar<<endl;
//                    cout<<"tempCar "<<tempXcar<<' '<<tempYcar<<' '<<tempZcar<<endl;
//                    cout<<missilePathPoint[missilePathPoint.size()-1].x<<' '<<missilePathPoint[missilePathPoint.size()-1].y<<' '<<missilePathPoint[missilePathPoint.size()-1].z<<endl;
//                    cout<<bombBlastArea<<' '<<xDiff<<' '<<yDiff<<' '<<zDiff<<endl;
//                    cout<<endl;
                    if(xDiff <= 150.0 and zDiff <= 10){
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

                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,v[0]);
                    glPushMatrix();
                        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                        glEnable(GL_TEXTURE_GEN_T);
                        glBindTexture(GL_TEXTURE_2D, v[17]);
                            glutSolidSphere(0.5,20,20);
                        glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                        glDisable(GL_TEXTURE_GEN_T);
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);

//                    drawcube(white[0],white[1],white[2],1,1,1);
    //                std::this_thread::sleep_for(std::chrono::milliseconds(5));
    //                pos++;
                    // to speed up the missile, don't use every point on the path
                    pos+=bombMovingSpeed;
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


int treeAnimation = 1;
int cnt = 0;
void maketree(float height,float Base, int textureID = 0)
{
    if(height < 0 or Base < 0) return;
    ++cnt;
    // for tree animation
//    if(cnt > treeAnimation) return;

    if(cnt > 250) return;
	glPushMatrix();
        float angle;
    //	makecylinder(height, Base);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,v[textureID]);
        glPushMatrix();
            makecylinder(height, Base);
//            Cylinder3D(Base, Base - (0.2 * Base), height);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glTranslatef(0.0f, height,0.0f);
        height -= height * 0.25f;
        Base -= Base * 0.1f;

        if (height > 0.2)
        {
            angle = 22.5f;
            glPushMatrix();
                glRotatef(angle, -1.0f, 0.0f, 0.0f);
                maketree(height, Base);
            glPopMatrix();

            glPushMatrix();
                glRotatef(angle, 0.5f, 0.0f, 0.866f);
                maketree(height, Base, 1);
            glPopMatrix();
            glPushMatrix();
                glRotatef(angle, 0.5f, 0.0f, -0.866f);
                maketree(height, Base, 1);
            glPopMatrix();
        }
	glPopMatrix();
}
// factorlTree
void factorlTree()
{
//    // for tree animation
//    cnt = 0;
//    glPushMatrix();
////        glTranslatef(10,3,30);
//        glTranslatef(0, 0, 3);
//        glScalef(3,3,3);
//        maketree(3.0f, 0.1f);
//    glPopMatrix();
//    cnt = 0;


    cnt = 0;
    glPushMatrix();
        glTranslatef(0, 0, 3);
        glScalef(1,1,1);
        maketree(1.0f, 0.1f);
    glPopMatrix();

    cnt = 0;
    glPushMatrix();
        glTranslatef(2, 0, 3);
        glScalef(1,1,1);
        maketree(1.0f, 0.1f);
    glPopMatrix();

    treeAnimation += 1;
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




/// building
struct buildingPosition{
    float xBuilding, yBuilding, zBuilding, buildingHeight;
};
vector<buildingPosition>buildingPos;
bool buildingPositionGenerated = false;

void singleBuilding(float x, float y, float z, int height, int textureID)
{
    glBindTexture(GL_TEXTURE_2D,v[textureID]);
    glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            glTranslatef(x, y, z);
//            glRotatef(45,0,1,0);
            glScaled(5, height, 3);
            drawcube(white[0], white[1], white[2], 1, 1, 1);
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

int texture = 0;
void buildingBuild()
{
    for(auto it:buildingPos){
        singleBuilding(it.xBuilding, it.yBuilding, it.zBuilding, it.buildingHeight, 13 + texture);
        texture++;
        if(texture>=3) texture = 0;
    }
    texture = 0;
    if(buildingPositionGenerated) return;
    buildingPosition Pos;
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
        float zPos = -25 - rand() % originToRoad;
        Pos.xBuilding = xPos; Pos.yBuilding = yPos; Pos.zBuilding = zPos;
        Pos.buildingHeight = rand() % 5 + 1.9;
        buildingPos.push_back(Pos);
        // - +
        xPos = - rand()%rangeFromOrigin;
        yPos = 0;
        zPos = -25 - rand() % originToRoad;
        Pos.xBuilding = xPos; Pos.yBuilding = yPos; Pos.zBuilding = zPos;
        Pos.buildingHeight = rand() % 5 + 1.9;
        buildingPos.push_back(Pos);
    }
    buildingPositionGenerated = true;

    vector<buildingPosition> temp;
    bool vis[buildingPos.size()] = {};
    float radius = 50;
    int maxNumberOfAllowedBuilding = 80;

    for(int i = 0; i < (int)buildingPos.size(); i++){
        if(vis[i]==false){
            temp.push_back(buildingPos[i]);

            vis[i]=true;

            if((int)temp.size() > maxNumberOfAllowedBuilding) break;

//            cout<<"pos "<<i<<' '<<endl;
            for(int j = i+1; j < (int)buildingPos.size(); j++){
                // we will discard all the tree which are with the radius of current tree

                if(vis[j]) continue; // if for some tree this one is already discarded

                float xDiff = abs(buildingPos[i].xBuilding - buildingPos[j].xBuilding) * abs(buildingPos[i].xBuilding - buildingPos[j].xBuilding);
                float yDiff = abs(buildingPos[i].yBuilding - buildingPos[j].yBuilding) * abs(buildingPos[i].yBuilding - buildingPos[j].yBuilding);
                float zDiff = abs(buildingPos[i].zBuilding  - buildingPos[j].zBuilding) * abs(buildingPos[i].zBuilding - buildingPos[j].zBuilding);
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
    buildingPos = temp;
//    cout<<"\n\n\n\n\n";
}

void landscape()
{
    glPushMatrix();
        glTranslatef(-150,0,-30);
        glScalef(300,100,2);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,v[19]);
        glPushMatrix();
            drawcube(white[0],white[1],white[2],1,1,1);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


























typedef float	M3DVector3f[3];
// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void m3dCrossProduct(M3DVector3f result, const M3DVector3f u, const M3DVector3f v)
{
	result[0] = u[1]*v[2] - v[1]*u[2];
	result[1] = -u[0]*v[2] + v[0]*u[2];
	result[2] = u[0]*v[1] - v[0]*u[1];
}

void m3dFindNormal(M3DVector3f result, const M3DVector3f point1, const M3DVector3f point2, const M3DVector3f point3)
{
	M3DVector3f v1,v2;		// Temporary vectors
	// Calculate two vectors from the three points. Assumes counter clockwise
	// winding!
	v1[0] = point1[0] - point2[0];
	v1[1] = point1[1] - point2[1];
	v1[2] = point1[2] - point2[2];
	v2[0] = point2[0] - point3[0];
	v2[1] = point2[1] - point3[1];
	v2[2] = point2[2] - point3[2];
	// Take the cross product of the two vectors to get
	// the normal vector.
	m3dCrossProduct(result, v1, v2);
}


int hatTex = 1, hairTex = 2, handTex = 3, blouseTex = 19;
// Called to draw scene
void RenderScene(void)
{
	GLUquadricObj *pObj; // Quadric object
	M3DVector3f vNormal;	// Storeage for calculated surface normal
	// Clear the window with current clearing color
	/****************************************************************************/
	/****************************************************************************/
	// Save the matrix state and do the rotations
	glPushMatrix();
	glTranslatef(0.0f, 10.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    // Set material color
	glColor3ub(128, 128, 128);
	/********************************************************************************/
	pObj =gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
	//head
	glColor3ub(205,133,63);//body color


	glBindTexture(GL_TEXTURE_2D, v[handTex]);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D, v[17]);
           gluSphere(pObj, 2.5f, 26, 13);
        glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);


	glPushMatrix();
		glColor3ub(0.0f, 0.0f, 0.0f);
		glTranslatef(-1.0, -0.20, 2.4f);
		glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluSphere(pObj, 0.4f, 26, 13);//left eye
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);

        glTranslatef(2.0, 0.0, 0.0f);
        glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluSphere(pObj, 0.4f, 26, 13);//right eye
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//ear
	glPushMatrix();
		glColor3ub(205,133,63);//body color
		glTranslatef(-2.2f, -0.50f, 0.30f);
//		gluSphere(pObj, 0.6f, 26, 13);//left ear
		glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluSphere(pObj, 0.6f, 26, 13);//left ear
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);

		glTranslatef(4.4f, 0.0f, 0.0f);
//		gluSphere(pObj, 0.6f, 26, 13);//rigth ear
		glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluSphere(pObj, 0.6f, 26, 13);//rigth ear
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);


	glPopMatrix();

	//hat(caping)
	glColor3ub(219,219,112);//hat color
	glPushMatrix();
		//glTranslatef(
		glRotatef(240.0f, 1.0f, 0.0f, 0.0f);
		glDisable(GL_CULL_FACE);



            glBindTexture(GL_TEXTURE_2D, v[hatTex]);
            glEnable(GL_TEXTURE_2D);
             glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                    glEnable(GL_TEXTURE_GEN_T);
                    glBindTexture(GL_TEXTURE_2D, v[hatTex]);
                        gluCylinder(pObj, 3.0f, 0.0f, 6.0f, 26, 1);
                    glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                    glDisable(GL_TEXTURE_GEN_T);
            glDisable(GL_TEXTURE_2D);


            glBindTexture(GL_TEXTURE_2D, v[hatTex]);
            glEnable(GL_TEXTURE_2D);
             glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                    glEnable(GL_TEXTURE_GEN_T);
                    glBindTexture(GL_TEXTURE_2D, v[hatTex]);
                        gluCylinder(pObj, 3.0f, 4.0f, 0.5f, 26, 1);
                    glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
                    glDisable(GL_TEXTURE_GEN_T);
            glDisable(GL_TEXTURE_2D);


//            gluCylinder(pObj, 3.0f, 0.0f, 6.0f, 26, 1);
//            gluCylinder(pObj, 3.0f, 4.0f, 0.5f, 26, 1);
		glEnable(GL_CULL_FACE);
	glPopMatrix();


	//hair
	glColor3ub(0,0,0);
	glPushMatrix();
		glTranslatef(0.0f, 0.1f, -0.1f);

		glBindTexture(GL_TEXTURE_2D, v[hairTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[hairTex]);
                gluSphere(pObj, 2.58f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
	//right hair twist
	glPopMatrix();

	//neck+stick
	glColor3ub(205,133,63);//body color
	glPushMatrix();
		glRotatef(90.0f, 1.0, 0.0, 0.0f);
		glDisable(GL_CULL_FACE);


		glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluCylinder(pObj, 0.5f, 0.5f, 29.0f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
		glTranslatef(0.0f, 0.0f, 29.0f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
	glPopMatrix();

	//hand
	//left hand
	glColor3ub(205,133,63);//body color
	glPushMatrix();
		glTranslatef(0.0f, -3.6f, 0.0f);
		glRotatef(160.0f, 1.0, 0.0, 1.0f);
//		gluCylinder(pObj, 0.5f, 0.5f, 13.0f, 26, 13);

		glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluCylinder(pObj, 0.5f, 0.5f, 13.0f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);

		glTranslatef(0.0f, 0.0f, 13.0f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
	glPopMatrix();
	//left hand
	glColor3ub(205,133,63);//body color
	glPushMatrix();
		glTranslatef(0.0f, -3.6f, 0.0f);
		glRotatef(160.0f, 1.0, 0.0, -1.0f);
//		gluCylinder(pObj, 0.5f, 0.5f, 13.0f, 26, 13);
		glBindTexture(GL_TEXTURE_2D, v[handTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[handTex]);
                gluCylinder(pObj, 0.5f, 0.5f, 13.0f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
		glTranslatef(0.0f, 0.0f, 13.0f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
	glPopMatrix();

	//pink blouse
	glColor3ub(	10,10,10);
	//triangle mesh

	glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, v[blouseTex]);

	glBegin(GL_TRIANGLES);


		//1st upper part
		{
        M3DVector3f vPoints[3] = {{3.0f, -3.50f, 0.70f},
								{ 3.0f, -3.50f, -0.70f },
								{-3.0f,-3.50f,-0.70f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//2nd upper part
		{
        M3DVector3f vPoints[3] = {{-3.0f, -3.50f, 0.70f},
								{ 3.0f, -3.50f, 0.70f },
								{-3.0f,-3.50f,-0.70f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//3rd lower part
		{
        M3DVector3f vPoints[3] = {{3.40f, -10.0f, 3.10f},
								{ 3.40f, -10.0f, -3.10f },
								{-3.40f,-10.0f,-3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//4th lower part
		{
        M3DVector3f vPoints[3] = {{-3.40f, -10.0f, 3.10f},
								{ 3.40f, -10.0f, 3.10f },
								{-3.40f,-10.0f,-3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//5th front part
		{
        M3DVector3f vPoints[3] = {{3.0f, -3.50f, 0.70f},
								{-3.0f, -3.50f, 0.70f},
								{ 3.40f, -10.0f, 3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//6th front part
		{
        M3DVector3f vPoints[3] = {{-3.0f, -3.50f, 0.70f},
								{ -3.40f, -10.0f, 3.10f },
								{3.40f, -10.0f, 3.10f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//7th back part
		{
        M3DVector3f vPoints[3] = {{3.0f, -3.50f, -0.70f},
								{ 3.40f, -10.0f, -3.10f },
								{-3.0f, -3.50f, -0.70f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//8th back part
		{
        M3DVector3f vPoints[3] = {{-3.0f, -3.50f, -0.70f},
								{3.40f, -10.0f, -3.10f},
								{ -3.40f, -10.0f, -3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//9th right side part
		{
        M3DVector3f vPoints[3] = {{3.40f, -10.0f, -3.10f},
								{3.0f, -3.50f, -0.7},
								{3.40f, -10.0f, 3.10f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//10th right side part
		{
        M3DVector3f vPoints[3] = {{3.40f, -10.0f, 3.10f},
								{3.0f, -3.50f, -0.7},
								{3.0f, -3.50f, 0.7}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//11th left side part
		{
        M3DVector3f vPoints[3] = {{-3.40f, -10.0f, -3.10f},
								{-3.40f, -10.0f, 3.10f},
								{-3.0f, -3.50f, -0.7}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//12th left side part
		{
        M3DVector3f vPoints[3] = {{-3.40f, -10.0f, 3.10f},
								{-3.0f, -3.50f, 0.7},
								{-3.0f, -3.50f, -0.7}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

	glEnd();
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);

	//puff
	//left puff
	glPushMatrix();
		glTranslatef(-3.2f, -4.40f, 0.0f);
		gluSphere(pObj,1.10f, 26, 13);
		glRotatef(90.0f, 1.0f,  -1.80f, 0.0f);


		glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
                gluCylinder(pObj, 1.1f, 1.4f, 1.0f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);

		glTranslatef(0.0f, 0.0f, 1.0f);
		gluDisk(pObj, 0.0f, 1.4f, 26, 13);
	glPopMatrix();
	//right puff
	glPushMatrix();
		glTranslatef(3.2f, -4.40f, 0.0f);
		gluSphere(pObj,1.10f, 26, 13);
		glRotatef(90.0f, 1.0f,  1.80f, 0.0f);

		glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
                gluCylinder(pObj, 1.1f, 1.4f, 1.0f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);



		glTranslatef(0.0f, 0.0f, 1.0f);

		glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
                gluDisk(pObj, 0.0f, 1.4f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);
//		gluDisk(pObj, 0.0f, 1.4f, 26, 13);
	glPopMatrix();

	//breast
//	glPushMatrix();
//		glTranslatef(-1.2f, -6.50f, 0.50f);
//		gluSphere(pObj,2.0f, 26, 13);//left breast
//		glTranslatef(2.40f, 0.0f, 0.0f);
//		gluSphere(pObj, 2.0f, 26, 13);//rigth breast
//	glPopMatrix();

	//skirt
	//brown skirt
//	glColor3ub(	92,51,23);
//	glPushMatrix();
//		glTranslatef(0.0f, -2.0f, 0.0f);
//		glRotatef(90, 1.0f, 0.0f, 0.0f);
//		gluCylinder(pObj, 0.0f, 7.0f, 18.0f, 26, 13);
//	glPopMatrix();
	//black belt
	glPushMatrix();
	glColor3ub(	0,0,0);
		glTranslatef(0.0f, -10.3f, 0.0f);
		glRotatef(90, 1.0f, 0.0f, 0.0f);

		glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glEnable(GL_TEXTURE_GEN_T);
            glBindTexture(GL_TEXTURE_2D, v[blouseTex]);
                gluCylinder(pObj, 3.3f, 3.5f, 0.8f, 26, 13);
            glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
            glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_2D);

//		gluCylinder(pObj, 3.3f, 3.5f, 0.8f, 26, 13);
	glPopMatrix();
	glPopMatrix();
}





void display(void)
{
//    cout<<eyeX<<' '<<eyeY<<' '<<eyeZ<<endl;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-5,5,-5,5,nearP,farP);
    //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,up_x,up_y,up_z);
    glViewport(0, 0, windowHeight, windowWidth);

//    drawaxes();
    soil();
    road();
////    piler();
////    car();
////    car1();
    resizedCar();


    // bomb
    missileLauncher();
    bomb();
    target();
//
    TreePlant();
    factorlTree();

    buildingBuild();

//    landscape();

    glPushMatrix();
        glTranslatef(3,2,0);
        glScalef(0.15, 0.15, 0.15);
        RenderScene();
    glPopMatrix();


//    fire();

    glFlush();
    glutSwapBuffers();
}

int makeNoise = 1;

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

        case 'h':
            xRot-= 5.0f;
            break;
        case 'n':
            xRot += 5.0f;
            break;

        case 'b':
            yRot -= 5.0f;
            break;

        case 'm':
            yRot += 5.0f;
            break;

        case '[':
            treeAnimation = 1;
            break;
        // sound
        case ',':
            if(makeNoise) {
                PlaySound(TEXT("C://Users//shakil//Desktop//lab//highway.wav"), NULL, SND_ASYNC | SND_FILENAME);
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
            yCar = 12.5;
            break;

        // throw the missile
        case 'o':
            throwTheMissile();
            break;

        // to move the target
        case 'i': // up
            if(canChangeTheTarget==false) break;
            zTarget--;
            break;
        case 'k': // down
            if(canChangeTheTarget==false) break;
            zTarget++;
            break;
        case 'j': // left
            if(canChangeTheTarget==false) break;
            xTarget--;
            break;
        case 'l': // right
            if(canChangeTheTarget==false) break;
            xTarget++;
            break;
        case 'I': // up
            if(canChangeTheTarget==false) break;
            yTarget++;
            break;
        case 'K': // down
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

        case 'p':
            Pitch();
            break;

        case 'P':
            Pitch(false);
            break;


        case 'f':
            FrustumChange();
            break;

        case 'F':
            FrustumChange(false);
            break;
        //ambient light handle
//        case 'A':
//            ambient0 = true;
//            light0();
//            break;
        case 'a':
            ambient0^=1;
            light0();
            break;
        //diffuse light handle
//        case 'D':
//            diffuse0 = true;
//            light0();
//            break;
        case 'd':
            diffuse0^=1;
            light0();
            break;

        //specular light handle
//        case 'S':
//            specular0 = true;
//            light0();
//            break;
        case 's':
            specular0^=1;
            light0();
            break;


        //ambient light handle
//        case 'Q':
//            ambient1 = true;
//            light1();
//            break;
        case 'A':
            ambient1^=1;
            light1();
            break;
        //diffuse light handle
//        case 'W':
//            diffuse1 = true;
//            light1();
//            break;
        case 'D':
            diffuse1^=1;
            light1();
            break;
        //specular light handle
//        case 'E':
//            specular1 = true;
//            light1();
//            break;
        case 'S':
            specular1^=1;
            light1();
            break;
//        case 'h':
        case 'H':
            l_on3^=1;
            break;
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

    glutInitWindowPosition(300,10);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("project");

    texture_image();

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    light0();
//    light1();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
