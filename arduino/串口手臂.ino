#include<Servo.h>
Servo a; 
Servo b;
Servo c; 
Servo d;
Servo e; 
Servo f;
int pos = 0;
int i,j = 0;
String input = "";
int setposition(int num, int positions)
{
    if(positions>=0 && positions<180)
    {
      if(num == 1)
      {a.write(positions);}
        if(num == 2)
      {b.write(positions);}
        if(num == 3)
      {c.write(positions);}
        if(num == 4)
      {d.write(positions);}
        if(num == 5)
      {e.write(positions);}
        if(num == 6)
      {f.write(positions);}
    }
}
int readposition(int num)
{
  if(num == 1)
  {Serial.println(a.read());}
  if(num == 2)
  {Serial.println(b.read());}
  if(num == 3)
  {Serial.println(c.read());}
  if(num == 4)
  {Serial.println(d.read());}
  if(num == 5)
  {Serial.println(e.read());}
  if(num == 6)
  {Serial.println(f.read());}
}
  
void setup()
  {
  Serial.begin(9600);
  Serial.println("Ready");
  Serial.println("输入0000 手动初始化，0001自动初始化（emmm，有未知bug），0002准备夹，0003夹了就跑。0004 放手");
  a.attach(3);  b.attach(5);  c.attach(6);  d.attach(9);  e.attach(10); f.attach(11);
  a.write(90);  b.write(90);  c.write(90);  d.write(90);  e.write(90);  f.write(90); 
  }
void loop()
{
  //receive command from serial port
  while (Serial.available()>0) //读取串口数据
  {
    input += char(Serial.read());
    delay(2);
  }
  if (input.length()>0) //output the command
  {
    Serial.println(input);
  }
  //动作0
  if (input == "0000" ) 
  {
    Serial.println("要执行动作0了，我被强制初始化了");
    delay(500);
    a.write(90);  b.write(90);  c.write(90);  d.write(90);  e.write(90);  f.write(90); 
  }
  
  //动作1
  if (input == "0001" ) 
  {
      Serial.println("我要做动作1了，这玩意要搭配0000号动作用");
      delay(500);
      if(j = readposition(1)<90){
      for(i=readposition(1);i<=90;i++) //Servo1
      {
        setposition(1,i);
        delay(15);
      }}
      if(j = readposition(1)>90){
      for(i=readposition(1);i>=90;i--)//Servo1
      {
        setposition(1,i); 
        delay(15);
      }}
      if( j = readposition(2)<90){
      for(i=  readposition(2);i<=90;i++){//Servo2
        setposition(2,i);
        delay(15);
      }}
      if(j = readposition(2)>90){
      for(i =readposition(2);i>=90;i--)//Servo2
      {
        setposition(2,i); 
        delay(15);
      }}
      if(j = readposition(3)<90){
      for(i=readposition(3);i<=90;i++){//Servo3
        setposition(3,i);
        delay(15);
      }}
      if(j = readposition(3)>90){
      for(i=readposition(3);i>=90;i--)//Servo3
      {
        setposition(3,i); 
        delay(15);
      }}
      if(j = readposition(3)<90){
      for(i=readposition(4);i<=90;i++)//Servo4
      {
        setposition(4,i); 
        delay(15);
      }}
      if(j = readposition(4)>90){
      for(i=readposition(4);i>=90;i--)//Servo4
      {
        setposition(4,i); 
        delay(15);
      }}
      if(j = readposition(5)<90){
      for(i=readposition(5);i<=90;i++)//Servo5
      {
        setposition(5,i);
        delay(15);
      } }
      if(j = readposition(5)>90){
      for(i=readposition(5);i>=90;i--)//Servo5
      {
        setposition(5,i); 
        delay(15);
      }}
      if(j = readposition(6)<90){
      for(i=readposition(6);i<=90;i++)//Servo6
      {
        setposition(6,i); 
        delay(15);
      }}
      if( j = readposition(6)>90){
      for(i=readposition(6);i>=90;i--)//Servo4
      {
        setposition(6,i); 
        delay(15);
      }}
  }
  
  //动作2
  if (input == "0002" ) 
  {
    Serial.println("我要做先摆好位置");
    delay(500);
    for(i=90;i>=50;i--) //舵机6
    {
      setposition(6,i);
      delay(15);}
    for(i=90;i<=170;i++)//舵机2
    { 
      setposition(2,i);
      delay(15);
    }
    for(i=90;i>40;i--)//舵机3
    {
      setposition(3,i);
      delay(15);
    }
    for(i=90;i<=125;i++)//舵机5
    {
      setposition(5,i++);
      delay(15);
    }
    Serial.println("我要夹了，你准备好了吗？！");
  }

  //动作3
  if (input == "0003" ) 
  {
    Serial.println("我夹啦，哈哈哈");
    delay(500);
    for(i=50;i<75;i++) //Servo6 夹子
    {
      setposition(6,i);
      delay(15);
    }
    Serial.println("贼鸡儿帅");
    for(i=125;i>=90;i--) //Servo5
    {
      setposition(5,i);
      delay(15);
    }
    for(i=29;i<=90;i++) //Servo3
    {
      setposition(3,i);
      delay(15);
    }
    for(i=170;i>=90;i--)//Servo2
    {
      setposition(2,i);
      delay(15);
    }
    for(i = 90;i<=135;i--)//Servo1
    {
      setposition(1,i);
      delay(15);
    }
    Serial.println("动作华丽结束");
  }
  if(input == "0004")//放手
  {
    Serial.println("很多事情结束终归是放手")；
    for(i=75;i>50;i--) //Servo6
    {
      setposition(6,i);
      delay(15);
    }
  }
  
  input = "";

  

}

 
 

