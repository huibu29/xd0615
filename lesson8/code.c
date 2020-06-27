int inches = 0;

int cm = 0; //Ϊcm��inches�����룩��Ĭ��ֵ

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // ��Trigger������Ϊ���
  digitalWrite(triggerPin, LOW); // ��Trigger���������ѹ��Ϊ�͵�ѹ
  delayMicroseconds(2); // �ȴ�2΢��
  
  digitalWrite(triggerPin, HIGH); //�����������ѹ��Ϊ�ߵ�ѹ
  delayMicroseconds(10); //�ȴ�10΢�룬Trigger����10��s�ĸߵ�ƽ�źţ��������
  digitalWrite(triggerPin, LOW); //�����������ѹ��Ϊ�͵�ѹ
  pinMode(echoPin, INPUT); //���ز�������Ϊ����״̬
  
  return pulseIn(echoPin, HIGH);// ��ȡ�ز����ţ���������������ʱ�䣨��΢��Ϊ��λ��
}

void setup()
{
  Serial.begin(9600);// ��ʼ������

}

void loop()
{
  
  cm = 0.01723 * readUltrasonicDistance(7, 7); //������ʱ��ת��Ϊ����
  
  inches = (cm / 2.54); //����2.54ת��ΪӢ��
  Serial.print(inches); //��ӡ��Ӣ��Ϊ��λ�ľ���
  Serial.print("in, "); 
  Serial.print(cm);
  Serial.println("cm"); //��ӡ��in������cm��
  delay(100); //�ȴ�100ms
}
