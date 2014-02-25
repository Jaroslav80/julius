#include "Window.h"
#include "AllWindows.h"
#include "TopMenu.h"
#include "PopupDialog.h"

#include "../Data/Mouse.h"

struct Window {
	void (*init)(void);
	void (*drawBackground)(void);
	void (*drawForeground)(void);
	void (*handleMouse)(void);
};

static void noop()
{
}

static struct Window windows[] = {
	// 0
	{ noop, UI_MainMenu_drawBackground, UI_MainMenu_drawForeground, UI_MainMenu_handleMouse },
	{ noop, UI_City_drawBackground, UI_City_drawForeground, UI_City_handleMouse },
	{ noop, UI_PopupDialog_drawBackground, UI_PopupDialog_drawForeground, UI_PopupDialog_handleMouse },
	{ noop, UI_City_drawBackground, UI_TopMenu_drawForeground, UI_TopMenu_handleMouse },
	{ noop, noop, UI_DifficultyOptions_drawForeground, UI_DifficultyOptions_handleMouse },
	{ UI_Advisors_init, UI_Advisors_drawBackground, UI_Advisors_drawForeground, UI_Advisors_handleMouse },
	{ noop, UI_SetSalaryDialog_drawBackground, UI_SetSalaryDialog_drawForeground, UI_SetSalaryDialog_handleMouse },
	{ UI_DonateToCityDialog_init, UI_DonateToCityDialog_drawBackground, UI_DonateToCityDialog_drawForeground, UI_DonateToCityDialog_handleMouse },
	{ UI_SendGiftToCaesarDialog_init, UI_SendGiftToCaesarDialog_drawBackground, UI_SendGiftToCaesarDialog_drawForeground, UI_SendGiftToCaesarDialog_handleMouse },
	{ noop, UI_LaborPriorityDialog_drawBackground, UI_LaborPriorityDialog_drawForeground, UI_LaborPriorityDialog_handleMouse },
	// 10
	{ noop, noop, noop, noop },
	{ UI_SoundOptions_init, noop, UI_SoundOptions_drawForeground, UI_SoundOptions_handleMouse },
	{ UI_SpeedOptions_init, noop, UI_SpeedOptions_drawForeground, UI_SpeedOptions_handleMouse },
	{ noop, UI_Empire_drawBackground, UI_Empire_drawForeground, UI_Empire_handleMouse },
	{ noop, UI_TradeOpenedDialog_drawBackground, UI_TradeOpenedDialog_drawForeground, UI_TradeOpenedDialog_handleMouse },
	{ noop, UI_HoldFestivalDialog_drawBackground, UI_HoldFestivalDialog_drawForeground, UI_HoldFestivalDialog_handleMouse },
};

static WindowId previousWindow;
static WindowId currentWindow;

WindowId UI_Window_getId()
{
	return currentWindow;
}

void UI_Window_goTo(WindowId windowId)
{
	previousWindow = currentWindow;
	currentWindow = windowId;
	windows[currentWindow].init();
	UI_Window_requestRefresh();
}

void UI_Window_goBack()
{
	UI_Window_goTo(previousWindow);
}

static void handleMouse()
{
	int prevLeftIsDown = Data_Mouse.left.isDown;
	int prevRightIsDown = Data_Mouse.right.isDown;
	Data_Mouse.left.isDown = 0;
	Data_Mouse.left.wentDown = 0;
	Data_Mouse.left.wentUp = 0;
	Data_Mouse.right.isDown = 0;
	Data_Mouse.right.wentDown = 0;
	Data_Mouse.right.wentUp = 0;

	Data_Mouse.left.isDown = Data_Mouse.leftDown;
	Data_Mouse.right.isDown = Data_Mouse.rightDown;

	if (Data_Mouse.left.isDown != prevLeftIsDown) {
		if (Data_Mouse.left.isDown) {
			Data_Mouse.left.wentDown = 1;
		} else {
			Data_Mouse.left.wentUp = 1;
		}
	}
	if (Data_Mouse.right.isDown != prevRightIsDown) {
		if (Data_Mouse.right.isDown) {
			Data_Mouse.right.wentDown = 1;
		} else {
			Data_Mouse.right.wentUp = 1;
		}
	}
}

void UI_Window_refresh(int force)
{
	handleMouse();
	if (force) {
		windows[currentWindow].drawBackground();
	}
	windows[currentWindow].drawForeground();
	windows[currentWindow].handleMouse();
}

void UI_Window_requestRefresh()
{
	// TODO
}