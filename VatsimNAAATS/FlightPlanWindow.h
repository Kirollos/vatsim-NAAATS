#pragma once
#include "pch.h"
#include "EuroScopePlugIn.h"
#include <string>
#include <map>
#include <gdiplus.h>
#include "BaseWindow.h"

using namespace std;
using namespace Gdiplus;
using namespace EuroScopePlugIn;

class CFlightPlanWindow : public CBaseWindow
{
	public:
		// Inherited methods
		CFlightPlanWindow(POINT topLeft);
		virtual void MakeWindowItems();
		virtual void RenderWindow(CDC* dc, Graphics* g, CRadarScreen* screen);
		CRect RenderDataPanel(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft, bool isCopy);
		void RenderConflictWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderMessageWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT bottomLeft);
		void RenderClearanceWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderManEntryWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderCoordModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderHistoryModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderATCRestrictModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderExchangeModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);

		bool IsButtonPressed(int id);

		// Button clicks
		virtual void ButtonDown(int id);
		virtual void ButtonUp(int id);
		virtual void ButtonPress(int id);
		virtual void ButtonUnpress(int id);
		virtual void SetButtonState(int id, CInputState state);

		// Fill data
		void UpdateData(CRadarScreen* screen, CAcFPStatus status);
		void OnCloseFlightPlanWindow();
		int ChangeDataPoint(CRadarScreen* screen, int data, string str); // Master method to deal with all cases of text input

		// Panel states
		bool IsData = false;
		bool IsCopyMade = false;
		bool IsConflictWindow = false;
		bool IsClearanceOpen = false;
		bool IsManualEntryOpen = false;
		bool IsMessageOpen = false;
		bool IsCoordOpen = false;
		bool IsHistoryOpen = false;
		bool IsATCRestrictionsOpen = false;
		bool IsTransferOpen = false;

		// Subwindow definitions
		static const int SUBWIN_ATCR = 400;
		static const int SUBWIN_COORD = 401;
		static const int SUBWIN_HIST = 402;
		static const int SUBWIN_XCHANGE = 403;

		// Button definitions
		static const int BTN_CLOSE = 0;
		static const int BTN_COPY = 1;
		static const int BTN_UNCLEAR = 2;
		static const int BTN_COORD = 3;
		static const int BTN_MANENTRY = 4;
		static const int BTN_PROBE = 5;
		static const int BTN_DELETE = 6;
		static const int BTN_ADS = 7;
		static const int BTN_READBK = 8;
		static const int BTN_MSG = 9;
		static const int BTN_HIST = 10;
		static const int BTN_SAVE = 11;
		static const int BTN_ATCR = 12;
		static const int BTN_ATCR_CPY = 13;
		static const int BTN_MSG_REMOVE = 14;
		static const int BTN_MSG_DONE = 15;
		static const int BTN_MSG_CLOSE = 16;
		static const int BTN_MSG_REQUEUE = 17;
		static const int BTN_MSG_FORWARD = 18;
		static const int BTN_CONF_ACCCL = 19;
		static const int BTN_CONF_MANCL = 20;
		static const int BTN_CONF_COORD = 21;
		static const int BTN_CONF_CLOSE = 22;

		// Dropdown definitions
		static const int DRP_ATCR = 200;
		static const int DRP_ATCR_CPY = 201;

		// Text definitions
		static const int TXT_ACID = 100;
		static const int TXT_TYPE = 101;
		static const int TXT_DEPART = 102;
		static const int TXT_ETD = 103;
		static const int TXT_SELCAL = 104;
		static const int TXT_DATALINK = 105;
		static const int TXT_COMMS = 106;
		static const int TXT_OWNERSHIP = 107;
		static const int TXT_SPD = 108;
		static const int TXT_LEVEL = 109;
		static const int TXT_DEST = 110;
		static const int TXT_TCK = 111;
		static const int TXT_STATE = 112;
		static const int TXT_SPD_CPY = 113;
		static const int TXT_LEVEL_CPY = 114;
		static const int TXT_DEST_CPY = 115;
		static const int TXT_TCK_CPY = 116;
		static const int TXT_STATE_CPY = 117;
};

