#ifdef DEMO
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static long CalculateCheckSum(long n)
{
	long s, d1, d2, d3, d4;
	
	s = n + 247;
	
	d1 = (s % 10)/1;
	d2 = (s % 100)/10;
	d3 = (s % 1000)/100;
	d4 = (s % 10000)/1000;
	
	s = d3*1000 + d1*100 + d2*10 + d4;
	
	s = s * 5;
	
	s = s - n * 3;
	
	if (s < 0) s = -s;
	
	s = s % 10000;
	
	return s;
}

/*
unix
~/.als_prolog_demo_key

mac 

preferences: ALS Prolog Demo Key

win

whever: ALS Prolog Demo Key
registery?

locate_demo_key

int demo_key_info_exists(void)
{
	return access(
}

*/

#ifdef macintosh

FSSpec DemoFileSpec;

static void init_demo_key_info(void)
{
	OSErr err;
	short vref;
	long dirid;
	
	err = FindFolder(kOnSystemDisk, kPreferencesFolderType,
					 kDontCreateFolder, &vref, &dirid);
	if (err == noErr) {
		FSMakeFSSpec(vref, dirid, "\pALS Prolog Demo Key", &DemoFileSpec);
	}
}

static int demo_key_info_exists(void)
{
	FInfo info;
	return (FSpGetFInfo(&DemoFileSpec, &info) == noErr);
}

static void read_demo_key_info(char *key, int max)
{
	OSErr err;
	short f;
	long count;
	
	err = FSpOpenDF(&DemoFileSpec, fsRdPerm, &f);
	if (err == noErr) {
		count = max-1;
		err = FSRead(f, &count, key);
		if (err == noErr || err == eofErr) key[count] = 0;
		else key[0] = 0;
		FSClose(f);
	}	
}

static void write_demo_key_info(char *key)
{
	OSErr err;
	short f;
	long count;
	
	err = FSpCreate(&DemoFileSpec, '????', '????', smSystemScript);
	if (err == noErr) {
		err = FSpOpenDF(&DemoFileSpec, fsRdWrPerm, &f);
		if (err == noErr) {
			count = strlen(key);
			FSWrite(f, &count, key);
			FSClose(f);
		}
	}
}

static void delete_demo_key_info(void)
{
	OSErr err;
	err = FSpDelete(&DemoFileSpec);
}
#endif

static void console_get_demo_key(char *key, int max)
{
	fprintf(stdout, "\
ALS Prolog Evaluation System\n\
\n\
This evaluation copy requires a serial number key in order to run.\n\
If you do not have a key, please contact Applied Logic Systems to\n\
receive an evaluation key.\n\
\n\
Web    http://www.als.com\n\
E-Mail info@als.com\n\
Voice  +1 (617) 497-0100\n\
Fax    +1 (617) 497-3963\n\
Mail   Applied Logic Systems, Inc.\n\
       P.O. Box 175\n\
       Cambridge, MA 02140\n\
       USA\n\
\n\
");
	fprintf(stdout, "Please enter the evaluation key: ");
	fflush(stdout);
	fgets(key, max, stdin);
	fprintf(stdout, "\n");
}

static void console_demo_error(const char *s)
{
	fprintf(stderr, "%s\n", s);
	exit(EXIT_FAILURE);
}

void (*demo_error)(const char *s) = console_demo_error;
void (*get_demo_key)(char *key, int max) = console_get_demo_key;

#define KEY_MAX 40
#define KEY_DIGITS 16
static int valid_demo_key(char *key)
{
	int a,b,c,d;
	
	sscanf(key, "%d-%d-%d-%d", a, b, c, d);

	CalculateCheckSum
	if (d != calculat_checksum(a | b | c)) return 0;
	
	a = rotate(a);
	b = rotate(b);
	c = rotate(c);
	
	year = ;
	month = ;
	day = ;
	duration = ;
	
	check time 
}

void demo_check(void);
void demo_check(void)
{
	char key[KEY_MAX];
	int pass = false;
	
	init_demo_key_info();
	
	if (demo_key_info_exists()) {
		read_demo_key_info(key, KEY_MAX);
		if (!valid_demo_key(key)) {
			delete_demo_key_info();
			demo_error("The evaluation key has expired.");
		}
	} else {
		get_demo_key(key, KEY_MAX);
		if (!valid_demo_key(key)) {
			demo_error("Invalid evaluation key, Please re-enter.");
		}
		write_demo_key_info(key);
	}
}
#endif /* DEMO */