# nutil

nutil is a c library for converting converting arbitrary long numbers

## Build
```sh
make all        # builds a shared and static library
make install    # builds and intalls the shared and static library and the headers
make test       # builds the test executeable
make example    # builds the example executeable

make uninstall  # deletes the library and the headers
make clean      # deletes intermediate compilation files
make fclean     # deletes all the output files from the compilation
```

when linking nutil into your executeable, link it with -lm (math.h) and -lgmp (GNU Multiple Precision Arithmetic Library)

## Usage
For example code, look at the file example.c, its a program thats print numbers in decimal

for more documentation you should look at nutil.h 

## todo list
* add support for decimal point and non-integer numbers

## Contributing
Please open an issue first to discuss what you would like to change. be sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)