void getdata() {
  Firebase.getJSON(firebaseData, "clients/b304@gmail_com/devices/dongco");
  String  json = firebaseData.jsonData();
  StaticJsonBuffer<300> JSONBuffer;                         //Memory pool
  JsonObject& parsed = JSONBuffer.parseObject(json); //Parse message

  if (!parsed.success()) {   //Check for errors in parsing
    Serial.println("Parsing failed");
    delay(5000);
    return;
  }

  String dongco1 = parsed["bom"], dongco2 = parsed["bomA"], dongco3 = parsed["bomB"], dongco4 = parsed["den"];
  if (dongco1 == "true") {
    ttbomHC = 1;
    Serial.println("t1");
  }
  else {
    ttbomHC = 0;
  }
  //bomA
  if (dongco2 == "true") {
    ttbomA = 1;
    Serial.println("t2");
  }
  else {
    ttbomA = 0;
  }
  //bomB)
  if (dongco3 == "true") {
    ttbomB = 1;
    Serial.println("t3");
  }
  else {
    ttbomB = 0;
  }
  //den
  if (dongco4 == "true") {
    ttden = 1;
    Serial.println("t4");
  }
  else {
    ttden = 0;
  }
}
