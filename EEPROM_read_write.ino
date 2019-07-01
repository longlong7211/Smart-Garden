void setpass() {
  if (id.length() > 0 && pw.length() > 0) {
    for (int i = 0; i < 150; i++) {
      EEPROM.write(i, 0);
    }
   for(int i=0;i<50;i++) {
      EEPROM.write(i, id[i]);
    }
    for(int i=0;i<50;i++) {
      EEPROM.write(50 + i, pw[i]);
    }
  }
  EEPROM.commit();
  Serial.println("Save pass done!");
}
