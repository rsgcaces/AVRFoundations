// PROJECT  :Permutations of a String
// PURPOSE  :AVR Foundations Workbook
uint8_t count = 0;
char points[] = "ACES";
char buff[5] = "     ";
void setup() {
  Serial.begin(9600);
  permute(points, 0, 3);
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
  int i;
  if (l == r) {
    sprintf(buff, "%s", a);
    Serial.println(buff);
    count++;
  }
  else
  {
    for (i = l; i <= r; i++)
    {
      swap(a + l, a + i);
      permute(a, l + 1, r);
      swap(a + l, a + i); //backtrack
    }
  }
}

void loop() {
  Serial.println(count);
  while(1);
}
