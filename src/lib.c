int add(int a, int b) { return a + b; }

char classify_person(float height, float weight) {
  if (height < 1.20) {
    if (weight < 60) {
      return 'A';
    } else if (weight < 90) {
      return 'D';
    } else {
      return 'G';
    }
  }

  if (height < 1.70) {
    if (weight < 60) {
      return 'B';
    } else if (weight < 90) {
      return 'E';
    } else {
      return 'H';
    }
  }

  if (weight < 60) {
    return 'C';
  } else if (weight < 90) {
    return 'F';
  } else {
    return 'I';
  }
}
