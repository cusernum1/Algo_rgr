#include <iostream>
#include <forward_list>

using namespace std;

template <class T>
class Stack 
{
   private:
      forward_list<T> data; // Односвязный список для хранения данных стека

   public:
      void push(const T& value);
      void pop();
      T top();
      bool empty();
};

template <class T>
void Stack<T>::push(const T& value) 
{
   data.push_front(value); // Добавление элемента в начало списка (так как это стек)
}

template <class T>
void Stack<T>::pop() 
{
   if (!data.empty()) 
   {
      data.pop_front(); // Удаление верхнего элемента стека
   }
   else 
   {
      cout << "Стек пуст!" << endl;
   }
}

template <class T>
T Stack<T>::top() 
{
   if (!data.empty()) 
   {
      return data.front(); // Возвращает значение верхнего элемента стека
   }
   else 
   {
      cerr << "Стек пуст!" << endl;
      exit(1);
   }
}

template <class T>
bool Stack<T>::empty() 
{
   return data.empty(); // Проверка на пустоту стека
}

int main() 
{
   Stack<int> stack;
   
   int n, i;
   
   cin >> n;
   
   i = 0;
   
   while(i != n)
   {
      int a;
      cin >> a;
      stack.push(a);
      i++;
   }

   while (!stack.empty()) 
   {
      cout << "Верхний элемент стека: " << stack.top() << endl;
      stack.pop();
   }

   return 0;
}