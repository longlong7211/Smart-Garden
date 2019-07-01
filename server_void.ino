void OnConnect() {
  server.send(200, "text/html", SendHTML());
}
void onok() {
  server.send(200, "text/html", ok());
  id = server.arg("ssid");
  pw = server.arg("pass");
  Serial.println(id);
  Serial.println(pw);
  WiFi.begin(id.c_str(), pw.c_str());
  setpass();
}
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

String SendHTML() {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server</h1>\n";
  ptr += "<h3>Using Access Point(AP) Mode</h3>\n";
  ptr += "</p><form method='get' action='setpass'><label>SSID: </label><input name='ssid' length=32><br><label>PASS: </label><input name='pass' length=64><br><label>USER: </label><input name='user' length=64><br><input type='submit'></form>";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
String ok() {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h3>Setup OK</h3>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
