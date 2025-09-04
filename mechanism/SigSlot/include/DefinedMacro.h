#include <functional>
#define DECLARE_SIGNAL(name, ...)               \
    Signal<__VA_ARGS__> name;

#define DECLARE_SLOT(name, ...)                     \
    Slot<__VA_ARGS__> _##name;                      \
    void name(__VA_ARGS__);



#define EMIT_SIGNAL(signal, ...) \
    signal.emit(__VA_ARGS__)

#define CONNECT(sender, signal, receiver, slot, type)   \
    sender->signal.connect(receiver->_##slot, type); 


#define DISCONNECT(sender, signal, receiver, slot)   \
    sender->signal.disconnect(receiver->_##slot); 

#define DISCONNECTALL(sender, signal)   \
    sender->signal.disconnect();