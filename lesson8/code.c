int inches = 0;

int cm = 0; //为cm和inches（距离）赋默认值

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // 将Trigger引脚设为输出
  digitalWrite(triggerPin, LOW); // 将Trigger引脚输出电压设为低电压
  delayMicroseconds(2); // 等待2微秒
  
  digitalWrite(triggerPin, HIGH); //将引脚输出电压设为高电压
  delayMicroseconds(10); //等待10微秒，Trigger引脚10μs的高电平信号，触发测距
  digitalWrite(triggerPin, LOW); //将引脚输出电压设为低电压
  pinMode(echoPin, INPUT); //将回波引脚设为输入状态
  
  return pulseIn(echoPin, HIGH);// 读取回波引脚，并返回声波传播时间（以微秒为单位）
}

void setup()
{
  Serial.begin(9600);// 初始化串口

}

void loop()
{
  
  cm = 0.01723 * readUltrasonicDistance(7, 7); //将传播时间转化为距离
  
  inches = (cm / 2.54); //除以2.54转化为英尺
  Serial.print(inches); //打印以英尺为单位的距离
  Serial.print("in, "); 
  Serial.print(cm);
  Serial.println("cm"); //打印“in，距离cm”
  delay(100); //等待100ms
}
