//CODE of lcd interfacing with 8051 microcontroller [cite: 2]
#include<reg51.h> [cite: 3]
#include<string.h> [cite: 4]

// Function Declarations [cite: 5, 6, 7, 8, 9, 10, 11, 17]
void delay(unsigned int i);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_init(void);
void lcd_str(unsigned char *str);
void sendser_char(unsigned char b);
void sendser_str(unsigned char *str);
void clear(void);

// Pin and Port Definitions [cite: 12, 13, 16]
sbit rs=P2^0; // Register Select pin on Port 2, bit 0
sbit en=P2^1; // Enable pin on Port 2, bit 1
sfr ldata=0x90; // LCD data port defined as Port 1 (address 0x90)

// Global Variables [cite: 14, 15]
unsigned int i;
unsigned char a[100]; // Array to store received serial data (RFID tag ID)

void main() [cite: 18]
{
    // Configure Timer 1 for Baud Rate Generation [cite: 20, 21, 22, 23]
    TMOD=0x20;  // Timer 1, Mode 2 (auto-reload mode)
    TH1=0xfd;   // Sets baud rate to 9600
    SCON=0x50;  // 8-bit data, 1 start bit, 1 stop bit
    TR1=1;      // Start Timer 1

    // Initial Display Messages [cite: 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34]
    lcd_init();
    lcd_str("  WELCOME TO   ");
    lcd_cmd(0xc0); // Move cursor to the second line
    lcd_str("  MY PROJECT   ");
    delay(65000);
    lcd_cmd(0x01); // Clear LCD
    lcd_cmd(0x80); // Move cursor to the first line
    lcd_str("  YT TRAINING  ");
    lcd_cmd(0xc0);
    lcd_str("  INSTITUTE   ");
    delay(65000);

    while(1) [cite: 35]
    {
        // Display "Waiting for Tag" message [cite: 37, 38, 39, 40, 41]
        lcd_cmd(0x01); // Clear LCD
        lcd_cmd(0x80);
        lcd_str("  Waiting For  ");
        lcd_cmd(0xc0);
        lcd_str("  RFID Tag   ");

        // Receive 10 characters from Serial Port (RFID Tag ID) [cite: 42, 43, 44, 45, 46]
        for(i=0;i<10;i++)
        {
            while(RI==0); // Wait until 1 character is received (RI becomes 1)
            RI=0;         // Clear the Receive Interrupt flag
            a[i]=SBUF;    // Store the received character in the array 'a'
        }
        a[10]='\0'; // Null-terminate the string [cite: 48]

        // Check for recognized Tag IDs [cite: 49, 59, 69]
        if(0==strcmp("10003B0CA7",a)) // Employee 1 Tag ID [cite: 49]
        {
            lcd_cmd(0x01); [cite: 51]
            lcd_cmd(0x80); [cite: 52]
            lcd_str(" EMPLOYEE NO : 1"); [cite: 53]
            lcd_cmd(0xc0); [cite: 54]
            lcd_str(a); [cite: 55]
            delay(65000); [cite: 56]
            clear(); [cite: 57]
        }
        else if(0==strcmp("10003B0CAE",a)) // Employee 2 Tag ID [cite: 59]
        {
            lcd_cmd(0x01); [cite: 61]
            lcd_cmd(0x80); [cite: 62]
            lcd_str(" EMPLOYEE NO : 2"); [cite: 63]
            lcd_cmd(0xc0); [cite: 64]
            lcd_str(a); [cite: 65]
            delay(65000); [cite: 66]
            clear(); [cite: 67]
        }
        else // Invalid Tag [cite: 69]
        {
            lcd_cmd(0x01); [cite: 71]
            lcd_cmd(0x80); [cite: 72]
            lcd_str(" INVALID TAG"); [cite: 73]
            lcd_cmd(0xc0); [cite: 74]
            lcd_str(a); [cite: 75]
            delay(65000); [cite: 76]
            clear(); [cite: 77]
        }
    }
}

// ---------------------------------------------------------------- //
// LCD and Utility Functions
// ---------------------------------------------------------------- //

void lcd_init() [cite: 81]
{
    lcd_cmd(0x38); // 2 lines, 5x7 matrix [cite: 83]
    lcd_cmd(0x0c); // Display ON, Cursor OFF [cite: 84]
    lcd_cmd(0x01); // Clear display [cite: 85]
    lcd_cmd(0x80); // Set cursor to 1st line, 1st position [cite: 86]
}

void delay(unsigned int i) [cite: 88]
{
    unsigned int j; [cite: 90]
    for(j=0;j<i;j++); // Simple software loop delay [cite: 91]
}

void lcd_cmd(unsigned char a) [cite: 93]
{
    rs=0; // Command mode (RS=0) [cite: 95]
    ldata=a; // Put command on data port [cite: 96]
    en=1; // Enable ON [cite: 97]
    delay(5); [cite: 98]
    en=0; // Enable OFF (sends pulse) [cite: 99]
    delay(5); [cite: 100]
}

void lcd_data(unsigned char b) [cite: 102]
{
    rs=1; // Data mode (RS=1) [cite: 104]
    ldata=b; [cite: 105]
    en=1; [cite: 106]
    delay(5); [cite: 107]
    en=0; [cite: 108]
    delay(5); [cite: 109]
}

void lcd_str(unsigned char *str) [cite: 111]
{
    while(*str) // Loop until null terminator is found [cite: 113]
    {
        lcd_data(*str++); // Send character and increment pointer [cite: 115]
    }
}

void sendser_char(unsigned char b) [cite: 118]
{
    SBUF=b; // Load character into Serial Buffer [cite: 120]
    while(TI==0); // Wait until Transmission Interrupt flag is set [cite: 121]
    TI=0; // Clear the flag [cite: 122]
}

void sendser_str(unsigned char *str) [cite: 124]
{
    while(*str) [cite: 126]
    {
        sendser_char(*str++); [cite: 128]
    }
}

void clear(void) [cite: 131]
{
    unsigned int i; [cite: 133]
    for(i=0;i<100;i++) [cite: 134]
    {
        a[i]='\0'; // Clear the contents of the RFID tag array 'a' [cite: 136]
    }
}