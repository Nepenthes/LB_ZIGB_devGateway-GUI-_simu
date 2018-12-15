/*********************************************************************
*						≤‚ ‘‘§±‡“Î¥˙¬Î£¨≤ªœÎ–¥◊¢ Õ			         *
**********************************************************************
---------------------------END-OF-HEADER------------------------------
*/

#include <stddef.h>
#include "GUI.h"
#include "DIALOG.h"
#include "usr_Manage.h"
#include "LCDConf.h"

#include "appChild_A.h"

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

/*********************************************************************
*
*       Dialog IDs
*/

#define ID_BUTTON_DBK_ICON_FUNEXT		0xA0

#define ID_BUTTON_DBK_ICON_SWITCH1		0xA1
#define ID_BUTTON_DBK_ICON_SWITCH2		0xA2
#define ID_BUTTON_DBK_ICON_SWITCH3		0xA3

//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 20)

#ifndef GUI_CONST_STORAGE
#define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_standBy;

extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_standByZigbee;
extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_standByWifi;

extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_infoIconTemperature;
extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_infoIconHumidity;
extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_infoIconElecSum;

extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_buttonFun;
extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_buttonOpenPot;
extern GUI_CONST_STORAGE GUI_BITMAP bmwinMain_buttonClosePot;

/*********************************************************************
*
*       Dialog resource
*
* This table conatins the info required to create the dialog.
* It has been created manually, but could also be created by a GUI-builder.
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {

	{ WINDOW_CreateIndirect,	"Main Screen",		0,									0,	  0, 240, 320, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect,	"funExtendButton",	ID_BUTTON_DBK_ICON_FUNEXT,        200,	 40,  25,  22 },
	{ BUTTON_CreateIndirect,	"sourceButton1",	ID_BUTTON_DBK_ICON_SWITCH1,        80,	100,  80,  85 },
	{ BUTTON_CreateIndirect,	"sourceButton2",	ID_BUTTON_DBK_ICON_SWITCH2,        80,	175,  80,  85 },
	{ BUTTON_CreateIndirect,	"sourceButton3",	ID_BUTTON_DBK_ICON_SWITCH3,        80,	250,  80,  85 },
};

static U8 buttonPressFLG_hold = 0;

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

/*********************************************************************
*
*       _cbDeskWindow_usr
*/
static void _cbDeskWinUsr(WM_MESSAGE * pMsg) {

	WM_HWIN hWin;
	GUI_RECT Rect;

	hWin = pMsg->hWin;

		switch (pMsg->MsgId) {

		case WM_PAINT: {
			
			//GUI_DrawBitmap(&bmbmp_deskBk, 0, 0);
			//GUI_DrawBitmap(&bmbmp_buttonSwitch, 0, 0);

			GUI_SetBkColor(GUI_DARKGRAY);
			GUI_Clear();

		}break;

		default: {
		
			WM_DefaultProc(pMsg);

		}break;
	}
}

/*********************************************************************
*
*       _cbButtonFunExt_usr
*/
static void _cbButtonFunExt(WM_MESSAGE * pMsg) {

	WM_HWIN hWin;
	GUI_RECT Rect;

	hWin = pMsg->hWin;

	switch (pMsg->MsgId) {
		
		case WM_PAINT: {
		
			if (BUTTON_IsPressed(hWin)) {

				//GUI_SetColor(GUI_WHITE);
				//GUI_Clear();
				//GUI_SetAlpha(0xb0);
				//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 0, 0);
				//GUI_SetAlpha(0);

				GUI_DrawBitmap(&bmwinMain_buttonFun, 0, 0);
			}
			else
			{

				GUI_DrawBitmap(&bmwinMain_buttonFun, 0, 0);
			}

		}break;

		default:BUTTON_Callback(pMsg);
	}
}

/*********************************************************************
*
*       _cbButtonPower1_usr
*/
static void _cbButtonPower1Usr(WM_MESSAGE * pMsg) {

	WM_HWIN hWin;
	GUI_RECT Rect;

	static U8 a = 1;

	hWin = pMsg->hWin;

	switch (pMsg->MsgId) {

		case WM_PAINT: {

			if (BUTTON_IsPressed(hWin)) {

				//GUI_SetColor(GUI_WHITE);
				//GUI_Clear();
				//GUI_SetAlpha(0xb0);
				//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 0, 0);
				//GUI_SetAlpha(0);

				//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 22, 12);

				buttonPressFLG_hold ^= 1 << 0;
			}
			else
			{
				(buttonPressFLG_hold & 0x01) ? (GUI_DrawBitmap(&bmwinMain_buttonClosePot, 10, 0)) : (GUI_DrawBitmap(&bmwinMain_buttonOpenPot, 10, 0));
			}

		}break;

		default:BUTTON_Callback(pMsg);
	}
}

/*********************************************************************
*
*       _cbButtonPower2_usr
*/
static void _cbButtonPower2Usr(WM_MESSAGE * pMsg) {

	WM_HWIN hWin;
	GUI_RECT Rect;

	static U8 a = 1;

	hWin = pMsg->hWin;

	switch (pMsg->MsgId) {

		case WM_PAINT: {

			if (BUTTON_IsPressed(hWin)) {

				//GUI_SetColor(GUI_WHITE);
				//GUI_Clear();
				//GUI_SetAlpha(0xb0);
				//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 0, 0);
				//GUI_SetAlpha(0);

				//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 22, 12);

				buttonPressFLG_hold ^= 1 << 1;
			}
			else
			{
				(buttonPressFLG_hold & 0x02) ? (GUI_DrawBitmap(&bmwinMain_buttonClosePot, 10, 0)) : (GUI_DrawBitmap(&bmwinMain_buttonOpenPot, 10, 0));
			}

		}break;

		default:BUTTON_Callback(pMsg);
	}
}

/*********************************************************************
*
*       _cbButtonPower3_usr
*/
static void _cbButtonPower3Usr(WM_MESSAGE * pMsg) {

	WM_HWIN hWin;
	GUI_RECT Rect;

	static U8 a = 1;

	hWin = pMsg->hWin;

	switch (pMsg->MsgId) {

	case WM_PAINT: {

		if (BUTTON_IsPressed(hWin)) {

			//GUI_SetColor(GUI_WHITE);
			//GUI_Clear();
			//GUI_SetAlpha(0xb0);
			//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 0, 0);
			//GUI_SetAlpha(0);

			//GUI_DrawBitmap(&bmwinMain_buttonINTPot, 22, 12);

			buttonPressFLG_hold ^= 1 << 2;
		}
		else
		{
			(buttonPressFLG_hold & 0x04) ? (GUI_DrawBitmap(&bmwinMain_buttonClosePot, 10, 0)) : (GUI_DrawBitmap(&bmwinMain_buttonOpenPot, 10, 0));
		}

	}break;

	default:BUTTON_Callback(pMsg);
	}
}

/*********************************************************************
*
*       _cbCallback
*/
static void _cbCallback(WM_MESSAGE * pMsg){

	WM_HWIN hDlg;
	WM_HWIN hWinSrc;
	int Id;
	int NCode;

	switch (pMsg->MsgId){
	
		case WM_INIT_DIALOG: {
		
			hDlg = pMsg->hWin;

			hDlg = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DBK_ICON_FUNEXT);
			WM_SetHasTrans(hDlg);
			WM_SetCallback(hDlg, _cbButtonFunExt);

			hDlg = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DBK_ICON_SWITCH1);
			WM_SetHasTrans(hDlg);
			WM_SetCallback(hDlg, _cbButtonPower1Usr);

			hDlg = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DBK_ICON_SWITCH2);
			WM_SetHasTrans(hDlg);
			WM_SetCallback(hDlg, _cbButtonPower2Usr);

			hDlg = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_DBK_ICON_SWITCH3);
			WM_SetHasTrans(hDlg);
			WM_SetCallback(hDlg, _cbButtonPower3Usr);

			//WM_InvalidateWindow();

		}break;

		case WM_PAINT: {

			GUI_DrawBitmap(&bmwinMain_standBy, 0, 0);
			GUI_DrawBitmap(&bmwinMain_standByZigbee, 164, 2);
			GUI_DrawBitmap(&bmwinMain_standByWifi, 220, 2);

			GUI_SetTextMode(GUI_TM_TRANS);
			GUI_SetFont(&GUI_Font8x10_ASCII);
			GUI_DispStringHCenterAt("20:14", 25, 5);
			GUI_SetFont(&GUI_Font8_ASCII);
			GUI_DispStringHCenterAt("50", 189, 8);

			GUI_DrawBitmap(&bmwinMain_infoIconElecSum, 20, 30);
			GUI_SetFont(&GUI_Font20_ASCII);
			GUI_DispStringHCenterAt("63.472kwh", 122, 65);

			//GUI_SetBkColor(GUI_DARKGRAY);
			//GUI_Clear();

			//GUI_SetColor(GUI_DARKRED);
			//GUI_SetFont(&GUI_Font16B_ASCII);
			//GUI_DispStringHCenterAt("just a kidding.", 50, 200);
		
		}break;

		case WM_NOTIFY_PARENT: {
		
			Id	  = WM_GetId(pMsg->hWinSrc);
			NCode = pMsg->Data.v;

			switch (Id) {

				case ID_BUTTON_DBK_ICON_FUNEXT: {
			
					switch (NCode) {

						case WM_NOTIFICATION_CLICKED: {
				


						}break;

						case WM_NOTIFICATION_RELEASED: {

							ExecAbout();

						}break;

						case WM_NOTIFICATION_MOVED_OUT: {
						

							
						}break;
					}

				}break;

				case ID_BUTTON_DBK_ICON_SWITCH1: {

					switch (NCode) {

						case WM_NOTIFICATION_CLICKED: {



						}break;

						case WM_NOTIFICATION_RELEASED: {



						}break;

						case WM_NOTIFICATION_MOVED_OUT: {



						}break;
					}

				}break;
			}

		}break;

		default: {
		
			WM_DefaultProc(pMsg);

		}break;
	}
}

/*********************************************************************
*
*       MainTask
*/
void MainTask(void);
void MainTask(void) {

	const GUI_RECT usr_InvalidationArea = {

		0, 0, 240, 320
	};

	int XSize;
	int YSize;

#if GUI_SUPPORT_MEMDEV
	WM_SetCreateFlags(WM_CF_MEMDEV);
#endif
	GUI_Init();
	//
	// Check if recommended memory for the sample is available
	//
	if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {

		GUI_ErrorOut("Not enough memory available.");
		return;
	}
	XSize = LCD_GetXSize();
	YSize = LCD_GetYSize();

	//KEY_BK_SWITCH1 = BUTTON_Create(100, 40,  40, 20, ID_BUTTON_DBK_ICON_SWITCH1, WM_CF_SHOW);
	//KEY_BK_SWITCH2 = BUTTON_Create(100, 120, 40, 20, ID_BUTTON_DBK_ICON_SWITCH2, WM_CF_SHOW);
	//KEY_BK_SWITCH3 = BUTTON_Create(100, 200, 40, 20, ID_BUTTON_DBK_ICON_SWITCH3, WM_CF_SHOW);

	//WM_SetCallback(WM_HBKWIN, _cbDeskWinUsr);

	//KEY_BK_SWITCH1 = BUTTON_CreateIndirect("powerSwitch1", WM_HBKWIN, 100, 50, _cbButtonPower1Usr);

	GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), &_cbCallback, WM_HBKWIN, 0, 0);

	//WM_InvalidateArea(&usr_InvalidationArea);

	GUI_Delay(10);

	while(1){
	
		GUI_Delay(10);
	}
}

/*************************** End of file ****************************/

