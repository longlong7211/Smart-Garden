void dongco()
{
  //bom hoi chuyen
  if (ttbomHC == 1)
  {
    digitalWrite(bomHCpin, LOW);
  } else {
    digitalWrite(bomHCpin, HIGH);
  }
  //bomA
  if (ttbomA == 1)
  {
    digitalWrite(bomApin, LOW);
  } else {
    digitalWrite(bomApin, HIGH);
  }
  //bomB
  if (ttbomB == 1)
  {
    digitalWrite(bomBpin, LOW);
  } else {
    digitalWrite(bomBpin, HIGH);
  }
  //den
  if (ttden == 1)
  {
    digitalWrite(denpin, LOW);
  } else {
    digitalWrite(denpin, HIGH);
  }
}
