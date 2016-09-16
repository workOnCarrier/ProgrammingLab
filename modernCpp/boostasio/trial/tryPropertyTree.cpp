#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <sstream>
#include <iostream>

using boost::property_tree::ptree;

int main()
{
        std::stringstream ss;
        ss << "<order>" ;
        ss << "<stock>s1</stock>";
        ss << "<trader>t1</trader>";
        ss << "<quantity>10</quantity>";
        ss << "<buySell>buy</buySell>";
        ss << "</order>";

        ptree pt;
        boost::property_tree::read_xml(ss, pt);

                std::cout << pt.get<std::string>("order.stock") << std::endl;
        return 0;
}
