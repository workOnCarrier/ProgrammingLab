#include "fileDetails.h"


fileDetails::fileDetails(const string &filepath):m_filePath(filepath)
{
    int status = 0;
   	status = lstat ( m_filePath.c_str(), &m_filestat );
}


fileDetails::~fileDetails(void)
{
}

bool fileDetails::isBlock ()
{
	return false;
}

bool fileDetails::isDir ()
{
	if ( S_ISDIR(m_filestat.st_mode) ) { return true; }
	return false;
}

bool fileDetails::isLink ()
{
	if ( S_ISLNK(m_filestat.st_mode) ) { return true;}
	return false;
}

bool fileDetails::isRegFile ()
{
	if ( !(isLink()) && !(isDir() ) && ! (isBlock() ) ) {return true;}
	return false;
}
