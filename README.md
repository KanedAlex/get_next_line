# 42 Paris project - Get Next Line

<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl4cq9w7c004409k3asnbj82v/project/1607718" alt="alienard's 42 get_next_line Score" /></a>

# Subject :
Parsing of given file director(s) function.

# Goals :	
- give us a better understanding of statics and file descriptors behavior
- have a basic parsing function to use in the next projects

# Behavior : 
- reads the fd sent in the first parameter
- returns 1 if it finds '\n' in the file with the corresponding line allocated into the second parameter
- returns 0 if EOF
- returns -1 if error

# Bonuses : 	
- handles multiple fd simultaneously (thanks to linked lists)
- uses only one static variable
