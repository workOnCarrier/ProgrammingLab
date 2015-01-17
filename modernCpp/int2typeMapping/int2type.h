#ifndef __INT2TYPE_H__
#define __INT2TYPE_H__

template <int T>
struct int2type {
	enum {val = T};
};
#endif // __INT2TYPE_H__
