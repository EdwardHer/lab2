
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


void display()
{   
   glClearColor (0,0,0.2,0);
    glShadeModel(GL_SMOOTH);
    //  Borrar pantalla y Z-buffer000000
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(0.9,0.5,0.1);
    glRotatef(185,0,1,0);
        glRotatef(rotate_x, 1.0, 0.0, 0.0 );
    glRotatef(rotate_y, 0.0, 1.0, 0.0 );
    glRotatef(rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z);  // Transladar en los 3 ejes
       //glRotatef(90,1,0,0);
   /* gluLookAt(0.0,0.0,-0.94, //punto de vista en el eje X,Y,Z
             -0.250,0.0,0.250, //Centro del Objeto en el eje X,Y,Z
             0.0,1.0,1.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
     */   
    glTranslatef(-0.5,-.50,0.0);

    glRotatef(20,1,0,0);
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
    glLineWidth(150);
    glBegin(GL_LINES);
    //lineas del cuadro
    glColor3f(0,0,0);
    glVertex3f(0,0.508,0);
    glVertex3f(0,0.508,3);

    glVertex3f(0.008,0.508,0);
    glVertex3f(0.008,1,0);

    glVertex3f(0,0.508,0);
    glVertex3f(1.25,0.508,0);
    
    glVertex3f(1.25,0.5,3);
    glVertex3f(1.25,0.5,3);

    glVertex3f(1.245,0.508,0);
    glVertex3f(1.245,1,0);

    glVertex3f(1.248,0.508,0);
    glVertex3f(1.248,0.508,3);
    glEnd();
    glFlush ();
//cuadro cara izquierda
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0,0.5,0);
    glVertex3f(0,0.5,3);
    glVertex3f(0,1,3);
    glVertex3f(0,1,0);
    glEnd();
    //atras
    glBegin(GL_POLYGON);
    glVertex3f(0,0.5,0);
    glVertex3f(1.25,0.5,0);
    glVertex3f(1.25,1,0);
    glVertex3f(0,1,0);
    glEnd();
    //derecha
    glBegin(GL_POLYGON);
    glVertex3f(1.25,0.5,0);
    glVertex3f(1.25,1,0);
    glVertex3f(1.25,1,3);
    glVertex3f(1.25,0.5,3);
    glEnd();
    glFlush();
    //cuadro atras
    
    // Resetear transformaciones
        
    // Rotar en el eje X,Y y Z


    //glRotatef(15,1,0,0);
    GLfloat ejey=-0.0f,ejex=-0.855f,cons=0.25f;
    int col=0;
    for(int y=0; y<=11;y++){
        
        ejex=-0;
        for(int x=0; x<=4;x++){
            
            
             if(col==0){
                glColor3f(0,0,0);
                col=1;
            }
            else{
                glColor3f( 1.0, 1.0, 1.0 );
                col=0;
            }
           glBegin(GL_QUADS);
                glVertex3f(ejex,0.5,ejey);
                glVertex3f(ejex+cons,0.5,ejey);
               glVertex3f(ejex+cons,0.5,ejey+cons);
                glVertex3f(ejex,0.5,ejey+cons);
            
              /*  glVertex3f(ejex,-0.000001,ejey);
                glVertex3f(ejex+cons,-0.000001,ejey);
                glVertex3f(ejex+cons,-0.000001,ejey+cons);
                glVertex3f(ejex,-0.000001,ejey+cons);
*/
            glEnd();
            glFlush();     
            ejex=ejex+cons;
        }
        ejey=ejey+cons;
    }

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
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}