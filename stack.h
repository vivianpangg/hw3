#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

using namespace std;

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack :private vector<T>
{
public:
    Stack():vector<T>(){}
    bool empty() const{
      // if(this.size() ==0){
      //   return true;
      // }else{
      //   return false;
      // }
      return vector<T>::empty();
    }

    size_t size() const{
      return vector<T>::size();
    }

    void push(const T& item){
      vector<T>::push_back(item);
    }

    // throws std::underflow_error if empty
    void pop(){
      if(empty()){
        throw underflow_error("Stack underflow_erro: Cannot pop from an empty stack");
      }else{
        vector<T>::pop_back();
      }

    }

    // throws std::underflow_error if empty
    const T& top() const {
      if(empty()){
        throw underflow_error("Stack underflow_error: Cannot top from an empty stack");
      }else{
        return vector<T>::back();
      }
    }
    // Add other members only if necessary
};


#endif