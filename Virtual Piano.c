#include <windows.h>
#include <math.h>
#include <stdio.h>

/* self-referential structure */
struct stackNode 
{
	char data; /* define data as a char */
	struct stackNode *nextPtr; /* stackNode pointer */
}; 
/* end structure stackNode */

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// GLOBAL DECLARATION VARIABLE
int a=0;  //Transpose var
char rec = 'a';  //compare char record
char sentinel = '0'; //compare parameter
StackNodePtr headPtr = NULL; /* initialize headPtr */
StackNodePtr tailPtr = NULL; /* initialize tailPtr */

/* function prototypes */
void enqueue( StackNodePtr *headPtr, StackNodePtr *tailPtr, char value );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr currentPtr );
char play (StackNodePtr *headPtr, StackNodePtr *tailPtr);
void play_note (char char_pass);

//BLOK UI MAIN MENU
void menu ()
{
	printf ("___________________________________________________\n");
	printf ("|                                                 |\n");
	printf ("|                                                 |\n");
	printf ("|================= Virtual Piano =================|\n");
	printf ("|                                                 |\n");
	printf ("|                                                 |\n");
	printf ("|                                                 |\n");
	printf ("|               >1. Start                         |\n");
	printf ("|               >2. Transpose                     |\n");
	printf ("|               >3. Record                        |\n");
	printf ("|               >4. Help                          |\n");
	printf ("|               >5. Exit                          |\n");
	printf ("|_________________________________________________|\n\n");
}

//BLOK HELP
int help () {
	
	printf ("___________________________________________________\n");
	printf ("|                                                 |\n");
	printf ("|                                                 |\n");
	printf ("|================= Virtual Piano =================|\n");
	printf ("|                                                 |\n");
	printf ("|                                                 |\n");
	printf ("|_________________________________________________|\n\n");
	printf ("> Program ini berfungsi sebagai piano pada umumnya dengan keyboard PC/laptop sebagai tuts pada piano.\n");
	printf ("> Untuk memainkan, cukup tekan tombol sesuai dengan ketentuan. Bunyi nada akan langsung keluar.\n");
	printf ("> Ketika sedang bermain, tekan '=' untuk kembali ke main menu.\n");
	printf ("> Menu transpose berfungsi untuk menaikkan dan menurunkan nada.\n");
	printf ("> Masukkan angka sesuai ketentuan yang diberikan.\n");
	printf ("> Menu record berfungsi untuk merekam not yang diinput dan dimainkan secara sekuensial.\n");
	printf ("> Untuk record, masukkan not yang diinginkan dan masukkan '0' untuk play.\n");
	printf ("> Untuk baris bawah (input z sampai ',') input lowercase untuk turun satu oktaf.\n");
	printf ("> Untuk baris atas (input q sampai i) input lowercase untuk naik satu oktaf.\n");
	printf ("> Untuk menambahkan delay antar not, masukkan salah satu dari karakter berikut: \n");
	printf ("1, 4, 8, 9, o, p, a, f, k, l, '.', '/', ';', '[', ']', '-', '='(tidak case sensitive).\n");
	printf ("\n\n<Tekan 1 untuk kembali ke main menu>");
a38 :switch (getch ()){
		
		case '1' :
			system ("cls");
			main ();
		break;
			
		default :
			printf ("\nInput salah!");
			goto a38;
		break;
	}
	
}



// BLOK SWITCH CASE MAIN MENU
int main (){	

	
	int note[88], count=1;
	double c,n,frq ;
	for (n=0;n<88;n++,count++)
	{
		c = pow(2,((n-49)/12));
		frq = c * 440;
		note[count] = frq;
	}
	
	int play_count = 0; // how many loop --until note played stop-- in record mode
	
	menu ();
	
a68 :switch (getch ()) {
	
	case '1' :
	system ("cls");
	printf (">                                     <Play>                                              <\n");
	printf ("___________________________________________________________________________________________\n");
	printf ("|   |   | |   |   |   |   | |   | |   |   |   |   | |   |   |   |   | |   | |   |   |     |\n");
	printf ("|   | S | | D |   |   | G | | H | | J |   |   | 2 | | 3 |   |   | 5 | | 6 | | 7 |   |     |\n");
	printf ("|   |___| |___|   |   |___| |___| |___|   |   |___| |___|   |   |___| |___| |___|   |     |\n");
	printf ("|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf ("|  Z  |  X  |  C  |  V  |  B  |  N  |  M  | ,/Q |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |\n");
	printf ("|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");	
	printf ("\n<Press = to go back>");
a80:switch (getch ())
	{
		case 'z' :
		case 'Z' :
			Beep (note[39+a], 50);
		goto a80;
		break;
		
		case 's' :
		case 'S' :
			Beep (note[40+a], 50);
		goto a80;
		break;
		
		case 'x' :
		case 'X' :
			Beep (note[41+a], 50);
		goto a80;
		break;
		
		case 'd' :
		case 'D' :
			Beep (note[42+a], 50);
		goto a80;
		break;
		
		case 'c' :
		case 'C' :
			Beep (note[43+a], 50);
		goto a80;
		break;
		
		case 'v' :
		case 'V' :
			Beep (note[44+a], 50);
		goto a80;
		break;
		
		case 'g' :
		case 'G' :
			Beep (note[45+a], 50);
		goto a80;
		break;
		
		case 'b' :
		case 'B' :
			Beep (note[46+a], 50);
		goto a80;
		break;
		
		case 'h' :
		case 'H' :
			Beep (note[47+a], 50);
		goto a80;
		break;
		
		case 'n' :
		case 'N' :
			Beep (note[48+a], 50);
		goto a80;
		break;
		
		case 'j' :
		case 'J' :
			Beep (note[49+a], 50);
		goto a80;
		break;
		
		case 'm' :
		case 'M' :
			Beep (note[50+a], 50);
		goto a80;
		break;
		
		case ',' :
			Beep (note[51+a], 50);
		goto a80;
		break;
		
		case 'q' :
		case 'Q' :
			Beep (note[51+a], 50);
		goto a80;
		break;
		
		case '2' :
			Beep (note[52+a], 50);
		goto a80;
		break;
		
		case 'w' :
		case 'W' :
			Beep (note[53+a], 50);
		goto a80;
		
		case '3' :
			Beep (note[54+a], 50);
		goto a80;
		break;
		
		case 'e' :
		case 'E' :
			Beep (note[55+a], 50);
		goto a80;
		break;
		
		case 'r' :
		case 'R' :
			Beep (note[56+a], 50);
		goto a80;
		break;
		
		case '5' :
			Beep (note[57+a], 50);
		goto a80;
		break;
		
		case 't' :
		case 'T' :
			Beep (note[58+a], 50);
		goto a80;
		break;
		
		case '6' :
			Beep (note[59+a], 50);
		goto a80;
		break;
		
		case 'y' :
		case 'Y' :
			Beep (note[60+a], 50);
		goto a80;
		break;
		
		case '7' :
			Beep (note[61+a], 50);
		goto a80;
		break;
		
		case 'u' :
		case 'U' :
			Beep (note[62+a], 50);
		goto a80;
		break;
		
		case 'i' :
		case 'I' :
			Beep (note[63+a], 50);
		goto a80;
		break;
		
		case '=' :
		system("Cls"); 
		menu ();
		goto a68;
		break;
		
		default :
			goto a80;
		break;
	}
	
	case '2' :
		system ("cls");
		
		printf ("Masukan angka antara -39 dan 24 : ");
		scanf ("%d", &a);
		while (a<=-40 || a>=25)
			{
				printf ("Angka yang anda masukan tidak memenuhi kriteria, silahkan masukan kembali : ");
				scanf("%d", &a);
			}
			
		system ("Cls");
		main ();
	break;
	

	case '3' :
		
		system ("cls");
a307:	printf (">                                   <Record>                                              <\n");
		printf ("___________________________________________________________________________________________\n");
		printf ("|   |   | |   |   |   |   | |   | |   |   |   |   | |   |   |   |   | |   | |   |   |     | Do = C4\n");
		printf ("|   | S | | D |   |   | G | | H | | J |   |   | 2 | | 3 |   |   | 5 | | 6 | | 7 |   |     |\n");
		printf ("|   |___| |___|   |   |___| |___| |___|   |   |___| |___|   |   |___| |___| |___|   |     |\n");
		printf ("|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
		printf ("|  Z  |  X  |  C  |  V  |  B  |  N  |  M  | ,/Q |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |\n");
		printf ("|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
		
		
			
		while (rec != sentinel)
				 
		{
			scanf ("\n%c", &rec);
			play_count ++;
			system ("cls");
			printf (">                                   <Record>                                              <\n");
			printf ("___________________________________________________________________________________________\n");
			printf ("|   |   | |   |   |   |   | |   | |   |   |   |   | |   |   |   |   | |   | |   |   |     | Do = C4\n");
			printf ("|   | S | | D |   |   | G | | H | | J |   |   | 2 | | 3 |   |   | 5 | | 6 | | 7 |   |     |\n");
			printf ("|   |___| |___|   |   |___| |___| |___|   |   |___| |___|   |   |___| |___| |___|   |     |\n");
			printf ("|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
			printf ("|  Z  |  X  |  C  |  V  |  B  |  N  |  M  | ,/Q |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |\n");
			printf ("|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
			
			enqueue (&headPtr , &tailPtr , rec); //queue the inserted note
   			printStack( headPtr ); //print the inserted note
		}
		
		printf ("\n");
		
		while (play_count > 1)
		{
			if (!isEmpty (headPtr))
			{
				rec = play (&headPtr, &tailPtr);  //dequeue algorithm modified
				play_note (rec);
				printf ("%c", rec);
				Sleep (100);
			}
			play_count--;
		}
		
		
		printf ("\n\n>Tekan 1 untuk kembali ke main menu.");
		printf ("\n>Tekan 2 untuk record lagi.\n");
a335:	switch (getch ())
		{
		
		case '1' :
			system ("cls");
			rec = 'a';
			main ();
		break;
		
		case '2' :
			system ("Cls");
			rec = 'a';
			goto a307;
		break;
		
		default :
			printf ("\nInput salah!");
			goto a335;
		break;
		}
		
	break;
		
	case '4' :
		system ("cls");
		help ();
	break;
	
	case '5' :
		system ("cls");
		printf ("Program berhenti.\n");
		printf ("Terima kasih telah menggunakan program ini.");
		getch ();
		return 0;
	break;
			
	default :
		printf ("\nInput salah!");
		goto a68;
	break;
	}
}
	
void enqueue( StackNodePtr *headPtr, StackNodePtr *tailPtr, char value )
{
	StackNodePtr newPtr; /* pointer to new node */
 	newPtr = malloc( sizeof( StackNode ) );
 	if ( newPtr != NULL ) 
 	{ /* is space available */
//  	strcpy (newPtr->data, value);
		newPtr->data = value;
	  	newPtr->nextPtr = NULL;
		if ( isEmpty( *headPtr ) ) 
		{
   			*headPtr = newPtr;
  		}
  		else 
		{
   			( *tailPtr )->nextPtr = newPtr;
  		}
	*tailPtr = newPtr;
 	}
 	
 	else 
 	{
  		printf( "%c not inserted. No memory available.\n", value );
 	} 
} 

char play (StackNodePtr *headPtr, StackNodePtr *tailPtr)
{
	char value;
	StackNodePtr tempPtr;
	
	value = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;
	
	if (*headPtr == NULL)
	{
		*tailPtr = NULL;
	}
	free (tempPtr);
	
	return value;
}

void play_note (char char_pass)
{
	int note[88], count=1;
	double c,n,frq ;
	for (n=0;n<88;n++,count++)
	{
		c = pow(2,((n-49)/12));
		frq = c * 440;
		note[count] = frq;
	}
	
	switch (char_pass)
	{
		case 'z' :
			Beep (note[39-12], 100);
		break;
		
		case 'Z' :
			Beep (note[39], 100);
		break;	
	
		case 's' :
			Beep (note[40-12], 100);
		break;
		
		case 'S' :
			Beep (note[40], 100);
		break;
		
		case 'x' :
			Beep (note[41-12], 100);
		break;
		
		case 'X' :
			Beep (note[41], 100);
		break;
		
		case 'd' :
			Beep (note[42-12], 100);
		break;
		
		case 'D' :
			Beep (note[42], 100);
		break;
		
		case 'c' :
			Beep (note[43-12], 100);
		break;
		
		case 'C' :
			Beep (note[43], 100);
		break;
		
		case 'v' :
			Beep (note[44-12], 100);
		break;
		
		case 'V' :
			Beep (note[44], 100);
		break;
		
		case 'g' :
			Beep (note[45-12], 100);
		break;
		
		case 'G' :
			Beep (note[45], 100);
		break;
		
		case 'b' :
			Beep (note[46-12], 100);
		break;
		
		case 'B' :
			Beep (note[46], 100);
		break;
		
		case 'h' :
			Beep (note[47-12], 100);
		break;
		
		case 'H' :
			Beep (note[47], 100);
		break;
		
		case 'n' :
			Beep (note[48-12], 100);
		break;
			
		case 'N' :
			Beep (note[48], 100);
		break;
		
		case 'j' :
			Beep (note[49-12], 100);
		break;
		
		case 'J' :
			Beep (note[49], 100);
		break;
		
		case 'm' :
			Beep (note[50-12], 100);
		break;
		
		case 'M' :
			Beep (note[50], 100);
		break;
		
		case ',' :
			Beep (note[51+12], 100);
		break;
		
		case '<':
			Beep (note[51], 100);
		break;
		
		case 'q' :
			Beep (note[51+12], 100);
		break;
		
		case 'Q' :
			Beep (note[51], 100);
		break;
		
		case '2' :
			Beep (note[52+12], 100);
		break;
		
		case '@':
			Beep (note[52], 100);
		break;
		
		case 'w' :
			Beep (note[53+12], 100);
		break;
		
		case 'W' :
			Beep (note[53], 100);
		break;
		
		case '3' :
			Beep (note[54], 100);
		break;
		
		case 'e' :
			Beep (note[55+12], 100);
		break;
		
		case 'E' :
			Beep (note[55], 100);
		break;
		
		case 'r' :
			Beep (note[56+12], 100);
		break;
		
		case 'R' :
			Beep (note[56], 100);
		break;
		
		case '5' :
			Beep (note[57+12], 100);
		break;
		
		case '%':
			Beep (note[57+12], 100);
		break;
		
		case 't' :
			Beep (note[58+12], 100);
		break;
		
		case 'T' :
			Beep (note[58], 100);
		break;
		
		case '6' :
			Beep (note[59+12], 100);
		break;
		
		case '^':
			Beep (note[59], 100);
		break;
		
		case 'y' :
			Beep (note[60+12], 100);
		break;
		
		case 'Y' :
			Beep (note[60], 100);
		break;
		
		case '7' :
			Beep (note[61+12], 100);
		break;
		
		case '&':
			Beep (note[61], 100);
		break;
		
		case 'u' :
			Beep (note[62+12], 100);
		break;
		
		case 'U' :
			Beep (note[62], 100);
		break;
		
		case 'i' :
			Beep (note[63+12], 100);
		break;
		
		case 'I' :
			Beep (note[63], 100);
		break;
		
		case '`':
		case '1':
		case '4':
		case '8':
		case '9':
		case 'o':
		case 'O':
		case 'p':
		case 'P':
		case 'a':
		case 'A':
		case 'f':
		case 'F':
		case 'k':
		case 'K':
		case 'l':
		case 'L':
		case '.':
		case '/':
		case ';':
		case '-':
		case '=':
		case '[':
		case ']':
			Sleep (100);
		break;
	}
}

int isEmpty( StackNodePtr topPtr )
{
	return topPtr == NULL;
} /* end function isEmpty */

void printStack( StackNodePtr currentPtr )
{
	if ( currentPtr == NULL ) 
 	{
  		printf( "Stack is empty.\n\n" );
 	}
 	else 
 	{
  		while ( currentPtr != NULL ) 
  		{
   			printf( "%c > ", currentPtr->data );
   			currentPtr = currentPtr->nextPtr;
  		}
	} /* end else */
} /* end function printStack */
