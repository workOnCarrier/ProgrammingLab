#pragma once

#include <iostream>
#ifdef __WIN32__
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#endif // __WIN32__
using  std::string;

class fileDetails {
public:
	fileDetails(const string& filePath);
	~fileDetails(void);

	bool isDir ();
	bool isRegFile ();
	bool isLink ();
	bool isBlock ();

private:
	string	m_filePath;
#ifdef __WIN32__
	DWORD	m_fileAttrib;
#else
	struct stat		m_filestat;
#endif // __WIN32__
};

