#ifndef __NUMGEN_H__
#define __NUMGEN_H__


class numGen {
public:
	void operator ()() ;
private:
	virtual void processNumber ( int )  = 0;
};
#endif //  __NUMGEN_H__
