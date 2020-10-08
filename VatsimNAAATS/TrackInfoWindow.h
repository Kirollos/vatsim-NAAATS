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

class CTrackInfoWindow : public CBaseWindow
{
	public:
		// Inherited methods
		CTrackInfoWindow(POINT topLeft);
		virtual void RenderWindow(CDC* dc, Graphics* g, CRadarScreen* screen);
		virtual void MakeButtons();

		// Window functions to do
		bool NATDataRefresh;

		// Window messages to display
		string MsgDataRefresh = "";
};

