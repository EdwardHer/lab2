#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 10.0f;
GLfloat zoom =0.1f;
GLfloat Y = 10.0f;
GLfloat Z = 10.0f;
GLfloat scale = 10.0f;

void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 10;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 10;
    else if (key == GLUT_KEY_UP)
        rotate_x += 10;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 10;
    glutPostRedisplay();

}
float conx =21.87, a=0, conz=31.25;
void poly2(){
    GLfloat ejey=0.0f,ejex=-10,consx=23.214f,consz=31.25,sepa=1;;
      int col=0, a=0,b=10;
    for(int y=0; y<=3;y++){
        
        ejex=-150;b=30;a=0;
        for(int x=0; x<=12;x++){

           glBegin(GL_QUADS);
                glVertex3f(ejex+sepa,ejey+sepa,-150+a);
                glVertex3f(ejex+consx,ejey+sepa,-150+b);
               glVertex3f(ejex+consx,ejey+consz,-150+b);
                glVertex3f(ejex+sepa,ejey+consz,-150+a);
             if (b==30)
                       {
                          a=30;
                          b=0; /* code */
                       }      
                else{
                    b=30;
                    a=0;
                } 
            glEnd();
            glFlush(); 
            sepa=2;    
            ejex=ejex+consx;
        }
        ejey=ejey+consz;
    }
}
void color(float a[3], float b[3], float c[3], float d[]){
    glMaterialfv(GL_FRONT, GL_AMBIENT, a);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, b);
    glMaterialfv(GL_FRONT, GL_SPECULAR, c);
    glMaterialfv(GL_FRONT, GL_SHININESS, d);
}

void poly(){
    GLfloat ejey=-150.0f,ejex=-150,consx=23.214f,consz=31.25,sepa=2;;
    for(int y=0; y<=8;y++){
        
        ejex=-150,a=0;
        for(int x=0; x<=12;x++){

           glBegin(GL_QUADS);
                glVertex3f(ejex+sepa,0,ejey+sepa);
                glVertex3f(ejex+consx,0,ejey+sepa);
               glVertex3f(ejex+consx,0,ejey+consz);
                glVertex3f(ejex+sepa,0,ejey+consz);
            glEnd();
            glFlush(); 
            sepa=2;    
            ejex=ejex+consx;
        }
        ejey=ejey+consz;
    }
}
void init(void)
{
	glClearColor(1,1,1,0);
    glShadeModel(GL_SMOOTH);
// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { -200, 100.0, 200.0, 1.0 };
    GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };


// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
   glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPushMatrix();
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-200, 200, -200, 200, -200, 200);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{
// Propiedades del material
    glPushMatrix();
    GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
    GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
    GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
    GLfloat shine[] = {27.8974f};

// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

    glRotatef( rotate_x, 200.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 200.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 200.0 );
    glTranslatef(X, Y, Z);  
    //glPushMatrix();
//setMaterial
    /*glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
*/
    color(mat_ambient,mat_diffuse,mat_specular,shine);

    glRotatef(20,1,0,0);
    glRotatef(0,0,1,0);
    poly();
    poly2();
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(200.f,0.0f,.0f);
    glVertex3f(.0f,0.f,-.0f);
    glColor3f(0,1,0);
    glVertex3f(0.f,.00f,0.0f);
    glVertex3f(-0.0f,200.f,0.0f);
    glColor3f(0,0,1);
    glVertex3f(0.f,-0.0f,.0f);
    glVertex3f(-0.0f,0.f,200.0f);
    glEnd();
    //glutSolidTeapot(125.0);
    //glutSolidCube(125.0);

    //********movemos las fieguras para alejarlas del centro
    glTranslatef(0,40,85);
    glPushMatrix();
   // GLfloat light_position[] = { 00, 100.0, 120.0, 1};
    //glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glRotatef(-15,0,1,0);
    glRotatef(10,1,0,0);
    //color de la esfera
    GLfloat mat_a2[] = { 0.05f, 0.05f, 0.0f,1.0f };
    GLfloat mat_d2[] = { 0.5f, 0.5f, 0.4f, 1.0f };
    GLfloat mat_s2[] = { 0.7f, 0.7f, 0.04f, 1.0f };
    GLfloat shine3[] = {0.07812};
    color(mat_a2,mat_d2,mat_s2,shine3);
    glutSolidCube(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-100,0,0);
    //color de la esfera
    GLfloat mat_a[] = { 0.05f, 0.0f, 0.0f,1.0f };
    GLfloat mat_d[] = { 0.5f, 0.4f, 0.4f, 1.0f };
    GLfloat mat_s[] = { 0.7f, 0.04f, 0.04f, 1.0f };
    GLfloat shine2[] = {0.078125};
    color(mat_a,mat_d,mat_s,shine2);
    glutSolidSphere(40,40,40);
    glPopMatrix();      

    glPushMatrix();
    glTranslatef(100,-25,0);
    glRotatef(-90,1,0,0);
    //color al cono
    GLfloat mat_a3[] = { 0.f, 1.0f, 0.0f,1.0f };
    GLfloat mat_d3[] = { 0.5f, 0.4f, 0.4f, 1.0f };
    GLfloat mat_s3[] = { 0.7f, 0.04f, 0.04f, 1.0f };
    GLfloat shine4[] = {0.078125};
    color(mat_a3,mat_d3,mat_s3,shine4);
    glutSolidCone(40,60,10,25);
    glPopMatrix();

    glFlush();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}

// Main del programa.
int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Teapot");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
     glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}