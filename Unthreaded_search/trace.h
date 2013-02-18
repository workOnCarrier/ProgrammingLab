#ifndef __TRACE_H__
#define __TRACE_H__
#include "mylog.h"

class CategoryStream;
class trace {
// constructor
trace();
trace(const trace&);
static trace *m_obj;
log4cpp::Category &m_category;

public:
static trace* getTrace();

log4cpp::CategoryStream Error();
log4cpp::CategoryStream Warn();
log4cpp::CategoryStream Info();
log4cpp::CategoryStream Notice();
};
#endif //__TRACE_H__
