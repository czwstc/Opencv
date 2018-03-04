#include<Servo.h>
#include <IRremote.h>

int recvPin = 13;//定义红外接收器的引脚为3
IRrecv irrecv(recvPin);
decode_results results;
Servo a,b,c,d;
int i,j;
long KEY_CODE_Left = 0xFF22DD;
long KEY_CODE_Right = 0xFF02FD;
long KEY_CODE_ZERO = 0xFFC23D;
String input = "";
void setup() 
{
  irrecv.enableIRIn(); // 初始化红外接收器
  Serial.begin(9600);
  for(i=2;i<9;i++)
  {if(i==2||i==4||i==7||i==8)
  {pinMode(i,OUTPUT); }}
  a.attach(5);b.attach(6);c.attach(9);d.attach(10);
  stop();
}
void up() //往前
{
  a.write(180);b.write(180);c.write(180);d.write(180);
  analogWrite(2,200);analogWrite(4,200);analogWrite(7,200);analogWrite(8,200);
}

void stop() //stop
{
  a.write(0);b.write(0);c.write(0);d.write(0);
}
void left()//往左
{
  a.write(180);b.write(180);c.write(180);d.write(180);
  digitalWrite(2,LOW);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,LOW);
}
void right()//往右
{
  a.write(180);b.write(180);c.write(180);d.write(180);
  digitalWrite(2,HIGH);digitalWrite(4,LOW);digitalWrite(7,LOW);digitalWrite(8,HIGH);
}
void loop() 
{ 
   if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);//以16进制换行输出接收代码
    Serial.println();//为了便于观看输出结果增加一个空行
    irrecv.resume(); // 接收下一个值
  }
  if (input.length()>0) //output the command
  {
    Serial.println(input);
  }

  if(results.value == KEY_CODE_ZERO )
  {
    stop();
  }
    if(results.value == KEY_CODE_Right)
  {
    right();    
    delay(5000);
    stop();
  }
      if(results.value == KEY_CODE_Left)
  {
    left();    
    delay(5000);
    stop();
  }
  
    input = "";
}
