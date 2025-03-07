#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void print();

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator comp_;

  void heapifyUp(size_t index);
  void heapifyDown(size_t index);

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
  : m_(m), comp_(c)
{}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  data_.push_back(item);
  heapifyUp(size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  
  std::swap(data_.front(), data_.back()); // initial swap
  data_.pop_back(); // remove last node
  if (!data_.empty()) heapifyDown(0);   // move new root down as needed
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index)
{
  if (index == 0) return;
  size_t parent = (index - 1) / m_; // parent formula based on m
    if (comp_(data_[index], data_[parent])) {
      std::swap(data_[index], data_[parent]);
      heapifyUp(parent);
    }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index)
{
  size_t child = m_ * index + 1;
  if (child >= size()) return;

  // set temporary best child
  size_t bestChild = child;

  // find actual best child
  for (int i = 1; i < m_; ++i) {
    if(child + i < size() && comp_(data_[child + i], data_[bestChild])) {
      bestChild = child + i;
    }
  }

  // check if best child is actually better than parent, swap, repeat
  if (comp_(data_[bestChild], data_[index])) {
    std::swap(data_[index], data_[bestChild]);
    heapifyDown(bestChild);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::print()
{
  typename std::vector<T>::iterator it;
  for (it = data_.begin(); it != data_.end(); ++it) {
      std::cout << *it << std::endl; 
  }
}

#endif

