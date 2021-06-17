#include <stdio.h> 
#include <pwd.h> 
#include <unistd.h>

int main() { 
	struct passwd *pass; 
	pass = getpwuid(getuid()); 
	printf("This is the login name: %s\n", pass->pw_name); 
	printf("This is the login home: %s\n", pass->pw_dir); 
	return 0; 
} 
