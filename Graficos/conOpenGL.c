/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

/**************
 *Declaraciones
 **************/

#include "logo.h"
#include "koch.h"
#include "rama.h"
#include "Dragon.h"
#include "CurvaH.h"
#include "CurvaS.h"
#include "CurvaC.h"
#include "Gosper.h"
#include "CopoC.h"
#include "Poli.h"
#include "Weave.h"
#include "Maze.h"
#include "Trian.h"
#include "CopoE.h"
#include "Hilbert.h"

#define escX 0.125
#define escY 0.125
#define MX 0.0
#define MY 0.0

void segmento(double, double, double, double);
//DibujaSegmentos dibujaSegmento=segmento;



/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "graficos";
    RegisterClass (&wc);

    misFractales miFractal;
    int nRecursion = 8;
    LOGO miTortuga;
    char *miParametro="kochI";

    if (iCmdShow>1) miParametro = lpCmdLine;
    if (strlen(lpCmdLine)==0) miParametro="CopoE"; //SUSTITUIR AQUI EL FRACTAL//
      asignaModoDibujarSegmento(segmento, &miTortuga);
    if((strncmp(miParametro, "koch", 4)==0) ){
    
	iniciaKoch(nRecursion, 10.0, -5.0, 0.0, &miTortuga);
	miFractal = dibujaKoch;	
	}else if (strncmp(miParametro, "rama", 4)==0){
		nRecursion = 10;
        iniciaRama(nRecursion, 60.0, 150, 10.0, -14.3, &miTortuga);
        miFractal = dibujaRama;
      }
	  
	    else if (strncmp(miParametro, "kochII", 6)==0){
        iniciaKoch(nRecursion, 50.0, 50.0, 20.5, &miTortuga);
        miFractal = dibujaKochII;
      }
	  
	    else if (strncmp(miParametro, "kochI", 5)==0){
        iniciaKoch(nRecursion, 50.0, -7.0, 2.5, &miTortuga);
        miFractal = dibujaKochI;
      }
	  
	    else if (strncmp(miParametro, "koch", 4)==0){
        iniciaKoch(nRecursion, 10.0, -5.0, 0.0, &miTortuga);
        miFractal = dibujaKochI;
      }
	    
		else if(strncmp(miParametro, "CurvaC", 6)==0) {
		iniciaCurvaC(17, 0.02, -3, 1.55, &miTortuga);
        miFractal = dibujaCurvaC;
      } 
	  
	    else if(strncmp(miParametro, "Dragon", 6)==0){
		iniciaDragon(17, 0.03, -4.2, -2.5, &miTortuga);
        miFractal = dibujaDragon;
      } 
	  
	    else if(strncmp(miParametro, "Hilbert", 7)==0) {
      	iniciaHilbert(11, -0.3, 8.0, 7.5, &miTortuga);
        miFractal = dibujaHilbert;
      }
	  
	    else if(strncmp(miParametro, "Sierpinski", 6)==0){
		iniciaCurvaS(6, 0.14, -7.4, 7.5, &miTortuga);
        miFractal = dibujaCurvaS;
      } 
	  
	    else if(strncmp(miParametro, "Gosper", 6)==0) {
		iniciaGosper(4, 12, -6.75, 1.75, &miTortuga);
        miFractal = dibujaGosper;
      } 
	  
	    else if(strncmp(miParametro, "CopoC", 5)==0) {
		iniciaCopoC(5, 9, -4.5, 4.5, &miTortuga);
        miFractal = dibujaCopoC;
      } 
	  
	    else if(strncmp(miParametro, "Poli", 4)==0) {
		iniciaPoli(50, 3.4, -1.7, 3.7, 1, 0, &miTortuga);
        miFractal = dibujaPoli;
      } 
	  
	    else if(strncmp(miParametro, "Weave", 5)==0) {
		iniciaWeave(3, 13, -7.5, 0.5, &miTortuga);
        miFractal = dibujaWeave;
      } 
	  
	    else if(strncmp(miParametro, "Maze", 4)==0) {
		iniciaMaze(2, 11, -7, -0.1, &miTortuga);
        miFractal = dibujaMaze;
      } 
	  
	    else if(strncmp(miParametro, "Trian", 10)==0) {
		iniciaTrian(10, 16, -8, 6.5, &miTortuga);
        miFractal = dibujaTrian;
      } 
	    
		else if(strncmp(miParametro, "CopoE", 5)==0) {
		iniciaCopoE(4, 15, -7.5, -4.25, &miTortuga);
        miFractal = dibujaCopoE;
      }

    /* create main window */
    hWnd = CreateWindow (
      "graficos", 
      "Fractales con OpenGL", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 2*256, 2*256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (1.0f, 1.0f, 1.0f, 0.5f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            glRotatef (theta, 0.0f, 0.0f, 1.0f);
            glColor3d(0.0, 0.0, 0.0);

              miFractal();
            glPopMatrix ();

            SwapBuffers (hDC);

            //theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}

void segmento(double x1, double y1, double x2, double y2)
{
  glBegin (GL_LINES);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
  glEnd ();
}

