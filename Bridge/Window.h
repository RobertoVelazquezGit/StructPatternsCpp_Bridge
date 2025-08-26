#pragma once
#include <windows.h>
#include "Point.h"

class Window
{
	HWND m_hWnd{} ;
public:
	Window() ;
	void Show() ;
	static LRESULT CALLBACK CallBackHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ;
	void DrawCircle(Point position, float radius) ;
	void DrawLine(Point start, Point end) ;
};

