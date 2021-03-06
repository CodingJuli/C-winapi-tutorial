#include <Windows.h>

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASSW wc = { 0 };
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"MainWndClass";
	wc.lpfnWndProc = MainWindowProc;

	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(
		L"MainWndClass", L"Textview",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		400, 200, 500, 250,
		NULL, NULL, NULL, NULL
	);

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

void addTextView(HWND hWnd) { //adding hWnd to our function

	CreateWindow(
		"Edit",	//the itemname of the windows.h its like the window name
		"Hello world",	//the text which is shown on creating
		WS_VISIBLE | WS_CHILD |
		WS_BORDER|  //creates a black border around it
		ES_AUTOHSCROLL | ES_AUTOVSCROLL | //horizontal and vertical scrolling
		ES_MULTILINE | //now there is more than one line
		WS_HSCROLL | WS_VSCROLL, //add scrollbars
		20, //pos x		x = left / right
		20, //pos y		y = up / down
		100, //size x
		100, //size y
		hWnd, //hWnd is the window
		NULL,
		NULL,
		NULL
	);

}

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

	switch (msg) {

	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	case WM_CREATE: {		//here we can add all the stuff to the window
		addTextView(hWnd); //its important to give hWnd to the void
		break;	//add break
	}

	}
	return DefWindowProcW(hWnd, msg, wp, lp);
}