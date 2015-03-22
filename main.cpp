#include <iostream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
using namespace std;

int main(void)
{
  namespace fs = boost::filesystem;
  fs::directory_iterator end;
  for(fs::directory_iterator it("/dev/"); it!=end; ++it )
    {
      if(fs::is_directory(*it))
	cout << "D ";
      else
	cout << "F";
      cout << it->path() << endl;
    }
  return 0;
}
