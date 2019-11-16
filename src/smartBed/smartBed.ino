#include <ESP8266WiFi.h>        
#include <ESP8266WiFiMulti.h>  
#include <ESP8266mDNS.h>  
#include <ESP8266WebServer.h>
#include <RtcDS3231.h> 
#include <Wire.h> 

#include "./webPages/pages.cpp"

const uint8_t LED_HIGH = 0;
const uint8_t LED_LOW = 1;

const String LED_HTTP_ARG = "ledStatus";
const String HOSTNAME = "smartbed";
String wifiSSID = "";
String wifiPSWD = "";

int LED_STATUS = LED_LOW;

ESP8266WiFiMulti wifiMulti;   
ESP8266WebServer server(80);

RtcDS3231<TwoWire> rtc(Wire);

void setup() {
  Serial.begin(115200);
  rtc.Begin();
  WiFi.mode(WIFI_STA);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_LOW);
  delay(10);
  Serial.println('\n');

  wifiMulti.addAP("FabLabDELT2G4", "FabL@b1200*");   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("labSCI", "LabSCI*8");   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("Beckers", "theovoador");   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("NET 2.4G", "oliveiracapanema356");   // add Wi-Fi networks you want to connect to

  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());      
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());  
  String macAdress = WiFi.macAddress();
  macAdress.replace(":","");
  if (!MDNS.begin(HOSTNAME)) {     
    Serial.println("Error setting up mDNS responder!");
  }
  else {
    digitalWrite(LED_BUILTIN, LED_HIGH);
    Serial.println("mDNS responder started");
    Serial.println("Use domain name " + HOSTNAME + ".local to access this device");
  }
  server.on("/", handleRoot);  
  server.on("/status", handleGetStatusPage);
  server.on("/index", handleIndexPage); 
  server.on("/connect", handleConnect); 
  
  server.begin();           
  Serial.print("HTTP server started.");
}

void loop() {
  server.handleClient();
  MDNS.update();
}

void handleRoot() {
  String argumentValue = "\n";
  for(int ii=0; ii<server.args(); ii++)
  {
    if(server.argName(ii)==LED_HTTP_ARG)
    {
      argumentValue = server.arg(ii);
    }
  }
  if(argumentValue!="\n")
  {
    LED_STATUS=argumentValue.toInt();
  }
  server.send(200, "text/plain", "Hello resolved by mDNS! MAC: "+WiFi.macAddress());
}

void handleGetStatusPage()
{
    server.send(200, "text/plain", "The status of the device is { ledStatus:\""
      +String(LED_STATUS)+"\"}");
}

void handleIndexPage()
{
    server.send(200, "text/html", String(indexPage));
}

void handleConnect()
{
    server.send(200, "text/html", String(connectPage));
}