
/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE ** WORK TO
CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR ** OR GRADERS
OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE ** OHIO STATE UNIVERSITY'S
ACADEMIC INTEGRITY POLICY. */

#include <stdio.h>

int main()
{

	//get string to encode
	char text[200];
	int l = 0;
	int c;
        #ifdef PROMPT 
	printf("enter a string to encode: ");
        #endif
	// preforms getchar on each char and prints Hexa deciaml
	while((c = getchar()) != '\n' && l <200) {
		text[l] = (char)c;
	        #ifdef PROMPT 
		if (l == 0)
			printf("string read as hexadecimal\n");
	       
		printf("%02x ", text[l]);
		if ( (l+ 1) % 10 == 0)
			printf("\n");
	        #endif
		l++;
	}
        #ifdef PROMPT 
	printf("\nstring read was : %s\n", text);
        #endif


	//get bit pattern for encode
	char keyPattern[8];
        #ifdef PROMPT 
	printf("enter a 4 digit binary number for encoding: ");
        #endif
	// using getchar it grabs the first 4 digits, also adds to 4 places ahead for 8-bit key
	for(int i = 0; i < 4; i++) {
		keyPattern[i] = getchar();
		keyPattern[i + 4] =keyPattern[i];
	}


	char Cipher[200]= {0};
	unsigned char Key = 0;
	unsigned char ONE = 1;
	// provided code for getting key
	for (int i = 0; i<8; i++) {
		if(keyPattern[i] == '1') {
			Key = Key | ONE;
		}
		if(i != 7) {
			Key = Key << 1;
		}
	}
        //provided code for cipher, preforms XOR for each Char in text with Key
	#ifdef PROMPT
	printf("hex Chipher\n");
	#endif
	
	for (int i = 0; i < l; i++) {
		Cipher[i] = text[i]^Key;

		printf("%02x ", Cipher[i]);
		if((i + 1) % 10 == 0)
			printf("\n");
	}
	
	printf("\n");

}
