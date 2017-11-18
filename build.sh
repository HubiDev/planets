echo "Executing build for $USER at `date`"

# Move to build directory

cd build
echo "Current dir ${PWD}"

#Delete old files

if [ -f "main.o" ]
then
    rm main.o
fi

if [ -f "planets" ]
then
    rm planets
fi

#Execute build
echo "Compiling program..."
g++ -c ../main.cpp

#Link to SFML
echo "Linking to SFML libs..."
g++ main.o -o planets -lsfml-graphics -lsfml-window -lsfml-system