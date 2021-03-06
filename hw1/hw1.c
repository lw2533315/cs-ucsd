/****************************************************************************

                                             Your name Lei Wan
                                             Course name, quarter cse12 fa16
                                             Today's date 9/23/2016
                                                        Your cs12x login
                                Assignment One

File Name:      hw1.c
Description:    This program tests functions to display output strings and 
                numbers. 
****************************************************************************/
#include <stdio.h>

#define COUNT 16	/* number of hex digits to display */
#define DECIMAL 10	/* to indicate base 10 */
#define HEX 16		/* to indicate base 16 */
long writeline(const char*message,FILE*stream);
/* array used for ASCII conversion */
const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
Function Name:         baseout
Purpose:               use base16 print out
Description:           print a base 16 number by char
Input:                 number is base 16 number
Result:                print number on base16, no return
--------------------------------------------------------------------------*/
void baseout (long number, long base, FILE * stream) {
	/* YOUR CODE GOES HERE */
	char num[BUFSIZ]; //store the digits of base 16 number
	int count=0;  //recorder the number of element in array
	while(number%16!=0){   //transfer base10 to base16
		int mod=(int)number%16;
		num[count++]=digits[mod];
		number=number/16;
	}
	int index;//loop count
	for(index=count; index<COUNT; index++){//fill the enough digits
		num[index]='0';
	}
	for( index=COUNT-1;index>=0;index--){
	        fputc(num[index],stream);
	}
}


/*--------------------------------------------------------------------------
Function Name:         decout
Purpose:               print out number by digits
Description:           use a array store the number and print it out
Input:                 number is long positive number
Result:                print number by char,no return
--------------------------------------------------------------------------*/
void decout (unsigned long number, FILE * stream) {
	/* YOUR CODE GOES HERE */
	char num[BUFSIZ];//store the digits of number
	int count=0;    //count the  element in the array
	if(number==0){//deal with special situation
		fputc('0',stream);
	}else{
	        while(number%10){//separate the number to digits
			num[count++]=number%10;
			number=number/10;
		}
		int index;
		for( index=count-1;index>=0;index--){
			fputc(num[index]+48,stream);
		}
	}
	
}


/*--------------------------------------------------------------------------
Function Name:         hexout
Purpose:               Prints a number in base 16 to the parameter FILE stream
Description:           Goal is achieved via delegating to the baseout function
Input:                 number:  the number to display
                       stream:  where to display, likely stdout or stderr
Result:                Number in base 16 is displayed.
                       No return value.
--------------------------------------------------------------------------*/
void hexout (unsigned long number, FILE * stream) {

	/* Output "0x" for hexidecimal. */
	writeline ("0x", stream);
	baseout (number, HEX, stream);
}


/*--------------------------------------------------------------------------
Function Name:         newline.
Purpose:               to a new line.
Description:           to a newline
Input:                 none
Result:                to a nuewline, no return 
--------------------------------------------------------------------------*/
void newline (FILE * stream) {
	/* YOUR CODE GOES HERE */
	fputc('\n',stream);
}


/*--------------------------------------------------------------------------
Function Name:         writeline.
Purpose:               print outa line message.
Description:           print out a line message by char
Input:                 message is array
Result:                print out a line message by char
                       return the length of message
--------------------------------------------------------------------------*/
long writeline (const char * message, FILE * stream) {
	/* YOUR CODE GOES HERE */
	int count=0;//the length of message
	while(message[count]!='\0'){
		fputc(message[count],stream);
		count++;
	}
	return count;
}


int main (int argc, char *const* argv) {
        writeline ("Hello World", stdout);
        fprintf (stderr, "Barev Ashkharh\n");
	newline(stdout);
	decout (123, stdout);
	newline(stdout);
	decout (0, stdout);
	newline(stdout);
	hexout (0xFEEDDAD, stdout);
	newline(stdout);
	return 0;
}



