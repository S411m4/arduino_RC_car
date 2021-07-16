char command;
int pwm = 255;
int speed;

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT); //LED
	for (int i = 6; i <= 13; i++)
         {
			pinMode(i, OUTPUT);
         }
   pinMode(A1, OUTPUT);
   pinMode(A2, OUTPUT);
   pinMode(A3, OUTPUT);
   pinMode(A4, OUTPUT);

}

void loop()
{

 if (Serial.available())
 {
   command = Serial.read();
   Serial.println(command);
 }
  
  if(command == 'F')
  {
   for(int j = 6; j <= 13; j += 2)
   {
    digitalWrite(j, HIGH);
   }
     for(int j = 7; j <= 13; j += 2)
   {
    digitalWrite(j, LOW);
   }
  }
  
   
  if(command == 'B')
  {
   for(int j = 6; j <= 13; j += 2)
   {
    digitalWrite(j, LOW);
   }
     for(int j = 7; j <= 13; j += 2)
   {
    digitalWrite(j, HIGH);
   }
  }
  
    if(command == 'R')
  {
   for(int j = 6; j <= 9; j += 2)
   {
    digitalWrite(j, HIGH);
   }
     for(int j = 7; j <= 9; j += 2)
   {
    digitalWrite(j, LOW);
   }
   for (int k = 10; k <= 13; k++)
   {
	digitalWrite(k, LOW);
   }
  }
    
    if(command == 'L')
  {
   for(int j = 10; j <= 13; j += 2)
   {
    digitalWrite(j, HIGH);
   }
     for(int j = 11; j <= 13; j += 2)
   {
    digitalWrite(j, LOW);
   }
   for (int k = 6; k <= 9; k++)
   {
	digitalWrite(k, LOW);
   }
  }
  
  if (command == 'W')
  {
    digitalWrite(3, HIGH);
  }
  
  if (command == 'w')
  {
	digitalWrite(3, LOW);
  }
  
  if(command == 'S')
  {
   for (int i = 6; i <= 13; i++)
   {
     digitalWrite(i, LOW);
   }  
  }
  
  speed = int(command);
  pwm = map(speed, 0, 5, 0, 255);
  
  analogWrite(A1, pwm);
  analogWrite(A2, pwm);
  analogWrite(A3, pwm);
  analogWrite(A4, pwm);

  
}
