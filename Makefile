OBJDIR = libs/objs
objects = $(addprefix $(OBJDIR)/, Message.o sha1.o ExceptionHandling.o User.o \
	 		UserBase.o Chat.o Functions.o \
			main.o MessageBase.o)

Chat: 
	g++ -o Chat $(objects)
Message.o:
	g++ -c libs/lDataBases/Message.cpp
	mv Message.o libs/objs
sha1.o:
	g++ -c libs/lHash/sha1.cpp
	mv sha1.o libs/objs
ExceptionHandling.o:
	g++ -c libs/lExceptions/ExceptionHandling.cpp
	mv ExceptionHandling.o libs/objs
User.o:
	g++ -c -I libs/lHash libs/lDataBases/User.cpp
	mv User.o libs/objs
UserBase.o:
	g++ -std=c++17 -c -I libs/lHash libs/lDataBases/UserBase.cpp -lstdc++fs
	mv UserBase.o libs/objs
Chat.o:
	g++ -std=c++17 -c -I libs/lDataBases -I libs/lHash -I libs/lExceptions libs/Chat.cpp -lstdc++fs
	mv Chat.o libs/objs
Functions.o:
	g++ -std=c++17 -c -I libs/lExceptions -I libs/lDataBases -I libs/lHash libs/Functions.cpp -lstdc++fs
	mv Functions.o libs/objs
main.o:
	g++ -std=c++17 -c -I libs/lExceptions -I libs/lDataBases -I libs/lHash libs/main.cpp -lstdc++fs
	mv main.o libs/objs
MessageBase.o:
	g++ -std=c++17 -c -I libs/lHash libs/lDataBases/MessageBase.cpp -lstdc++fs
	mv MessageBase.o libs/objs
