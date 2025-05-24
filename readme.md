# Patrei

## Installation of ANTLR

In order to work on patrei you first need to install the ANTLR library on linux. There is a special path that is logically correct but doesn't have to be used, that is /usr/local/lib.

We will install the ANTLR into that directory. Download a copy of .jar that contains everything ANTLR needs and you must have java installed on your machine, even if the code generated might be C++ or python.

Set CLASSPATH, Java will be able to find both the ANTLR tool and the runtime library that way.

On UNIX add this to the list of environmental variables .bashrc
Replace the name "antlr-4.0-complete.jar" with the name of your jar file

```bash
export CLASSPATH=".:/usr/local/lib/antlr-4.0-complete.jar:$CLASSPATH"
```
