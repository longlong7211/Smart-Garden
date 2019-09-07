void senddongco() {
  String Jsonset = "{\"bom\":" + sendbom + ",\"bomA\":" + sendbomA + ",\"bomB\":" + sendbomB + ",\"den\":" + sendden + ",\"maysucoxi\":\"false\"}";
  if (Firebase.setJSON(firebaseData, "clients/b304@gmail_com/devices/dongco", Jsonset)) { }else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    };
}
