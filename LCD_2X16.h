/* 
 * File:   LCD_2X16.h
 * Author: HP
 *
 * Created on 31 de marzo de 2020, 02:23 AM
 */

#ifndef LCD_2X16_H
#define	LCD_2X16_H

#define _XTAL_FREQ 20000000



/*
 * Declaracion de macros
 */

#define LCD_RW PORTCbits.RC0
#define LCD_RS PORTCbits.RC1
#define LCD_EN PORTCbits.RC2
#define TRIS_CONTROL TRISC
#define TRIS_DATOS TRISD
#define LCD_DATOS PORTD
#define LCD_TOGGLE() ((LCD_EN = 1), (LCD_EN = 0))

/*
 * Declaracion de funciones 
 */

//Escritura en LCD

/****************************************************************************
 * Nombre de la función: Lcd_Escribir_Byte
 * retorna : Nada
 * ingresa: Todo tipo de dato de 1 byte que permita configurar el LCD dichos datos se pueden encontrar en el datasheet del LCD
 * Descripción : Permite introducir un byte al LCD ya sea en su modalidad de caracter o comando.
 * Notas :  Tener cuidado de no introducir variables de un numero mayor a 8 bits ( 1 byte) 
 *****************************************************************************/

void Lcd_Escribir_Byte (unsigned char comando);

/****************************************************************************
 * Nombre de la función: Lcd_Limpiar
 * retorna : Nada
 * Ingresa: Nada
 * Descripción : Permite limpiar los mensajes y las configuraciones realizadas al LCD 
 * Notas :  La función debe ser usada de manera adecuada pues puede producir errores al momentos de 
 * visualizar los mensajes. Se suele usar para limpiar la pantalla de mensajes dispuestos en ella.
 *****************************************************************************/

void Lcd_Limpiar (void);

/****************************************************************************
 * Nombre de la función: Lcd_Escribir_Cadena
 * retorna : Nada
 * Ingresa: La cadena de caracteres 
 * Descripción : Permite visualizar todo tipo de mensaje que se introduzca a la función "MENSAJE"
 * Notas :  Tomar en cuenta que el mensaje no debe superar los 16 caracteres y debe ser introducido entre "comillas"
 *****************************************************************************/

void Lcd_Escribir_Cadena (const char *cadena);

/****************************************************************************
 * Nombre de la función: Lcd_Escribir_Caracter
 * retorna : Nada
 * Ingresa: Caracter 
 * Descripción : Permite escribir un caracter en la pantalla del LCD
 * Notas :  el caracter puede ser introducido en su formato HEXADECIMAL o ser puesto con 'comillas simples'
 *****************************************************************************/

void Lcd_Escribir_Caracter(char caracter);


//Mover el cursor 


/****************************************************************************
 * Nombre de la función:  Posicion_Linea_Superior
 * retorna : Nada
 * Ingresa: caracter sin signo
 * Descripción : Permite mover el cursor a la posicion requerida por el usuario a lo largo de la linea superior del LCD
 * Notas :  Pasada la posicion 15 no se podrá mostrar ningún mensaje pues el lcd solo dispone de 16 caracteres para trabajar 
 *****************************************************************************/


void Posicion_Linea_Superior (unsigned char pos);

/****************************************************************************
 * Nombre de la función:  Posicion_Linea_Inferior
 * retorna : Nada
 * Ingresa: caracter sin signo
 * Descripción : Permite mover el cursor a la posicion requerida por el usuario a lo largo de la linea inferior del LCD
 * Notas :  Pasada la posicion 15 no se podrá mostrar ningún mensaje pues el lcd solo dispone de 16 caracteres para trabajar 
 *****************************************************************************/

void Posicion_Linea_Inferiror (unsigned char pos);


//Inicio del LCD


/****************************************************************************
 * Nombre de la función: Iniciar_Lcd
 * retorna : Nada
 * Ingresa: Nada
 * Descripción : Inicia y configura el LCD 
 * Notas :  Solo debe ser llamada una vez en el código 
 *****************************************************************************/

void Iniciar_Lcd (void);

 /*****************************************************************************/


#endif	/* LCD_2X16_H */


