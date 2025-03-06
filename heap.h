#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> // added 

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
  
  // data members For Heap
  std::vector<T> data_; // vector to store the elements of the heap
  int m_; // m-ary value
  PComparator comp_; // Comparator function to determine what type of heap

  // Helper Functions
  void heapifyUp( size_t index); // Work from the end of heap to make the heap in order 
  void heapifyDown( size_t index); // Work from the beggining of heap to make the heap in order 


  size_t parent( size_t index) const; // function to do math for where parent is located on heap
  size_t child( size_t index, size_t n) const; // function to do math for where which child is located on heap

};

// Add implementation of member functions here

//////////////////////////////////////////////////////////////////////////////////////

// Constrctor
template <typename T, typename PComparator>
Heap< T , PComparator >::Heap(int m, PComparator c) : m_(m) , comp_(c) 
{
}

// Destructor
template <typename T, typename PComparator>
Heap< T , PComparator >::~Heap() 
{
}

// Push Item Into Heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  data_.push_back(item); // use push_back from vector to push to back of the list
  heapifyUp(data_.size() - 1); // use the helper heapifyUp function to keep the Heap
}

// Check If Heap Is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty(); // uses the vector function empty from library to see if its empty
}

// Check The Size of The Heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size(); // uses the vector functiomn size from library to see size of array
}


//// HELPER FUNCTIONS ////

// Goes through the heap to order the heap from the end of heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp( size_t index)
{
    while ( index > 0 ) // runs until reching the 0th index
    {  
      size_t p = parent(index); // gets place where parent is for node
      if ( comp_( data_[index] , data_[p] ) ) // comparing placements 
      {
        std::swap( data_[index] , data_[p] ); // swapping index
        index = p; 
      }
      else 
      {
        break;
      }
    }
}


// Goes through the heap to order the heap from the beggining of heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown( size_t index)
{
    size_t best = index;
    while( true ) // will continue to run until it hits a break 
    {
      for (size_t i = 1; i <= m_; ++i )
      {
        size_t c = child(index, i);
        if ( c < data_.size() && comp_( data_[c] , data_[best] ) )
        {
          best = c; 
        }
      }
      if ( best != index) 
      {
        std::swap(data_[index], data_[best]);
        index = best;
      }
      else 
      {
        break;
      }
    }
}

// Does math for where parent is located in heap, helper functions for heapifyUp and heapifyDown
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::parent( size_t index) const
{
    return (index - 1) / m_ ; 
}

// Does math for where child is located in heap, helper functions for heapifyUp and heapifyDown
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::child( size_t index, size_t n) const
{
    return index * m_ + n; 
}

/////////////////////////////////////////////////////////////////////////////////////


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

    throw std::underflow_error("HEAP IS EMPTY"); // Added to throw correct error 

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data_.front(); // return the front of the vector which would be the first node of the heap "tree"

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

    throw std::underflow_error("HEAP IS EMPTY"); // Added for throw correct error 

  }

  if (data_.size() == 1) // Base Case: if data only has 1 element, just pop and end
  {
    data_.pop_back();
    return;
  }
  std::swap(data_.front(), data_.back()); // swap the beginning and end of heap
  data_.pop_back(); // delete orginally the top of the heap
  heapifyDown(0); // run heapifyDown to correct Heap
}


#endif

