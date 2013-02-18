#include "workItem.h"
#include "workQueue.h"
#include "fileWorkItem.h"

#ifdef __WIN32__
#include <Windows.h>
#else
#include <dirent.h>
#endif // __WIN32__
#include <stdio.h>
#include <boost/ref.hpp>
#include "error.h"
//#include "crew.h"
#include "fileDetails.h"


fileWorkItem::fileWorkItem ( workQueue<fileWorkItem> &workContext, std::string path, std::string search )
: m_path(path),m_search(search) , m_queue(workContext){
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
        throw custom::runtime_error("This is not a valid application work item" );
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
:m_path(path), m_search(search),m_queue ( queue) {}

void dirWork::doWork() {
			DIR *directory;
			struct dirent *result;
			directory = opendir ( m_path.c_str() );
			if ( NULL == directory )
			{
				fprintf ( stderr, "unable to open directory %s, %d (%s) \n", m_path.c_str(), errno, strerror(errno) );
				return ;
			}
			int status = 0;
	        struct dirent	entry;
			while (1)
			{
				status = readdir_r ( directory, &entry, &result );
				if ( 0 != status )
				{
					fprintf ( stderr, "Unable to read directory %s, %d (%s) \n", m_path.c_str(), status , strerror(status ) );
					break;
				}
				if ( NULL == result ) return ;
				if ( strcmp ( entry.d_name, "." ) == 0  ) continue;
				if ( strcmp ( entry.d_name, ".." ) == 0 ) continue;

				std::string 	path ;
				if ( entry.d_name[0] == '/' ) { // this is absolute path
				    path = entry.d_name;
				}else
				{ // this is relative path
				    path += m_path + "/";
    				path += entry.d_name ;
				}

				fileWorkItem	newWork ( m_queue, path, m_search );
				m_queue.addWork ( newWork );
			}
			closedir ( directory );
}

