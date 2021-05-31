#include <SoftwareSerial.h>
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
String c = "";
String d = "";
String BILDIRIMgonderen = "";
String BILDIRIMicerik = "";
SoftwareSerial bluetooth(10,11); 
void draw(void) {
  u8g.setFont(u8g_font_9x15B);
  u8g.setPrintPos(0,10);
  u8g.print(BILDIRIMgonderen);
  u8g.setPrintPos(0,50);
  u8g.print(BILDIRIMicerik);
  
}
void setup() {
     Serial.begin(9600);
    bluetooth.begin(9600);

}

void loop() {

while (bluetooth.available()) 
{  
  c = c + (char)bluetooth.read();
}

String BILDIRIMuid = c.substring(12,16);
char charBuf[5];
BILDIRIMuid.toCharArray(charBuf, 5) ;
int len = strlen(charBuf);
 if (len == 4){
ble("160", BILDIRIMuid);
 BILDIRIMgonderen  = d.substring(33,45) + d.substring(55,63) ;     
Serial.println(BILDIRIMgonderen);
d = "";
c = "";
ble("355", BILDIRIMuid);
 BILDIRIMicerik = d.substring(33,45) + d.substring(55,75) + d.substring(85,105) + d.substring(115,135) ;  
Serial.println(BILDIRIMicerik);
d = "";
c = "";
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
}
  }

void ble(String i, String BILDIRIMuid) {

 char charBuf[5];
BILDIRIMuid.toCharArray(charBuf, 5) ;

char e[4];
i.toCharArray(e, 4) ;

bluetooth.write("AT+ANCS");
bluetooth.write(charBuf);
bluetooth.write(e);

  delay(90);
while (bluetooth.available()) //HM-10dan aldığı her harfi çevirir.
{  
  c = (char)bluetooth.read();
if (c=="A") {d = d + "A";}
else if (c=="B"){d = d + "B";}
else if (c=="C"){d = d + "C";}
else if (c=="D"){d = d + "D";}
else if (c=="E"){d = d + "E";}
else if (c=="F"){d = d + "F";}
else if (c=="G"){d = d + "G";}
else if (c=="H"){d = d + "H";}
else if (c=="I"){d = d + "I";}
else if (c=="J"){d = d + "J";}
else if (c=="K"){d = d + "K";}
else if (c=="L"){d = d + "L";}
else if (c=="M"){d = d + "M";}
else if (c=="N"){d = d + "N";}
else if (c=="O"){d = d + "O";}
else if (c=="P"){d = d + "P";}
else if (c=="R"){d = d + "R";}
else if (c=="S"){d = d + "S";}
else if (c=="T"){d = d + "T";}
else if (c=="U"){d = d + "U";}
else if (c=="V"){d = d + "V";}
else if (c=="Y"){d = d + "Y";}
else if (c=="Z"){d = d + "Z";}
else if (c=="W"){d = d + "W";}
else if (c=="X"){d = d + "X";}
else if (c=="Q"){d = d + "Q";}
else if (c=="+"){d = d + "+";}
else if (c=="-"){d = d + "-";}
else if (c==","){d = d + ",";}
else if (c=="."){d = d + ".";}
else if (c=="!"){d = d + "!";}
else if (c==":"){d = d + ":";}
else if (c=="["){d = d + "[";}
else if (c=="]"){d = d + "]";}
else if (c=="?"){d = d + "?";}
else if (c=="a"){d = d + "a";}
else if (c=="b"){d = d + "b";}
else if (c=="c"){d = d + "c";}
else if (c=="d"){d = d + "d";}
else if (c=="e"){d = d + "e";}
else if (c=="f"){d = d + "f";}
else if (c=="g"){d = d + "g";}
else if (c=="h"){d = d + "h";}
else if (c=="i"){d = d + "i";}
else if (c=="j"){d = d + "j";}
else if (c=="k"){d = d + "k";}
else if (c=="l"){d = d + "l";}
else if (c=="m"){d = d + "m";}
else if (c=="n"){d = d + "n";}
else if (c=="o"){d = d + "o";}
else if (c=="p"){d = d + "p";}
else if (c=="r"){d = d + "r";}
else if (c=="s"){d = d + "s";}
else if (c=="t"){d = d + "t";}
else if (c=="u"){d = d + "u";}
else if (c=="v"){d = d + "v";}
else if (c=="y"){d = d + "y";}
else if (c=="z"){d = d + "z";}
else if (c=="x"){d = d + "x";}
else if (c=="w"){d = d + "w";}
else if (c=="q"){d = d + "q";}
else if (c=="1"){d = d + "1";}
else if (c=="2"){d = d + "2";}
else if (c=="3"){d = d + "3";}
else if (c=="4"){d = d + "4";}
else if (c=="5"){d = d + "5";}
else if (c=="6"){d = d + "6";}
else if (c=="7"){d = d + "7";}
else if (c=="8"){d = d + "8";}
else if (c=="9"){d = d + "9";}
else if (c=="0"){d = d + "0";}
else if (c=="'"){d = d + "'";}
else if (c==" "){d = d + " ";}
else {d = d + " ";}
  }
  
  
}
