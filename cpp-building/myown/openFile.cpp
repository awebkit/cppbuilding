// print the content of a text file.
#include <iostream>
#include <fstream>
using namespace std;

int main () {

  ifstream infile;

  infile.open ("test.html", ifstream::in);

  int ch = infile.get();
  while (infile.good()) {
    cout << (char) ch;
    ch = infile.get();
  }

  infile.close();

  return 0;
}
