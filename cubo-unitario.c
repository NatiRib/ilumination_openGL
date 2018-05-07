#include <gl/gl.h>
#include <math.h>

void face_cubo(float xmin, float xmax, float ymin, float ymax, float valor_x)
{
    float x, y, dx, dy;
    dx = (xmax-xmin) / 20;
    dy = (ymax-ymin) / 20;

    x = xmin;

    while(x < xmax)
    {
        y = ymin;
        while (y < ymax)
        {
            glBegin(GL_QUADS);
                glNormal3f(1,0,0);
                glVertex3f(valor_x,x,y);
                glVertex3f(valor_x,x+dx,y);
                glVertex3f(valor_x,x+dx,y+dy);
                glVertex3f(valor_x,x,y+dy);
            glEnd();
            y = y + dy;
        }
        x = x + dx;
    }
}

void cubo_unitario()
{
    glColor3f(1,0,0); //vermelho //frente
    face_cubo(-0.5, 0.5, -0.5, 0.5, 0.5);

    glPushMatrix();
    glColor3f(0,1,0); //verde //direita
    glRotated(90,0,0,1);
    face_cubo(-0.5, 0.5, -0.5, 0.5, 0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1); // azul //esquerda
    glRotated(-90,0,0,1);
    face_cubo(-0.5, 0.5, -0.5, 0.5, 0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);//preto //tras
    glRotated(-180,0,0,1);
    face_cubo(-0.5, 0.5, -0.5, 0.5, 0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5); //cinza //cima
    glRotated(-90,0,1,0);
    face_cubo(-0.5, 0.5, -0.5, 0.5, 0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,1); //rosa //baixo
    glRotated(90,0,1,0);
    face_cubo(-0.5, 0.5, -0.5, 0.5, 0.5);
    glPopMatrix();
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
        cubo_unitario();
        glPopMatrix();

        glPushMatrix();
        glRotatef(i * 12, 0, 0, 1);
        glTranslatef(1.5, 16.5, 2.0);
        glScalef(3.2, 1.0, 1.0);
        cubo_unitario();
        glPopMatrix();
    }
}

void plano()
{
    glPushMatrix();
    glColor3f(0.5,0,0);
    glRotated(90,0,1,0);
    face_cubo(-20, 20, -20, 20, 2);
    glPopMatrix();
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












