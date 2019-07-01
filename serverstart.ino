void serverstart() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  server.begin();
  server.on("/", OnConnect);
  server.on("/setpass", onok);
  server.onNotFound(handle_NotFound);
  Serial.println("HTTP server started");
}
