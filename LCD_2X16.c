#include <xc.h>
#include "LCD_2X16.h"

void Lcd_Escribir_Byte(unsigned char comando) {
    __delay_us(50);
    LCD_DATOS = ((comando >> 4) & 0x0F); //Hacemos el fraccionamieto del byte de datos en 4 bits
    LCD_TOGGLE(); //Hacemos la habilitacion del bit de enable del LCD
    LCD_DATOS = (comando & 0x0F); //Enviamos los 4 bits restantes del fraccionamiento anterior 
    LCD_TOGGLE(); //Hacemos la habilitacion del bit de enable del LCD
}

void Lcd_Limpiar(void) {
    LCD_RS = 0; //Ponemos el LCD en modo comando
    Lcd_Escribir_Byte(0x01);
    __delay_ms(3);
}

void Lcd_Escribir_Cadena(const char *cadena) {
    LCD_RS = 1; //Ponemos el LCD en modo caracter 
    while (*cadena)
        Lcd_Escribir_Byte(*cadena++); //Enviamos y escribimos los caracteres de a 1 en el LCD
}

void Lcd_Escribir_Caracter(char caracter) {
    LCD_RS = 1; //Ponemos el LCD en modo caracter 
    Lcd_Escribir_Byte(caracter);
}

void Posicion_Linea_Superior(unsigned char pos) {
    LCD_RS = 0; //Ponemos el LCD en modo comando
    Lcd_Escribir_Byte(0x80 + pos); //Movemos el cursor en la linea superior 
}

void Posicion_Linea_Inferiror(unsigned char pos) {
    LCD_RS = 0; //Ponemos el LCD en modo comando
    Lcd_Escribir_Byte(0xC0 + pos); //Movemos el cursor en la linea inferior 
}

//FUNCION DE INICIO 

void Iniciar_Lcd(void) {
    char valor_inicial;
    TRIS_CONTROL = 0x00;
    TRIS_DATOS = 0x00;
    valor_inicial = 0x03;

    LCD_EN = 0;
    LCD_RS = 0;
    LCD_RW = 0;

    __delay_ms(20);

    LCD_DATOS = valor_inicial;
    LCD_TOGGLE();
    __delay_ms(5);
    LCD_TOGGLE();
    __delay_us(200);
    LCD_TOGGLE();
    __delay_us(200);
    LCD_DATOS = 2; //Ponemos al LCD en modo de 4 bits
    LCD_TOGGLE();

    Lcd_Escribir_Byte(0x28);
    Lcd_Escribir_Byte(0xF); //Activamos el cursor y el parpadep
    Lcd_Limpiar();
    Lcd_Escribir_Byte(0x6); //Modo de entrada
}