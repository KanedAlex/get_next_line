42 Paris project - Get Next Line

Parsing of given file director(s) function.

Goal :	give us a better understanding of statics and file descriptors behavior
		have a basic parsing function to use in the next projects

Behavior : reads the fd sent in the first parameter, return 1 if it finds '\n' in the file with the correcponding line 
			allocated into the second parameter.

Bonuses : 	- handles multiple fd simultaneously (thanks to chained lists)
			- uses only one static variable
