void touch1f() {
  sendtt=1;
  if (ttbomHC == 1) {
    sendbom="true";
    Serial.println("t1 on");
    ttbomHC = 0;
  } else {
    Serial.println("t1 off");
    sendbom="false";
    ttbomHC = 1;
  }
}

void touch2f() {
  sendtt=1;
  Serial.println("t2");
  if (ttbomA == 1) {
    sendbomA="true";
    ttbomA = 0;
  } else {
    sendbomA="False";
    ttbomA = 1;
  }
}

void touch3f() {
  sendtt=1;
  Serial.println("t3");
  if (ttbomB == 1) {
    sendbomB="true";
    ttbomB = 0;
  } else {
    sendbomB="false";
    ttbomB = 1;
  }
}

void touch4f() {
  sendtt=1;
  Serial.println("t4");
  if (ttden == 1) {
    sendden="true";
    ttden = 0;
  } else {
    sendden="false";
    ttden = 1;
  }
}
