void anhsang() {
  gtin = getMedianNum(gt, 30);
  gtt = map(gtin, 0, 4096, 1000, 0);
  Serial.print("light: ");
  Serial.println(gtt);
}
