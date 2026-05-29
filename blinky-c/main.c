#include <avr/io.h>
int main() {
  // Configure clock

  // Set DDRD - DDD5 as output
  DDRD |= (1 << DDD5);

  // Toggle PORTD5 every second

  // Or maybe try and turn it on for starters
  PORTD |= (1 << PORTD5);
  return 0;
}
