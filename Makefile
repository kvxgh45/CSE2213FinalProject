store: User.o Account.o Book.o ShoppingCart.o Order.o ExFiles.o
	g++ User.o Account.o Book.o ShoppingCart.o Order.o ExFiles.o -o store

User.o: User.cpp User.h
	g++ -c User.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

ShoppingCart.o: ShoppingCart.cpp ShoppingCart.h
	g++ -c ShoppingCart.cpp

Order.o: Order.cpp Order.h
	g++ -c Order.cpp

ExFiles.o: ExFiles.cpp User.h Account.h Book.h ShoppingCart.h Order.h
	g++ -c ExFiles.cpp

clean:
	rm *.o store