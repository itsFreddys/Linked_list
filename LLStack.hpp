#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include <stdexcept>
#include <iostream>
// changes

class StackEmptyException : std::runtime_error {
public:
  StackEmptyException(const std::string &err) : std::runtime_error(err) {}
};

// This is the LLStack class you will be implementing for this project.
// Remember to see the write-up for more details!
template <typename Object> class LLStack {
private:
  // fill in private member data here
  class Node{
    public:
        Object data;
        Node* next;
    Node(const Object& val) : data(val), next(nullptr){}
  };

  Node* head = nullptr;
  size_t temp_size = 0;

public:
  // constructor
  LLStack();

  // copy constructor (remember, deep copy!)
  LLStack(const LLStack &st);

  // assignment operator (remember, deep copy!)
  LLStack &operator=(const LLStack &st);

  // destructor
  ~LLStack();

  size_t size() const noexcept;
  bool isEmpty() const noexcept;

  // We have two top() functions.  The first gets called if your LLStack is not
  // a const, while the latter gets called on a const LLStack
  // (the latter might occur via const reference parameter, for instance).
  // Be sure to test both!  It is important when testing to ensure that
  // EVERY funtion gets called and tested!
  Object &top();
  const Object &top() const;

  void push(const Object &elem);
  void pop();

  void printList();
};

template <typename Object> 
LLStack<Object>::LLStack() {
  // TODO: Fill in your constructor implementation here.
  head = nullptr;
  temp_size = 0;
}

template <typename Object> 
LLStack<Object>::LLStack(const LLStack &st) {
  // TODO: Fill in your copy constructor implementation here.
    head = nullptr;
    Node* current = st.head;
    temp_size = 0;

    // creating the linked list with the values in reverse order
    while (current != nullptr){
        Node* newNode = new Node(current->data);
        if (head == nullptr){
          newNode->next = head;
          head = newNode;
        }
        else{
          Node* temp = head;
          while (temp->next != nullptr){
            temp = temp->next;
          }
          temp->next = newNode;
        }
        current = current->next;

        temp_size++;

    }
}

template <typename Object>
LLStack<Object> &LLStack<Object>::operator=(const LLStack &st) {
  // TODO: Fill in your assignment operator implementation here.
  // check if current is new or same as assigning object
    if (this != &st) {
        Node* current = head;
        while (current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }

    head = nullptr;
    current = st.head;
    temp_size = 0;

    // creating the linked list with the values in reverse order
    // to accomadate for the copy to be correct
    while (current != nullptr){
        Node* newNode = new Node(current->data);
        if (head == nullptr){
          newNode->next = head;
          head = newNode;
        }
        else{
          Node* temp = head;
          while (temp->next != nullptr){
            temp = temp->next;
          }
          temp->next = newNode;
        }
        current = current->next;
        temp_size++;
    }
    }
  return *this; // Stub so this function compiles without implementation.
}

template <typename Object> 
LLStack<Object>::~LLStack() {
  // TODO: Fill in your destructor implementation here.
  Node* tempN;
    if (temp_size != 0)
    {
        Node* current = head;

        while (current != nullptr){
            tempN = current;
            current = current->next;

            delete tempN;
        }
    }
}

template <typename Object> 
size_t LLStack<Object>::size() const noexcept {
  // TODO: Fill in your size() implementation here.
  return temp_size; // Stub so this function compiles without an implementation.
}

template <typename Object> 
bool LLStack<Object>::isEmpty() const noexcept {
  // TODO: Fill in your isEmpty() implementation here.
  if (size()){
        return false;
    }
    else {
        return true; // Stub so this function compiles without an implementation.
    }
}

template <typename Object> 
Object &LLStack<Object>::top() {
  // TODO: Fill in your top() implementation here.
  // The following is a stub just to get the template project to compile.
  if (head == nullptr){
        throw StackEmptyException("Stack is empty.");
    }

    return head->data;
}

template <typename Object> 
const Object &LLStack<Object>::top() const {
  // TODO: Fill in your const top() implementation here.
  // The following is a stub just to get the template project to compile.
  // You should delete it for your implementation.
  if (head == nullptr){
        throw StackEmptyException("Stack is empty.");
    }
    return head->data;
}

template <typename Object> 
void LLStack<Object>::push(const Object &elem) {
  // TODO: Fill in your push() implementation here.
  if (head != nullptr){
        Node* newNode = new Node(elem);
        newNode->next = head;
        head = newNode;
    }
    else{

        Node* newNode = new Node(elem);
        head = newNode;
    }
    temp_size += 1;
}

template <typename Object> 
void LLStack<Object>::pop() {
  // TODO: Fill in your pop() implementation here.
  if (head != nullptr){
        //remove node
        Node* temp = head;
        head = head->next;

        temp_size -= 1;
        delete temp;
    }
    else{
        throw StackEmptyException("Stack is empty, nothing to pop.");
    }
}

template <typename Object>
void LLStack<Object>::printList(){
    Node* current = head;
    if (temp_size !=0){
        while (current != nullptr){
            std::cout<<current->data<<" ";
            current = current->next;
        }
        std::cout<<std::endl;
    }
}

#endif
