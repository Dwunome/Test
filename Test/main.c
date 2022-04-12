#include <stdio.h>
// strängar har automatiskt inbyggda pekare. behöver ej ha & tecken, o pekare.
// Vill man ändå använda & tecken för o skicka adressen, så måste man använda dubbelpekare till variabeln
	// men ints har detta ej per default. därför måste man skicka adress via & operand till variabeln
// Strängar är undantag för pekare. 
// Sträng är en behållare för text, medan text är innehållet i strängen.
#define SIZE 100

static size_t length(const char* s)		// Returnerar antalet tecken i strängen (räknar ej nolltecken)
{
	register size_t i;	// Måste deklarera variabeln i här uppe, räcker ej att skapa den direkt i for satsen 
	// Alla variabler som deklareras i en sats, öberlever bara inne i satsen, ej synlig utanför.
	// I for satsen används nu variabeln i. men skriver ej register framför, för då sparas den bara i for loopen o dör efter loop.
	for (i = 0; s[i] != '\0'; i++);		// Sålänge S index y (s[y]] ej är ett nolltecken itereras strängen y.
	return i;
}
	//exempel: s1 innehåller innehåller "ela", s2 innehåller "är bäst". dessa två slås ihop till en strängg/mening sen.
static void join(char* s1, const char* s2)	// Sätter samman två strängar.	(s1 = strängen vi ska lagra i, s2 = texten / vad som ska lagras.
{
	const size_t length1 = length(s1);	// variabeln a tilldelas värdet från funktionen length med ingående argument s1
	const size_t length2 = length(s2);
	const size_t new_length = length1 + length2;	// sätter ihop s1 o s2 till en mening (beräknar ny längd efter sammansättning.

	for (register size_t i = 0; s2[i] != '\0'; i++)		// I for satsen, använd size_t eller unsigned int som datatyp
		s1[length1 + i] = s2[i];			//length 1 som är ela räknas upp till ela's \0 tecken, därefter plussas i på, som är
	s1[new_length] = '\0';					// den andra texten man vill sätta ihop. läggs ihop efter length2 mha +1
	return;									// så skrivs inte length 1 över, bara dess 0 tecken
}

//*s1 = [ E | L | A |'\0']	= 4 indexplatser
//*s2 ? [ 2 | 1 | '\0']	= 3 indexplatser
// new_length Dessa lås ihop till [ E | L | A | 2 | 1 | '\0'] = 6 indexplatser.

static inline void print(const char* s)
{
	//for (register size_t i = 0; s[i] != '\0'; i++)	// Skriver ut 1 tecken i taget. Använder formatspecificerare %c för o skriva 
														// ut 1 tecken i taget
		printf("%s\n", s);	// Skriver ut innehåll tills 0-tecken nås. Printf har inbyggd '\0'
	return;
}

int main(void)
{
	char s[SIZE];	// lagras på stacken. som de globala variablerna gör.
	s[0] = '\0';
	join(s, "Hello there!\n");		// Lägger till text och lagrar i strängvariabeln s 
	join(s, "The function names are poorly chosen this time around!\n");
	join(s, "What do you think?\n");
	print(s);
	return 0;
}

// size_t	=	unsigned int	=	uint64_t