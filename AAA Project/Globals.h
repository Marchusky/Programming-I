//Used to avoid the same header file being included multiple times in the same CPP file.
#ifndef __GLOBALS_H__
//We call a _FILE_H_ (any name is valid if it follows the mandatory spelling rules)
#define __GLOBALS_H__

//These defines new variables with its parameters initialized by yourself, they are called Variadic Macros.
/*In this case everytime we call LOG, it will ned a format and same with log, but in this one we will need a file (path to a file, it will return the path itself),
a line (where is the actual line in the file) , a format and Variable Arguments*/
#define LOG(format,...) log(__FILE__, __LINE__, format,__VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

//????????
#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

//update_status as a enum type. As Update() will have more conditions besides true and false.
enum update_status {

	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR

};

typedef unsigned int uint;

//Configuration
#define SCREEN_SIZE 2
#define SCREEN_WIDTH 360
#define SCREEN_HEIGHT 240
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0
//vertical syncronization
#define REN_VSYNC 1

#endif // _GLOBALS_H_
