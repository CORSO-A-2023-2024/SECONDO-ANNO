#include <assert.h> 	// Diagnostics Functions
1.Diagnostics functions:
		assert 	Assert Truth of Expression (macro)
#include <ctype.h> 	// Character Handling Functions
1.Character Testing functions:
		isalnum 	Test for Alphanumeric
		isalpha 	Test for Alphabetic
		iscntrl 	Test for Control Character
		isdigit 	Test for Digit
		isgraph 	Test for Graphical Character (does not include a space)
		islower 	Test for Lowercase Letter
		isprint 	Test for Printing Character (does include a space)
		ispunct 	Test for Punctuation Character
		isspace 	Test for White-Space Character
		isupper 	Test for Uppercase Letter
		isxdigit 	Test for Hexadecimal Digit
2.Character Case-Mapping functions:
		tolower 	Convert to Lowercase
		toupper 	Convert to Uppercase
#include  <locale.h> 	// Localization Functions
1.Localization functions:
		localeconv 	Get Locale Conventions
		setlocale 	Set Locale
#include  <math.h> 	// Mathematics Functions
1.Absolute Value functions: 
		fabs 	Absolute Value of Floating-Point Number
2.Nearest Integer, Absolute Value, and Remainder functions:
		ceil 	Ceiling
		floor 	Floor
		fmod 	Floating Modulus
3.Exponential and Logarithmic functions:
		exp 	Exponential
		frexp 	Split into Fraction and Exponent
		ldexp 	Combine Fraction and Exponent
		log 	Natural Logarithm
		log10 	Common Logarithm
		modf 	Split into Integer and Fractional Parts
4.Power functions:
		pow 	Power
		sqrt 	Square Root
5.Trigonometric functions:
		acos 	Arc Cosine
		asin 	Arc Sine
		atan 	Arc Tangent
		atan2 	Arc Tangent of Quotient
		cos 	Cosine
		sin 	Sine
6.Hyperbolic functions:
		cosh 	Hyperbolic Cosine
		sinh 	Hyperbolic Sine
		tanh 	Hyperbolic Tangent
#include  <setjmp.h> 	// Nonlocal Jump Functions
1.Nonlocal Jump functions:
		longjmp 	Nonlocal Jump
		setjmp 	Prepare for Nonlocal Jump
#include <signal.h> 	// Signal Handling Functions
1.Signal Handling functions:
		raise 	Raise Signal
		signal 	Install Signal Handler
#include <stdarg.h> 	// Variable Argument List Functions
1.Variable Argument List functions
		va_arg 	Fetch Argument from Variable Argument List
		va_end 	End Processing of Variable Argument List
		va_start 	Start Processing of Variable Argument List
#include <stdio.h> 	// Input/Output Functions
1.Formatted Input/Output functions:
		fprintf 	Formatted File Write
		fscanf 	Formatted File Read
		printf 	Formatted Write
		scanf 	Formatted Read
		sprintf 	Formatted String Write
		sscanf 	Formatted String Read
		vfprintf 	Formatted File Write Using Variable Argument List
		vprintf 	Formatted Write Using Variable Argument List
		vsprintf 	Formatted String Write Using Variable Argument List
2.File Operation functions:
		fclose 	Close File
		fflush 	Flush File Buffer
		fopen 	Open File
		freopen 	Reopen File
		remove 	Remove File
		rename 	Rename File
		setbuf 	Set Buffer (obsolete)
		setvbuf 	Set Buffer
		tmpfile 	Create Temporary File
		tmpnam 	Generate Temporary File Name
3.Character Input/Output functions:
		fgetc 	Read Character from File
		fgets 	Read String from File
		fputc 	Write Character to File
		fputs 	Write String to File
		getc 	Read Characters from File
		getchar 	Read Character
		gets 	Read String
		putc 	Write Character to File
		putchar 	Write Character
		puts 	Write String
		ungetc 	Unread Character
4.Block Input/Output functions:
		fread 	Read Block from File
		fwrite 	Write Block to File
5.File Positioning functions:
		fgetpos 	Get File Position
		fseek 	File Seek
		fsetpos 	Set File Position
		ftell 	Determine File Position
		rewind 	Rewind File
5.Error Handling functions:
		clearerr 	Clear Stream Error
		feof 	Test for End-of-File
		ferror 	Test for File Error
		perror 	Print Error Message
#include <stdlib.h> 	// General Utility Functions
1.Communication with the Environment functions:
		abort 	Abort Program
		atexit 	Register Function to be Called at Program Exit
		exit 	Exit from Program
		getenv 	Get Environment String
		system 	Perform Operating System Command
2.Integer Arithmetic functions:
		abs 	Absolute Value of Integer
		div 	Integer Division
		labs 	Absolute Value of Long Integer
		ldiv 	Long Integer Division
3.Pseudo-Random Sequence Generation functions:
		rand 	Generate Pseudo-Random Number
		srand 	Seed Pseudo-Random Number Generator
4.String Conversion functions:
		atof 	Convert String to Floating-Point
		atoi 	Convert String to Integer
		atol 	Convert String to Long Integer
		strtod 	Convert String to Double
		strtol 	Convert String to Long Integer
		strtoll 	Convert String to Long Long
		strtoul 	Convert String to Unsigned Long Integer
5.Searching and Sorting functions:
		bsearch 	Binary Search
		qsort 	Sort Array
6.Dynamically Allocated Array functions:
		calloc 	Allocate and Clear Memory Block
		malloc 	Allocate Memory Block
		realloc 	Resize Memory Block
7.Deallocating Storage functions:
		free 	Free Memory Block
8.Multibyte Character functions:
		mblen 	Compute Length of Multibyte Character
		mbtowc 	Convert Multibyte Character to Wide Character
		wctomb 	Convert Wide Character to Multibyte Character
9.Multibyte String functions:
		mbstowcs 	Convert Multibyte String to Wide Character String
		wcstombs 	Convert Wide Character String to Multibyte String
#include <string.h> 	// String Functions
1.Comparison functions:
		memcmp 	Compare Memory Blocks
		strcmp 	String Compare
		strcoll 	String Compare Using Locale-Specific Collating Sequence
		strncmp 	Bounded String Compare
		strxfrm 	Transform Locale-Specific String
2.Concatenation functions:
		strcat 	String Concatenation
		strncat 	Bounded String Concatenation
3.Copying functions:
		memcpy 	Copy Memory Block
		memmove 	Copy Memory Block
		strcpy 	String Copy
		strncpy 	Bounded String Copy
4.Search functions:
		memchr 	Search Memory Block for Character
		strchr 	Search String for Character
		strcspn 	Search String for Intial Span of Characters Not in Set
		strpbrk 	Search String for One of a Set of Characters
		strrchr 	Search String in Reverse for Character
		strspn 	Search String for Initial Span of Characters in Set
		strstr 	Search String for Substring
		strtok 	Search String for Token
		Miscellaneous functions
		memset 	Initialize Memory Block
		strerror 	Convert Error Number to String
		strlen 	String Length
#include <time.h> 	// Date and Time Functions
1.Time Conversion functions:
		asctime 	Convert Date and Time to ASCII
		ctime 	Convert Date and Time to String
		gmtime 	Convert to Greenwich Mean Time
		localtime 	Convert to Local Time
		mktime 	Convert to Calendar Time
		strftime 	Write Formatted Date and Time to String
2.Time Manipulation functions:
		clock 	Processor Clock
		difftime 	Time Difference
		time 	Current Time
