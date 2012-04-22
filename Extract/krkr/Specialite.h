#pragma once

#include "Krkr.h"

class CSpecialite : public CKrkr
{
protected:

    virtual BOOL  OnCheckDecrypt( CArcFile* pclArc );
    virtual DWORD OnInitDecrypt( CArcFile* pclArc );
    virtual DWORD OnDecrypt( BYTE* pvTarget, DWORD dwTargetSize, DWORD dwOffset, DWORD dwDecryptKey );
};
