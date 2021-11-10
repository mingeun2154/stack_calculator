// 2018203023 Mingeun Park
// This is the implement for the Stack class.

#include <assert.h>
#include "myStack.h"
#include "node.h"
using namespace linkedList;

namespace mystack
{
  template <class ValueType>
  Stack<ValueType>::Stack(ValueType data) { top_ptr = new Node<ValueType>(data); }
  template <class ValueType>
  Stack<ValueType>::Stack(const Stack<ValueType> &source)
  {
    list_copy(source.top_ptr, &this->top_ptr);
  }

  template <class ValueType>
  void Stack<ValueType>::push(const ValueType &entry)
  {
    list_head_insert(&top_ptr, entry);
  }

  template <class ValueType>
  void Stack<ValueType>::pop()
  {
    assert(!this->empty()); // Check underflow
    list_head_remove(&top_ptr);
  }

  template <class ValueType>
  bool Stack<ValueType>::empty(){
      return top_ptr == NULL;}

  template <class ValueType>
  ValueType Stack<ValueType>::top() const
  {
    assert(!this->empty());
    return top_ptr->get_data();
  }
} // namespace mystack