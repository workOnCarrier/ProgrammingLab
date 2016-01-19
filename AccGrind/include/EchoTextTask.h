#ifndef __ECHOTEXTTASK_H__
#define __ECHOTEXTTASK_H__

namespace AccGrind{
    class EchoTextTask : public ITask {
    public:
        EchoTextTask (std::string&);
        ~EchoTextTask ();
        virtual void execute();
    private:
    };
}
#endif // __ECHOTEXTTASK_H__
