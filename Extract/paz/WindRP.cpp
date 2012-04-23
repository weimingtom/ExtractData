#include	"stdafx.h"
#include	"WindRP.h"

//////////////////////////////////////////////////////////////////////////////////////////
//	Mount

BOOL	CWindRP::Mount(
    CArcFile*			pclArc							// Archive
    )
{
    if( !pclArc->CheckExe( _T("WindRP.exe") ) )
    {
        return	FALSE;
    }

    return	CPaz::Mount( pclArc );
}

//////////////////////////////////////////////////////////////////////////////////////////
//	Decode

BOOL	CWindRP::Decode(
    CArcFile*			pclArc							// Archive
    )
{
    if( !pclArc->CheckExe( _T("WindRP.exe") ) )
    {
        return	FALSE;
    }

    return	CPaz::Decode( pclArc );
}

//////////////////////////////////////////////////////////////////////////////////////////
//	Initialize Mount Key

void	CWindRP::InitMountKey(
    CArcFile*			pclArc							// Archive
    )
{
    static const SKeyInfo	astKeyInfo[] =
    {
        { _T("scr"),	"\xFC\x0B\x51\x21\xD5\x31\x0A\xC6\x92\xA0\xC6\x85\x58\xB2\x21\x88\xAC\xCC\x09\xB8\xC6\x6F\x87\x53\xCB\x83\xDE\xA4\xB6\xA0\xAE\x88" },
        { _T("bg"),		"\xA8\x16\xE5\xA4\x6D\x6A\x3F\xE3\xE4\x13\x0F\x1C\x1A\x36\x13\x93\xC9\x18\x18\x0F\x0E\x0F\x28\x55\xFD\xAE\x00\xB7\xF1\xF0\x9C\x87" },
        { _T("st"),		"\x39\x1E\x81\x1E\xFC\x28\xA2\x44\x03\x4C\x86\xB6\x31\xA6\x7F\x7D\x68\x8D\xA9\xF0\x95\x5C\x7B\x0A\xAF\x82\xA2\xD7\x61\x8D\xE0\xCA" },
        { _T("sys"),	"\x16\xEB\xC7\xA4\x42\x2C\xED\xB8\x87\x82\x7F\x56\x8E\x33\xD0\x02\x4F\xD5\xBD\x50\x7A\xF8\x9D\x20\xDA\x19\x77\xEA\x56\x87\x49\xF1" },
        { _T("bgm"),	"\x68\x07\x1B\x0B\xBF\xF9\x9C\xCC\xC6\xB0\x0D\xC4\xDF\xCF\x32\xA0\x06\x58\x1A\xE5\x9F\x45\x69\x05\x34\x4D\xF2\x95\xDF\xB0\x5F\x57" },
        { _T("voice"),	"\x16\xBC\xA1\xEA\xB2\xCF\xEB\xCE\xDA\x90\x03\x85\x94\x2A\x90\x96\xD4\x42\x42\x24\xA1\x65\x79\xE6\x36\xB6\x48\x3D\xCC\x99\x70\x1B" },
        { _T("se"),		"\xC7\x14\x3B\x96\x1B\xB0\xD5\xCA\x98\x9A\xF5\xDE\xDD\xB6\x96\xE0\xC1\x7A\x78\x42\xE0\x38\x2B\xB1\x17\xAF\x6B\x08\xAC\x95\x87\x1A" },
        { _T("mov"),	"\xE2\xD7\x8F\x24\xB9\x5E\x15\x8F\x99\x08\x36\xD4\xA9\xA6\xB0\x3B\x95\xAB\xC1\x35\x7D\x60\x99\x14\xCE\x51\x10\xDB\xCF\xB5\x6E\xF1" }
    };

    SetKey( pclArc, astKeyInfo );
}

//////////////////////////////////////////////////////////////////////////////////////////
//	Initialize Decode Key

void	CWindRP::InitDecodeKey(
    CArcFile*			pclArc							// Archive
    )
{
    static const SKeyInfo	astKeyInfo[] =
    {
        { _T("scr"),	"\x93\x99\x64\x8D\x1D\x52\xF4\x75\x3B\xA1\x89\xBD\xA6\x83\xB3\x16\x2B\xE8\xA1\x05\x16\x77\xC7\xEA\x00\x15\x50\xB3\xD7\xE6\x1B\xDF" },
        { _T("bg"),		"\xC1\x88\x09\xA0\xBC\x4F\x4D\xDA\x9B\x35\x8F\xC1\x39\x4F\x9E\xCA\x96\x78\x64\xC5\x9B\xF8\xF1\xC3\x51\xEE\x47\xAA\x3F\x2A\xBD\x14" },
        { _T("st"),		"\xB6\x4F\xA7\x56\xCB\xEA\x0A\x5F\xB6\x45\x20\x30\x66\xBB\x65\xB4\xFB\x43\xF1\xB3\xEF\xF8\xDC\xA4\xA8\x5E\x72\x0F\x38\x26\xF1\x5D" },
        { _T("sys"),	"\x0A\x25\x90\xB7\x39\x53\x96\xC2\x53\x79\x3F\x00\x4B\x68\x25\x80\x53\x63\xFB\xB7\x62\x87\x54\x29\x2D\xF0\x36\xB8\x42\x5C\x33\x48" },
        { _T("bgm"),	"\x13\x05\xD7\x86\xB5\x7C\x1E\x81\xFA\x3B\xB1\xE7\xC9\xB8\xB8\x9E\x54\xB2\xF6\x74\x04\x77\xE6\xB0\xC9\xED\xB5\x3A\x9C\x0E\xBF\x23" },
        { _T("voice"),	"\xEB\xA9\x52\x4A\xAF\x18\x8B\xD8\xF3\xB5\xF7\x59\x7F\xCC\xBB\x39\x77\xC8\x14\x51\xA3\x5A\xDB\x56\x21\x5E\xD4\xEA\x45\x3D\x8F\xFB" },
        { _T("se"),		"\x67\x89\x92\x49\x57\x96\x8B\xC5\x45\xCF\x56\x8E\xCC\x86\x88\x40\xF3\x00\x4B\x72\xD0\x81\x40\xFA\x9E\x0D\x35\xDF\xFE\xAA\x60\x9D" },
        { _T("mov"),	"\x20\xDF\xEC\x87\x9C\x2A\x88\x07\xB7\x35\xD2\x79\xD1\x87\x3C\x61\xBF\x73\x4C\xBE\xD9\xFD\xE0\x39\x68\x83\x3C\xEE\x46\xD7\xAD\x97" }
    };

    SetKey( pclArc, astKeyInfo );
}
