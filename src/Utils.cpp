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

void printStart(std::wofstream &output)
{
	output << L"======================================================================================================================================\n"
					  L"=>                                                    ### START PROCESS ###\n"
	          L"======================================================================================================================================\n"
            L"\n"
	          L"======================================================================================================================================\n"
				    L"=>                                                    ### PARTIAL RESULT ###\n"
	          L"======================================================================================================================================\n"
            L"\n";
}

std::wofstream createOutput(const std::locale &loc)
{
  wofstream output("./dataset/output.data");

  if(!output.is_open()) {
    wcout << L"Não foi possível abrir o arquivo \"./dataset/output.data\"" << endl;
    exit(1);
  }

  output.imbue(loc);

  return output;
}

void printEnd(std::wofstream &output, Map &mp)
{
  output << L"======================================================================================================================================\n"
  L"                                                    ### WORDS ###\n";

   for(const auto &pair : mp.mp) {
    output<< L"\t\t\t\t\t\t\t\t\t\t\t\t\t"<< L"Chave: " << pair.first << L" apareceu: " <<pair.second.appearences << endl;
   }
}