void gettime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  int d, m, y, mi, h;
  mi = timeinfo.tm_min;
  h = timeinfo.tm_hour;
  y = 1900 + timeinfo.tm_year;
  m = timeinfo.tm_mon + ((1 + timeinfo.tm_year) / 4) / 30;
  d = timeinfo.tm_mday + ((1 + timeinfo.tm_year) / 4) - 30;
  Serial.print(h);
  Serial.println(mi);
  Serial.print(d);
  Serial.print(m);
  Serial.println(y);
}
