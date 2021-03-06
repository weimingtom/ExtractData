#pragma once

#include "HaruotoFD.h"

//----------------------------------------------------------------------------------------
//-- ef - Second Fan Mix -----------------------------------------------------------------
//----------------------------------------------------------------------------------------

class CEFsfm final : public CHaruotoFD
{
public:
	BOOL Mount(CArcFile* pclArc) override;
	BOOL Decode(CArcFile* pclArc) override;

private:
	BOOL IsSupported(CArcFile* pclArc);

	void InitMountKey(CArcFile* pclArc) override;
	void InitDecodeKey(CArcFile* pclArc) override;

	DWORD InitMovieTable(void* pvTable) override;

	void DecodeMovieData(void* pvTarget, DWORD dwSize) override;

	DWORD GetMovieBufSize(CArcFile* pclArc) override;

	BYTE  m_btKey;
	BYTE  m_aabtMovieTable[256][256];
	DWORD m_dwMovieTableID;
};
