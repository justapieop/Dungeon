#ifndef EVENT_HPP
#define EVENT_HPP

class Event
{
public:
    Event();
    virtual ~Event();

    template <typename... TArgs>
    void execute(TArgs... args);
private:
};
#endif //EVENT_HPP
