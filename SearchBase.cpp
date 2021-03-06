#include "stdafx.h"
#include "SearchBase.h"

CSearchBase::CSearchBase()
{
	Init();
	//for (int i = 0; i < 2; i++)
	//    m_pattern[i].pattern = nullptr;
}

CSearchBase::~CSearchBase()
{
	//for (int i = 0; i < 2; i++)
	//{
	//    if (m_pattern[i].pattern != nullptr)
	//        delete[] m_pattern[i].pattern;
	//}
}

void CSearchBase::Init()
{
	m_offset = 0;
	m_ctFile = 1;
}

void CSearchBase::Init(SOption* pOption)
{
	Init();
	OnInit(pOption);
}

void CSearchBase::InitPattern(const LPVOID pattern, DWORD size, DWORD num)
{
	//m_pattern[num].pattern = new BYTE[size];
	memcpy(m_pattern[num].pattern, pattern, size);
	m_pattern[num].size = size;
}

// Enter the header
void CSearchBase::InitHed(const LPVOID pattern, DWORD size)
{
	InitPattern(pattern, size, 0);
}
// Enter the footer
void CSearchBase::InitFot(const LPVOID pattern, DWORD size)
{
	InitPattern(pattern, size, 1);
}

inline BOOL CSearchBase::CmpMem(const LPBYTE data, const LPBYTE pattern, DWORD size)
{
	for (size_t i = 0; i < size; i++)
	{
		if ((data[i] != pattern[i]) && (pattern[i] != '*'))
			return FALSE;
	}

	return TRUE;
}
/*
inline DWORD CSearchBase::CreateDecKey(LPBYTE buf)
{
	m_deckey = *(LPDWORD)&buf[0] ^ m_dwHeader;
	return (m_deckey);
}
*/
BOOL CSearchBase::Search(CArcFile* pclArc, LPBYTE buf, DWORD dwReadSize, DWORD dwSearchSize)
{/*
	if (pclArc->GetOpt()->bEasyDecrypt == TRUE)
	{
		DWORD deckey = CreateDecKey(&buf[0]);
		for (int offset = 0; offset <= (int)dwSearchSize; offset++)
		{
			// Search while decoding
			for (int i = 0; i < GetHedSize; i += 4)
			DWORD deckey = *(LPDWORD)&buf[offset] ^ dwHeader;
			if (CmpHed(&buf[offset] ^ deckey) == TRUE)
			{
				SetOffset(offset);
				return TRUE;
			}
		}
	}
	else
	{*/
		for (int offset = 0; offset <= (int)dwSearchSize; offset++)
		{
			if (CmpHed(&buf[offset]) == TRUE)
			{
				SetOffset(offset);
				return TRUE;
			}
		}
//	}
	return FALSE;
/*
	for (int i = 0; i <= (int)dwSearchSize; i++)
	{
		if (CmpHed(&buf[i]) == TRUE)
		{
			// dwReadSize - i back to first position, while moving through the header
			pclArc->Seek(-((int)dwReadSize-i), FILE_CURRENT);
			pclArc->GetProg()->UpdatePercent(i);
			return TRUE;
		}
	}
	return FALSE;
*/
}
/*
BOOL CSearchBase::Search(CArcFile* pclArc, LPBYTE buf, DWORD dwReadSize)
{
	LPBYTE hed2 = GetHed2();
	for (int i = 0; i < (int)dwReadSize; i++)
	{
		if (CmpHed(&buf[i]) == TRUE)
		{
			//if (hed2 != nullptr)
			{
			//  pclArc->Seek(-(BUFSIZE-i), FILE_CURRENT);
			//  if (CmpHed2(&buf[i]) == TRUE)
				{
					pclArc->Seek(-(BUFSIZE-i), FILE_CURRENT);
					pclArc->GetProg()->UpdatePercent(i);
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
*/
BOOL CSearchBase::SearchFot(CArcFile* pclArc)
{
	DWORD FotSize = GetFotSize();
	while (1)
	{
		BYTE buf[BUFSIZE];
		DWORD dwReadSize = pclArc->Read(buf, BUFSIZE);
		
		if (dwReadSize < FotSize)
		{
			pclArc->GetProg()->UpdatePercent(dwReadSize);
			break;
		}

		DWORD dwSearchSize = dwReadSize - FotSize;
		for (int i = 0; i <= (int)dwSearchSize; i++)
		{
			if (CmpFot(&buf[i]) == TRUE)
			{
				// dwReadSize - i -- Moves back to position found by i, has moved to the footer file and proceeds from the FotSize
				pclArc->Seek(-((int)dwReadSize-i - (int)FotSize), FILE_CURRENT);
				pclArc->GetProg()->UpdatePercent(i+FotSize);
				return TRUE;
			}
		}
		pclArc->GetProg()->UpdatePercent(dwSearchSize);
		pclArc->Seek(-((int)FotSize-1), FILE_CURRENT);
	}
	return FALSE;
}
