// Define a file descriptor for the serial output:
static FILE uartout = { 0 };

// Declare our put-character function:
static int uart_putchar (char c, FILE *stream);


void setup() {
   // Fill in UART file descriptor with pointer to my char-out func.
   fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
   stdout = &uartout;

   Serial.begin(9600);   // open serial port, sets baud rate
}

void loop( void ){
   printf("Run time: %ld\n", millis());
   delay(1000);          // wait 1 sec
}

// My char output function
static int uart_putchar (char c, FILE *stream)
{
   if( c == '\n' )
      Serial.write('\r');
   Serial.write(c) ;
   return 0 ;
}