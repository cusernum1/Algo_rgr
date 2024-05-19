#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Table {
private:
   vector<string> columnNames; // названия столбцов
   vector<vector<string>> rows; // строки со значениями
   string sortKey; // ключ для сортировки строк таблицы

public:
   // Конструктор, создающий пустую таблицу
   Table();

   // Деструктор
   ~Table();

   // Метод для добавления столбца в таблицу
   void addColumn(const string& columnName);

   // Метод для добавления строки в таблицу
   void addRow(const vector<string>& rowValues);

   // Метод для установки ключа для сортировки строк таблицы
   void setSortKey(const string& keyColumn);

   // Метод для получения количества столбцов в таблице
   int getColumnCount() const;

   // Метод для получения количества строк в таблице
   int getRowCount() const;

   // Метод для получения значения определенной ячейки таблицы
   string getValue(int row, int column) const;

   // Метод для получения строки таблицы по ключу
   vector<string> getRowByKey(const string& key) const;

   // Метод для удаления строки таблицы по ключу
   void deleteRowByKey(const string& key);

   // Метод для обновления значения в определенной ячейке таблицы
   void updateValue(int row, int column, const string& value);
};
