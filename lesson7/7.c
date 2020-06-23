#include <MsTimer2.h>     //��ʱ�����ͷ�ļ�
 
int tick = 0; //����ֵ
byte count = 0;
#define IN1 11
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 9

#define LT 7
#define BT 6
 

void onTimer()
{
  Light(tick);  //�����߶���ʾ����
  tick++;
  if(tick==10)
    tick=0;
}

int pinInterrupt = 2; //���ж��źŵĽ�
//�жϷ������ 
void onChange()
{
   if ( digitalRead(pinInterrupt) == LOW )
      tick=0;
}
 
void setup()
{
  pinMode(IN1, OUTPUT);//����1
  pinMode(IN2, OUTPUT);//����2
  pinMode(IN3, OUTPUT);//����3
  pinMode(IN4, OUTPUT);//����4

  pinMode(S1, OUTPUT);//Ƭѡ1
  
  pinMode(LT,OUTPUT);//����
  pinMode(BT,OUTPUT);//����
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  
  Serial.begin(9600); //��ʼ������
  
  pinMode( pinInterrupt, INPUT);
  
  MsTimer2::set(1000, onTimer); //�����жϣ�ÿ1000ms����һ���жϷ������ onTimer()
  MsTimer2::start(); //��ʼ��ʱ
  
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  
}
 
void Light(int tick)
{
  count=tick;
  count=count-'0';
  digitalWrite(S1,LOW);
  digitalWrite(IN1,count&0x1);
  digitalWrite(IN2,(count>>1)&0x1);
  digitalWrite(IN3,(count>>2)&0x1);
  digitalWrite(IN4,(count>>3)&0x1);
  digitalWrite(S1,HIGH);  
}

void loop()
{
  
}
