#include"Utils.hpp"


wchar_t *getText(const std::locale &loc,int counter)
{

  string number;
  string name = "./dataset/txt0";
  
  number = to_string(counter);

  name = name + number;
  name = name + ".txt";

  wifstream txt(name, ios::binary);

  if(!txt.is_open()) {
    wcout << L"Não foi possível abrir o arquivo" << endl;
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

  wstring_convert<codecvt_utf8<wchar_t>> converter;
  string key;

   for(int i = 0 ; i < MAXSIZE ; i++) {
    key = converter.to_bytes(Heapp->vet[i].value);
    cout << " Chave: " << key;
    printf(" frequência: %d\n",Heapp->vet[i].frequence);
   }
}