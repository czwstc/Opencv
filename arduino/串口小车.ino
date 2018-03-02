#include<Servo.h>

Servo a,b,c,d;
int i,j;
long KEY_CODE_CHL = 0xFFA25D;//前进
long KEY_CODE_CH = 0xFF629D;//后退
long KEY_CODE_CHH = 0xFFE21D;//左移动
long KEY_CODE_TUI = 0xFF22DD;//右移动
long KEY_CODE_JIN = 0xFF02FD;//左上移动
long KEY_CODE_XIA = 0xFFC23D;//左下移动
long KEY_CODE_L = 0xFFE01F;//右上移动
long KEY_CODE_H = 0xFFA857;//右下移动
long KEY_CODE_EQ = 0xFF906F;//顺时针旋转
long KEY_CODE_ZERO = 0xFF6897;//逆时针旋转

long KEY_CODE_LONG_PRESS = 0xFFFFFFFF;
long longPressKey = -1; //长按下的那个键
void setup() 
{
  irrecv.enableIRIn(); // 初始化红外接收器
  Serial.begin(9600);
  for(i=2;i<9;i++)
  {if(i==2||i==4||i==7||i==8)
  {pinMode(i,OUTPUT); }}
  a.attach(5);b.attach(6);c.attach(9);d.attach(10);
  a.write(180);b.write(180);c.write(180);d.write(180);
  }
  void up()
  {
    a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,HIGH);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,HIGH);
    }
     void down()
  {
    a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,LOW);digitalWrite(4,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);
    }
     void left()
  {
    a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,LOW);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,LOW);
    }
     void right()
  {
    a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,HIGH);digitalWrite(4,LOW);digitalWrite(7,LOW);digitalWrite(8,HIGH);
    }
     void left_and_up()
  {
    a.write(0);b.write(180);c.write(180);d.write(0);
    digitalWrite(2,LOW);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,LOW);
    }
    void left_and_down()
  {
    a.write(180);b.write(0);c.write(0);d.write(180);
    digitalWrite(2,LOW);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,LOW);
    }
    void right_and_up()
  {
    a.write(180);b.write(0);c.write(0);d.write(180);
    digitalWrite(2,HIGH);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,HIGH);
    }
    void right_and_down()
  {
    a.write(0);b.write(180);c.write(180);d.write(0);
    digitalWrite(2,LOW);digitalWrite(4,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);
    }
    void clock_wise()
    {
     a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,HIGH);digitalWrite(4,LOW);digitalWrite(7,HIGH);digitalWrite(8,LOW);
      }
      void anti_clock_wise()
    {
     a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,LOW);digitalWrite(4,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);
      }

void loop() 
{ if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);//以16进制换行输出接收代码
    Serial.println();//为了便于观看输出结果增加一个空行
    irrecv.resume(); // 接收下一个值
  }
  //按下CH-键的事件
  if (results.value == KEY_CODE_CHL ) {
     up();
    longPressKey = KEY_CODE_CHL;
  }
  //长按CH-键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_CHL)
{
    up();
  }//按下CH键的事件
  if (results.value == KEY_CODE_CH) {
    down();
    longPressKey = KEY_CODE_CH;
  }
  //长按CH键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_CH)
{
    down();
  }//按下CH+键的事件
  if (results.value == KEY_CODE_CHH ) {
    left();
    longPressKey = KEY_CODE_CHH;
  }
  //长按CH+键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_CHH)
{
    left();
  }//按下|◀◀键的事件
  if (results.value == KEY_CODE_TUI ) {
    right();
    longPressKey = KEY_CODE_TUI;
  }
  //长按|◀◀键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_TUI)
{
    right();
  }//按下▶▶|键的事件
  if (results.value == KEY_CODE_JIN ) {
    left_and_up();
    longPressKey = KEY_CODE_JIN;
  }
  //长按▶▶|键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_JIN)
{
    left_and_up();
  }//按下▶||键的事件
  if (results.value == KEY_CODE_XIA ) {
    left_and_down();
    longPressKey = KEY_CODE_XIA;
  }
  //长按▶||键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_XIA)
{
    left_and_down();
  }//按下"-"键的事件
  if (results.value == KEY_CODE_L ) {
     right_and_up();
    longPressKey = KEY_CODE_L;
  }
  //长按"-"键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_L)
{
     right_and_up();
  }//按下"+"键的事件
  if (results.value == KEY_CODE_H ) {
     right_and_down();
    longPressKey = KEY_CODE_H;
  }
  //长按"+"键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_H)
{
     right_and_down();
  }//按下EQ键的事件
  if (results.value == KEY_CODE_EQ ) {
    clock_wise();
    longPressKey = KEY_CODE_EQ;
  }
  //长按EQ键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_EQ)
{
    clock_wise();
  }//按下0键的事件
  if (results.value == KEY_CODE_ZERO ) {
    anti_clock_wise();
    longPressKey = KEY_CODE_ZERO;
  }
  //长按0键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_ZERO)
{
    anti_clock_wise();
  }}
