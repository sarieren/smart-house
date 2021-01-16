#include <SoftwareSerial.h> //ספריות בהן השתמשנו
#include <TimeLib.h>
#include <Wire.h>
#include <DS3232RTC.h>
SoftwareSerial BT(A0, A1); // RX, TX // הגדרת רגלי הבלוטוס שיהיו מחוברים למוצאים
bool onDoor = false; // הגדרת משתנים ואיפוסם
boolean onMicrophone = false;
volatile boolean onLed = false;
unsigned long tmpLed;
int gonh = 0, gonm = 0, goffh = 0, goffm = 0; //green
int ronh = 0, ronm = 0, roffh = 0, roffm = 0; //red
int bonh = 0, bonm = 0, boffh = 0, boffm = 0; //blue
int lonh = 0, lonm = 0, loffh = 0, loffm = 0; //lamp
#define do 262 // המשך הגדרת משתנים בשביל השירים
#define re 294
#define mi 330
#define fa 349
#define sol 392
#define la 440
#define si 494
#define do1 523
#define re1 587
#define mi1 659
#define fa1 698
#define sol1 784
#define la1 880
#define si1 988
#define sold 415
#define sib 466

long time = 600;
void pause() { // פונקציה לכיבוי הרמקול
noTone(8);
delay(time / 4);
}
void intro() { // פונקציה לשיר cry no more
tone(8, re1);
delay(time / 2);
tone(8, mi1);
delay(time / 2);
tone(8, mi1);
delay (time / 2);
tone(8, fa1);
delay( time / 2);
tone(8, si);
delay( time * 2);
}
void partA1() { // פונקציה לשיר cry no more
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, fa);
delay(time);
tone(8, do1);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, do1);
delay(time);
tone(8, re1);
delay(time);
tone(8, si);
delay(time);
noTone(8);
delay(time * 2);
}
void partA(){ // פונקציה לשיר cry no more
partA1();
tone(8, do1);
delay(time / 2);
tone(8, fa);
delay(time / 2);
tone(8, fa);
delay(time * 2);
noTone(8);
partA1();
tone(8, re1);
delay(time / 2);
tone(8, mi1);
delay(time / 2);
tone(8, mi1);
delay(time * 2);
noTone(8);
delay(time * 2);
tone(8, mi1);
delay(time * 3);
tone(8, re1);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, si);
delay(time);
tone(8, la);
delay(time / 2);
tone(8, la);
delay(time * 2);
tone(8, mi1);
delay(time / 2);
tone(8, re1);
delay(time / 2);
tone(8, mi1);
delay(time / 2);
tone(8, re1);
delay(time / 2);
tone(8, mi1);
delay(time);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, do1);
delay(time * 2);
tone(8, re1);
delay(time / 2);
tone(8, do1);
delay(time / 2);
}
void partA2() { // פונקציה לשיר cry no more
tone(8, si);
delay(time);
tone(8, sol);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
}
void partB() { // פונקציה לשיר cry no more
tone(8, fa1);
delay(time * 2);
noTone(8);
delay(time / 2);
tone(8, fa1);
delay(time / 2);
tone(8, mi1);
delay(time / 2);
tone(8, re1);
delay(time / 2);
tone(8, mi1);
delay(time / 2);
tone(8, re1);
delay(time / 4);
tone(8, do1);
delay(time / 4);
}
void cryNoMore() { // הפונקציה הראשית שקוראת לכל הפונקציות
intro();
intro();
intro();
tone(8, si);
delay(time * 4);
noTone(8);
delay(time * 8);
partA();
partA2();
tone(8, do1);
delay(time);
tone(8, fa);
delay(time / 2);
tone(8, fa);
delay(time * 4);
partA();
partA2();
tone(8, fa1);
delay(time);
tone(8, fa1);
delay(time / 2);
tone(8, fa1);
delay(time * 4);
/////part B
tone(8, re1);
delay(time * 3);
tone(8, re1);
delay(time / 2);
tone(8, fa1);
delay(time / 2);
partB();
tone(8, do1);
delay(time * 2);
tone(8, re1);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time * 4);
tone(8, re1);
delay(time * 3);
tone(8, sol1);
delay(time);
partB();
tone(8, do1);
delay(time * 3);
noTone(8);
delay(time * 2.5);
tone(8, mi1);
delay(time / 2);
tone(8, mi1);
delay(time / 2);
tone(8, re1);
delay(time / 2);
tone(8, mi1);
delay(time);
tone(8, mi1);
delay(time);
tone(8, mi1);
delay(time);
tone(8, re1);
delay(time / 2);
tone(8, re1);
delay(time / 2);
tone(8, re1);
delay(time * 2);
noTone(8);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, re1);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, do1);
delay(time);
tone(8, do1);
delay(time);
tone(8, do1);
delay(time / 2);
tone(8, re1);
delay(time);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time * 2);
noTone(8);
delay(time / 2);
tone(8, sol);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, si);
delay(time * 2);
noTone(8);
delay(time);
tone(8, si);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, do1);
delay(time * 2);
noTone(8);
delay(time / 2);
tone(8, do1);
delay(time / 2);
tone(8, si);
delay(time / 2);
tone(8, la);
delay(time / 4);
tone(8, si);
delay(time / 4);
tone(8, si);
delay(time / 4);
tone(8, la);
delay(time / 4);
tone(8, sol);
delay(time / 2);
tone(8, sol);
delay(time * 3);
tone(8, sol);
delay(time * 4);
}
void partC1() { // הפונקציה לשיר "שלום עליכם"
tone(8, mi);
delay(time * 2);
tone(8, do1);
delay(time);
tone(8, si);
delay(time);
tone(8, la);
delay(time * 2);
tone(8, la);
delay(time * 2);
tone(8, sold);
delay(time);
tone(8, la);
delay(time);
tone(8, si);
delay(time);
tone(8, la);
delay(time);
tone(8, sold);
delay(time);
tone(8, fa);
delay(time);
}
void partC2() { // הפונקציה לשיר "שלום עליכם"
tone(8, do1);
delay(time * 2);
tone(8, mi1);
delay(time);
tone(8, mi1);
delay(time);
tone(8, mi1);
delay(time * 2);
tone(8, mi1);
delay(time * 2);
tone(8, re1);
delay(time);
tone(8, do1);
delay(time);
tone(8, si);
delay(time);
tone(8, do1);
delay(time);
tone(8, re1);
delay(time);
tone(8, mi1);
delay(time);
tone(8, re1);
delay(time * 2);
tone(8, do1);
delay(time);
tone(8, si);
delay(time);
tone(8, la);
delay(time);
tone(8, si);
delay(time);
tone(8, do1);
delay(time * 2);
tone(8, mi1);
delay(time * 2);
tone(8, si);
delay(time * 4);
tone(8, si);
delay(time * 4);
tone(8, si);
delay(time);
tone(8, do1);
delay(time);
tone(8, re1);
delay(time * 2);
tone(8, re1);
delay(time * 2);
tone(8, re1);
delay(time * 2);
tone(8, re1);
delay(time);
tone(8, fa1);
delay(time);
tone(8, mi1);
delay(time);
tone(8, re1);
delay(time);
tone(8, do1);
delay(time);
tone(8, si);
delay(time);
tone(8, la);
delay(time);
tone(8, mi);
delay(time);
tone(8, do1);
delay(time * 2);
tone(8, si);
delay(time);
tone(8, la);
delay(time);
tone(8, si);
delay(time * 2);
tone(8, la);
delay(time);
tone(8, sold);
delay(time);}
void shalomAleichem() { // הפונקציה שמפעילה את הפונקציות המשניות
partC1();
tone(8, mi);
delay(time * 2);
tone(8, sold);
delay(time * 2);
tone(8, sold);
delay(time * 2);
tone(8, la);
delay(time);
tone(8, sold);
delay(time);
tone(8, la);
delay(time);
tone(8, do1);
delay(time);
tone(8, si);
delay(time * 4);
tone(8, si);
tone(8, sold);
tone(8, mi);
delay(time * 4);
partC1();
tone(8, mi);
delay(time);
tone(8, mi);
delay(time);
tone(8, re);
delay(time * 2);
tone(8, la);
delay(time * 2);
tone(8, sold);
delay(time * 2);
tone(8, fa);
delay(time / 2);
tone(8, mi);
delay(time / 2);
tone(8, fa);
delay(time);
tone(8, mi);
delay(time * 4);
tone(8, mi);
delay(time * 2);
noTone(8);
delay(time);
tone(8, do1);
delay(time);
partC2();
tone(8, la);
delay(time * 4);
tone(8, si);
delay(time * 4);
partC2();
tone(8, la);
delay(time * 4);
tone(8, la);
delay(time * 4);
}
void partD1() { // הפונקציה לשיר "אשת חיל"
tone(8, do1);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, la);
delay(time);
pause();
tone(8, re1);
delay(time / 2);
pause();
tone(8, do1);
delay(time / 2);
pause();
tone(8, do1);
delay(time * 3);
pause();
}
void partD2() { // הפונקציה לשיר "אשת חיל"
tone(8, la);
delay(time / 2);
pause();
tone(8, la);
delay(time / 2);
pause();
noTone(8);
delay(time / 2);
tone(8, la);
delay(time / 2);
pause();
tone(8, la);
delay(time * 2);
pause();
tone(8, sol);
delay(time / 2);
pause();
tone(8, fa);
delay(time / 2);
pause();
noTone(8);
delay(time / 2);
tone(8, mi);
delay(time / 2);
pause();
tone(8, mi);
delay(time * 2);
pause();
}
void eshetChail() { // הפונקציה שמפעילה את הפונקציות המשניות
partD1();
tone(8, do1);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, sib);
delay(time / 2);
pause();
tone(8, la);
delay(time / 2);
pause();
tone(8, sol);
delay(time * 2);
pause();
tone(8, la);
delay(time);
pause();
tone(8, sib);
delay(time);
pause();
partD1();
tone(8, sib);
delay(time);
pause();
tone(8, sib);
delay(time);
pause();
tone(8, la);
delay(time);
pause();
tone(8, sol);
delay(time);
pause();
tone(8, fa);
delay(time * 4);
pause();
partD2();
tone(8, do);
delay(time / 2);
pause();
tone(8, sib);
delay(time / 2);
pause();
noTone(8);
delay(time / 2);
tone(8, sib);
delay(time / 2);
pause();
tone(8, sib);
delay(time * 2);
pause();
tone(8, la);
delay(time / 2);
pause();
tone(8, sol);
delay(time / 2);
pause();
noTone(8);
delay(time / 2);
tone(8, la);
delay(time / 2);
pause();
tone(8, la);
delay(time * 2);
pause();
partD2();
tone(8, do);
delay(time);
pause();
tone(8, sib);
delay(time);
pause();
tone(8, la);
delay(time);
pause();
tone(8, sol);
delay(time);
pause();
tone(8, fa);
delay(time * 4);
pause();
}
void partE1() { //הפונקציה לשיר "המלאך הגואל"
tone(8, la);
delay(time);
pause();
tone(8, la);
delay(time);
pause();
noTone(8);
delay(time / 2);
tone(8, la);
delay(time / 2);
pause();
tone(8, la);
delay(time);
pause();
tone(8, sol);
delay(time);
pause();
tone(8, fa);
delay(time);
pause();
tone(8, sol);
delay(time * 3);
pause();
tone(8, sol);
delay(time * 2);
pause();
noTone(8);
delay(time / 2);
tone(8, sol);
delay(time / 2);
pause();
tone(8, la);
delay(time);
pause();
tone(8, la);
delay(time);
pause();
noTone(8);
delay(time / 2);
tone(8, la);
delay(time / 2);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, sib);
delay(time * 1.5);
pause();
tone(8, la);
delay(time / 2);
pause();
tone(8, sol);
delay(time);
pause();
tone(8, la);
delay(time);
pause();
tone(8, sib);
delay(time);
pause();
tone(8, la);
delay(time * 3);
pause();
tone(8, re1);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, sib);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, fa1);
delay(time);
pause();
tone(8, mi1);
delay(time);
pause();
tone(8, re1);
delay(time * 3);
pause();
tone(8, do1);
delay(time * 2);
pause();
noTone(8);
delay(time / 2);
tone(8, do1);
delay(time / 2);
pause();
tone(8, do1);
delay(time);
pause();
tone(8, re1);
delay(time);
pause();
tone(8, do1);
delay(time);
pause();
}
void hamalach() { // הפונקציה שמפעילה את הפונקציה המשנית
tone(8, do);
delay(time / 2);
pause();
partE1();
tone(8, sib);
delay(time);
pause();
tone(8, la);
delay(time * 1.5);
pause();
tone(8, sib);
delay(time / 2);
pause();
tone(8, sol);
delay(time * 3);
pause();
tone(8, sol);
delay(time * 2);
pause();
noTone(8);
delay(time / 2);
tone(8, do);
delay(time / 2);
pause();
partE1();
tone(8, sib);
delay(time);
pause();
tone(8, la);
delay(time * 1.5);
pause();
tone(8, sol);
delay(time / 2);
pause();
tone(8, fa);
delay(time * 3);
pause();
tone(8, fa);
delay(time * 2);
pause();
}
void turnOnLed(){ //פונקציית הדלקת אפקט הלדים
tone(8, 200);// משמיע צליל שהאפקט נדלק
delay(500);
noTone(8);
analogWrite(6, 150); // מדליק את הלד האדום בעוצמה 150
analogWrite(5, 150); // מדליק את הלד הכחול בעוצמה 150
delay(1000);
analogWrite(5, 200);
analogWrite(6, 100);
delay(1000);
analogWrite(5, 250);
analogWrite(6, 50);
delay(1000);
analogWrite(6, 0);
analogWrite(9, 50); // מדליק את הלד הירוק בעוצמה 50
delay(1000);
analogWrite(9, 100);
delay(1000);
analogWrite(9, 150);
delay(1000);
analogWrite(9, 200);
analogWrite(5, 200);
delay(1000);
analogWrite(9, 250);
analogWrite(5, 150);
delay(1000);
analogWrite(5, 100);
delay(1000);
analogWrite(5, 50);
delay(1000);
analogWrite(5, 0);
analogWrite(6, 50);
delay(1000);
analogWrite(6, 100);
delay(1000);
analogWrite(6, 150);
delay(1000);
analogWrite(9, 200);
analogWrite(6, 200);
delay(1000);
analogWrite(9, 150);
analogWrite(6, 250);
delay(1000);
analogWrite(9, 100);
delay(1000);
analogWrite(9, 50);
delay(1000);
analogWrite(9, 0);
mDelay(1000);
analogWrite(5, 50);
analogWrite(6, 200);
delay(1000);
analogWrite(5, 100);
analogWrite(6, 150);
delay(1000);
turnOffLed();// קורא לפונקציה שמכבה את הלדים
}

void blueLed(){ // פונקציית הדלקת לדים כחולים
analogWrite(5, 200);
tone(8, 200);
delay(500);
noTone(8);
}

void greenLed(){ // פונקציית הדלקת לדים ירוקים
analogWrite(6, 200);
tone(8, 200);
delay(500);
noTone(8);
}

void redLed(){ // פונקציית הדלקת לדים אדומים
analogWrite(9, 200);
tone(8, 200);
delay(500);
noTone(8);
}

void turnOffLed(){ // פונקציית כיבוי לדים
analogWrite(9, 0);
analogWrite(6, 0);
analogWrite(5, 0);
tone(8, 200);
delay(500);
noTone(8);
}

unsigned long tmpDoor = 0;// הגדרת משתנה ואיפוסו לפונקציה של הדלת
void Door(){ // פונקציה לפתיחת הדלת למשך 10 שניות
if (millis() - tmpDoor < 10000) {
digitalWrite(11, HIGH);
}
else{
digitalWrite(11, LOW);
}
}

void OpenDoor(){ // פונקציה שמאתחלת את המשתנה הגלובלי כדי שהדלת תיפתח
tmpDoor = millis();
}

void motorStop(){// פונקציית עצירת המעלית
digitalWrite(12, 0);
digitalWrite(13, 0);
}

void motorUp(){ // פונקציית עליית המעלית
digitalWrite(12, 0);
digitalWrite(13, 1);
}

void motorDown(){ // פונקציית ירידת המעלית
digitalWrite(12, 1);
digitalWrite(13, 0);
}

void greenOnHour(){ // פונקציית להדלקת הלד הירוק לפי השעה שקבע המשתמש
if (gonh == hour() && gonm == minute())
digitalWrite(6, 1);
}

void greenOffHour(){ // פונקציית לכיבוי הלד הירוק לפי השעה שקבע המשתמש
if (goffh == hour() && goffm == minute())
digitalWrite(6, 0);
}

void redOnHour(){ // פונקציית להדלקת הלד האדום לפי השעה שקבע המשתמש
if (ronh == hour() && ronm == minute())
digitalWrite(9, 1);
}

void redOffHour(){// פונקציית לכיבוי הלד האדום לפי השעה שקבע המשתמש
if (roffh == hour() && roffm == minute())
digitalWrite(9, 0);
}

void blueOnHour(){// פונקציית להדלקת הלד הכחול לפי השעה שקבע המשתמש
if (bonh == hour() && bonm == minute())
digitalWrite(5, 1);
}

void blueOffHour(){// פונקציית לכיבוי הלד הכחול לפי השעה שקבע המשתמש
if (boffh == hour() && boffm == minute())
digitalWrite(5, 0);
}

void lampOnHour()/{/ // פונקציית להדלקת האור לפי השעה שקבע המשתמש
if (lonh == hour() && lonm == minute())
digitalWrite(7, 0);
}

void lampOffHour(){// פונקציית לכיבוי האור לפי השעה שקבע המשתמש
if (loffh == hour() && loffm == minute())
digitalWrite(7, 1);
}

int sound;
void setup() { // הגדרת ההדקים כמוצאים
pinMode (8, OUTPUT);//microphone
pinMode(5, OUTPUT); //blue led
pinMode(6, OUTPUT); //green led
pinMode(9, OUTPUT);// red led
pinMode(11, OUTPUT);// door
pinMode(12, OUTPUT);// elevator
pinMode(13, OUTPUT);// elevator
pinMode(4, OUTPUT);//socket
digitalWrite(4, HIGH);// socket
pinMode(7, OUTPUT);//lamp
digitalWrite(7, HIGH);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);
setSyncProvider(RTC.get);
BT.begin(9600); // 9600 bps תקשורת ערוץ פתח
}

void loop() {// התחלת התוכנית הראשית
int sensorUp;
int sensorDown;
int choice;
Door();// הפעלת הפונקציות שצריכות כל הזמן לפעול ברקע
greenOnHour();
greenOffHour();
redOffHour();
redOnHour();
blueOffHour();
blueOnHour();
lampOffHour();
lampOnHour();
if (BT.available() > 0)// הפקודה מחכה לבדוק מתי נכנס ערך מהבלוטוס
{
choice = BT.read();
switch (choice)// הפעלת הפונקציה הרצויה עם הערכים הרצויים לפי בקשת המשתמש
{
case '1':
greenLed();
break;
case '2':
redLed();
break;
case '3':
blueLed();
break;
case '4':
turnOnLed();
break;
case '5':
turnOffLed();
break;
case '6':
cryNoMore();
break;
case '7':
shalomAleichem();
break;
case '8':
eshetChail();
break;
case '9':
hamalach();
break;
case 'a':
sensorUp = analogRead(A2);// הפקודה קוראת את המרחק בין המעלית לחיישן
while (sensorUp < 250)
{
motorUp();
sensorUp = analogRead(A2);
}
motorStop();
break;
case 'b':
sensorDown = analogRead(A3);
while (sensorDown < 150)
{
motorDown();
sensorDown = analogRead(A3);
}
motorStop();
break;
case 'c':
digitalWrite(7, 1);// הדלקת האור
break;
case 'd':
digitalWrite(7, 0);
break;
case 'e':
ronh = BT.parseInt();// הפקודה קוראת מהשעון זמן אמת את השעה הרצויה
ronm = BT.parseInt();// הפקודה קוראת מהשעון זמן אמת את הדקה הרצויה
Serial.println(ronh);
Serial.println(ronm);
break;
case 'f'://red led off
roffh = BT.parseInt();
roffm = BT.parseInt();
break;
case 'g'://green led on
gonh = BT.parseInt();
gonm = BT.parseInt();
break;
case 'h'://green led off
goffh = BT.parseInt();
goffm = BT.parseInt();
break;
case 'i'://blue led on
bonh = BT.parseInt();
bonm = BT.parseInt();
break;
case 'j'://blue led off
boffh = BT.parseInt();
boffm = BT.parseInt();
break;
case 'k'://lamp on
lonh = BT.parseInt();
lonm = BT.parseInt();
break;
case 'l'://lamp off
loffh = BT.parseInt();
loffm = BT.parseInt();
break;
case 'm':
tone(8, 600);
delay(500);
noTone(8);
OpenDoor();
break;
case 'n':
digitalWrite(4, 1);
break;
case 'o':
digitalWrite(4, 0);
break;
}
}
}