#ifndef __IEVENT_H__
#define __IEVENT_H__

template<typename T>
class IEventHandler {
public:
    IEventHandler() {}
    virtual ~IEventHandler() {}

    virtual bool notify ( IEvent& ) = 0;
};


class IEvent {
public:
    IEvent() {}
    virtual ~IEvent() {}

    template <typename T>
    virtual bool notify ( IEventHandler<T>& eventHandler) {
        eventHandler.notify ( *this );
    }
    void raise (){
        EventBus::getInstance()->raise ( *this );
    }
};

#endif //  __IEVENT_H__
