#include <gl/gl.h>
#include <math.h>
void cubo()
{
    glBegin(GL_QUADS);

        //frente
        glColor3f(1,0,0);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);

        //direita
        glColor3f(0,1,0);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,0.5);

        //tras
        glColor3f(0,1,1);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,0.5);

        //esquerda
        glColor3f(1,0,1);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);

        //cima
        glColor3f(1,0.5,1);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,0.5,0.5);

        //baixo
        glColor3f(1,1,0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);

    glEnd();
}

void anel()
{
    int i = 0;
    float n = 30;
    for(i=0; i<n; i++)
    {
        glPushMatrix();
        glRotatef(i * 12, 0, 0, 1);
        glTranslatef(0, 16.5, 0);
        glScalef(2.0, 1.0, 4.0);
        cubo();
        glPopMatrix();

        glPushMatrix();
        glRotatef(i * 12, 0, 0, 1);
        glTranslatef(1.5, 16.5, 2.0);
        glScalef(3.2, 1.0, 1.0);
        cubo();
        glPopMatrix();
    }
}

void linhas_suporte()
{
    //circulo
    float raio = 16.5;
    float thetaf = 2*M_PI;
    float thetai = 0;
    float du = (thetaf-thetai)/50;
    float u = thetai;
    glColor3f(0,0,0);

    glBegin(GL_LINE_LOOP);
    while(u<=thetaf)
    {
        glVertex2f(raio*cos(u), raio*sin(u));
        u = u + du;
    }
    glEnd();
}

//base da figura
void plano()
{
    glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable(GL_BLEND);

    glBegin(GL_QUADS);
        glColor4f(0,0,0,0.2);
        glVertex3f(-40,40,-2);
        glVertex3f(-40,-40,-2);
        glVertex3f(40,-40,-2);
        glVertex3f(40,40,-2);
    glEnd();
}

void face_cubo()
{
    for(int i=-0.5; i>=0.5; i=i+0.1)
    {
        for(int j=-0.5; j>=0.5; j=j+0.1)
        {
            glBegin(GL_LINE_LOOP);
                glColor3f(1,0,0);
                glVertex3f(0.5,i,j);
                glVertex3f(0.5,i,j);
                glVertex3f(0.5,i,j);
                glVertex3f(0.5,i,j);
            glEnd();

        }
    }

//    glBegin(GL_QUADS);
//        glColor3f(1,0,0);
//        glVertex3f(0.5,0.5,0.5);
//        glVertex3f(0.5,-0.5,0.5);
//        glVertex3f(0.5,-0.5,-0.5);
//        glVertex3f(0.5,0.5,-0.5);
//    glEnd();
}



