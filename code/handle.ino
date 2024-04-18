#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 25
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
WiFiServer server(80);
 
String header;
bool isRunning = false;
bool called = false; 
int setTemperature = 0;
long motorStepCounter = 0;
 
const int dirPin = 32;
const int stepPin = 33;
int flag = 0; 
int end = 1;
int temperature_check = 0;
int reset = 0;
 
 
void setup() {
  Serial.begin(115200);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  WiFi.softAP(ssid, password);
 
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
  sensors.begin();
  Serial.println("Setup complete.");
}
 
void loop() {
  WiFiClient client = server.available();
  sensors.requestTemperatures();
  float currentTemperature = sensors.getTempFByIndex(0);
 
  if (client){
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            sendWebPage(client, currentTemperature);
 
            if (header.indexOf("GET /stop") >= 0) {
              isRunning = false;
              reset = 1;
              //resetMotor();
            } else if (header.indexOf("GET /setTemperature?temperature=") >= 0) {
              int pos = header.indexOf("temperature=") + 12;
              int endPos = header.indexOf(' ', pos);
              setTemperature = header.substring(pos, endPos).toInt();
              isRunning = true;
            }
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    if( isRunning == true && called == false){
        Serial.println("Called");
        end = 0;
        temperature_check = setTemperature;
        }
    }
    sensors.requestTemperatures();
    float temperature  = sensors.getTempFByIndex(0);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" F");
    Serial.println(flag);
    if( end == 0 || end == 2 ){
        if (((temperature > temperature_check) && flag > 0) || reset == 1){
            //end = 2;
            stepCCW();
            delay(50);
            flag--;
            if(flag <= 0){
                end = 1; 
                called = false; 
                isRunning = false; 
                reset = 0;
            }
        } else {
            stepCW();
            delay(50);
            flag++;
            }
    }
}


void resetMotor() {
  while (motorStepCounter > 0) {
    stepCCW();
    motorStepCounter--;
    delay(50);
  }
  while (motorStepCounter < 0) {
    stepCW();
    motorStepCounter++;
    delay(50);
  }
}
 
void stepCW() {
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(10);
}
 
void stepCCW() {
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(10);
}
 
void sendWebPage(WiFiClient& client, float currentTemperature) {
  client.println("<!DOCTYPE html><html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
  client.println("</style></head>");
  client.println("<body><h1>ESP32 Temperature Control Server</h1>");
  client.println("<form action=\"/setTemperature\" method=\"GET\">");
  client.println("<input type=\"number\" name=\"temperature\" placeholder=\"Enter Temperature\">&deg;F<br>");
  client.println("<input type=\"submit\" value=\"Start\" class=\"button\">");
  client.println("</form>");
  client.println("<p><a href=\"/stop\"><button class=\"button\">Stop</button></a></p>");
  client.println("<p>Current Temperature: " + String(currentTemperature) + " &deg;F</p>");
  client.println("</body></html>");
}
