#ifndef B2_PRIORITY_QUEUE_INTERFACE_HPP
#define B2_PRIORITY_QUEUE_INTERFACE_HPP

#include <list>

template <typename T>
class QueueWithPriority
{
public:
    enum class ElementPriority
    {
        LOW,
        NORMAL,
        HIGH,
    };

    QueueWithPriority();


    bool operator ==(const QueueWithPriority& rhs) const;
    bool operator !=(const QueueWithPriority& rhs) const;

    void putElementToQueue(const T& element, ElementPriority priority);

    template <typename handle_type>
    void getElementFromQueue(handle_type handle);

    void accelerate();

    bool empty() const noexcept;
    void clear() noexcept;

private:
    std::list<T> queue_;
    typename std::list<T>::iterator normal_;
    typename std::list<T>::iterator low_;
};

#endif //B2_PRIORITY_QUEUE_INTERFACE_HPP
