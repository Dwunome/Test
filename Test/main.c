#include <stdio.h>
// str�ngar har automatiskt inbyggda pekare. beh�ver ej ha & tecken, o pekare.
// Vill man �nd� anv�nda & tecken f�r o skicka adressen, s� m�ste man anv�nda dubbelpekare till variabeln
	// men ints har detta ej per default. d�rf�r m�ste man skicka adress via & operand till variabeln
// Str�ngar �r undantag f�r pekare. 
// Str�ng �r en beh�llare f�r text, medan text �r inneh�llet i str�ngen.
#define SIZE 100

static size_t length(const char* s)		// Returnerar antalet tecken i str�ngen (r�knar ej nolltecken)
{
	register size_t i;	// M�ste deklarera variabeln i h�r uppe, r�cker ej att skapa den direkt i for satsen 
	// Alla variabler som deklareras i en sats, �berlever bara inne i satsen, ej synlig utanf�r.
	// I for satsen anv�nds nu variabeln i. men skriver ej register framf�r, f�r d� sparas den bara i for loopen o d�r efter loop.
	for (i = 0; s[i] != '\0'; i++);		// S�l�nge S index y (s[y]] ej �r ett nolltecken itereras str�ngen y.
	return i;
}
	//exempel: s1 inneh�ller inneh�ller "ela", s2 inneh�ller "�r b�st". dessa tv� sl�s ihop till en str�ngg/mening sen.
static void join(char* s1, const char* s2)	// S�tter samman tv� str�ngar.	(s1 = str�ngen vi ska lagra i, s2 = texten / vad som ska lagras.
{
	const size_t length1 = length(s1);	// variabeln a tilldelas v�rdet fr�n funktionen length med ing�ende argument s1
	const size_t length2 = length(s2);
	const size_t new_length = length1 + length2;	// s�tter ihop s1 o s2 till en mening (ber�knar ny l�ngd efter sammans�ttning.

	for (register size_t i = 0; s2[i] != '\0'; i++)		// I for satsen, anv�nd size_t eller unsigned int som datatyp
		s1[length1 + i] = s2[i];			//length 1 som �r ela r�knas upp till ela's \0 tecken, d�refter plussas i p�, som �r
	s1[new_length] = '\0';					// den andra texten man vill s�tta ihop. l�ggs ihop efter length2 mha +1
	return;									// s� skrivs inte length 1 �ver, bara dess 0 tecken
}

//*s1 = [ E | L | A |'\0']	= 4 indexplatser
//*s2 ? [ 2 | 1 | '\0']	= 3 indexplatser
// new_length Dessa l�s ihop till [ E | L | A | 2 | 1 | '\0'] = 6 indexplatser.

static inline void print(const char* s)
{
	//for (register size_t i = 0; s[i] != '\0'; i++)	// Skriver ut 1 tecken i taget. Anv�nder formatspecificerare %c f�r o skriva 
														// ut 1 tecken i taget
		printf("%s\n", s);	// Skriver ut inneh�ll tills 0-tecken n�s. Printf har inbyggd '\0'
	return;
}

int main(void)
{
	char s[SIZE];	// lagras p� stacken. som de globala variablerna g�r.
	s[0] = '\0';
	join(s, "Hello there!\n");		// L�gger till text och lagrar i str�ngvariabeln s 
	join(s, "The function names are poorly chosen this time around!\n");
	join(s, "What do you think?\n");
	print(s);
	return 0;
}

// size_t	=	unsigned int	=	uint64_t