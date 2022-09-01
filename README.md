# computacao-grafica

Repositório destinado aos exercícios práticos realizados em sala de aula da disciplina GAC104 - Computação Gráfica

### Instruções e comandos para compilar e executar em ambientes Windows:

- Instalar o MinGW: https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/

- Tutorial de configuração/instação MinGW: https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/

- Seguir o seguinte tutorial de configuração da biblioteca GLUT no MinGW: https://w3.cs.jmu.edu/bernstdh/web/common/help/cpp_mingw-glut-setup.php

obs: O passo anterior, de forma simplicaficada, devem ser incluídas as .h do glut na pasta include do MinGW e os arquivos glut32.dll e glut32.lib devem ser incluídos na mesma pasta que o código "01-nomeExercicio.cpp", além disso é necessário descomentar a linha da biblioteca "#include <windows.h>"

`> g++ -o '.\01-nomeExercicio' -Wall '.\01-nomeExercicio.cpp' -mwindows glut32.lib -lopengl32 -lglu32`

`> & '.\01-nomeExercicio'`

### Instruções e comandos para compilar e executar em ambientes Linux

- Instale a OpenGL Utility Toolkit (GLUT) por meio do comando sudo apt-get install freeglut3-dev
- Instale o pacote Miscellaneous Mesa GL utilities por meio do cmando sudo apt-get install mesa-utils
- Instale as bibliotecas X11 miscellaneous utility library e X11 Input extension library por meio do comando `sudo apt-get install libxmu-dev libxi-dev`
- Após completar as instalações, compile o código com o seguinte comando `g++ -o 01-nomeExercicio 01-nomeExercicio.cpp -lglut -lGLU -lGL -lm`
- Execute o programa `$ ./01-nomeExercicio`
