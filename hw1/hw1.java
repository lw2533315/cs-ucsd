/**
 * The hw1 class is a direct port of hw1.c to java.
 * As you already know in java when you pass literal strings like
 * <P>
 *   writeline("a literal string\n", stream);
 * <P>
 * in C is considered a char[], but in java it's automatically
 * converted and treated as a String object.  Therefore 
 * the function writeline accepts literal strings and 
 * String types.
 */

import java.io.*;      // System.out

public class hw1 {
	private static final long COUNT = 16;	// number of hex digits to display
	private static final long DECIMAL = 10;	// to indicate base 10
	private static final long HEX = 16;		// to indicate base 16

	private static final char digits[] = 	// used for ASCII conversion
		new String("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ").toCharArray();
	private static long hexCounter = 0; // counter for the number hex digits


	/**
	* Takes in a positive number and displays in a given base.
        *
        * @param    Numeric value to be displayed.
        * @param    Base to used to display number.
        * @param    Where to display, likely System.out or System.err.
        */
	private static void baseout (long number, long base, PrintStream stream) {
		// YOUR CODE GOES HERE
		String num=""; //empty String for save the ox number
		while(number%16!=0){//transfer frome base10 to base 16
			int mod=(int)number%16;
			num=digits[mod]+num;
			number=number/16;
		}
		int len=num.length();//get the length of number
		int index;//loop counter
		for(index=0;index<COUNT-len;index++){
			num="0"+num;
		}
		for(index=0;index<COUNT;index++){
			fputc(num.charAt(index),stream);
		}
	}


        /**
        * Takes in a positive number and displays it in decimal.
        *
        * @param    positive numeric value to be displayed.
        * @param    Where to display, likely System.out or System.err.
        */
	public static void decout (long number, PrintStream stream) {
		// YOUR CODE GOES HERE
		String num=String.valueOf(number); //from long to string
		int len=num.length();//get the length of number
		int index=0;//loop counter
		for(index=0;index<len;index++){
			fputc(num.charAt(index),stream);
		}
	}


        /**
        * Displays a single character.
        *
        * @param    Character to display.
        * @param    Where to display, likely System.out or System.err.
        */
        public static void fputc(char CharToDisp, PrintStream stream) {

                // Print a single character.
                stream.print (CharToDisp);   

                // Flush the system.out buffer, now. 
                stream.flush ();
        }


        /**
        * Takes in a positive number and displays it in hex.
        *
        * @param    A positive numeric value to be displayed in hex.
        * @param    Where to display, likely System.out or System.err.
        */
        public static void hexout (long number, PrintStream stream) {

                // Output "0x" for hexidecimal.
                writeline ("0x", stream);
                baseout (number, HEX, stream);
        }


        /**
        * Prints out a newline character.
        * @param    Where to display, likely System.out or System.err.
        *
        */
        public static void newline ( PrintStream stream ) {
		// YOUR CODE GOES HERE
	             fputc('\n',stream);	

        }



        /**
        * Prints out a string.
        *
        * @param    A string to print out.
        * @param    Where to display, likely System.out or System.err.
        * @return     <code>long</code> The length of the string.
        */
        public static long writeline (String message, PrintStream stream) {
		// YOUR CODE GOES HERE
		long len=message.length();//get the length of message
		int index=0;
		for( index=0;index<len;index++){
		fputc(message.charAt(index),stream);
		}
		return len;
        }

        
	public static void main( String[] args ) {

        	System.err.print ("Barev Ashkharh\n");
        	writeline ("Hello World", System.out);
		newline(System.out);
		decout (123, System.out);
		newline(System.out);
		decout (0, System.out);
		newline(System.out);
		hexout (0xFEEDDAD, System.out);
		newline(System.out);
	}
}
