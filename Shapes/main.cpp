
// Only one of them
#define ENABLE_OPENGL
//#define ENABLE_GDI_WINDOWS

#ifdef ENABLE_OPENGL
// Only one of them
#define ENABLE_OPENGL_LINE
//#define ENABLE_OPENGL_CIRCLE
#endif

//#include <simple2d.h>
#include "my_simple2d.h"  

#include "Circle.h"
#include "Circle_OpenGL.h"
#include "Line.h"
#include "Line_OpenGL.h"

void RenderShape(Shape* pShape) {
	pShape->Draw();
}
void Software() {
	Window window{};
	window.Show();
	Line l{ {100,100}, {300, 300}, &window };
	//l.Draw() ;
	Circle c{ {500, 500}, 50, &window };
	//c.Draw() ;

	RenderShape(&l);
	RenderShape(&c);
	window.Run();
}

void OpenGL() {
#ifdef ENABLE_OPENGL_CIRCLE
	S2D_Window* pWin = S2D_CreateWindow("MainWindow", 800, 600, nullptr, &Circle_OpenGL::Render,
		S2D_RESIZABLE);
	Circle_OpenGL c{ {300, 300}, 100, pWin };
	c.Draw();
#elif defined ENABLE_OPENGL_LINE
	S2D_Window* pWin = S2D_CreateWindow("MainWindow", 800, 600, nullptr, &Line_OpenGL::Render,
		S2D_RESIZABLE);
	Line_OpenGL l{{100,100}, {300, 300}, pWin} ;
	l.Draw() ;
#endif

	S2D_Show(pWin);
	S2D_FreeWindow(pWin);
}

int main(int argc, char* argv[]) {
#ifdef ENABLE_OPENGL
	OpenGL();
#elif defined ENABLE_GDI_WINDOWS
	Software();
#endif
	return 0;
}


// See project options: Debug, x64
// VC++ Directories Include, Library. Linker Input Aditional Depencencies simple2d.lib
// C:\Users\vmrob\AppData\Local\simple2d <-- Configured in PATH variable in environment, is where the bunch of *.dll reside,
// is where the the simple2d.h resides, simple2d.h makes include of C:\Users\vmrob\AppData\Local\simple2d\SDL2

