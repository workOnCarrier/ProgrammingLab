#ifndef __PRODUCTLINE_H__
#define __PRODUCTLINE_H__

namespace modernCpp{
    const int first = 0, second=1;

    class Interface {
	public :
		Interface();
		virtual ~Interface()=0;
	};

	class firstChild : public Interface {
	public :
		firstChild();
		~firstChild();
	};

	class secondChild : public Interface {
	public:
		secondChild();
		~secondChild();
	};
}
#endif // __PRODUCTLINE_H__
