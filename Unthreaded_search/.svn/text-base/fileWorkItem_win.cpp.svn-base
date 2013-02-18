#include "workItem.h"
#include "workQueue.h"
#include "fileWorkItem.h"

#include <Windows.h>
#include <stdio.h>
#include <boost/ref.hpp>
#include "error.h"
#include "crew.h"
#include "fileDetails.h"


fileWorkItem::fileWorkItem ( workQueue<fileWorkItem> &workContext, std::string path, std::string search )
:m_queue(workContext), m_path(path), m_search(search)
{
}
fileWorkItem::fileWorkItem ( const fileWorkItem & rhs):m_queue(rhs.m_queue)
{
	if ( m_path == rhs.m_path && m_search == rhs.m_search)
	{
		// this is same object, no need to do anything
		// or possibly throw and exception
	}else{
		m_path = rhs.m_path;
		m_search = rhs.m_search;
	}
}
fileWorkItem::fileWorkItem ( workQueue<fileWorkItem> &workContext ): m_queue(workContext)
{
}
fileWorkItem& fileWorkItem::operator = ( const fileWorkItem& rhs) 
{
	if ( m_path == rhs.m_path && m_search == rhs.m_search)
	{
		// this is same object, no need to do anything
		// or possibly throw and exception
	}else{
		m_path = rhs.m_path;
		m_search = rhs.m_search;
	}
	return *this;
}

void fileWorkItem::doWork()
{
    m_work->doWork();
}
void fileWorkItem::InitWork()
{
    fileDetails fileAttribObj( getPath() );
    if ( fileAttribObj.isDir() )
    {
        m_work.reset(new dirWork(m_queue, m_path, m_search ) );
    }
    else if ( fileAttribObj.isRegFile() )
    {
        m_work.reset ( new fileWork ( m_path, m_search ) );
    }
    else
    {
        throw std::exception("This is not a valid application work item" );
    }
}
void fileWorkItem::cleanupWork (){}

fileWork::fileWork (std::string path, std::string search )
:m_path(path), m_search(search){}

void fileWork::doWork() {
    FILE *search;
    char buffer[256], *bufptr, *search_ptr;

    search = fopen ( m_path.c_str(), "r" );
    if ( NULL == search )
    {
        fprintf ( stderr, "Unable to open %s: %d (%s)\n", m_path.c_str(), errno, strerror ( errno ) );
    }else
    {
        while ( 1 )
        {
            bufptr = fgets ( buffer, sizeof (buffer), search );
            if ( NULL == bufptr )
            {
                if ( feof (search ) )break;
                if ( ferror (search ) ) 
                {
                    fprintf ( stderr, "Unable to read %s: %d (%s)", m_path.c_str(), errno, strerror(errno) );
                    break;
                }
            }
            search_ptr = strstr ( buffer, m_search.c_str() );
            if ( search_ptr != NULL ){
                printf ( "Thread found \"%s\" in \"%s\" \n", m_search.c_str(), m_path.c_str() );
                break;
            }
        }
        fclose ( search );
    }
}

dirWork::dirWork(workQueue<fileWorkItem> &queue, std::string path, std::string search)
:m_queue ( queue), m_path(path), m_search(search){}

void dirWork::doWork() {
    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    string        directory = m_path + "\\*.*";
    char        chararray[1025];
    strncpy ( chararray, directory.c_str(), directory.size() + 1 );
    hFind = FindFirstFile( (LPCTSTR)chararray, &ffd );
    if ( INVALID_HANDLE_VALUE == hFind )
    {
        DWORD        errorCode = GetLastError();
        const int    errMsgSize = 124;
        LPVOID        lpMsgBuf;
        DWORD        lang = 01;
        DWORD        status = FormatMessage ( FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                        FORMAT_MESSAGE_FROM_SYSTEM |
                        FORMAT_MESSAGE_IGNORE_INSERTS
                        , NULL, errorCode,
                        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
                        (LPTSTR)&lpMsgBuf, 0 , NULL );
        fprintf ( stderr, "unable to open directory %s with error: %d (%s) \n", directory.c_str(), errorCode,  lpMsgBuf );
        LocalFree ( lpMsgBuf );
        return;
    }
    do
    {
        std::string     path = m_path;
        path += "\\";
        path += reinterpret_cast<char*>(ffd.cFileName);
        if ( 0==strcmp(ffd.cFileName, ".") || 0==strcmp(ffd.cFileName ,"..") ) continue;

        fileWorkItem        newWork ( m_queue, path, m_search );
        m_queue.addWork ( newWork );
        m_queue.signalMoreWork ();
    } while ( FindNextFile(hFind, &ffd) != 0 );
    FindClose ( hFind);
}

