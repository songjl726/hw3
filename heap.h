#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream> // for debugging 😢

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

private:
  /// Add whatever helper functions and data members you need below
  int arity_;
  PComparator comp_;
  std::vector<T> data_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
  arity_(m), comp_(c) {

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  // code
  data_.push_back(item);

  // heapify the last (just-added) item (aka trickle UP)
  size_t idx = data_.size() - 1;
  while (idx != 0){
    size_t parent_idx = (idx - 1) / arity_;
    T& current = data_[idx];
    T& parent = data_[parent_idx];
    if (!comp_(current, parent)){
      break;
    }
    // std::cout << "Now swapping " << current << " with " << parent << std::endl;
    std::swap(current, parent);
    idx = parent_idx;
  }
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
    throw std::out_of_range("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0]; // index the 0th (top) element
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
    throw std::out_of_range("Empty heap");
  }
  // move the top item to the last spot, then pop pop back
  data_[0] = data_.back();
  data_.pop_back();

  // then heapify the resulting heap with the new "best" (aka trickleDOWN)'
  size_t idx = 0;
  bool done = false;
  while(!done){
    size_t best = idx;
    size_t leftmost = idx * arity_ + 1;
    // since we can have any m-arity basically, different formula
      // this makes it so that the rightmost child is either the leftmost child + the whole m 
      // or the very last element in data_
    size_t rightmost = std::min(leftmost + arity_, data_.size());

    // iterate over all the children until we find one "better" (if we even do)
    for (size_t i = leftmost; i < rightmost; i++){
      // if we find one better than our current one, make it the new best
      if(comp_(data_[i], data_[best])){
        best = i;
      }
    }

    if(best != idx){
      // std::cout << "Now swapping " << data_[idx] << " with " << data_[best] << std::endl;
      std::swap(data_[idx], data_[best]);
    } else {
      done = true;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();
}

#endif

