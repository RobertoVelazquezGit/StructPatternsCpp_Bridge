#include "Window.h"

#include <stdexcept>
LRESULT CALLBACK Window::CallBackHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps{};
		HDC hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProcA(hWnd, message, wParam, lParam);
}

void Window::DrawCircle(Point position, float radius) {
	auto hdc = GetDC(m_hWnd);
	auto left = position.x - radius;
	auto top = position.y - radius;

	auto right = position.x + radius;
	auto bottom = position.y + radius;
	Ellipse(hdc, left, top, right, bottom);
	ReleaseDC(m_hWnd, hdc);
}

void Window::DrawLine(Point start, Point end) {
	auto hdc = GetDC(m_hWnd);
	MoveToEx(hdc, start.x, start.y, nullptr);
	LineTo(hdc, end.x, end.y);
	ReleaseDC(m_hWnd, hdc);
}

void Window::Run() {
	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

Window::Window()
{
	const char* className = "windowclass";
	WNDCLASSA wndclass{};
	wndclass.hInstance = GetModuleHandleA(nullptr);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = CallBackHandler;
	wndclass.hIcon = LoadIcon(wndclass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszClassName = className;
	RegisterClassA(&wndclass);
	m_hWnd = CreateWindowA(className, "MainWindow", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		nullptr,
		nullptr,
		wndclass.hInstance, nullptr);
	if (!m_hWnd)
	{
		throw std::runtime_error{ "Error creating window" };
	}
}

void Window::Show()
{

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);
	
}
