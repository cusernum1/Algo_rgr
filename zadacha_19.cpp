bool findLargeStringInFile(const string& text_file_name, const string& pattern_file_name) 
{
   ifstream text_file(text_file_name);
   ifstream pattern_file(pattern_file_name);
   if (!text_file.is_open() || !pattern_file.is_open()) 
   {
      cerr << "ќшибка открыти€ файлов" << endl;
      return false;
   }
   char pattern_char;
   pattern_file.get(pattern_char);
   int pattern_index = 0;
   char text_char;
   while (text_file.get(text_char)) 
   {
      if (text_char == pattern_char) 
      {
         pattern_index++;
         if (pattern_index == pattern_file.tellg()) 
         {
            return true;
         }
         pattern_file.get(pattern_char);
      }
      else 
      {
         pattern_index = 0;
         pattern_file.seekg(0);
         pattern_file.get(pattern_char);
      }
   }
   return false;
}
Ёффективность: ќ(mn), где m Ц количество символов в текстовом файле, а n Ц количеств символов в файле со строкой.
