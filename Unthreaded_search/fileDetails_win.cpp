#include "fileDetails.h"


fileDetails::fileDetails(const string &filepath):m_filePath(filepath)
{
	m_fileAttrib = GetFileAttributes( (LPCTSTR)(m_filePath.c_str()) );
}


fileDetails::~fileDetails(void)
{
}

bool fileDetails::isBlock ()
{
	if ( m_fileAttrib & FILE_ATTRIBUTE_DEVICE ) {	return true; }
	return false;
}

bool fileDetails::isDir ()
{
	if ( m_fileAttrib & FILE_ATTRIBUTE_DIRECTORY ) { return true; }
	return false;
}

bool fileDetails::isLink ()
{
//	if ( m_fileAttrib & FILE_ATTRIBUTE_REPARSE_POINT ) { return true;}
	return false;
}

bool fileDetails::isRegFile ()
{
	if ( !(isLink()) && !(isDir() ) && ! (isBlock() ) ) {return true;}
	return false;
}
