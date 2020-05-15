/******************************************************************************

               Tested this on https://www.onlinegdb.com/online_c++_compiler

*******************************************************************************/

#include <iostream>
#include <ctime>


using namespace std;

int main ()
{

  // current date/time based on current system
  time_t now = time (0);

  // convert now to tm struct for UTC
  struct tm *gmtm = gmtime (&now);

  //convert to string
  char *dt = asctime (gmtm);

  //result
  cout << "The UTC current date and time is:" << dt << endl;

  //   int tm_year is the year since 1900
  cout << "Year:" << 1900 + gmtm->tm_year << endl;

  // month of year from 0 to 11
  cout << "Month: " << 1 + gmtm->tm_mon << endl;

  // day of month from 1 to 31
  cout << "Day: " << gmtm->tm_mday << endl;

  // hours of day from 0 to 23
  cout << "Time: " << gmtm->tm_hour << ":";

  // minutes of hour from 0 to 59
  cout << gmtm->tm_min << endl;

  cout << endl;


  //struct is not necessary, initialize
  tm *timeOfTakingOff = gmtime (&now);
  int input = 0;
  cout << endl << "Day of Taking off: ";
  cin >> input;
  timeOfTakingOff->tm_mday = input;

  cout << endl << "Month of Taking off: ";
  cin >> input;
  timeOfTakingOff->tm_mon = input - 1;	//Because 0<=tm_mon<=11

  cout << endl << "Year of Taking off: ";
  cin >> input;
  timeOfTakingOff->tm_year = input - 1900;

  cout << endl << "Hour of Taking off: ";
  cin >> input;
  timeOfTakingOff->tm_hour = input;

  cout << endl << "Minute of Taking off: ";
  cin >> input;
  timeOfTakingOff->tm_min = input;


  dt = asctime (timeOfTakingOff);
  //result
  cout << endl << "time of taking off is:" << dt << endl;

  return 0;
}
