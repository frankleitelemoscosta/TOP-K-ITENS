#include"Utils.hpp"


wchar_t *getText(const std::locale &loc)
{
  wifstream txt("./dataset/input.data", ios::binary);

  if(!txt.is_open()) {
    wcout << L"Não foi possível abrir o arquivo \"./dataset/input.data\"" << endl;
    exit(1);
  }

  // Set the locale to handle UTF-8 encoding
  txt.imbue(loc);

  // Determine the size of the file in bytes
  txt.seekg(0, ios::end);
  streampos fileSize = txt.tellg();
  txt.seekg(0, ios::beg);

  // Allocate memory for the wchar_t buffer
  wchar_t* buffer = new wchar_t[fileSize];

  // Read the file contents into the buffer
  txt.read(buffer, fileSize);

  // Close the file
  txt.close();

  return buffer;
}

void printEnd( Vector *Heapp)
{

   for(int i = 0 ; i < 20 ; i++) {
    wcout << "Chave: " << Heapp->vet[i].value << L" apareceu: " << Heapp->vet[i].frequence << endl;
   }
}