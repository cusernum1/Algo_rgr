#include<iostream>
#include<forw
ard_list>

using namespace std;

template <typename T>
class stack
{
private:
   forward_list<T> lst;
   int Size = 0;

public:
   stack(int Size)
   {
      this->Size = Size;
   }
   
   void push(T val);
   T top();
   void pop();
   bool empty();
   int size();
   void clear();
};

template <typename T>
void stack<T>::push(T val)
{
   lst.push_front(val);
}

template <typename T>
T stack<T>::top()
{
   return lst.front();
}

template <typename T>
void stack<T>::pop()
{
   if(!lst.empty())
   {
      lst.pop_front();
      this->Size--;
   }
   else
   {
      throw;
   }
   
}
template <typename T>
int stack<T>::size()
{
   return this->Size;
}

template <typename T>
bool stack<T>::empty()
{
   return lst.empty();
}

template <typename T>
void stack<T>::clear()
{
   lst.clear();
   this->Size = 0;
}


int main()
{
   int size = 5;
   stack<int>st(size);
   for(int i = 0; i < size; i++)
   {
      cout << "Write element " << i << ":";
      int value;
      cin >> value;
      st.push(value);
   }
   for(int i = 0; i < size; i++)
   {
      cout << st.top() << " ";
      st.pop();
   }
   
   
   
   cout << "Top " << st.top() << endl;
   cout << "Empty " << st.empty() << endl;
   cout << "Size " << st.size() << endl;
   
   st.pop();
   cout << "After delete " << endl;
   cout << "Top " << st.top() << endl;
   cout << "Size " << st.size() << endl;
   
   st.clear();
   cout << "Size " << st.size() << endl;
   cout << "Empty " << st.empty() << endl;
   return 0;
}

