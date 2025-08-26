
// Only one of them
//#define ENABLE_WITHOUT_AUX_CLASS
#define ENABLE_WITH_AUX_CLASS

#include "Line.h"
#include "Circle.h"
#include "GDI.h"
#include "OpenGL.h"

// Static or compile time bridge
class Line_GDI : public Line, private GDI {
	using Line::Line;
public:
	void Draw() override {
		RenderLine(GetStart(), GetEnd());
		Show();
	}
};

void RenderShape(Shape* s, Renderer* r) {
	s->SetRenderer(r);
	s->Draw();
	r->Show();
}

int main(int argc, char* argv[]) {  // Needed by simple2d, int main() does not work
#ifdef ENABLE_WITHOUT_AUX_CLASS
	Line line{{100, 100}, {100, 300}} ;
	Circle circle{{400, 400}, 100} ;

	GDI gdi{} ;
	OpenGL opengl{} ;

	RenderShape(&circle, &opengl) ;
#elif defined ENABLE_WITH_AUX_CLASS
	Line_GDI lg{ {100, 100}, {100, 300} };
	lg.Draw();
#endif
	return 0;  // Needed by simple2d
}

