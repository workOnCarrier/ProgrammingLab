#ifndef __ECHOTEXTOPTION_H__
#define __ECHOTEXTOPTION_H__
namespace AccGrind{
    class EchoTextOption : public IOption {
    public:
        EchoTextOption ();
        ~EchoTextOption ();
        virtual std::string getOptionString ( )const;
        virtual Task        getTask ( std::string& ) const = 0;
    private:
    };
}
#endif // __ECHOTEXTOPTION_H__
