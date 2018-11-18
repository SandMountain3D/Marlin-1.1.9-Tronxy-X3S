/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Melzi (Creality) pin assignments
 *
 * The Creality board needs a bootloader installed before Marlin can be uploaded.
 * If you don't have a chip programmer you can use a spare Arduino plus a few
 * electronic components to write the bootloader.
 *
 * See http://www.instructables.com/id/Burn-Arduino-Bootloader-with-Arduino-MEGA/
 */

#define BOARD_NAME "Melzi (Tronxy)"
#define IS_MELZI

#include "pins_SANGUINOLOLU_12.h"

// For the stock Tronxy graphic LCD use the REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
//   option for the display in Configuration.h

#undef LCD_SDSS
#undef LED_PIN
#undef LCD_PINS_RS
#undef LCD_PINS_ENABLE
#undef LCD_PINS_D4
#undef LCD_PINS_D5
#undef LCD_PINS_D6
#undef LCD_PINS_D7
#undef FIL_RUNOUT_PIN
#undef BTN_ENC
//#undef X_ENABLE_PIN
//#undef Y_ENABLE_PIN
#undef Z_ENABLE_PIN
//#undef E0_ENABLE_PIN

// extracted changes by TronXY to pins_SANGUINOLOLU_11.h from firmware X5S-20-12864/Marlin-1.1 Melzi 2.0 12864 (hopefully correct with all those if's)

#define Z_ENABLE_PIN X_ENABLE_PIN

// Alter timing for graphical display
#define ST7920_DELAY_1 DELAY_NS(0)
#define ST7920_DELAY_2 DELAY_NS(125)
#define ST7920_DELAY_3 DELAY_NS(0)


#ifdef ULTRA_LCD
 #ifdef NEWPANEL
   //we have no buzzer installed
   #define BEEPER_PIN -1  //A1
   //LCD Pins
   #ifdef DOGLCD
   #ifdef U8GLIB_ST7920 //SPI GLCD 12864 ST7920 ( like [www.digole.com] ) For Melzi V2.0
     #define LCD_PINS_RS 30 //CS chip select /SS chip slave select
     #define LCD_PINS_ENABLE 28 //SID (MOSI)
     #define LCD_PINS_D4 16 //SCK (CLK) clock
     #define BEEPER_PIN -1 // Pin 27 is take by LED_Pin, but Melzi LED do nothing with Marlin and I take this pin for BEEPER.... See here > [github.com] , If you want use this pin with Gcode M42 instead BEEPER
   #else
     // Pins for DOGM SPI LCD Support
     #define DOGLCD_A0 30
     #define DOGLCD_CS 29
     #define LCD_CONTRAST 1
   #endif
     // Uncomment screen orientation
     #define LCD_SCREEN_ROT_0
       // #define LCD_SCREEN_ROT_90
       // #define LCD_SCREEN_ROT_180
       // #define LCD_SCREEN_ROT_270
     #else // standard Hitachi LCD controller
     #define LCD_PINS_RS        30//4
     #define LCD_PINS_ENABLE    28//17
     #define LCD_PINS_D4        16//SDA
     #define LCD_PINS_D5        17//SCL
     #define LCD_PINS_D6        27//A4
     #define LCD_PINS_D7        29//A2
   #endif
   //The encoder and click button
   #define BTN_EN1 10
   #define BTN_EN2 11
   //#define BTN_ENC 11
   
   #ifdef LCD_I2C_PANELOLU2
     #if MB(MELZI)
       #define BTN_ENC 11 //the click switch
       #define LCD_SDSS -1 //to use the SD card reader on the Panelolu2 rather than the melzi board
     #else
       #define BTN_ENC 11 //the click switch
     #endif
   #else
     #define BTN_ENC 26  //the click switch
    //#define LCD_SDSS 28 //to use the SD card reader on the smart controller rather than the melzi board
   #endif //Panelolu2
   //not connected to a pin
   #define SD_DETECT_PIN -1

 #endif //NEWPANEL
#endif //ULTRA_LCD

#ifdef MAKRPANEL
  #define BEEPER_PIN 29
  // Pins for DOGM SPI LCD Support
  #define DOGLCD_A0  30
  #define DOGLCD_CS  17
  #define LCD_PIN_BL 28  // backlight LED on PA3
  // GLCD features
  #define LCD_CONTRAST 1
  // Uncomment screen orientation
  #define LCD_SCREEN_ROT_0
  // #define LCD_SCREEN_ROT_90
  // #define LCD_SCREEN_ROT_180
  // #define LCD_SCREEN_ROT_270
  //The encoder and click button
  #define BTN_EN1 11
  #define BTN_EN2 10
  #define BTN_ENC 16  //the click switch
  //not connected to a pin
  #define SD_DETECT_PIN -1
#endif //Makrpanel

/** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  PIN:   0   Port: B0        E0_DIR_PIN                  protected              ???
  PIN:   1   Port: B1        E0_STEP_PIN                 protected              ???
  PIN:   2   Port: B2        Z_DIR_PIN                   protected              ???
  PIN:   3   Port: B3        Z_STEP_PIN                  protected              ???
  PIN:   4   Port: B4        AVR_SS_PIN                  protected
  .                          FAN_PIN                     protected
  .                          SS_PIN                      protected
  PIN:   5   Port: B5        AVR_MOSI_PIN                Output = 1
  .                          MOSI_PIN                    Output = 1
  PIN:   6   Port: B6        AVR_MISO_PIN                Input  = 0    TIMER3A   PWM:     0    WGM: 1    COM3A: 0    CS: 3    TCCR3A: 1    TCCR3B: 3    TIMSK3: 0
  .                          MISO_PIN                    Input  = 0
  PIN:   7   Port: B7        AVR_SCK_PIN                 Output = 0    TIMER3B   PWM:     0    WGM: 1    COM3B: 0    CS: 3    TCCR3A: 1    TCCR3B: 3    TIMSK3: 0
  .                          SCK_PIN                     Output = 0
  PIN:   8   Port: D0        RXD                         Input  = 1
  PIN:   9   Port: D1        TXD                         Input  = 0
  PIN:  10   Port: D2      + BTN_EN2                     Input  = 1
  PIN:  11   Port: D3      + BTN_EN1                     Input  = 1
  PIN:  12   Port: D4        HEATER_BED_PIN              protected
  PIN:  13   Port: D5        HEATER_0_PIN                protected
  PIN:  14   Port: D6        E0_ENABLE_PIN               protected
  .                          X_ENABLE_PIN                protected
  .                          Y_ENABLE_PIN                protected
  PIN:  15   Port: D7        X_STEP_PIN                  protected              ???
  PIN:  16   Port: C0      + LCD_PINS_D4                 Output = 1
  .                          SCL                         Input  = 1
  PIN:  17   Port: C1      + LCD_PINS_D5                 Output = 1
  .                          SDA                         Output = 0
  PIN:  18   Port: C2      + X_MIN_PIN                   protected
  .                        + X_STOP_PIN                  protected
  PIN:  19   Port: C3      + Y_MIN_PIN                   protected
  .                        + Y_STOP_PIN                  protected
  PIN:  20   Port: C4      + Z_MIN_PIN                   protected
  .                        + Z_STOP_PIN                  protected
  PIN:  21   Port: C5        X_DIR_PIN                   protected              ???
  PIN:  22   Port: C6        Y_STEP_PIN                  protected              ???
  PIN:  23   Port: C7        Y_DIR_PIN                   protected              ???
  PIN:  24   Port: A7      + TEMP_0_PIN                  protected
  PIN:  25   Port: A6      + TEMP_BED_PIN                protected
  PIN:  26   Port: A5      + BTN_ENC                     Output = 0             ??? Z_ENABLE_PIN                protected
  PIN:  27   Port: A4      + LCD_PINS_D6                 Output = 1             ??? BEEPER_PIN                  Output = 0
  PIN:  28   Port: A3      + LCD_PINS_ENABLE             Output = 0
  PIN:  29   Port: A2      + LCD_PINS_D7                 Output = 1
  PIN:  30   Port: A1      + LCD_PINS_RS                 Output = 1
  PIN:  31   Port: A0        SDSS                        Output = 1
*/
