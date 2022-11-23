/*
A train leaves station A at 4.00 A.M. and travels at 80KM/h. After every 30 minutes, it reaches a station where
it halts for 10 minutes. It reaches its final destination B at 1.00 P.M. Display a table showing its arrival and
departure time at every intermediate station. Also calculate the total distance between A and B.

departure = A -> 4 AM
speed = 80 KM/Hr
distance_between_stations = 30 mins => 40 KMs
halt = 10 mins
arrival = B -> 1 PM
total_time = 9 Hrs => 540 mins

total distance between A and B =
*/

#include <iostream>

int main()
{
  const int total_time = 540;
  int remaining_time = total_time;
  int station_count = 0;
  double km_traveled = 0;
  const int speed = 80; // Km/Hr

  while (remaining_time > 0)
  {
    if (remaining_time - 30 < 0)
    {
      km_traveled += (speed * remaining_time) / 60;
      std::cout << "km_traveled_last: " << (speed * remaining_time) / 60 << std::endl;
      remaining_time = 0;
    }
    else
    {
      // 30 mins travel
      remaining_time -= 30;
      km_traveled += 40;

      int st_arrival_time = total_time - remaining_time;

      // 10 mins halt
      remaining_time -= 10;

      int st_departure_time = st_arrival_time + 10;

      station_count++;

      std::cout << "[+] station_count: " << station_count;
      std::cout << "| KMs traveled: " << km_traveled;
      std::cout << "| Arrival time: " << st_arrival_time / 60 << "Hrs " << st_arrival_time % 60 << "Mins";
      std::cout << "| Departure time: " << st_departure_time / 60 << "Hrs" << st_departure_time % 60 << "Mins" << std::endl;
    }
  }

  std::cout << "station_count: " << station_count << std::endl;
  std::cout << "km_traveled: " << km_traveled << std::endl;
}