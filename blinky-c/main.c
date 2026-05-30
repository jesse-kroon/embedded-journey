#include <avr/io.h>
int main() {
  // Configure clock
  TCCR1B |= (1 << CS12) |
            (1 << CS10); // This sets the clocks prescaler to 1024. We divide
                         // our chip's processing speed (16mhz) by 1024 to make
                         // time more manageable. So 16.000.000 / 1024 = 15.625
                         // timer ticks per second

  TCNT1 = 0; // This holds our ticks. Make sure it starts at 0.
  const int SECOND = 15625;

  // Set DDRD - DDD5 as output
  DDRD |= (1 << DDD5);

  while (1) {
    // Toggle PORTD5 every half second
    if (TCNT1 >= SECOND / 2) {
      PORTD ^= (1 << PORTD5);
      TCNT1 = 0;
    }
  }

  return 0;
}
