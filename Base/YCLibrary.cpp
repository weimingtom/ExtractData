#include "stdafx.h"
#include "YCLibrary.h"

/// Constructor
YCLibrary::YCLibrary()
{
	m_hModule = nullptr;
}

/// Destructor
YCLibrary::~YCLibrary()
{
	Free();
}

/// Load the specified module
///
/// @param pszPathToFile Load module name
///
bool YCLibrary::Load(LPCTSTR pszPathToFile)
{
	m_hModule = ::LoadLibrary(pszPathToFile);

	return (m_hModule != nullptr);
}

/// Release the loaded module
void YCLibrary::Free()
{
	if (m_hModule != nullptr)
	{
		::FreeLibrary(m_hModule);
		m_hModule = nullptr;
	}
}

/// Gets the function address
///
/// @param pszProcName Name of the function
///
FARPROC YCLibrary::GetProcAddress(LPCTSTR pszProcName)
{
	if (m_hModule == nullptr)
		return nullptr;

	YCStringA clsProcName = pszProcName; // Done as a last resort because there is no GetProcAddressW

	return ::GetProcAddress(m_hModule, clsProcName);
}
