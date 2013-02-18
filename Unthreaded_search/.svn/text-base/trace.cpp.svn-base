

#include "trace.h"

trace* trace::m_obj = NULL;
trace* trace::getTrace()
{
    if ( NULL == m_obj )
	{
	    m_obj = new trace();
	}
	return m_obj;
}
trace::trace()
:m_category ( log4cpp::Category::getRoot() )
{
    log4cpp::Appender * appender1 = new log4cpp::FileAppender ( "default", "search.log" );
	log4cpp::PatternLayout *ptrn = new log4cpp::PatternLayout ( );
	ptrn->setConversionPattern ( "%d{%H:%M:%S,%l} %p    %m%n" );
	//appender1->setLayout ( new log4cpp::BasicLayout() );
	appender1->setLayout ( ptrn );

	m_category.setPriority( log4cpp::Priority::INFO );
	m_category.addAppender ( appender1 );
}
log4cpp::CategoryStream trace::Error()
{
    return m_category.errorStream();
}
log4cpp::CategoryStream trace::Warn()
{
    return m_category.warnStream();
}
log4cpp::CategoryStream trace::Info()
{
    return m_category.infoStream();
}
log4cpp::CategoryStream trace::Notice()
{
    return m_category.noticeStream();
}

