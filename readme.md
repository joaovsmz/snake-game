# Snake game project

## Português
### Descrição:
Esse projeto é o jogo clássico da cobrinha feito em linguagem C. Jogue escolhendo uma das três dificuldades disponíveis: fácil, médio ou difícil.

A cobra cresce ao de alimentar das comidas ( `*` )  geradas aleatóriamente numa posição do tabuleiro. O tamanho da cobra é a sua pontuação, tente marcar mais pontos antes da cobra ficar grande demais e ela acidentalmente se comer!

O jogo termina caso a cobra se alimente de uma parte de seu corpo ou se o jogador pressionar `q` durante o jogo. 

### Tecnologias utilizadas
O programa usa as bibliotecas nativas da linguagem C, como:
- `<stdio.h>`
- `<stdlib.h>`
- `<unist.h>`
- `<time.h>` 

Também é usada a biblioteca `ncurses.h`, para permitir uma maior manipulação dos caracteres na tela do terminal.

### Pré-requisitos
1. Build essentials `apt-get install -y build-essential `
2. ncurses `apt-get install -y libncurses5-dev`
3. Opcional: Docker

### Instalação e uso
Essa versão funciona nativamente numa distribuição Linux baseada em Debian.
1. Clone o repositório do github para uma pasta local `git clone https://github.com/joaovsmz/snake-game.git`
2. Instale a suite de compiladores com `apt-get install -y build-essential`
3. Instale o ncurses com `apt-get install -y libncurses5-dev`
4. Instale o docker [Como instalar?](https://docs.docker.com/desktop/install/linux/)


**Uso nativo no Linux**

Com o build essential e ncurses instalado, dentro da pasta do projeto:
1. Compile todo o projeto para gerar o executável usando o comando `make all`
2. Execute o programa com `./snake`


**Uso simplificado usando docker**

Com o docker instalado, dentro da pasta do projeto, execute o comando `make run` para criar o contâiner e executar o jogo.

### Licença
Esse projeto usa a licença [MIT](https://github.com/aws/mit-0), ou seja, está permitido clonar e fazer alterações a vontade no código.
Caso tenha alguma sugestão de melhoria, compartilhe comigo, assim posso melhorar minhas habilidades também!

### Autores
João



## English

### Description
This is the classical snake game done in C language. Play choosing one of the 3 dificulties: easy (fácil), medium (médio) or hard (difícil).

The snake grows eating the randomly generated food ( `*` ) in the board. The snake lenght is your current score, try to score as many points as you can before the snake becomes too big and it eats itself!

The game ends if the snake eats itself or if the player presses `q`.

### Used technologies
The program uses the native C language libraries:
- `<stdio.h>`
- `<stdlib.h>`
- `<unist.h>`
- `<time.h>` 

Library `ncurses.h`, to allow greater character manipulation on the screen.

### Requirements
1. Build essentials `apt-get install -y build-essential `
2. ncurses `apt-get install -y libncurses5-dev`
3. Opcional: Docker

### Installation and usage
This version works natively in a debian based Linux distro
1. Clone the remote repository to a local folder `git clone https://github.com/joaovsmz/snake-game.git`
2. Install the compiller suite `apt-get install -y build-essential`
3. Install ncurses with `apt-get install -y libncurses5-dev`
4. Install docker [How to install it?](https://docs.docker.com/desktop/install/linux/)


**Linux native use**

With both build essentials and ncurses installed, use the make commands inside the project folder:
1. Compile all files to generate the executable `make all`
2. Run the program with `./snake`


**Simplified use with docker**

With docker installed, inside the project folder, run `make run` to build and execute the container and play the game.

### Licence
This project uses the [MIT](https://github.com/aws/mit-0) license. You are free to clone and make any changes you want!
In case you have any improvement and other suggestions, please share with me so I can improve my skills!

### Authors
João
