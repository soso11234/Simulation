#ifndef LIST_H
#define LIST_H

/*
  Name : List
  Purpose : Making Template class, it is singly linked list, and also can convert to array as well.
  overloading += operator to add something into the linked list. To convert to array, it needs an array, it modify the array but no return anything (for converarray member function)

*/
template <class T>
class List
{
  class Node
  {
    public:
      T data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void convertToArray(T*,int&);
    List<T>& operator+=(T);

  private:
    Node* head;
};

template <class T> List<T>::List() : head(nullptr) { }

template <class T> List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}
template <class T> List<T>& List<T>::operator+=(T t)
{
  Node* temp;
  Node* current;
  Node* prev;
  temp = new Node;
  temp->data = t;
  temp->next = nullptr;
  current = head;
  prev = nullptr;
  while(current != nullptr)
  {//current = next to tail, prev = tail
    prev = current;
    current = current->next;
  }
  if(prev == nullptr)
  {//nothing in here
      head = temp;
      return *this;
  }
  else{//prev = tail, 
    prev->next = temp;
  }
  temp->next = current;
  return *this;
}
template <class T> void List<T>::convertToArray(T* arr, int& size)
{
  Node* current;
  current = head;
  size = 0;
  while(current != nullptr)
  {
    arr[size] = current->data;
    size +=1;
    current = current->next;
  }
}
#endif