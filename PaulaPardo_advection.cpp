#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int n_x = 100;
int n_t = 700;
int ancho = 6;

// Produce una copia de un array
void copia(float *u, float *u_c)
{
    for(int i=0; i<n_x; i++) 
        u_c[i] = u[i]; 
}

// Asigna valores de un vector a otro
void past_copy(float *u_p, float *u_c)
{
    for(int i=0; i<n_x; i++) 
        u_p[i] = u_c[i]; 
}

int main()
{
    // Se crean arrays necesarios para el problema
    float *u = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        u[i] = 0;
    
    float *u_past = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        u_past[i] = 0;

    float *u_copy = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        u_copy[i] = 0;

    float *u2 = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        u2[i] = 1;
    
    float *u_past2 = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        u_past2[i] = 0;

    float *u_copy2 = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        u_copy2[i] = 0;

    float *x = (float*)malloc(n_x*sizeof(float)); 
    for (int i=0; i<n_x; i++)
        x[i] = -2.0 + 4.0*i/(n_x); //con n_x= 100 se asegura que si i= 0 entonces x=-2 y si i=n_x entonces x= 2

    float **MatrizU = (float **)malloc(n_x * sizeof(float *));
    for (int i=0; i<n_x; i++)
        MatrizU[i] = (float *)malloc(ancho * sizeof(float));

    float dx = x[1] - x[0];
    float dt = 0.001;
    float c = 1.0;

    for(int i=37; i<62; i++) // i=37 es x= -0.5 e i=62 es x=0.5
        u[i] = 0.5;
    
    // Se inician iteraciones para resolver ecuacion diferencial
    for(int n=0; n<n_t; n++)
    {
        copia(u, u_copy);
        past_copy(u_past, u_copy); 

        copia(u2, u_copy2);
        past_copy(u_past2, u_copy2); 
        
        for(int i=1; i<n_x; i++)
        {
            u[i] = u_past[i] - ((c*dt/dx)*(u_past[i] - u_past[i-1]));
        }
 
        // Se capturan 5 momentos en el desplazamiento de la onda
        if(n == 0)
        {
            for(int i=0; i<n_x; i++) 
            {
                MatrizU[i][1] = u[i];
            }    
        }

        if(n == 175)
        {
            for(int i=0; i<n_x; i++) 
            {
                MatrizU[i][2] = u[i];
            }    
        }
 
        if(n == 350)
        {
            for(int i=0; i<n_x; i++) 
            {
                MatrizU[i][3] = u[i];
            }    
        }
   
        if(n == 525)
        {
            for(int i=0; i<n_x; i++) 
            {
                MatrizU[i][4] = u[i];
            }    
        }
    
        if(n == 700)
        {
            for(int i=0; i<n_x; i++) 
            {
                MatrizU[i][5] = u[i];
            }    
        }

        for(int i=0; i<n_x; i++) 
        {
            MatrizU[i][0] = x[i];
        }
    
    
    // Se imprimen valores de x y de todos los U a cierto tiempo
    for(int i=0;i<n_x;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("%f %s",MatrizU[i][j], " ");
        }
        printf("\n");
    }
        
    }
    
    

}
