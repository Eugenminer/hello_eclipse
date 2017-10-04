#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON 1    /* идентификатор дл€ кнопочки внутри главного окна */

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int ss) {
 /* создаем и регистрируем класс главного окна */
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

 /* создаем главное окно и отображаем его */
 HWND hMainWnd=CreateWindow("Example 4 MainWnd Class","ZP-41",WS_OVERLAPPEDWINDOW,
 100,100,300,200,NULL,NULL,hInst,NULL);
 if (!hMainWnd) return FALSE;
 ShowWindow(hMainWnd,ss);
 UpdateWindow(hMainWnd);

 MSG msg; /* цикл обработки событий */
 while (GetMessage(&msg,NULL,0,0)) {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
 }
 return msg.wParam;
}

/* процедура обработки сообщений дл€ главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
 switch (msg) {
  case WM_CREATE:
   /* при создании окна внедр€ем в него кнопочку */
   CreateWindow("button","Ќажми мен€",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    100,90,100,20,hw,(HMENU)ID_MYBUTTON,NULL,NULL);
   /* стиль WS_CHILD означает, что это дочернее окно и дл€ него
    вместо дескриптора меню будет передан целочисленный идентификатор,
    который будет использоватьс€ дочерним окном дл€ оповещени€
    родительского окна через WM_COMMAND */
   return 0;
  case WM_COMMAND:
   /* нажата наша кнопочка? */
   if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON))
    MessageBox(hw,"’елло¬орлд дл€ Eclipse","ZP-41",MB_OK|MB_ICONWARNING);
   return 0;
  case WM_DESTROY:
   /* пользователь закрыл окно, программа может завершатьс€ */
   PostQuitMessage(0);
   return 0;
 }
 return DefWindowProc(hw,msg,wp,lp);
}
