#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON 1    /* ������������� ��� �������� ������ �������� ���� */

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int ss) {
 /* ������� � ������������ ����� �������� ���� */
 WNDCLASS wc;
 wc.style=0;
 wc.lpfnWndProc=MainWinProc;
 wc.cbClsExtra=wc.cbWndExtra=0;
 wc.hInstance=hInst;
 wc.hIcon=NULL;
 wc.hCursor=NULL;
 wc.hbrBackground=(HBRUSH)(COLOR_WINDOW);
 wc.lpszMenuName=NULL;
 wc.lpszClassName="Example 4 MainWnd Class";
 if (!RegisterClass(&wc)) return 0;

 /* ������� ������� ���� � ���������� ��� */
 HWND hMainWnd=CreateWindow("Example 4 MainWnd Class","ZP-41",WS_OVERLAPPEDWINDOW,
 100,100,300,200,NULL,NULL,hInst,NULL);
 if (!hMainWnd) return FALSE;
 ShowWindow(hMainWnd,ss);
 UpdateWindow(hMainWnd);

 MSG msg; /* ���� ��������� ������� */
 while (GetMessage(&msg,NULL,0,0)) {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
 }
 return msg.wParam;
}

/* ��������� ��������� ��������� ��� �������� ���� */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
 switch (msg) {
  case WM_CREATE:
   /* ��� �������� ���� �������� � ���� �������� */
   CreateWindow("button","����� ����",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    100,90,100,20,hw,(HMENU)ID_MYBUTTON,NULL,NULL);
   /* ����� WS_CHILD ��������, ��� ��� �������� ���� � ��� ����
    ������ ����������� ���� ����� ������� ������������� �������������,
    ������� ����� �������������� �������� ����� ��� ����������
    ������������� ���� ����� WM_COMMAND */
   return 0;
  case WM_COMMAND:
   /* ������ ���� ��������? */
   if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON))
    MessageBox(hw,"���������� ��� Eclipse","ZP-41",MB_OK|MB_ICONWARNING);
   return 0;
  case WM_DESTROY:
   /* ������������ ������ ����, ��������� ����� ����������� */
   PostQuitMessage(0);
   return 0;
 }
 return DefWindowProc(hw,msg,wp,lp);
}
