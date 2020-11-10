# nutil

nutil is a c library for converting converting arbitay long numbers

## Build
```sh
make all     # builds a shared and static library
make test    # builds the test executeable
make example # builds an example executable
```

when linking nutil into your executable, link it with -lm (math.h) and -lgmp (GNU Multiple Precision Arithmetic Library)

## Usage
For example code, look at the file example.c, its a program thats print numbers in decimal
```sh
> ./example ffff 16
66535
```

for more documentation you should look at nutil.h 

## todo list
* add support for decimal point and non-integer numbers

## Contributing
Please open an issue first to discuss what you would like to change. be sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
