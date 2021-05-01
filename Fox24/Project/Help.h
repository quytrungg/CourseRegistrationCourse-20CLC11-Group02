#ifndef HELP_H_
#define HELP_H_

int Convert_wchart_to_int(wchar_t* a, int n);
int Convert_char_to_int(char* a, int n);
char* Convert_int_to_char(int n);
wchar_t* Convert_int_to_wchart(int n);
double Conver_wchart_to_double(wchar_t* a, int n);
void GotoXY(int, int); // Di chuyen den toa do Oxy
void SetColor(int, int); // Chon mau nen va mau chu
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableResizeWindow();
void DisableControlButon(bool Close, bool Min, bool Max);
void ShowScrollBar(BOOL Show);
void ShowCur(bool CursorVisibility);
void Exit();
bool checkFileWithFstream(std::wstring path);

#endif // !HELP_H_

