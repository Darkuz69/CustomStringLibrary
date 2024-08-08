# ✨ CustomString
Hey, Darkuz_69 here!! This is my string implementation in C Language.

# 🤖 Functions
In this library, strings are called "custom_string", which is an alias for the data type "char*"
~~~c
typedef char* custom_string;
~~~
Currently, this library has 4 Functions:
- 🔨 createString(string) -> a variable declaration function for custom_strings
~~~c
custom_string myStr = createString("This is a sample string");
~~~
- 🫴 getString(prompt) -> get a string from a user input
~~~c
custom_string myStr = getString("Enter something here: ");
~~~
- 🚚 getLength(string) -> returns the length of the given string
~~~c
int len = getLength(myStr);
int len2 = getLength("Sample");
~~~
- 🆓 freeStrings() -> frees all the strings created by the user;
~~~c
freeStrings();
~~~
📌 Disclaimer: This function is now a destructor, which means, it would be called at the end of a program.

# 🤔 Compiling
To compile with this library, use this...
~~~bash
gcc {filename}.c -L. -lcustomstring -o {filename}
~~~

# 📜 Log.txt
These file contains the "behind-the-scenes" process as I create this project. Some phrases are written in my native language, so apologies in advance (if someone finds this repo)
