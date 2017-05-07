
//crear cubo

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.0f;

void patas(float x , float z){
    float con = 0;
    for(int p = 0; p<10; p++ ){
        glPushMatrix();
        glTranslatef(x,0.05+con,z);
        glutSolidCube(0.05);
        glPopMatrix();
        con+=0.05;
    }
}
void tablas(){
    float conx = 0, conz=0;
    for(int p = 0; p<30; p++ ){
        conx=0;
        for (int i = 0; i < 21; ++i)
        {
            glPushMatrix();
            glTranslatef(0.25+conx,.5,0.2+conz);
            glutSolidCube(0.05);
            glPopMatrix();
            conx+=0.05;    /* code */
        }
       conz+=0.05;
    }
}
void display()
{ 

   glClearColor (0,0,0.2,0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,0,5);
    glEnd();
    glFlush();
    glPushMatrix();
    glShadeModel (GL_SMOOTH);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
  // glEnable(GL_DEPTH_TEST);
   GLfloat position[] = { 0, 19,6, 3};
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLightfv (GL_LIGHT0, GL_POSITION, position);

glPushMatrix();
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, -4, 4);
    glScalef(0.9,1,0.9);
    glRotatef(35,1,0,0);
    glRotatef(-45,0,1,0);
    
   // glRotatef(-35,0,0,1);
    //glRotatef(-15,0,1,0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0 );
    glRotatef(rotate_y, 0.0, 1.0, 0.0 );
    glRotatef(rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z);  // Transladar en los 3 ejes
       //glRotatef(90,1,0,0);
   /* gluLookAt(0.0,0.0,-0.94, //punto de vista en el eje X,Y,Z
             -0.250,0.0,0.250, //Centro del Objeto en el eje X,Y,Z
             0.0,1.0,1.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
     */   
    glTranslatef(-0.0,-.30,0.0);

    glRotatef(15,0,1,0);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(1.f,0.0f,.0f);
    glVertex3f(.0f,0.f,-.0f);
    glColor3f(0,1,0);
    glVertex3f(0.f,.00f,0.0f);
    glVertex3f(-0.0f,1.f,0.0f);
    glColor3f(0,0,1);
    glVertex3f(0.f,-0.0f,.0f);
    glVertex3f(-0.0f,0.f,1.0f);
    glEnd();
//cuadro cara izquierda
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,3);
    glVertex3f(0,3,3);
    glVertex3f(0,3,0);
    glEnd();
    //atras
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(3,0,0);
    glVertex3f(3,3,0);
    glVertex3f(0,3,0);
    glEnd();
    //ABAJO
     glBegin(GL_POLYGON);
     glColor3f(0,0,0);
    glVertex3f(0,0,0);
    glVertex3f(3,0,0);
    glVertex3f(3,0,3);
    glVertex3f(0,0,3);
    glEnd();
    //derecha
    glFlush();
    glColor3f(1,0,0);
    //tetera
    glPushMatrix();
    glTranslatef(1,0.7,0.75);
    glutSolidTeapot(0.2);
    //glutSolidCube(0.1);
    glPopMatrix();
    glColor3f(1,0.7,1);

    //******mesa******
    //patas
    patas(0.25,0.2);
    patas(0.25,1.7);
    patas(1.25,0.2);
    patas(1.25,1.7);
    //tabñe
    tablas();
    glutPostRedisplay();
    glutSwapBuffers();


}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;

    //  Solicitar actualización de visualización
    glutPostRedisplay();

}

// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 'q':
        exit(0);            // exit
    }
    glutPostRedisplay();
}



int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Cubo controlado por teclas");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    //glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}