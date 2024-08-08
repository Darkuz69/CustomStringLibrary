# ✨ CustomString
Hey, Darkuz_69 here!! This is my string implementation in C Language.

# 🤖 Functions
In this library, strings are called "custom_string", which is an alias for the data type "char*"
~~~c
typedef char* custom_string;
~~~
Currently, this library has 4 Functions:
- 🔨 createString(string) -> a variable declaration function forr custom_strings
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
📌 Disclaimer: Please, always call this function when using this library for I have not yet achieved the skill to create some header magic to automatically call this function. In order to call this function, use the atexit function...
~~~c
atexit(freeStrings);
~~~

# 📜 Log.txt
These file contains the "behind-the-scenes" process as I create this project. Some phrases are written in my native language, so apologies in advance (if someone finds this repo)