#include "mbed.h"
DigitalOut relay(D6);
DigitalOut led(LED1);
DigitalIn mybutton(D7);

char pass[4] = {'1', '2', '3', '4'};
char inputPass[4] = {};

bool checkPassword(char p[])
{
  int sovp = 0;
  for (int i = 0; i < 4; i++)
  {
    if (p[i] == pass[i])
    {
      sovp++;
    }
  }
  if (sovp == 4)
  {
    return true;
  }
  else
    return false;
}

int w = 0;
int main()
{

  while (1)
  {
    printf("Введите пароль: ");
    inputPass[0] = getchar();
    inputPass[1] = getchar();
    inputPass[2] = getchar();
    inputPass[3] = getchar();
    if (checkPassword(inputPass))
    {
      if (mybutton == 0)
      {
        led = !led;
      }
      else
      {
        while (w < 50)
        {
          relay = !relay;
          while (w < 50)
          {
            led = !led;
            w++;
            wait_ns(100000);
          }
          relay = !relay;
          w = 0;
          if (!led)
          {
            led = !led;
          }
        }
      }
    }
    printf("Пароль не подошел, введите его заново");
  }
}