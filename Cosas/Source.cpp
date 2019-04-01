#include <Windows.h>
#include "resource.h"


#include <iostream>
#include <tchar.h>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char e1[10] = "";

static HWND hEdit2 = 0;
char e2[10] = "";


char re[20] = "";






using namespace std;

HWND ghDlg = 0;
HINSTANCE _ghInst;

int _gShow = 0;

BOOL CALLBACK ProcDialog1(HWND Dlg, UINT Mensaje, WPARAM wParam, LPARAM lparam);

void Acumular(int n);
void Acumular2(int n);
 
 double Num1 = 0; double ANum1 = 0;
 double Num2 = 0;
 double R = 0;

int flag = -1;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmd, int show)
{

	_ghInst = hInst;
	_gShow = show;
	ghDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, ProcDialog1);
	ShowWindow(ghDlg, show);
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}


BOOL CALLBACK ProcDialog1(HWND Dlg, UINT Mensaje, WPARAM wParam, LPARAM lparam)
{
	
	
	
	
	char aux[]="";
	

	
	

	switch (Mensaje)
	{
	case WM_INITDIALOG:
	{
		
		//hEdit2 = GetDlgItem(Dlg, IDC_EDIT3);


		hEdit2 = 0;
		hEdit2 = GetDlgItem(Dlg, IDC_Edit5);


		//SetWindowText(hEdit2, "0");

		return true;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case IDC_p:
		{

			
			char Num[50] = "0";
			//Num = atof(ANum1);
			printf(Num, ANum1);
			//Num = { "dsds" };

			//snprintf(Num, sizeof Num, "%f", ANum1);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}

		case IDC_negativo:
		{
			char Num[50] = "0";
			ANum1 = -ANum1;

			snprintf(Num, sizeof Num, "%f", ANum1);
			//_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_0:
		{
			char Num[50] = "0";
			Acumular(0);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_1:
		{
			char Num[50] = "0";
			Acumular(1);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_2:
		{
			char Num[50] = "0";
			Acumular(2);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_3:
		{
			char Num[50] = "0";
			Acumular(3);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_4:
		{
			char Num[50] = "0";
			Acumular(4);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_5:
		{
			char Num[50] = "0";
			Acumular(5);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_6:
		{
			char Num[50] = "0";
			Acumular(6);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_7:
		{
			char Num[50] = "0";
			Acumular(7);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_8:
		{
			char Num[50] = "0";
			Acumular(8);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}
		case IDC_9:
		{
			char Num[50] = "0";
			Acumular(9);
			_itoa(ANum1, Num, 10);
			SendMessage((HWND)hEdit2, (UINT)WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			return true;
		}


		case IDC_BUTTON_SUMA:
		{
			SendMessage(hEdit2, WM_GETTEXT, 10, (LPARAM)e1);
			
			

			flag=0;
			SetWindowText(hEdit2, 0);
			ANum1 = 0;
			
			//HWND SetFocus(hEdit2 );
			
			return true;
		}
		case IDC_BUTTON_RESTA:
		{
			SendMessage(hEdit2, WM_GETTEXT, 10, (LPARAM)e1);
			
			flag = 1;
			SetWindowText(hEdit2, 0);
			ANum1 = 0;
		
			return true;
		}
		case IDC_BUTTON_MULTI:
		{
			SendMessage(hEdit2, WM_GETTEXT, 10, (LPARAM)e1);
			
			flag = 2;
			SetWindowText(hEdit2, 0);
			ANum1 = 0;
			
			return true;
		}
		case IDC_DIV:
		{
			SendMessage(hEdit2, WM_GETTEXT, 10, (LPARAM)e1); 
			
			flag = 3;
			SetWindowText(hEdit2, 0);
			ANum1 = 0;

			return true;
		}
		case IDC_RAIZ:
		{
			SendMessage(hEdit2, WM_GETTEXT, 10, (LPARAM)e1);
			
			Num1 = atoi(e1);//Num1 = strtod(e1,0);
			R = sqrt(Num1);

			snprintf(re, sizeof re, "%f", R);
			
			//MessageBox(Dlg,e1,"",MB_OK);

			//_itoa(Num1, e1, 10);
			SetWindowText(hEdit2, re);
			ANum1 = 0;

			return true;
		}
		case IDC_BUTTON_LIMP:
		{
			
			SetWindowText(hEdit2, 0);
			
			flag = -1;
			ANum1 = 0;
			return true;
		}
		case IDC_CE:
		{

			SetWindowText(hEdit2, 0);
			ANum1 = 0;
			return true; 
		}

		case IDC_IGUAL:
		{
			ANum1 = 0;
			Num1 = 0;
			Num2 = 0;
			SendMessage(hEdit2, WM_GETTEXT, 10, (LPARAM)e2);

			Num2 = atof(e2);
			Num1 = atof(e1);

			/*snprintf(e1, sizeof e1, "%f", Num1);

			MessageBox(Dlg, e1, "e1", MB_OK);
*/
			
			switch (flag) {
			case 0: {
			
				
				R = Num1 + Num2;
				snprintf(re, sizeof re, "%f", R);
				//_itoa(R, re, 10);
				SetWindowText(hEdit2, re);
				
				break;
			}
			case 1: {


				R = Num1 - Num2;
				snprintf(re, sizeof re, "%f", R);
				SetWindowText(hEdit2, re);

				break;
			}
			case 2: {


				R = Num1 * Num2;


				snprintf(re, sizeof re, "%f", R);
				SetWindowText(hEdit2, re);

				break;
			}
			case 3: {


				R = Num1 / Num2;
				snprintf(re, sizeof re, "%f", R);
				
				SetWindowText(hEdit2, re);

				break;
			}
			case 4: {


				break;
			}

			default:
				break;
			
			}
			return true;
		}

		


		
		
		}

		return true;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return true;
	}
	case WM_DESTROY:
	{

		return true;
	}
	}



	return false;
}

void Acumular(int n)
{
	ANum1 = ANum1 * 10 + n;
}
void Acumular2(int n)
{
	ANum1 = ANum1 * 10 + n;
}
