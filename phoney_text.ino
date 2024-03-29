#include <LiquidCrystal.h>
#include <GSM.h>

#define PINNUMBER ""

char remoteNum[20];
GSM gsmAccess;
GSM_SMS sms;
GSMVoiceCall vcs;

String remoteNumber = "";  // the number you will call
char charbuffer[20];
char numtel[20];

char txtMsg[20];

int pin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 44, 45, 46, 47, 50, 51, 52, 53};
int val[47];
int cryp;
int casey;
int i = 0;
int x = 0;
int y = 0;

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void cursors()
{
  lcd.noBlink();
  delay(1000);
  lcd.blink();
  delay(2000);
}

void homescreen()
{
  lcd.setCursor(0, 1);
  lcd.print("CALL");
  lcd.setCursor(12, 1);
  lcd.print("TEXT");
}
void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("SMS Messages Sender");
  boolean notConnected = true;

  while (notConnected)
  {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY)
    {
      notConnected = false;
    }
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }


  Serial.println("GSM initialized");
  lcd.begin(16, 2);
  for (int i = 0 ; i <= 47; i++)
  {
    pinMode(pin[i], INPUT);
  }
}
void reading()
{
  for (int i = 0 ; i <= 47; i++)
  {
    val[i] = digitalRead(pin[i]);
    delay(20);
    if (val[i] == HIGH)
    {
      cryp = i + 100;
    }
  }
}

void cursor_control()
{
  switch (cryp)
  {
    case 142:
      {
        delay(100);
        if (x <= 0)
        {
          x = 0;
        }
        else
        {
          x = x - 1;
        }
      }
    case 143:
      {
        delay(100);
        if (x >= 15)
        {
          x = 0;
        }
        else
        {
          x = x + 1;
        }
      }
    case 144:
      {
        if (y <= 0)
        {
          y = 0;
        }
        else
        {
          y = y - 1;
        }
      }
    case 145:
      {
        if (y >= 1)
        {
          y = 0;
        }
        else
        {
          y = y + 1;
        }
      }
  }
}
void typing()
{
  if (x >= 15)
  {
    x = 0;
  }
  lcd.setCursor(x, y);
  switch (cryp)
  {
    case 100:
      {
        lcd.print("a");
        x = x + 1;
        txtMsg[i] = "a";
        i = +1;
      }
    case 101:
      {
        lcd.print("b");
        x = x + 1;
        txtMsg[i] = "b";
        i = +1;
      }
    case 102:
      {
        lcd.print("c");
        x = x + 1;
        txtMsg[i] = "c";
        i = +1;
      }
    case 103:
      {
        lcd.print("d");
        x = x + 1;
        txtMsg[i] = "d";
        i = +1;
      }
    case 104:
      {
        lcd.print("e");
        x = x + 1;
        txtMsg[i] = "e";
        i = +1;
      }
    case 105:
      {
        lcd.print("f");
        x = x + 1;
        txtMsg[i] = "f";
        i = +1;
      }
    case 106:
      {
        lcd.print("g");
        x = x + 1;
        txtMsg[i] = "g";
        i = +1;
      }
    case 107:
      {
        lcd.print("h");
        x = x + 1;
        txtMsg[i] = "h";
        i = +1;
      }
    case 108:
      {
        lcd.print("i");
        x = x + 1;
        txtMsg[i] = "i";
        i = +1;
      }
    case 109:
      {
        lcd.print("j");
        x = x + 1;
        txtMsg[i] = "j";
        i = +1;
      }
    case 110:
      {
        lcd.print("k");
        x = x + 1;
        txtMsg[i] = "k";
        i = +1;
      }
    case 111:
      {
        lcd.print("l");
        x = x + 1;
        txtMsg[i] = "l";
        i = +1;
      }
    case 112:
      {
        lcd.print("m");
        x = x + 1;
        txtMsg[i] = "m";
        i = +1;
      }
    case 113:
      {
        lcd.print("n");
        x = x + 1;
        txtMsg[i] = "n";
        i = +1;
      }
    case 114:
      {
        lcd.print("o");
        x = x + 1;
        txtMsg[i] = "o";
        i = +1;
      }
    case 115:
      {
        lcd.print("p");
        x = x + 1;
        txtMsg[i] = "p";
        i = +1;
      }
    case 116:
      {
        lcd.print("q");
        x = x + 1;
        txtMsg[i] = "q";
        i = +1;
      }
    case 117:
      {
        lcd.print("r");
        x = x + 1;
        txtMsg[i] = "r";
        i = +1;
      }
    case 118:
      {
        lcd.print("s");
        x = x + 1;
        txtMsg[i] = "s";
        i = +1;
      }
    case 119:
      {
        lcd.print("t");
        x = x + 1;
        txtMsg[i] = "t";
        i = +1;
      }
    case 120:
      {
        lcd.print("u");
        x = x + 1;
        txtMsg[i] = "u";
        i = +1;
      }
    case 121:
      {
        lcd.print("v");
        x = x + 1;
        txtMsg[i] = "v";
        i = +1;
      }
    case 122:
      {
        lcd.print("w");
        x = x + 1;
        txtMsg[i] = "w";
        i = +1;
      }
    case 123:
      {
        lcd.print("x");
        x = x + 1;
        txtMsg[i] = "x";
        i = +1;
      }
    case 124:
      {
        lcd.print("y");
        x = x + 1;
        txtMsg[i] = "y";
        i = +1;
      }
    case 125:
      {
        lcd.print("z");
        x = x + 1;
        txtMsg[i] = "z";
        i = +1;
      }
    case 126:
      {
        lcd.print("1");
        x = x + 1;
        txtMsg[i] = "1";
        i = +1;
      }
    case 127:
      {
        lcd.print("2");
        x = x + 1;
        txtMsg[i] = "2";
        i = +1;
      }
    case 128:
      {
        lcd.print("3");
        x = x + 1;
        txtMsg[i] = "3";
        i = +1;
      }
    case 129:
      {
        lcd.print("4");
        x = x + 1;
        txtMsg[i] = "4";
        i = +1;
      }
    case 130:
      {
        lcd.print("5");
        x = x + 1;
        txtMsg[i] = "5";
        i = +1;
      }
    case 131:
      {
        lcd.print("6");
        x = x + 1;
        txtMsg[i] = "6";
        i = +1;
      }
    case 132:
      {
        lcd.print("7");
        x = x + 1;
        txtMsg[i] = "7";
        i = +1;
      }
    case 133:
      {
        lcd.print("8");
        x = x + 1;
        txtMsg[i] = "8";
        i = +1;
      }
    case 134:
      {
        lcd.print("9");
        x = x + 1;
        txtMsg[i] = "9";
        i = +1;
      }
    case 135:
      {
        lcd.print("0");
        x = x + 1;
        txtMsg[i] = "0";
        i = +1;
      }
    case 136:
      {
        lcd.print(" ");
        x = x + 1;
        txtMsg[i] = " ";
        i = +1;
      }
    case 137:
      {
        lcd.print("&");
        x = x + 1;
        txtMsg[i] = "&";
        i = +1;
      }
    case 138:
      {
        lcd.print(".");
        x = x + 1;
        txtMsg[i] = ".";
        i = +1;
      }
    case 139:
      {
        lcd.print(",");
        x = x + 1;
        txtMsg[i] = ",";
        i = +1;
      }
    case 140:
      {
        lcd.print("?");
        x = x + 1;
        txtMsg[i] = "?";
        i = +1;
      }
    case 141:
      {
        lcd.print("!");
        x = x + 1;
        txtMsg[i] = "!";
        i = +1;
      }
    case 142:
      {
        i = +1;
        if (x <= 0)
        {
          x = 0;
        }
        else
        {
          x = x - 1;
        }
      }
    case 143:
      {
        i = -i;
        if (x >= 15)
        {
          x = 0;
        }
        else
        {
          x = x + 1;
        }
      }

    case 146:
      {
        casey = 1;
      }
    case 147:
      {
        casey = 2;
      }
    default:
      {
        cryp = 0;
      }
  }
}

void dial()
{
  int q = 0;
  switch (cryp)
  {
    case 126:
      {
        lcd.print("1");
        x = x + 1;
        remoteNum[q] = "1";
        q + 1;

      }
    case 127:
      {
        lcd.print("2");
        x = x + 1;
        remoteNum[q] = "2";
        q + 1;
      }
    case 128:
      {
        lcd.print("3");
        x = x + 1;
        remoteNum[q] = "3";
        q + 1;
      }
    case 129:
      {
        lcd.print("4");
        x = x + 1;
        remoteNum[q] = "4";
        q + 1;
      }
    case 130:
      {
        lcd.print("5");
        x = x + 1;
        remoteNum[q] = "5";
        q + 1;
      }
    case 131:
      {
        lcd.print("6");
        x = x + 1;
        remoteNum[q] = "6";
        q + 1;
      }
    case 132:
      {
        lcd.print("7");
        x = x + 1;
        remoteNum[q] = "7";
        q + 1;
      }
    case 133:
      {
        lcd.print("8");
        x = x + 1;
        remoteNum[q] = "8";
        q + 1;
      }
    case 134:
      {
        lcd.print("9");
        x = x + 1;
        remoteNum[q] = "9";
        q + 1;
      }
    case 135:
      {
        lcd.print("0");
        x = x + 1;
        remoteNum[q] = "0";
        q + 1;
      }
    default:
      cryp = 0;
  }
}
void loop()
{
  homescreen();
  switch (vcs.getvoiceCallStatus())
  {
    case IDLE_CALL: // Nothing is happening
      break;
    case RECEIVINGCALL: // Yes! Someone is calling us
      vcs.retrieveCallingNumber(numtel, 20);
      lcd.print("Number:");
      Serial.println(numtel);
      if (casey == 1)
      {
        vcs.answerCall();
      }
      else if (casey == 2)
      {
        vcs.hangCall();
      }
      break;

    case TALKING:  // In this case the call would be established
      if (casey == 2)
      {
        vcs.hangCall();
      }
      break;
  }
  reading();
  if (casey == 1)
  {
    casey = 0;
    typing();
    lcd.setCursor(0, 0);
    lcd.print("Enter a mobile number: ");
    delay(2000);
    lcd.clear();

    lcd.println(remoteNum);

    lcd.setCursor(0, 1);
    lcd.print("SEND");
    lcd.setCursor(12, 1);
    lcd.print("BACK");
    lcd.setCursor(0, 0);
    lcd.print(txtMsg);
    if (casey == 1)
    {
      sms.beginSMS(remoteNum);
      sms.print(txtMsg);
      sms.endSMS();
    }
    else if (casey == 2)
    {
      homescreen();
    }
  }
  else if (casey == 2)
  {
    casey = 0;
    dial();

    while (Serial.available() > 0)
    {
      char inChar = Serial.read();
      if (inChar == '\n')
      {
        if (remoteNumber.length() < 20)
        {
          remoteNumber.toCharArray(charbuffer, 20);
          if (vcs.voiceCall(charbuffer))
          {
            lcd.println("Call Established");
            while (Serial.read() != '\n' && (vcs.getvoiceCallStatus() == TALKING));
            vcs.hangCall();
          }
          remoteNumber = "";
        }
        else
        {
          remoteNumber = "";
        }
      }
      else
      {
        if (inChar != '\r')
        {
          remoteNumber += inChar;
        }
      }
    }
    if (casey == 1)
    {
      lcd.setCursor(0, 1);
      lcd.print("CALL");
      lcd.setCursor(12, 1);
      lcd.print("BACK");

    }
    else if (casey == 2)
    {
      homescreen();
    }
  }
}
