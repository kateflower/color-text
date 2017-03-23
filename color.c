#include <stdlib.h>
#include <6502.h>
#include <lynx.h>
#include <tgi.h>
// enable Mikeys interrupt response
//#define CLI asm("\tcli")

// These header files are related to the processor family, the Lynx and the TGI libraries.

//  this array will contain a string “tgi” that indicates that the loading of the driver was successful.
extern char lynxtgi[]; 


// lynx-160-102-16.tgi file. The filename is derived from the 160×102 resolution and 16 color palette



void initialize()
{
	// driver for the Tiny Graphics Interface (TGI)
	// allows for 2D graphics primitives like drawing and text 
  	// Lynx file is called lynx-160-102-16.tgi and is part of the Lynx specific CC65 files
	// function call to tgi_install will install the Lynx specific TGI driver
	// Lynx does not have the ability to load a driver dynamically it needs to be linked statically when the game is built.   
	tgi_install(&lynxtgi);

	// performs the initialization of the loaded drivers of which the TGI graphics driver is just one
	// There are two additional drivers (joystick and comlynx) that you can load as well. 
  	tgi_init();

	// represents the CLI assembly instruction for the 65SC02 processor
	// allows you to clear the Interrupt Disable flag of the processor,   
  	CLI();
	
  	while (tgi_busy())  {  };
 
  	tgi_setpalette(tgi_getdefpalette());
  	tgi_setcolor(COLOR_WHITE);
  	tgi_setbgcolor(COLOR_BLACK);
  	tgi_clear();
}

//
// Render the screen
//
// The TGI library has two types of typography support: vector and bitmap fonts.
// The Lynx only has support for bitmaps and a single system supplied bitmap font. 
//  vector related functions are not available for the Lynx
//  the scale, style and direction (vertical or horizontal) of the font cannot be changed. 
// This leaves just a couple of functions: outtext and outtextxy to output text. 
void show_screen()
{
	char text[20];

	// clearing the screen and redrawing all
  	tgi_clear();
	
	tgi_outtextxy(10, 0, "Resolution:");
	// tgi_getxres, tgi_getyres These functions return the x and y resolution of the screen
	// For the Lynx this is 160 by 102 as per the hardware specs.
	itoa(tgi_getxres(), text, 10);
	tgi_outtextxy(10, 10, text); 
	itoa(tgi_getyres(), text, 10);
	tgi_outtextxy(40, 10, text);
	// x,y position  y=0 is the top of the display, y=102 is the bottom
  	// x = 0 is the left of the display, 160 is the right	
	tgi_outtextxy(10, 20, "Max coor (x,y):");	
	// use tgi_gotoxy to move the current position to a particular point (x,y)
	tgi_gotoxy(10, 30);
	// tgi_outtext after that will place the text at that position and advance the current coordinate to the end of the text.
	tgi_outtext("(0x");
	itoa(tgi_getmaxx(), text, 16);
	tgi_outtext(text);
	tgi_outtext(",0x");
	//  itoa call that converts an integer value to a string value based on the radix
	itoa(tgi_getmaxy(), text, 16);
	tgi_outtext(text);
	tgi_outtext(")");
 
	// display is updated
	// tgi_updatedisplay function is a Lynx-only  
  	tgi_updatedisplay();
}

// The entry point is the main function
void main(void)  {	
  	initialize();
	  
	// An infinite loop where we remain forever  
  	while (1)
  	{
    	if (!tgi_busy())
    	{
      		show_screen();
    	}
  	};
}