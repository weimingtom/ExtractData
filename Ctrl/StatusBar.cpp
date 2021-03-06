#include "stdafx.h"
#include "../res/ResExtractData.h"
#include "../Common.h"
#include "../MainListView.h"
#include "Statusbar.h"

#define SBSIZE 2

CStatusBar::CStatusBar()
{
	m_hWnd = nullptr;
	m_hSBWnd = nullptr;
	m_pOption = nullptr;
	m_pListView = nullptr;
}

void CStatusBar::Init(HWND hWnd, SOption& option, CMainListView& listview)
{
	m_hWnd = hWnd;
	m_pOption = &option;
	m_pListView = &listview;
}

// Function that creates a status bar
HWND CStatusBar::Create(HWND hWnd, SOption& option, CMainListView& listview)
{
	Init(hWnd, option, listview);

	HWND hSBWnd = CreateStatusWindow(
		WS_CHILD | WS_VISIBLE | CCS_BOTTOM,
		nullptr,
		m_hWnd,
		ID_STATUS);
	m_hSBWnd = hSBWnd;

	int sb_size[SBSIZE];
	memset(sb_size, 0, sizeof(sb_size));
	SendMessage(hSBWnd, SB_SETPARTS, SBSIZE, reinterpret_cast<LPARAM>(sb_size));

	SetCount();

	return hSBWnd;
}

// Function to update the status bar: Displays the number of files
void CStatusBar::SetCount()
{
	TCHAR szFileCount[256];
	_stprintf(szFileCount, _T("Files %d"), m_pListView->GetCount());
	SendMessage(m_hSBWnd, SB_SETTEXT, 0 | 0, reinterpret_cast<WPARAM>(szFileCount));
}

void CStatusBar::SetWindowPos(int cx)
{
	int sb_size[SBSIZE];
	sb_size[1] = cx;
	sb_size[0] = cx / 2;
	SendMessage(m_hSBWnd, SB_SETPARTS, SBSIZE, reinterpret_cast<LPARAM>(sb_size));
	SendMessage(m_hSBWnd, WM_SIZE, 0, 0); 
}
