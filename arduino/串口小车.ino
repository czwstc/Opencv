#include<Servo.h>

Servo a,b,c,d;
int i,j;

void setup() 
{
  Serial.begin(9600);
  for(i=2;i<9;i++)
  {if(i==2||i==4||i==7||i==8)
  {pinMode(i,OUTPUT); }}
  a.attach(5);b.attach(6);c.attach(9);d.attach(10);
  a.write(180);b.write(180);c.write(180);d.write(180);
}
void up() //往前
{
  a.write(180);b.write(180);c.write(180);d.write(180);
  digitalWrite(2,HIGH);digitalWrite(4,HIGH);digitalWrite(7,HIGH);digitalWrite(8,HIGH);
}
void down()//往后
{
  a.write(180);b.write(180);c.write(180);d.write(180);
    digitalWrite(2,LOW);digitalWrite(4,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);
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
void left_and_up()//左上
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
void stop() //stop
{
  a.write(0);b.write(0);c.write(0);d.write(0);
}

void loop() 
{ 

  //按下CH-键的事件
  if (results.value == KEY_CODE_CHL ) 
  {
    up();
    longPressKey = KEY_CODE_CHL;
  }
  //长按CH-键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_CHL)
  {
    up();
  }//按下CH键的事件
  if (results.value == KEY_CODE_CH) 
  {
    down();
    longPressKey = KEY_CODE_CH;
  }
  //长按CH键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_CH)
  {
    down();
  }//按下CH+键的事件
  if (results.value == KEY_CODE_CHH ) 
  {
    left();
    longPressKey = KEY_CODE_CHH;
  }
  //长按CH+键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_CHH)
  {
    left();
  }//按下|◀◀键的事件
  if (results.value == KEY_CODE_TUI ) 
  {
    right();
    longPressKey = KEY_CODE_TUI;
  }
  //长按|◀◀键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_TUI)
  {
    right();
  }//按下▶▶|键的事件
  if (results.value == KEY_CODE_JIN ) 
  {
    left_and_up();
    longPressKey = KEY_CODE_JIN;
  }
  //长按▶▶|键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_JIN)
  {
    left_and_up();
  }//按下▶||键的事件
  if (results.value == KEY_CODE_XIA ) 
  {
    left_and_down();
    longPressKey = KEY_CODE_XIA;
  }
  //长按▶||键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_XIA)
  {
    left_and_down();
  }//按下"-"键的事件
  if (results.value == KEY_CODE_L ) 
  {
    right_and_up();
    longPressKey = KEY_CODE_L;
  }
  //长按"-"键的事件
  if ( results.value == KEY_CODE_LONG_PRESS && longPressKey == KEY_CODE_L)
  {
    right_and_up();
  }//按下"+"键的事件
  if (results.value == KEY_CODE_H ) 
  {
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
  }
}
