#include <iostream>
#include <string>
#include <vector>
#include <ostream>


using namespace std;

enum class color { red, green, blue };
ostream& operator << ( ostream& stream, const color colorVal ) {
    if ( color::red == colorVal ) stream << "red" ;
	else if ( color::green == colorVal ) stream << "green" ;
	else if ( color::blue == colorVal ) stream << "blue" ;
	else stream << "unknown yet" ;
	return stream;
}
enum class size { small, medium, large };
ostream& operator << ( ostream& stream, const size sizeVal ) {
    if ( size::small == sizeVal ) stream << "small" ;
    else if ( size::medium == sizeVal ) stream << "medium" ;
    else if ( size::large == sizeVal ) stream << "large" ;
    else  stream << "unknown yet" ;
	return stream;
}

class Product {
public:
    Product ( string name, color colorVal, size sizeVal ) 
	: m_name ( name ), m_color ( colorVal ), m_size ( sizeVal ) { }
	inline color	get_color() const { return m_color; }
	inline size		get_size() const { return m_size; }
	inline string	get_name() const { return m_name; }
private:
	string	m_name;
    color	m_color;
	size	m_size;
	friend class ProductFilter_NoOCP ;
	friend ostream& operator << ( ostream& stream, const Product& product) {
	    stream << product.m_name << " " << product.m_color << " " << product.m_size << " ";
		return stream;
	}
};

typedef vector<Product>	Items;

// bad design -- as the filter class is to be modified for as many filters
// client does not have the flexibility to manipulate
// the filter class has to be modified for each new filter
class ProductFilter_NoOCP {
public:
	static Items byColor ( Items ItemVect, color filter) {
		Items result;
		for ( auto product : ItemVect ) {
		    if ( product.get_color() == filter ) result.push_back(product) ;
		}
		return result;
	}
	static Items bysize ( Items ItemVect, size filter) {
		Items result;
		for ( auto product : ItemVect ) {
		    if ( product.get_size() == filter ) result.push_back(product) ;
		}
		return result;
	}
	static Items bysizeAndColor ( Items ItemVect, size filter1, color filter2 ) {
		Items result;
		for ( auto  product : ItemVect ) {
		    if ( product.get_size() == filter1 && product.get_color() == filter2 ) result.push_back(product) ;
		}
		return result;
	}
};
void test_ProductFilter_NoOCP () {
    Items productList;
	productList.push_back ( Product ("car", color::red, size::small ) );
	productList.push_back ( Product ("cycle", color::red, size::small ) );
	productList.push_back ( Product ("tree", color::green, size::large ) );

	for ( auto product : productList ) {
	    cout << product << endl;
	}

	Items filtered = ProductFilter_NoOCP::byColor ( productList, color::red );
	cout << " This is filtered by color " << endl;

	for ( auto product : filtered ) {
	    cout << product << endl;
	}
}

namespace OCP {
    template <typename T>  class ISpecification { public:
	    virtual bool is_satisfied ( const T& item ) const = 0;
	};
	template <typename T> class IFilter { public:
	    typedef vector<T>	TList;
	    virtual TList filter ( const TList&  TListObj , const ISpecification<T> &) = 0;
	};
	typedef IFilter<Product> IProdFilter;
	template <typename T> class BetterFilter : IFilter<T> { public:
	    typename IFilter<T>::TList filter ( const typename IFilter<T>::TList&  TListObj , const ISpecification<T> &specObj) override {
			typename IFilter<T>::TList result;
			for ( auto item : TListObj ) {
				if ( specObj.is_satisfied ( item ) ) result.push_back(item) ;
			}
			return result;
		}
	};
	class colorSpec : public ISpecification<Product> { public:
	    colorSpec ( const color& colorVal ) : m_color ( colorVal ) {}
	    bool is_satisfied ( const Product& item ) const override {
		    return item.get_color() == m_color;
		}
		private: color	m_color;
	};
	class sizeSpec : public ISpecification<Product> { public:
	    sizeSpec ( const size& filterVal ) : m_size ( filterVal ) {}
	    bool is_satisfied ( const Product& item ) const override {
		    return item.get_size() == m_size;
		}
		private: size	m_size;
	};
	class andSpec : public ISpecification < Product > { public :
	    andSpec ( const ISpecification<Product>& first, const ISpecification<Product>&  second ) 
		: m_first(first), m_second (second) { }
		bool is_satisfied ( const Product &item ) const override {
		    return m_first.is_satisfied ( item ) && m_second.is_satisfied ( item ) ;
		}
		private: const ISpecification<Product>& m_first; const ISpecification<Product>& m_second;
	};

	void test_ocp_filter () {
		cout << " Testing ocp filter  " << endl;
		Items productList;
		productList.push_back ( Product ("car", color::red, size::small ) );
		productList.push_back ( Product ("cycle", color::red, size::small ) );
		productList.push_back ( Product ("tree", color::green, size::large ) );

		for ( auto product : productList ) {
			cout << product << endl;
		}

		colorSpec  colorSpecObj(color::red);
		cout << " This is filtered by color red " << endl;

		BetterFilter<Product>	bfObj;
		Items filtered = bfObj.filter ( productList, colorSpecObj );

		for ( auto product : filtered ) {
			cout << product << endl;
		}

		cout << "this is a combined filter for color and size" << endl;
		colorSpec 	greenColorSpec(color::green);
		sizeSpec 	largeSizeSpec(size::large);
		andSpec		andSpecObj ( greenColorSpec, largeSizeSpec );

		Items  complexFilter = bfObj.filter ( productList, andSpecObj );
		for ( auto product : complexFilter  ) {
			cout << product << endl;
		}
	}
}

int main ( int argc, char** argv ) {
    test_ProductFilter_NoOCP ();
	OCP::test_ocp_filter();
    return 0;
}
