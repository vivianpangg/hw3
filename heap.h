#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

using namespace std;

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
  vector<T> heap_;
  int m_;
  PComparator comp_;

  void heapifyDownList(size_t index);
  void heapifyUpList(size_t index);
};

// Add implementation of member functions here

//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c):m_(m), comp_(c){}

//destructor
template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

//returns if heap is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  // if(heap_.size() ==0){
  //   return true;
  // }else{
  //   return false;
  // }
  return heap_.empty();
}

//return size of heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heap_.size();
}

//heap push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heap_.push_back(item);
  heapifyUpList(heap_.size()-1);

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
    throw underflow_error("Underflow_error: Heap is empty");



  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();
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
    throw underflow_error("Underflow_error: Cannot pop empty heap");

  }

  swap(heap_.front(), heap_.back());
  heap_.pop_back();

  if(empty() == false){
    //push the new element at the top into heapify algorithm
    heapifyDownList(0);

  }



}

//Heapify number from a certain index down to where it should be
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDownList(size_t index){
  size_t bestElementIndex = index;

  for(int i = 0; i < m_ ; i++){
    size_t childIndex = m_*index+1+i;
    if(childIndex<heap_.size() && comp_(heap_[childIndex], heap_[bestElementIndex])){
      bestElementIndex = childIndex;
    }

  }

  if(bestElementIndex != index){
    swap(heap_[index], heap_[bestElementIndex]);
    heapifyDownList(bestElementIndex);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>:: heapifyUpList(size_t index){

  // size_t bestElementIndex = index;
  if(index==0){
    return;
  }else{
    //parent element index
    size_t parent = (index-1)/m_;

    if(comp_(heap_[index], heap_[parent])){
      swap(heap_[index], heap_[parent]);
      heapifyUpList(parent);
    }
  }

}



#endif

