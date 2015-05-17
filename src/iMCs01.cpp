#include "my_include.hpp"

bool insmod_iMCs01()
{
  system( "sudo insmod /home/sakamoto/catkin_ws/src/third_robot_driver/include/ThirdRobotInterface/imcs01_driver/driver/urbtc.ko" );
  return true;
}

bool permit_iMCs01()
{
  ofstream ofs("./DeviceLog.txt");
  namespace fs = boost::filesystem;
  fs::directory_iterator end;
  for(fs::directory_iterator it("/dev/"); it!=end; ++it )
    {
      ofs << it->path() << endl;
    }

  int i=0;
  int j=0;
  int flag=0;
  int allflag=0;
  std::string compare = "/dev/urbtc";
  std::string kyoka = "sudo chmod 777 ";
  std::string line[1000];
  std::ifstream ifs("./DeviceLog.txt");

  while (std::getline(ifs, line[i])) {
    flag = 1;

    for(j=1;j<10;j++){
      if(line[i][j] == compare[j-1]){
	flag*=flag;
      }else{
	flag*=0;
	break;
      }
    }

    if(flag==1){
      std::string command = kyoka + line[i];
      const char *c = command.c_str();
      system( c );
      std::cout << c << std::endl;
      allflag=1;
    }
    i++;
  }

  if(allflag == 0){
    cout << "nothing device!!" << endl;
    return false;
  }else{
    return true;
  }
}
