#include <gl/gl.h>
#include <math.h>

void Configura_Material()
{
    glEnable(GL_COLOR_MATERIAL);

    float ka[4] = {0.0, 0.0, 0.0, 1.0};
    float kd[4] = {0.8, 0.8, 0.8, 1.0};
    float ks[4] = {0.5, 0.4, 0.1, 1.0};
    float ke[4] = {0.0, 0.0, 0.0, 1.0};
    int n = 20;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ka);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ks);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, ke);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, n);
}

void Configura_Fonte_Pontual(float p[])
{
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    float LAP[4] = {0.0, 0.0, 0.0, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LAP);

    glLightfv(GL_LIGHT0, GL_POSITION, p);

    //intensidade luminosa de cada componente
    float la[4] = {0.0, 0.0, 0.0, 0.0};
    float ld[4] = {0.8, 0.8, 0.8, 1.0};
    float ls[4] = {0.2, 0.2, 0.2, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, la);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ld);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ls);

    //constantes de atenuacao atmosferica
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
}

void Desenha_Fonte_Pontual(float p[])
{
    glDisable(GL_LIGHTING);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
        glVertex3fv(p);
    glEnd();
}

void Configura_Fonte_Refletora(float p[])
{
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    float LAP[4] = {0.0, 0.0, 0.0, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LAP);

    float d[3] = {0.0, 0.0, -1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, p);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, d);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1);

    float la[4] = {0.0, 0.0, 0.0, 0.0};
    float ld[4] = {0.8, 0.8, 0.8, 1.0};
    float ls[4] = {0.2, 0.2, 0.2, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, la);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ld);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ls);

    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
}

void Desenha_Fonte_Refletora(float p[])
{
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
        glLoadIdentity();
        glTranslatef(p[0], p[1], p[2]);
        glPointSize(5);
        glEnable(GL_POINT_SMOOTH);

        glBegin(GL_POINTS);
            glVertex3f(0.0, 0.0, 0.0);
        glEnd();

        glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, -1.0);
        glEnd();

        float u = 0;
        float r = 0.5*tan(30*M_PI/180);
        float du = 2*M_PI/10;
        while(u < 2*M_PI)
        {
            glBegin(GL_LINE_LOOP);
                glVertex3f(0.0, 0.0, 0.0);
                glVertex3f(r*cos(u), r*sin(u), -0.5);
                glVertex3f(r*cos(u+du), r*sin(u+du), -0.5);
            glEnd();
            u = u+du;
        }
        glPopMatrix();
}

