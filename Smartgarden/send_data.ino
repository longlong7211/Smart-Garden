void senddata() {
  String Jsonset = "{\"anhsang\":" + String(gtt) + ",\"pH\":" + String(pHValue) + ",\"nongdoct\":" + String(tdsValue) + ",\"tnuoc\":" + String(temperatureC) + ",\"khongkhi\":" + String(temperatureC + 1) + "}";
  Firebase.setJSON(firebaseData, "clients/b304@gmail_com/devices/cambien", Jsonset);
}
