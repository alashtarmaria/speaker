#define SPEAKER_PIN     LATGbits.LATG9
#define SPEAKER_TRIS    TRISGbits.TRISG9


#define DISPLAY_ONOFF LATG.F7

void InitUART1(unsigned long baudrate);
void InitUART3(unsigned long baudrate);
void UART1_W(char *txt);
void UART3_W(char *txt);
void Display_TurnOn();

void Speaker_Init() {
    SPEAKER_TRIS = 0;       // RG9 çikis olarak ayarlandi
    SPEAKER_PIN = 0;        // Baslangiçta LOW (kapali)
}

void UART3_Init_Config(unsigned long baudrate) {
    PPS_Mapping(69, _INPUT,  _U3RX);
    PPS_Mapping(68, _OUTPUT, _U3TX);
    UART3_Init(baudrate);
    Delay_ms(100);
}



void Speaker_Test_Beep() {
    SPEAKER_PIN = 1;        // RG9 HIGH ? buzzer aktif
    Delay_ms(300);          // 300 ms ses
    SPEAKER_PIN = 0;        // RG9 LOW ? buzzer kapanir
    Delay_ms(700);          // Bekleme süresi
}

void main() {
    PLLFBD = 70;
    CLKDIV = 0x0000;

    UART3_Init_Config(9600);
    Speaker_Init();

    UART3_Write_Text("Speaker Test Basladi\r\n");

    while (1) {
        Speaker_Test_Beep();  // Her saniye bip sesi ver
    }
}

