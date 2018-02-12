#include<fstream>
#include<sstream>
#include<string>

using namespace std;

std::string ReplaceString(std::string subject, const std::string& search,
                        const std::string& replace);

int main(){
  ostringstream text;
  ifstream in_file("Lesen-7");
  text<<in_file.rdbuf();
  string str = text.str();
  string str_find = "\n";
  string str_replace = " ";
  ReplaceString(str, "\n", " ");
  in_file.close();
  ofstream out_file("Lesen-7");
  out_file<<str;

}

std::string ReplaceString(std::string subject, const std::string& search,
                        const std::string& replace) {
  size_t pos = 0;
  while ((pos = subject.find(search, pos)) != std::string::npos) {
       subject.replace(pos, search.length(), replace);
       pos += replace.length();
  }
  return subject;
}
