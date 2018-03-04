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
  Serial.println("输入0000 手动初始化，0001自动初始化（bug修复了，我真牛逼），0002准备夹，0003夹了就跑。0004 放手");
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
    Serial.println("我被强制初始化完成了，每个舵机都是标准的九十度。不信你量"); 
  }
  
  //动作1
  if (input == "0001" ) 
  {
      Serial.println("我要做动作1了，这玩意贼鸡儿好用，自动缓慢的还原，缓慢初始化！！！");
      delay(500);
      
      if(j = c.read()<90){
      for(i=c.read();i<=90;i++){//Servo3
        setposition(3,i);
        delay(15);
      }}
      if(j = c.read()>90){
      for(i=c.read();i>=90;i--)//Servo3
      {
        setposition(3,i); 
        delay(15);
      }}
      
      if( j = b.read()<90){
      for(i=  b.read();i<=90;i++){//Servo2
        setposition(2,i);
        delay(15);
      }}
      if(j = b.read()>90){
      for(i =b.read();i>=90;i--)//Servo2
      {
        setposition(2,i); 
        delay(15);
      }}

      
      if(j = a.read()<90){
      for(i=a.read();i<=90;i++) //Servo1
      {
        setposition(1,i);
        delay(15);
      }}
      if(j = a.read()>90){
      for(i=a.read();i>=90;i--)//Servo1
      {
        setposition(1,i); 
        delay(15);
      }}
     
     
      if(j = d.read()<90){
      for(i=d.read();i<=90;i++)//Servo4
      {
        setposition(4,i); 
        delay(15);
      }}
      if(j = d.read()>90){
      for(i=d.read();i>=90;i--)//Servo4
      {
        setposition(4,i); 
        delay(15);
      }}
     
      
      if(j = e.read()<90){
      for(i= e.read();i<=90;i++)//Servo5
      {
        setposition(5,i);
        delay(15);
      } }
      if(j =  e.read()>90){
      for(i= e.read();i>=90;i--)//Servo5
      {
        setposition(5,i); 
        delay(15);
      }}
      if(j =  f.read()<90){
      for(i=f.read();i<=90;i++)//Servo6
      {
        setposition(6,i); 
        delay(15);
      }}
      if( j = f.read()>90){
      for(i=f.read();i>=90;i--)//Servo6
      {
        setposition(6,i); 
        delay(15);
      }}
      Serial.println("缓慢初始化换成，我变成了刚正不阿九十的机器手包青天");
  }
  
  //动作2
  if (input == "0002" ) 
  {
    Serial.println("我要做开始准备拿东西了，麻烦先摆好位置，谢谢");
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
    Serial.println("我要夹了，你准备好了吗？！准备好了就抠键盘！");
  }

  //动作3
  if (input == "0003" ) 
  {
    Serial.println("收到，我要夹啦，哈哈哈");
    delay(500);
    for(i=50;i<73;i++) //Servo6 夹子
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
    for(i=40;i<=90;i++) //Servo3
    {
      setposition(3,i);
      delay(15);
    }
    for(i=170;i>=90;i--)//Servo2
    {
      setposition(2,i);
      delay(15);
    }
    for(i = 90;i<=165;i++)//Servo1
    {
      setposition(1,i);
      delay(15);
    }
    Serial.println("动作华丽结束，木块在我手里！，你想要吗？");
  }
  if(input == "0004")//放手
  {
    Serial.println("很多事情结束终归是放手");
    
    for(i=90;i<=120;i++)//Servo2
    {
      setposition(2,i);
      delay(15);
    }
    
    for(i=90;i>=60;i--) //Servo3
    {
      setposition(3,i);
      delay(15);
    }
    
    for(i=90;i<=130 ;i++) //Servo5
    {
      setposition(5,i);
      delay(25);
    }

    for(i=73;i>50;i--) //Servo6
    {
      setposition(6,i);
      delay(15);
    }

    
    Serial.println("SEEYA");
  }

  
  input = "";

  

}

 
 

