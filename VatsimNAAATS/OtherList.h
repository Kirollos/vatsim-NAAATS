#pragma once
#include "pch.h"
#include <string>
#include <map>
#include <vector>
#include <gdiplus.h>
#include <EuroScopePlugIn.h>
#include "BaseList.h"

using namespace std;
using namespace Gdiplus;
using namespace EuroScopePlugIn;

class COtherList : public CBaseList
{
	public:
		COtherList(POINT topLeft);
		virtual void RenderList(Graphics* g, CDC* dc, CRadarScreen* screen);

		// Aircraft list
		static vector<string> AircraftList;

		// Hides and shows
		bool HideShowButton = true;
};
