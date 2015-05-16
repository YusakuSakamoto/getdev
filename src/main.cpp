#include "my_include.hpp"

bool permit_nothing()
{
  cout <<"OK!  What do you want to permit?" << endl;
  cout <<"1:JOYSTICK(js*)" << endl;
  cout <<"2:ARDUINO(ttyACM*)" << endl;
  cout <<"3:iMCs01(urbtc*)->4,5,6,3" << endl;
  cout <<"Please input your command.Like \"./main 1\"" << endl;
}


int main(int argc,char **argv)
{
  cout <<"---------------------------------------------" << endl;
  if(argc==2){
    int judge = 0;

    judge = atof(argv[1]);

    switch(judge)
      {
      case 1:
	permit_joystick();
	break;
      case 2:
	permit_arduino();
	break;
      case 3:
	permit_iMCs01();
	break;
      case 4:	
	insmod_iMCs01();
	break;
      default:
	permit_nothing();
	break;
      }
  }else{
    permit_nothing();
  }

  cout <<"---------------------------------------------" << endl;
  return 0;
}
