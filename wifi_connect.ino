void setup_wifi() {
  String id;
  for (int i = 0; i < 50; ++i)
  {
    id += char(EEPROM.read(i));
  }
  Serial.print("SSID: ");
  Serial.println(id);
  Serial.println("Reading EEPROM pass");
  String pw = "";
  for (int i = 50; i < 100; ++i)
  {
    pw += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(pw);
  if ( id.length() > 1 ) {
    WiFi.begin(id.c_str(), pw.c_str());
   
  }
}
