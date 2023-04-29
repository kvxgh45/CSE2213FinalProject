store: User.o Account.o Shirts.o Cart.o Order.o main.o
	g++ User.o Account.o Shirts.o Cart.o Order.o main.o -o store

User.o: User.cpp User.h
	g++ -c User.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

Shirts.o: Shirts.cpp Shirts.h
	g++ -c Shirts.cpp

Cart.o: Cart.cpp Cart.h
	g++ -c Cart.cpp

Order.o: Order.cpp Order.h
	g++ -c Order.cpp

main.o: main.cpp User.h Account.h Shirts.h Cart.h Order.h
	g++ -c main.cpp

clean:
	rm *.o store