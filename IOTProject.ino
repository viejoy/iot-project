#include <ESP8266WiFi.h>
const int relay1Pin = 14;
const int relay2Pin = 12;
const int relay3Pin = 13;
const int relay4Pin = 2;

const char* ssid = "Boarding_House";
const char* password = "idunnoclue101";
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);

  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
  digitalWrite(relay3Pin, LOW);
  digitalWrite(relay4Pin, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

//
//   // config static IP
//  IPAddress ip(192, 168, 1, 24); // where xx is the desired IP Address
//  IPAddress gateway(192, 168, 1, 1); // set gateway to match your network
//  Serial.print(F("Setting static ip to : "));
//  Serial.println(ip);
//  IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your
////network
//  WiFi.config(ip, gateway, subnet);
 }

 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 
  // Match the request
  if (request.indexOf("/d1light-on") > 0)  {
    digitalWrite(relay1Pin, LOW);
  }
  if (request.indexOf("/d1light-off") >0)  {
    digitalWrite(relay1Pin, HIGH);
  }
  if (request.indexOf("/d2light-on") > 0)  {
    digitalWrite(relay2Pin, LOW);
  }
  if (request.indexOf("/d2light-off") >0)  {
    digitalWrite(relay2Pin, HIGH);
  }
  if (request.indexOf("/d3light-on") > 0)  {
    digitalWrite(relay3Pin, LOW);
  }
  if (request.indexOf("/d3light-off") >0)  {
    digitalWrite(relay3Pin, HIGH);
  }  
  if (request.indexOf("/d4light-on") > 0)  {
    digitalWrite(relay4Pin, LOW);
  }
  if (request.indexOf("/d4light-off") >0)  {
    digitalWrite(relay4Pin, HIGH);
  }

// Set ledPin according to the request
 
 // Return the response
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println(""); //  do not forget this one

client.println("<!DOCTYPE html>");
client.println("<html lang='en'>");

client.println("<head>");
client.println("<meta charset='UTF-8'>");
client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
client.println("<meta http-equiv='X-UA-Compatible' content='ie=edge'>");
client.println("<title>Internet-of-Things | Smart Power Outlet</title>");
client.println("</head>");
client.println("<style>body { background-color: #fff; margin: 0; font-family: sans-serif; font-size: 1em; line-height: 1.5; color: #FFF; text-align: left; } body { background: #242424 url(bg-03.jpg) center; background-attachment: fixed; background-size: cover; } body { padding: 0 30%; } h1, h2, h3, h4, h5, h6 { margin-top: 0.75rem; margin-bottom: 0.5rem; } .text-center { text-align: center; } .flex-row { display: flex; flex-direction: row; width: 100%; } .container { width: 100%; padding-right: 15px; padding-left: 15px; margin-right: auto; margin-left: auto; } .onButton { background-color: #56c277; /* border: none; */ color: #fff; padding: 15px 32px; text-align: center; text-decoration: none; font-size: 1.5em; width: 150px; } .offButton { background-color: #ff334e; color: #fff; padding: 15px 32px; text-align: center; text-decoration: none; font-size: 1.5em; width: 150px; } .table { border-collapse: collapse; width: 100%; max-width: 100%; margin-bottom: 1rem; background-color: transparent; height: 200px; font-weight: bold; text-align: center; } .item-box { margin-left: auto; margin-right: auto; } .box { background-color: rgba(0, 0, 0, .0); padding: 2% 0; } </style>");

client.println("<body>");
client.println("    <h1 class='text-center'>Internet-Of-Things: Smart Power Outlet </h1>");
client.println("    <hr>");
client.println("    <div class='box'>");
client.println("        <h2 class='text-center'>Switches</h2>");
client.println("        <div>");
client.println("           <div class='flex-row'>");
client.println("                <div class='item-box'>");
client.println("                    <h4 class='text-center'>OUTLET 1</h4>");
client.println("                    <a href=\"/d1light-on\"\">");
client.println("    <button class='onButton '>On </button></a>");
client.println("    <a href=\"/d1light-off\"\">");
client.println("                        <button class='offButton'>OFF</button>");
client.println("                    </a>");
client.println("                </div>");
client.println("                <div class='item-box'>");
client.println("                    <h4 class='text-center'>OUTLET 2</h4>");
client.println("                    <a href=\"/d2light-on\"\"><button class='onButton'>ON</button></a>");
client.println("    <a href=\"/d2light-off\"\">");
client.println("                        <button class='offButton'>OFF</button>");
client.println("                    </a>");
client.println("                </div>");
client.println("            </div>");
client.println("        </div>");


client.println("        <div>");
client.println("           <div class='flex-row'>");
client.println("                <div class='item-box'>");
client.println("                    <h4 class='text-center'>OUTLET 3</h4>");
client.println("                    <a href=\"/d3light-on\"\"><button class='onButton '>ON </button></a>");
client.println("    <a href=\"/d3light-off\"\">");
client.println("                        <button class='offButton'>OFF </button>");
client.println("                    </a>");
client.println("                </div>");
client.println("                <div class='item-box'>");
client.println("                    <h4 class='text-center'>OUTLET 4</h4>");
client.println("                    <a href=\"/d4light-on\"\"><button class='onButton'>ON </button></a>");
client.println("    <a href=\"/d4light-off\"\">");
client.println("                        <button class='offButton'>OFF </button>");
client.println("                    </a>");
client.println("                </div>");
client.println("            </div>");
client.println("        </div>");
client.println("    </div>");
client.println("    <hr>");

client.println("    <div class='box'>");
client.println("        <h2 class='text-center'>Status</h2>");
client.println("        <table class='table padding-center' border=\"5\">");
client.println("            <tr>");
                  if (digitalRead(relay1Pin))
         { 
           client.print("<td>Outlet 1 is OFF</td>");
         }
          else
          {
            client.print("<td>Outlet 1 is ON</td>");
          }
  if (digitalRead(relay2Pin))
         { 
           client.print("<td>Outlet 2 is OFF</td>");
         }
          else
          {
            client.print("<td>Outlet 2 is ON</td>");
          }

client.println("           </tr>");

client.println("           <tr>");
  if (digitalRead(relay3Pin))
         { 
           client.print("<td>Outlet 3 is OFF</td>");
         }
          else
          {
            client.print("<td>Outlet 3 is ON</td>");
          }


 if (digitalRead(relay4Pin))
         { 
           client.print("<td>Outlet 4 is OFF</td>");
         }
          else
          {
            client.print("<td>Outlet 4 is ON</td>");
          }

 client.println("           </tr>");

client.println("        </table>");
client.println("   </div>");
client.println("</body>");

client.println("</html>");
 delay(1);

  
 Serial.println("Client disonnected");
 Serial.println("");
}
