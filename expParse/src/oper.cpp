#include "oper.h"

operatr::operatr():
right(NULL), left(NULL)
{
}
double operatr::evaluate( void )
{
        throw -200;
        return 0.0;
}

void operatr::AddRight(Exp* node){right = node;}
void operatr::AddLeft(Exp* node){left = node;}


