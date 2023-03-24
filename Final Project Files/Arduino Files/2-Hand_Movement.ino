#include <Servo.h>
Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo small;
int valsrec[5];
int stringlen = 6;
int counter = 0;
bool counterstart = false;
String received;


void setup()
{
  Serial.begin(9600);
  thumb.attach(13);
  index.attach(12);
  middle.attach(11);
  ring.attach(10);
  small.attach(9);
}

void program()
{  
  while(Serial.available())
  {
    char c = Serial.read();
    if (c == '$')
    {
      counterstart = true;
    }
    if(counterstart == true);
    {
      if(counter < stringlen)
      {
       received = String(received + c); 
       counter++;
      }
    }
    if(counter >= stringlen)
    {
      for(int i=0; i<5; i++)
      {
        valsrec[i] = received.substring(i+1,i+2) .toInt();
      }
      received = "";
      counter = 0;
      counterstart = false;
    }
  }
}

void loop()
{
    program();
    if(valsrec[0]==1)
    {
      thumb.write(180);
    }
    else
    {
      thumb.write(0);
    }
     if(valsrec[1]==1)
    {
      index.write(180);
    }
    else
    {
      index.write(0);
    }
     if(valsrec[2]==1)
    {
      middle.write(180);
    }
    else
    {
      middle.write(0);
    }
     if(valsrec[3]==1)
    {
      ring.write(180);
    }
    else
    {
      ring.write(0);
    }
     if(valsrec[4]==1)
    {
      small.write(180);
    }
    else
    {
      small.write(0);
    }
}
