all:
	gcc cooldude.c -lreadline -o cooldude-100
	strip cooldude-100
	gcc coding.c -lreadline -o coding-200
	strip coding-200
	gcc youshallnotpass.c -lreadline -std=gnu99 -o youshallnotpass-300
	strip youshallnotpass-300
	gcc blastoff.c -O3 -std=gnu99 -o blastoff-400
	strip blastoff-400
	gcc enterprise.c -lreadline -lcrypto -std=gnu99 -o enterprise-500
	strip enterprise-500

clean:
	rm -f cooldude-100
	rm -f coding-200
	rm -f youshallnotpass-300
	rm -f blastoff-400
	rm -f enterprise-500
