#include <Wire.h>
#include <TinyGPSPlus.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WebServer.h>

TinyGPSPlus gps;
LiquidCrystal_I2C lcd(0x27,16,2);
WebServer server(80);

const char* ssid = "RowingMonitor";
const char* password = "12345678";

float gpsSpeed = 0;
float filteredSpeed = 0;
float splitSeconds = 0;

int strokeRate = 0;
unsigned long lastStroke = 0;


float readIMU()
{

  return random(-20,20)/10.0;
}


void readGPS()
{
  while (Serial1.available())
  {
    gps.encode(Serial1.read());
  }

  if (gps.speed.isUpdated())
  {
    gpsSpeed = gps.speed.mps();

    filteredSpeed = 0.85 * filteredSpeed + 0.15 * gpsSpeed;

    if(filteredSpeed > 0.2)
      splitSeconds = 500.0 / filteredSpeed;
  }
}


void detectStroke()
{
  float accel = readIMU();

  if(accel > 1.5)
  {
    if(millis() - lastStroke > 300)
    {
      unsigned long now = millis();

      strokeRate = 60000 / (now - lastStroke);

      lastStroke = now;
    }
  }
}

void updateLCD()
{
  int minutes = splitSeconds / 60;
  int seconds = (int)splitSeconds % 60;

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(minutes);
  lcd.print(":");

  if(seconds < 10) lcd.print("0");
  lcd.print(seconds);

  lcd.print(" /500 ");

  lcd.print(strokeRate);
  lcd.print("spm");

  lcd.setCursor(0,1);
  lcd.print(filteredSpeed,2);
  lcd.print(" m/s");
}


String webpage()
{
  int minutes = splitSeconds / 60;
  int seconds = (int)splitSeconds % 60;

  String page = "<html><body>";
  page += "<h1>Rowing Monitor</h1>";
  page += "Speed: " + String(filteredSpeed,2) + " m/s<br>";
  page += "Split: " + String(minutes) + ":" + (seconds<10?"0":"") + String(seconds) + "<br>";
  page += "Stroke Rate: " + String(strokeRate) + " spm<br>";
  page += "</body></html>";

  return page;
}

void handleRoot()
{
  server.send(200,"text/html",webpage());
}


void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600);

  Wire.begin(6,7);

  lcd.init();
  lcd.backlight();

  WiFi.softAP(ssid,password);

  server.on("/", handleRoot);
  server.begin();

  lcd.print("Row Monitor");
  delay(2000);
}


void loop()
{
  readGPS();

  detectStroke();

  updateLCD();

  server.handleClient();

  delay(200);
}