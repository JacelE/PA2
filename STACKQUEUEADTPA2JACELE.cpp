#include <iostream>
#include <string>

using namespace std;

// Data Class : Holds all the data that goes inside the Node
class TicketItem {
public:
  string personName;
  string reserveCode;
  TicketItem(string personName, string reserveCode) {
    this->personName = personName;
    this->reserveCode = reserveCode;
  }
  void print() {

    cout << personName << " " << endl;
    cout << reserveCode << " " << endl;
  }
};

// Node Class : Node for the LinkedList
template <typename T> class Node {
public:
  T *data;
  Node<T> *nextNode;

  Node(T *data) {
    this->data = data;
    nextNode = nullptr;
  }
  void print() { data->print(); }
};

template <typename T> class LLStack{
private:
Node<T> *top;
int stackSize;
const int SMAXITEM = 100;

public:
//Constructor
LLStack(){
    stackSize = 0 ;
}
LLStack(T *data){
    Node <T> *newNode = new Node<T>(data);
    top = newNode;
    stackSize = 1;
}

//Destructor
~LLStack(){
  while(top!=NULL){
    pop(); 
  }
}

bool isFull(){
if(stackSize == SMAXITEM){
  return true;
}
else{
  return false;
}
}

bool isEmpty(){
if(stackSize == 0){
return true;
} 
else{
  return false;
}
}

void push(T* item){ //check
Node<T> *temp = new Node<T>(item);

if(isFull()){
cout<< "Stack is Full" << endl;
return;
}

temp->nextNode = top;
top = temp; 
stackSize++;


}

void pop(){
Node<T> *temp = top;
top = top->nextNode;
stackSize--;
delete temp;
}

T* peek(){
if(isEmpty()){
    return nullptr;
}

  return top->data;


}

void print(){ // pop stack one by one and print 

    LLStack<T>* temp(nullptr);

    //pushing elements into temp stack and reversing order
    while(!isEmpty()){
        temp->push(peek());
        pop();
    }
    //pushing elements back into main stack and printing them in the correct order
    while(!temp->isEmpty()){
        T* data1;
        data1 = temp->peek();
        push(data1);
        data1->print();
        temp->pop();

    }


  cout<<endl;
}

};


template <typename T> class StackQ{
    private:
    LLStack<T>* enQStack;
    LLStack<T>* deQStack;
    int queueSize;
    const int QMAXITEMS = 100;

    public:

  StackQ(){
    enQStack = new LLStack<T>();
    deQStack = new LLStack<T>();
    queueSize = 0;
  }

  StackQ(T* data){ //make another constructor that puts a data type in
    enQStack = new LLStack<T>(data);
    deQStack = new LLStack<T>(data);
  }
    
  ~StackQ(){
    while(!enQStack->isEmpty()){
      enQStack->pop();
    }
    while(!deQStack->isEmpty()){
      deQStack->pop();
    }
    delete enQStack;
    delete deQStack;
  }
    
    bool IsFull(){
      if(queueSize == QMAXITEMS){
        return true;
      }
      else{
        return false;
      }
    }

    bool IsEmpty(){
      if(queueSize == 0){
        return true;
      }
      else{
        return false;
      }
    }

    void enqueue (T* item){
      if(IsFull()){
        cout<<"Queue is Full!"<<endl;
        return;
      }

      enQStack->push(item);
      queueSize++;
    }

    void dequeue(){
     
     if(IsEmpty()){
      cout<< "Queue is Empty!" <<endl;
      return;
     }

     if(deQStack->isEmpty()){   
      while(!enQStack->isEmpty()){
        deQStack->push(enQStack->peek());
        enQStack->pop();
      }
     }

      deQStack->pop();
      queueSize--;
      
    }

    T* peek(){
      return deQStack->peek();
    }

    int getQueueSize(){ 
        return queueSize;
    }
    void printTicketQueue(){
      
      if(deQStack->isEmpty()){       
        while(!enQStack->isEmpty()){
        deQStack->push(enQStack->peek());
        enQStack->pop();
      }
      }
       deQStack->print(); 
    }

    void print(){
      if(IsEmpty()){
        cout<<"Is Empty" << endl;
        return;
      }
       
          cout<<"enQStack:"<<endl;
          enQStack->print();
        
          cout<<"deQStack:"<<endl;
          deQStack->print();
    
    }

};

//Main Program

int main() {
    StackQ<TicketItem> *ll1 = new StackQ<TicketItem>();
    cout<<"Welcome to the Queue Implemented as two stacks!"<<endl;
    cout<<"Select one of the options to do: " << endl;
    cout<< "Type A: Add Item to ticket queue"<<endl;
    cout<<"Type B: Delete from ticket queue"<<endl;
    cout<<"Type C: Peek from the ticket queue"<<endl;    
    cout<<"Type D: Display the ticket queue"<<endl;  
    cout<<"Type E: Display ticket queue size"<<endl;  
    cout<<"Type F: Display enQStack and deQStack"<<endl;  
    cout<<"Type G: Exit"<<endl;  
    char input;
    bool done = false;
    while(!done){
    label1:
    cin >> input;
    //for loop to check if valid
    if(input == 'A' || input == 'a'){
        string name;       
        cout<<"Input a name: ";
        cin >> name;
        cout<<endl; 
        cout<<"Input an integer Reservation Code: ";
        string code;
        cin >> code;
        cout<<endl;
        TicketItem *d1 = new TicketItem(name, code);
        ll1->enqueue(d1);
    }
    else if(input == 'B' || input == 'b'){

      ll1->dequeue();

    }
    else if(input == 'C' || input == 'c'){
      TicketItem *temp;
      cout<<"Peek: " <<endl;  
      temp = ll1->peek();
        cout<<temp<<endl;
    }
    else if(input == 'D' || input == 'd'){
          ll1->printTicketQueue();
    }
    else if(input == 'E' || input == 'e'){
      cout<<ll1->getQueueSize()<<endl;
    }
    else if(input == 'F' || input == 'f'){
          ll1->print();
    }
    else if(input == 'G' || input == 'g'){

        cout<<"Exiting the Program"<<endl;
        done = true;
        break;
        }
    else{
        cout<<"Please enter a valid Response: ";
        goto label1;
    }
    cout<<"Select Another Option or You can exit:" << endl;
    }
  return 0;
}