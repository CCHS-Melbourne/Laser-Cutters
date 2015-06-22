#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// This configuration file contains the basic settings.
// Advanced settings can be found in Configuration_adv.h
// BASIC SETTINGS: select your board type, temperature sensor type, axis scaling, and endstop configuration

// User-specified version info of this build to display in [Pronterface, etc] terminal window during
// startup. Implementation of an idea by Prof Braino to inform user that any changes made to this
// build by the user have been successfully uploaded into firmware.
#define STRING_VERSION_CONFIG_H __DATE__ " " __TIME__ // build date and time
#define STRING_CONFIG_H_AUTHOR "(none, default config)" // Who made the changes.

// SERIAL_PORT selects which serial port should be used for communication with the host.
// This allows the connection of wireless adapters (for instance) to non-default port pins.
// Serial port 0 is still used by the Arduino bootloader regardless of this setting.
#define SERIAL_PORT 0

// This determines the communication speed of the printer
//#define BAUDRATE 250000
#define BAUDRATE 115200

// Define this to set a custom name for your generic Mendel,
// #define CUSTOM_MENDEL_NAME "This Mendel"

//===========================================================================
//============================= Laser Settings ==============================
//===========================================================================
//
// Laser control is used by the Muve1 3D printer and the Buildlog.net laser cutter
//

//// The following defines select which G codes tell the laser to fire.  It's OK to uncomment more than one.
#define LASER_FIRE_G1 10 // fire the laser on a G1 move, extinguish when the move ends
#define LASER_FIRE_SPINDLE 11 // fire the laser on M3, extinguish on M5
//#define LASER_FIRE_E 12 // fire the laser when the E axis moves

//// Raster mode enables the laser to etch bitmap data at high speeds.  Increases command buffer size substantially.
#define LASER_MAX_RASTER_LINE 68 // maximum number of base64 encoded pixels per raster gcode command
#define LASER_RASTER_ASPECT_RATIO 1 // pixels aren't square on most displays, 1.33 == 4:3 aspect ratio
#define LASER_RASTER_MM_PER_PULSE 0.2 //Can be overridden by providing an R value in M649 command : M649 S17 B2 D0 R0.1 F4000

//// Uncomment the following if the laser cutter is equipped with a peripheral relay board
//// to control power to an exhaust fan, water pump, laser power supply, etc.
#define LASER_PERIPHERALS
#define LASER_PERIPHERALS_TIMEOUT 30000  // Number of milliseconds to wait for status signal from peripheral control board

//// Uncomment the following line to enable cubic bezier curve movement with the G5 code
// #define G5_BEZIER

#define CUSTOM_MENDEL_NAME "Laser Cutter"
#define LASER_WATTS 40.0
#define LASER_DIAMETER 0.1 // milimeters
#define LASER_PWM 25000 // hertz
#define LASER_FOCAL_HEIGHT 74.50 // z axis position at which the laser is focused

//===========================================================================
//=============================Thermal Settings  ============================
//===========================================================================
//
//--NORMAL IS 4.7kohm PULLUP!-- 1kohm pullup can be used on hotend sensor, using correct resistor and table
//
//// Temperature sensor settings:
// -2 is thermocouple with MAX6675 (only for sensor 0)
// -1 is thermocouple with AD595
// 0 is not used
// 1 is 100k thermistor - best choice for EPCOS 100k (4.7k pullup)
// 2 is 200k thermistor - ATC Semitec 204GT-2 (4.7k pullup)
// 3 is mendel-parts thermistor (4.7k pullup)
// 4 is 10k thermistor !! do not use it for a hotend. It gives bad resolution at high temp. !!
// 5 is 100K thermistor - ATC Semitec 104GT-2 (Used in ParCan) (4.7k pullup)
// 6 is 100k EPCOS - Not as accurate as table 1 (created using a fluke thermocouple) (4.7k pullup)
// 7 is 100k Honeywell thermistor 135-104LAG-J01 (4.7k pullup)
// 71 is 100k Honeywell thermistor 135-104LAF-J01 (4.7k pullup)
// 8 is 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
// 9 is 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
// 10 is 100k RS thermistor 198-961 (4.7k pullup)
// 60 is 100k Maker's Tool Works Kapton Bed Thermister
//
//    1k ohm pullup tables - This is not normal, you would have to have changed out your 4.7k for 1k
//                          (but gives greater accuracy and more stable PID)
// 51 is 100k thermistor - EPCOS (1k pullup)
// 52 is 200k thermistor - ATC Semitec 204GT-2 (1k pullup)
// 55 is 100k thermistor - ATC Semitec 104GT-2 (Used in ParCan) (1k pullup)

// If your bed has low resistance e.g. .6 ohm and throws the fuse you can duty cycle it to reduce the
// average current. The value should be an integer and the heat bed will be turned on for 1 interval of
// HEATER_BED_DUTY_CYCLE_DIVIDER intervals.
//#define HEATER_BED_DUTY_CYCLE_DIVIDER 4

// PID settings:
// Comment the following line to disable PID and enable bang-bang.
#define PID_MAX 255 // limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current

// This sets the max power delivered to the bed, and replaces the HEATER_BED_DUTY_CYCLE_DIVIDER option.
// all forms of bed control obey this (PID, bang-bang, bang-bang with hysteresis)
// setting this to anything other than 255 enables a form of PWM to the bed just like HEATER_BED_DUTY_CYCLE_DIVIDER did,
// so you shouldn't use it unless you are OK with PWM on your bed.  (see the comment on enabling PIDTEMPBED)
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

//===========================================================================
//=============================Mechanical Settings===========================
//===========================================================================

// coarse Endstop Settings
#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors

#ifndef ENDSTOPPULLUPS
	// fine Enstop settings: Individual Pullups. will be ignored if ENDSTOPPULLUPS is defined
	// #define ENDSTOPPULLUP_XMAX
	// #define ENDSTOPPULLUP_YMAX
	// #define ENDSTOPPULLUP_ZMAX
	// #define ENDSTOPPULLUP_XMIN
	// #define ENDSTOPPULLUP_YMIN
	// #define ENDSTOPPULLUP_ZMIN
#endif

#ifdef ENDSTOPPULLUPS
	#define ENDSTOPPULLUP_XMAX
	#define ENDSTOPPULLUP_YMAX
	#define ENDSTOPPULLUP_ZMAX
	#define ENDSTOPPULLUP_XMIN
	#define ENDSTOPPULLUP_YMIN
	#define ENDSTOPPULLUP_ZMIN
#endif

// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
const bool X_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Y_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool X_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Y_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
#define DISABLE_MAX_ENDSTOPS
//#define DISABLE_MIN_ENDSTOPS

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z true

// For Z-Axis with leadscrews, uncomment to save homeing status when disabling steppers (axis is unlikely to move on its own)
#define Z_AXIS_IS_LEADSCREW

#define INVERT_X_DIR true    // for Mendel set to false, for Orca set to true
#define INVERT_Y_DIR true    // for Mendel set to true, for Orca set to false
#define INVERT_Z_DIR false     // for Mendel set to false, for Orca set to true
#define INVERT_E0_DIR false   // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E1_DIR false    // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E2_DIR false   // for direct drive extruder v9 set to true, for geared extruder set to false

// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define min_software_endstops true // If true, axis won't move to coordinates less than HOME_POS.
#define max_software_endstops true  // If true, axis won't move to coordinates greater than the defined lengths below.
// Travel limits after homing

// AMRI Laser Cutter
//#define X_MAX_POS 600
//#define X_MIN_POS 0
//#define Y_MAX_POS 475
//#define Y_MIN_POS 0
//#define Z_MAX_POS 90
//#define Z_MIN_POS 0

// Lansing Makers Netowrk Laser Cutter
#define X_MAX_POS 531
#define X_MIN_POS 0
#define Y_MAX_POS 558
#define Y_MIN_POS 0
#define Z_MAX_POS 95
#define Z_MIN_POS 0

// China Town K40 CO2 Laser Engraver/Cutter
//#define X_MAX_POS 337
//#define X_MIN_POS 0
//#define Y_MAX_POS 230
//#define Y_MIN_POS 0
//#define Z_MAX_POS 75
//#define Z_MIN_POS 0

#define X_MAX_LENGTH (X_MAX_POS - X_MIN_POS)
#define Y_MAX_LENGTH (Y_MAX_POS - Y_MIN_POS)
#define Z_MAX_LENGTH (Z_MAX_POS - Z_MIN_POS)

// The position of the homing switches
//#define MANUAL_HOME_POSITIONS  // If defined, MANUAL_*_HOME_POS below will be used
//#define BED_CENTER_AT_0_0  // If defined, the center of the bed is at (X=0, Y=0)

//Manual homing switch locations:
// For deltabots this means top and center of the cartesian print volume.
#define MANUAL_X_HOME_POS 0
#define MANUAL_Y_HOME_POS 0
#define MANUAL_Z_HOME_POS 0
//#define MANUAL_Z_HOME_POS 402 // For delta: Distance between nozzle and print surface after homing.

//// MOVEMENT SETTINGS
#define NUM_AXIS 4 // The axis order in all axis related arrays is X, Y, Z, E
#define HOMING_FEEDRATE {3000, 3000, 240, 0}  // set the homing speeds (mm/min)

// default settings

// AMRI Laser Cutter
//#define DEFAULT_AXIS_STEPS_PER_UNIT   {167.20882, 167.20882, 4000/25.4, 1380/4}
//#define DEFAULT_MAX_FEEDRATE          {165, 165, 50, 200000}    // (mm/sec)
//#define DEFAULT_MAX_ACCELERATION      {5000,5000,5000,500}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.
//#define DEFAULT_ACCELERATION          3000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
//#define DEFAULT_RETRACT_ACCELERATION  3000   // X, Y, Z and E max acceleration in mm/s^2 for r retracts

// Lansing Makers Netowork Laser Cutter
#define DEFAULT_AXIS_STEPS_PER_UNIT   {157.4802,157.4802,6047.2440}  // default steps per unit for Ultimaker
#define DEFAULT_MAX_FEEDRATE          {3000, 3000, 10, 25}    // (mm/sec)
#define DEFAULT_MAX_ACCELERATION      {2600,2600,2.5,2.5}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.

#define DEFAULT_ACCELERATION          2000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
#define DEFAULT_RETRACT_ACCELERATION  2000   // X, Y, Z and E max acceleration in mm/s^2 for retracts

// The speed change that does not require acceleration (i.e. the software might assume it can be done instantaneously)
#define DEFAULT_XYJERK                20.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.4     // (mm/sec)
#define DEFAULT_EJERK                 5.0    // (mm/sec)

//===========================================================================
//=============================Additional Features===========================
//===========================================================================

// EEPROM
// the microcontroller can store settings in the EEPROM, e.g. max velocity...
// M500 - stores paramters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).
// M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
//define this to enable eeprom support
#define EEPROM_SETTINGS
//to disable EEPROM Serial responses and decrease program space by ~1700 byte: comment this out:
// please keep turned on if you can.
#define EEPROM_CHITCHAT

// Preheat Constants
#define PLA_PREHEAT_HOTEND_TEMP 180
#define PLA_PREHEAT_HPB_TEMP 70
#define PLA_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255

#define ABS_PREHEAT_HOTEND_TEMP 240
#define ABS_PREHEAT_HPB_TEMP 100
#define ABS_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255

//LCD and SD support
//#define ULTRA_LCD  //general lcd support, also 16x2
//#define DOGLCD  // Support for SPI LCD 128x64 (Controller ST7565R graphic Display Family)
//#define SDSUPPORT // Enable SD Card Support in Hardware Console
//#define SDSLOW // Use slower SD transfer mode (not normally needed - uncomment if you're getting volume init error)

//#define ULTIMAKERCONTROLLER //as available from the ultimaker online store.
//#define ULTIPANEL  //the ultipanel as on thingiverse

// The MaKr3d Makr-Panel with graphic controller and SD support
// http://reprap.org/wiki/MaKr3d_MaKrPanel
//#define MAKRPANEL

// The RepRapDiscount Smart Controller (white PCB)
// http://reprap.org/wiki/RepRapDiscount_Smart_Controller
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

// The GADGETS3D G3D LCD/SD Controller (blue PCB)
// http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//#define G3D_PANEL

// The RepRapDiscount FULL GRAPHIC Smart Controller (quadratic white PCB)
// http://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
// ==> REMEMBER TO INSTALL U8glib to your ARDUINO library folder: http://code.google.com/p/u8glib/wiki/u8glib
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

// The RepRapWorld REPRAPWORLD_KEYPAD v1.1
// http://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // how much should be moved when a key is pressed, eg 10.0 means 10mm per click

// The Elefu RA Board Control Panel
// http://www.elefu.com/index.php?route=product/product&product_id=53
// REMEMBER TO INSTALL LiquidCrystal_I2C.h in your ARUDINO library folder: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//#define RA_CONTROL_PANEL

//automatic expansion
#if defined (MAKRPANEL)
	#define DOGLCD
	#define SDSUPPORT
	#define ULTIPANEL
	#define NEWPANEL
	#define DEFAULT_LCD_CONTRAST 17
#endif

#if defined (REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
	#define DOGLCD
	#define U8GLIB_ST7920
	#define REPRAP_DISCOUNT_SMART_CONTROLLER
#endif

#if defined(ULTIMAKERCONTROLLER) || defined(REPRAP_DISCOUNT_SMART_CONTROLLER) || defined(G3D_PANEL)
	#define ULTIPANEL
	#define NEWPANEL
#endif

#if defined(REPRAPWORLD_KEYPAD)
	#define NEWPANEL
	#define ULTIPANEL
#endif
#if defined(RA_CONTROL_PANEL)
	#define ULTIPANEL
	#define NEWPANEL
	#define LCD_I2C_TYPE_PCA8574
	#define LCD_I2C_ADDRESS 0x27   // I2C Address of the port expander
#endif

//I2C PANELS

//#define LCD_I2C_SAINSMART_YWROBOT
#ifdef LCD_I2C_SAINSMART_YWROBOT
	// This uses the LiquidCrystal_I2C library ( https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home )
	// Make sure it is placed in the Arduino libraries directory.
	#define LCD_I2C_TYPE_PCF8575
	#define LCD_I2C_ADDRESS 0x27   // I2C Address of the port expander
	#define NEWPANEL
	#define ULTIPANEL
#endif

// PANELOLU2 LCD with status LEDs, separate encoder and click inputs
//#define LCD_I2C_PANELOLU2
#ifdef LCD_I2C_PANELOLU2
	// This uses the LiquidTWI2 library v1.2.3 or later ( https://github.com/lincomatic/LiquidTWI2 )
	// Make sure the LiquidTWI2 directory is placed in the Arduino or Sketchbook libraries subdirectory.
	// (v1.2.3 no longer requires you to define PANELOLU in the LiquidTWI2.h library header file)
	// Note: The PANELOLU2 encoder click input can either be directly connected to a pin
	//       (if BTN_ENC defined to != -1) or read through I2C (when BTN_ENC == -1).
	#define LCD_I2C_TYPE_MCP23017
	#define LCD_I2C_ADDRESS 0x20 // I2C Address of the port expander
	#define LCD_USE_I2C_BUZZER //comment out to disable buzzer on LCD
	#define NEWPANEL
	#define ULTIPANEL
#endif

// Panucatt VIKI LCD with status LEDs, integrated click & L/R/U/P buttons, separate encoder inputs
//#define LCD_I2C_VIKI
#ifdef LCD_I2C_VIKI
	// This uses the LiquidTWI2 library v1.2.3 or later ( https://github.com/lincomatic/LiquidTWI2 )
	// Make sure the LiquidTWI2 directory is placed in the Arduino or Sketchbook libraries subdirectory.
	// Note: The pause/stop/resume LCD button pin should be connected to the Arduino
	//       BTN_ENC pin (or set BTN_ENC to -1 if not used)
	#define LCD_I2C_TYPE_MCP23017
	#define LCD_I2C_ADDRESS 0x20 // I2C Address of the port expander
	#define LCD_USE_I2C_BUZZER //comment out to disable buzzer on LCD (requires LiquidTWI2 v1.2.3 or later)
	#define NEWPANEL
	#define ULTIPANEL
#endif

#ifdef ULTIPANEL
	//  #define NEWPANEL  //enable this if you have a click-encoder panel
	#define SDSUPPORT
	#define ULTRA_LCD
	#ifdef DOGLCD // Change number of lines to match the DOG graphic display
		#define LCD_WIDTH 20
		#define LCD_HEIGHT 5
	#else
		#define LCD_WIDTH 20
		#define LCD_HEIGHT 4
	#endif
#else //no panel but just lcd
	#ifdef ULTRA_LCD
		#ifdef DOGLCD // Change number of lines to match the 128x64 graphics display
			#define LCD_WIDTH 20
			#define LCD_HEIGHT 5
		#else
			#define LCD_WIDTH 16
			#define LCD_HEIGHT 2
		#endif
	#endif
#endif

// default LCD contrast for dogm-like LCD displays
#ifdef DOGLCD
	#ifndef DEFAULT_LCD_CONTRAST
		#define DEFAULT_LCD_CONTRAST 32
	#endif
#endif

// Use software PWM to drive the fan, as for the heaters. This uses a very low frequency
// which is not ass annoying as with the hardware PWM. On the other hand, if this frequency
// is too low, you should also increment SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// Incrementing this by 1 will double the software PWM frequency,
// affecting heaters, and the fan if FAN_SOFT_PWM is enabled.
// However, control resolution will be halved for each increment;
// at zero value, there are 128 effective control positions.
#define SOFT_PWM_SCALE 0

// M240  Triggers a camera by emulating a Canon RC-1 Remote
// Data from: http://www.doc-diy.net/photo/rc-1_hacked/
// #define PHOTOGRAPH_PIN     23

// SF send wrong arc g-codes when using Arc Point as fillet procedure
//#define SF_ARC_FIX

#include "Configuration_adv.h"
#include "thermistortables.h"

#endif //__CONFIGURATION_H
