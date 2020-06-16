int i=0;
void setup()
{
  for(i=0;i<9;i++)
  pinMode(i, OUTPUT);
}

void loop()
{
  
  for(i=0;i<9;i++)
  {
    digitalWrite(i, HIGH);
    delay(400); // Wait for 1000 millisecond(s)
    digitalWrite(i, LOW);
    delay(400); // Wait for 1000 millisecond(s)
  }
  

  for(int j=0;j<5;j++)
  {
    i=2;
    i=i+j;
    for(;i<8;i+=i/2)
    {
      digitalWrite(i, HIGH);
      delay(300); // Wait for 1000 millisecond(s)
      digitalWrite(i, LOW);
      delay(300); // Wait for 1000 millisecond(s)
    }
  }
  
  for(i=0;i<9;i++)
  {
    digitalWrite(9-i, HIGH);
    delay(400); // Wait for 1000 millisecond(s)
    digitalWrite(9-i, LOW);
    delay(400); // Wait for 1000 millisecond(s)
  }
  
}
