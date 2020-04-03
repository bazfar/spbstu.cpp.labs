#ifndef QUEUE_WITH_PRIORITY_HPP
#define QUEUE_WITH_PRIORITY_HPP

#include <functional>
#include <iostream>
#include <list>

#include "priorityQueueInterface.hpp"


template <typename T>
QueueWithPriority<T>::QueueWithPriority() :
  queue_(),
  normal_(queue_.begin()),
  low_(queue_.begin())
{ }

template <typename T>
bool QueueWithPriority<T>::operator ==(const QueueWithPriority<T>& rhs) const
{
  return (queue_ == rhs.queue_);
}

template <typename T>
bool QueueWithPriority<T>::operator !=(const QueueWithPriority<T>& rhs) const
{
  return !(*this == rhs);
}

template <typename T>
void QueueWithPriority<T>::putElementToQueue(const T& element, ElementPriority priority)
{
  switch (priority)
  {
  case ElementPriority::LOW:
    queue_.insert(queue_.end(), element);
    if (low_ == queue_.end())
    {
      low_ = std::prev(queue_.end());
      if (normal_ == queue_.end())
      {
        normal_ = std::prev(queue_.end());
      }
    }
    break;
  case ElementPriority::NORMAL:
    queue_.insert(low_, element);
    if (normal_ == low_)
    {
      normal_ = std::prev(low_);
    }
    break;
  case ElementPriority::HIGH:
    queue_.insert(normal_, element);
    break;
  }
}

template <typename T>
template <typename handle_type>
void QueueWithPriority<T>::getElementFromQueue(handle_type handle)
{
  if (!empty())
  {
    handle(queue_.front());

    if (normal_ == queue_.begin())
    {
      normal_ = low_;
    }

    if (low_ == queue_.begin())
    {
      low_ = queue_.end();
      normal_ = queue_.end();
    }

    queue_.pop_front();
  }
  else
  {
    throw std::out_of_range("Queue is empty.");
  }
}

template <typename T>
void QueueWithPriority<T>::accelerate()
{
  queue_.splice(normal_, queue_, low_, queue_.end());
}

template <typename T>
bool QueueWithPriority<T>::empty() const noexcept
{
  return queue_.empty();
}

template <typename T>
void QueueWithPriority<T>::clear() noexcept
{
  queue_.clear();

  normal_ = queue_.begin();
  low_ = queue_.begin();
}

#endif //QUEUE_WITH_PRIORITY_HPP

